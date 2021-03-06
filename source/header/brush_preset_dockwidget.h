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

#ifndef BRUSH_PRESET_DOCKWIDGET_H
#define BRUSH_PRESET_DOCKWIDGET_H

#include <QtWidgets>
#include <QDockWidget>
#include <QTabWidget>
#include "brush_widget.h"
#include "preset_widget.h"
#include "clipboard_widget.h"

QT_BEGIN_NAMESPACE
class QDockWidget;
QT_END_NAMESPACE

class MainWindow;

/****************************************************************************
 This class represents a DockWidget
 It is a container class to hold the actual BrushWidget
 ***************************************************************************/
class BrushPresetDockWidget : public QDockWidget
{
    Q_OBJECT

    public:
        BrushPresetDockWidget(QString title, MainWindow* parent, Qt::WindowFlags flags = 0);
        ~BrushPresetDockWidget(void);

        // Add a thumb to the preset list
        void addPreset (const QString& path, const QString& thumbName);

        // Add a clip to the clipboard
        void addToClipboard (const QString& filename);

        // Use a selected clip from the clipboard
        void useFromClipboard (const QString& fileName, const QString& baseName);

    private slots:
        void handleBrushDoubleClicked(const QString& name, const QString& baseName);
        void handleCreateMaterial(const QString& name, const QString& baseName);
        void handleCreateMaterialAndApply(const QString& name, const QString& baseName);

    protected:
        const QString& createMaterialFromPreset (const QString& name, const QString& baseName);

    private:
        MainWindow* mParent;
        BrushWidget* mBrushWidget;
        PresetWidget* mPresetWidget;
        ClipboardWidget* mClipboardWidget;
        QTabWidget* mTabWidget;
        QString mHelperString;
};

#endif
