/****************************************************************************
**
** Copyright (C) 2016
**
** This file is generated by the Magus toolkit
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE go (ODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
****************************************************************************/

#include "ogre3_renderman.h"
#include "OgreConfigFile.h"
#include "OgreArchiveManager.h"
#include "OgreHlms.h"
#include "OgreHlmsUnlit.h"
#include "OgreHlmsPbs.h"
#include "OgreHlmsManager.h"
#include "OgreHlmsCommon.h"

namespace Magus
{
    //****************************************************************************/
    OgreManager::OgreManager(void)
    {
        mGlContext = 0;

        #ifdef _DEBUG
            mResourcesCfg = "resources_d.cfg";
            mPluginsCfg = "plugins_d.cfg";
        #else
            mResourcesCfg = "resources.cfg";
            mPluginsCfg = "plugins.cfg";
        #endif

        // Create Ogre tt and initialize
        mRoot = new Ogre::Root(mPluginsCfg);

        // Setup renderer
        mCurrentRenderSystem = 0;
        const Ogre::RenderSystemList& rsList = mRoot->getAvailableRenderers();
        Ogre::RenderSystem* renderSystem = rsList[0];
        std::vector<Ogre::String> renderOrder;
        #if defined(Q_OS_WIN)
            renderOrder.push_back("Direct3D11");
        #endif
            renderOrder.push_back("OpenGL 3+");
        for (std::vector<Ogre::String>::iterator iter = renderOrder.begin(); iter != renderOrder.end(); iter++)
        {
            for (Ogre::RenderSystemList::const_iterator it = rsList.begin(); it != rsList.end(); it++)
            {
                if ((*it)->getName().find(*iter) != Ogre::String::npos)
                {
                    renderSystem = *it;
                    break;
                }
            }
            if (renderSystem != 0) break;
        }

        if (renderSystem == 0)
        {
            if (!mRoot->restoreConfig())
            {
                if (!mRoot->showConfigDialog())
                    OGRE_EXCEPT(Ogre::Exception::ERR_INVALIDPARAMS, "Abort render system configuration", "OgreManager::OgreManager");
            }
        }

        renderSystem->setConfigOption("Full Screen", "No");
        renderSystem->setConfigOption("VSync", "Yes");
        mRoot->setRenderSystem(renderSystem);
        mCurrentRenderSystem = renderSystem;

        // Uncomment next line to show dialog
        //if(mRoot->restoreConfig() || mRoot->showConfigDialog())
        //{
            mRoot->initialise(false);
        //}

        // Initialize resources
        setupResources();

        // Start timer
        mTimer = new Ogre::Timer();
        mTimer->reset();
    }

    //****************************************************************************/
    OgreManager::~OgreManager(void)
    {
        // Delete Ogre root
        delete mRoot;
    }

    //-------------------------------------------------------------------------------------
    void OgreManager::initialize(void)
    {
        // After resources have been setup and renderwindows created (in ogre widget), the Hlms managers are registered
        registerHlms();

        // Initialise, parse scripts etc
        Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
    }

    //-------------------------------------------------------------------------------------
    void OgreManager::setupResources(void)
    {
        // Load resource paths from config file
        Ogre::ConfigFile cf;
        cf.load(mResourcesCfg);

        // Go through all sections & settings in the file
        Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();

        Ogre::String secName, typeName, archName;
        while( seci.hasMoreElements() )
        {
            secName = seci.peekNextKey();
            Ogre::ConfigFile::SettingsMultiMap *settings = seci.getNext();

            if( secName != "Hlms" )
            {
                Ogre::ConfigFile::SettingsMultiMap::iterator i;
                for (i = settings->begin(); i != settings->end(); ++i)
                {
                    typeName = i->first;
                    archName = i->second;
                    Ogre::ResourceGroupManager::getSingleton().addResourceLocation( archName, typeName, secName );
                }
            }
        }
    }

    //****************************************************************************/
    bool OgreManager::isRenderSystemGL(void)
    {
        if (mCurrentRenderSystem)
            return (mCurrentRenderSystem->getName() == OGRE_RENDERSYSTEM_OPENGL3PLUS);

        return false;
    }

    //****************************************************************************/
    HGLRC OgreManager::getGlContext(void) const
    {
        return mGlContext;
    }

    //****************************************************************************/
    void OgreManager::setGlContext(HGLRC glContext)
    {
        mGlContext = glContext;
    }

    //****************************************************************************/
    void OgreManager::registerHlms(void)
    {
        Ogre::ConfigFile cf;
        cf.load(mResourcesCfg);

        Ogre::String dataFolder = cf.getSetting( "DoNotUseAsResource", "Hlms", "" );

        if( dataFolder.empty() )
            dataFolder = "./";
        else if( *(dataFolder.end() - 1) != '/' )
            dataFolder += "/";

        Ogre::RenderSystem* renderSystem = mRoot->getRenderSystem();
        Ogre::String shaderSyntax = "GLSL";
        if( renderSystem->getName() == OGRE_RENDERSYSTEM_DIRECTX11 )
            shaderSyntax = "HLSL";

        Ogre::Archive* archiveLibrary = Ogre::ArchiveManager::getSingletonPtr()->load(
                        dataFolder + "Hlms/Common/" + shaderSyntax,
                        "FileSystem", true );

        Ogre::ArchiveVec library;
        library.push_back( archiveLibrary );

        Ogre::Archive* archiveUnlit = Ogre::ArchiveManager::getSingletonPtr()->load(
                        dataFolder + "Hlms/Unlit/" + shaderSyntax,
                        "FileSystem", true );

        Ogre::HlmsUnlit* hlmsUnlit = OGRE_NEW Ogre::HlmsUnlit( archiveUnlit, &library );
        mRoot->getHlmsManager()->registerHlms( hlmsUnlit );

        Ogre::Archive* archivePbs = Ogre::ArchiveManager::getSingletonPtr()->load(
                        dataFolder + "Hlms/Pbs/" + shaderSyntax,
                        "FileSystem", true );
        Ogre::HlmsPbs* hlmsPbs = OGRE_NEW Ogre::HlmsPbs( archivePbs, &library );
        mRoot->getHlmsManager()->registerHlms( hlmsPbs );

        if( renderSystem->getName() == "Direct3D11 Rendering Subsystem" )
        {
            //Set lower limits 512kb instead of the default 4MB per Hlms in D3D 11.0
            //and below to avoid saturating AMD's discard limit (8MB) or
            //saturate the PCIE bus in some low end machines.
            bool supportsNoOverwriteOnTextureBuffers;
            renderSystem->getCustomAttribute( "MapNoOverwriteOnDynamicBufferSRV",
                                              &supportsNoOverwriteOnTextureBuffers );

            if( !supportsNoOverwriteOnTextureBuffers )
            {
                hlmsPbs->setTextureBufferDefaultSize( 512 * 1024 );
                hlmsUnlit->setTextureBufferDefaultSize( 512 * 1024 );
            }
        }
    }

    //****************************************************************************/
    void OgreManager::renderOgreWidgetsOneFrame(void)
    {
        if (mRoot && !mQOgreWidgetMap.isEmpty())
        {
            // Determine time since last frame
            Ogre::Real timeSinceLastFrame = 0.0f;
            unsigned long startTime = 0;

            // Render an one frame
            startTime = mTimer->getMillisecondsCPU();
            mRoot->renderOneFrame();
            timeSinceLastFrame = (mTimer->getMillisecondsCPU() - startTime) / 1000.0f;

            // Update all QOgreWidgets
            QMap<int, QOgreWidget*>::iterator i;
            QOgreWidget* item = 0;
            for (i = mQOgreWidgetMap.begin(); i != mQOgreWidgetMap.end(); ++i)
            {
                item = i.value();
                item->updateOgre(timeSinceLastFrame);
            }
        }
    }

    //****************************************************************************/
    void OgreManager::registerOgreWidget(int ogreWidgetId, QOgreWidget* ogreWidget)
    {
        mQOgreWidgetMap[ogreWidgetId] = ogreWidget;
    }

    //****************************************************************************/
    void OgreManager::unregisterOgreWidget(int ogreWidgetId)
    {
        mQOgreWidgetMap.remove(ogreWidgetId);
    }

    //****************************************************************************/
    QOgreWidget* OgreManager::getOgreWidget(int ogreWidgetId) const
    {
        return mQOgreWidgetMap.value(ogreWidgetId);
    }

    //****************************************************************************/
    Ogre::Root* OgreManager::getOgreRoot(void)
    {
        return mRoot;
    }
}