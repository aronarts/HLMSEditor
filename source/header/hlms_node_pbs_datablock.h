/****************************************************************************
**
** Copyright (C) 2016 - 2017
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

#ifndef HLMS_NODE_PBS_DATABLOCK_H
#define HLMS_NODE_PBS_DATABLOCK_H

#include <QWidget>
#include "node_node.h"

QT_BEGIN_NAMESPACE

QT_END_NAMESPACE

/****************************************************************************
 * ...
 ***************************************************************************/
class HlmsNodePbsDatablock : public Magus::QtNode
{
    public:
        HlmsNodePbsDatablock(QString title, QGraphicsItem* parent = 0);
        virtual ~HlmsNodePbsDatablock(void);

        // Getters
        const QString& getName (void) {return mName;}
        float getDiffuseRed(void) const {return mDiffuseRed;}
        float getDiffuseGreen(void) const {return mDiffuseGreen;}
        float getDiffuseBlue(void) const {return mDiffuseBlue;}
        float getBackgroundDiffuseRed(void) const {return mBackgroundDiffuseRed;}
        float getBackgroundDiffuseGreen(void) const {return mBackgroundDiffuseGreen;}
        float getBackgroundDiffuseBlue(void) const {return mBackgroundDiffuseBlue;}
        float getBackgroundDiffuseAlpha(void) const {return mBackgroundDiffuseAlpha;}
        float getSpecularRed(void) const {return mSpecularRed;}
        float getSpecularGreen(void) const {return mSpecularGreen;}
        float getSpecularBlue(void) const {return mSpecularBlue;}
        float getRoughness(void) const {return mRoughness;}
        unsigned int getWorkflow(void) const {return mWorkflow;}
        float getMetalness(void) const {return mMetalness;}
        bool isSeparateFresnel(void) const {return mSeparateFresnel;}
        float getFresnelRed(void) const {return mFresnelRed;}
        float getFresnelGreen(void) const {return mFresnelGreen;}
        float getFresnelBlue(void) const {return mFresnelBlue;}
        float getTransparencyValue(void) const {return mTransparencyValue;}
        unsigned int getTransparencyMode(void) const {return mTransparencyMode;}
        bool isTwoSidedLighting(void) const {return mTwoSidedLighting;}
        bool isUseAlphaFromTexture(void) const {return mUseAlphaFromTexture;}
        unsigned int getBrdf(void) {return mBrdf;}
        unsigned int getAlphaTest(void) const {return mAlphaTest;}
        float getAlphaTestThreshold(void){return mAlphaTestThreshold;}

        // Setters
        void setName (const QString& name) {mName = name;}
        void setDiffuseRed(float diffuseRed) {mDiffuseRed = diffuseRed;}
        void setDiffuseGreen(float diffuseGreen) {mDiffuseGreen = diffuseGreen;}
        void setDiffuseBlue(float diffuseBlue) {mDiffuseBlue = diffuseBlue;}
        void setBackgroundDiffuseRed(float backgroundDiffuseRed) {mBackgroundDiffuseRed = backgroundDiffuseRed;}
        void setBackgroundDiffuseGreen(float backgroundDiffuseGreen) {mBackgroundDiffuseGreen = backgroundDiffuseGreen;}
        void setBackgroundDiffuseBlue(float backgroundDiffuseBlue) {mBackgroundDiffuseBlue = backgroundDiffuseBlue;}
        void setBackgroundDiffuseAlpha(float backgroundDiffuseAlpha) {mBackgroundDiffuseAlpha = backgroundDiffuseAlpha;}
        void setSpecularRed(float specularRed) {mSpecularRed = specularRed;}
        void setSpecularGreen(float specularGreen) {mSpecularGreen = specularGreen;}
        void setSpecularBlue(float specularBlue) {mSpecularBlue = specularBlue;}
        void setRoughness(float roughness) {mRoughness = roughness;}
        void setWorkflow(unsigned int workflow) {mWorkflow = workflow;}
        void setMetalness(float metalness) {mMetalness = metalness;}
        void setSeparateFresnel(bool separateFresnel) {mSeparateFresnel = separateFresnel;}
        void setFresnelRed(float fresnelRed) {mFresnelRed = fresnelRed;}
        void setFresnelGreen(float fresnelGreen) {mFresnelGreen = fresnelGreen;}
        void setFresnelBlue(float fresnelBlue) {mFresnelBlue = fresnelBlue;}
        void setTransparencyValue(float transparencyValue) {mTransparencyValue = transparencyValue;}
        void setTransparencyMode(unsigned int transparencyMode) {mTransparencyMode = transparencyMode;}
        void setTwoSidedLighting(bool twoSidedLighting) {mTwoSidedLighting = twoSidedLighting;}
        void setUseAlphaFromTexture(bool useAlphaFromTexture) {mUseAlphaFromTexture = useAlphaFromTexture;}
        void setBrdf(unsigned int brdf) {mBrdf = brdf;}
        void setAlphaTest(unsigned int alphaTest) {mAlphaTest = alphaTest;}
        void setAlphaTestThreshold(float alphaTestThreshold){mAlphaTestThreshold = alphaTestThreshold;}

    private:
        QString mName;
        float mDiffuseRed;
        float mDiffuseGreen;
        float mDiffuseBlue;
        float mBackgroundDiffuseRed;
        float mBackgroundDiffuseGreen;
        float mBackgroundDiffuseBlue;
        float mBackgroundDiffuseAlpha;
        float mSpecularRed;
        float mSpecularGreen;
        float mSpecularBlue;
        float mRoughness;
        unsigned int mWorkflow; // 0 = Specular Workflow
                                // 1 = Specular as fresnel Workflow
                                // 2 = Metallic Workflow
        float mMetalness;
        bool mSeparateFresnel;
        float mFresnelRed;
        float mFresnelGreen;
        float mFresnelBlue;
        float mTransparencyValue;
        unsigned int mTransparencyMode; // 0 = None
                                        // 1 = Transparent
                                        // 2 = Fade
        bool mTwoSidedLighting;
        bool mUseAlphaFromTexture;
        unsigned int mBrdf;
        unsigned int mAlphaTest;
        float mAlphaTestThreshold;
};

#endif
