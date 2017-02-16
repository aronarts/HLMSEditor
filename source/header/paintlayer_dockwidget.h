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
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
****************************************************************************/

#ifndef PAINTLAYER_DOCKWIDGET_H
#define PAINTLAYER_DOCKWIDGET_H

#include <QtWidgets>
#include <QDockWidget>
#include "paintlayer_widget.h"

QT_BEGIN_NAMESPACE
class QDockWidget;
QT_END_NAMESPACE

class MainWindow;
class PaintLayerManager;

/****************************************************************************
 The PaintLayerDockWidget is a container to manage the PaintLayerManager and
 the PaintLayerWidget. The PaintLayerWidget is the actual widget that contains
 the table with layers/
 ***************************************************************************/
class PaintLayerDockWidget : public QDockWidget
{
    Q_OBJECT

    public:
        PaintLayerDockWidget(PaintLayerManager* paintLayerManager,
                             QString title,
                             MainWindow* parent,
                             Qt::WindowFlags flags = 0);
        ~PaintLayerDockWidget(void);

        /* Determines whether there is a current datablock.
         * It must be a Pbs, because Unlit painting is not very interesting (and therefor not supported)
         */
        bool currentDatablockExists(void);
        bool currentDatablockIsPbs(void);

        /* The function is called everytime a new Hlms material is created
         * The Paint Layers don't have any meaning for the new Hlms, so they can be deleted
         */
        void newHlmsCreated (void);

    private slots:
        void handleNewLayer (int layerId, QString layerName);
        void handleDeleteLayer (int layerId, QString layerName);
        void handleTextureTypeSelected(int layerId, QString textureType);

    private:
        MainWindow* mParent;
        PaintLayerWidget* mPaintLayerWidget;
        PaintLayerManager* mPaintLayerManager; // Use the PaintLayerManager to manager paint layers
};

#endif
