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

#ifndef MAGUS_NODE_CONSTANTS_H
#define MAGUS_NODE_CONSTANTS_H

#include <QString>

namespace Magus
{
    //****************************************************************************/
    // Enums
    enum Alignment {ALIGNED_LEFT, ALIGNED_RIGHT, ALIGNED_CENTER};
    enum QtPortShape {PORT_SHAPE_CIRCLE, PORT_SHAPE_SQUARE};


    //****************************************************************************/
    // Icons
    static const QString NODE_HEADER_COMPOUND_ICON = QString("../common/icons/compound.png");
    static const QString NODE_HEADER_ACTION1_ICON = QString("../common/icons/minmax.png");
    static const QString NODE_HEADER_ACTION2_ICON = QString("../common/icons/close.png");

    //****************************************************************************/
    // Types
    static const int NODE_KEY_GRAPHIC_ITEM_TYPE = 1;
    static const int NODE_KEY_GRAPHIC_ITEM_SUBTYPE = 2;
    static const int NODE_VALUE_TYPE_NODE = 2;
    static const int NODE_VALUE_TYPE_NODE_BODY = 3;
    static const int NODE_VALUE_TYPE_HEADER_ICON = 4;
    static const int NODE_VALUE_TYPE_ACTION_1_ICON = 5;
    static const int NODE_VALUE_TYPE_ACTION_2_ICON = 6;
    static const int NODE_VALUE_TYPE_PORT = 7;
    static const int NODE_VALUE_TYPE_HEADER_TITLE = 8;
    static const int NODE_VALUE_TYPE_CONNECTION = 9;
    static const int NODE_VALUE_SUBTYPE_COMPOUND = 10;

    //****************************************************************************/
    // Default node values
    static const int NODE_HEADER_TITLE_FONT_SIZE = 12;
    static const qreal NODE_HEADER_ICON_SIZE = 20.0f;
    static const qreal NODE_WIDTH = 200.0f;
    static const qreal NODE_HEADER_HEIGHT = 30.0f;
    static const qreal NODE_BODY_HEIGHT = 32.0f;

    //****************************************************************************/
    // Default port values
    static const unsigned int NODE_PORT_TYPE_INPUT = 1; // Reserved for input port
    static const unsigned int NODE_PORT_TYPE_OUTPUT = 2; // Reserved for output port
    static const int NODE_PORT_FONT_SIZE = 10;
    static const int NODE_PORT_SHAPE_SIZE = 10;
    static const qreal NODE_PORT_OFFSET = 10.0f;
    static const qreal NODE_PORT_WIDTH_MARGIN = 10.0f; // Margin in pixel value
    static const qreal NODE_PORT_HEIGHT_MARGIN_FACTOR = 0.8f; // Margin factor in fraction of text height
    static const int NODE_PORT_PEN_SIZE = 2;

    //****************************************************************************/
    // Default image values
    static const qreal NODE_IMAGE_OFFSET = 5.0f;
    static const qreal NODE_IMAGE_FRACTION = 0.95f;

    //****************************************************************************/
    // Actions
    static const unsigned int NODE_ACTION_BASE = 1;
    static const unsigned int NODE_ACTION_TARGET = 2;
    static const QString NODE_ACTION_DELETE = QString("Delete selected items");
    static const QString NODE_ACTION_CENTER = QString("Center");
    static const QString NODE_ACTION_SELECTED_TO_COMPOUND = QString("Create compound from selected items");
    static const QString NODE_ACTION_ZOOM = QString("Zoom (%)");
    static const QString NODE_ACTION_ZOOM_10 = QString("10%");
    static const QString NODE_ACTION_ZOOM_25 = QString("25%");
    static const QString NODE_ACTION_ZOOM_50 = QString("50%");
    static const QString NODE_ACTION_ZOOM_75 = QString("75%");
    static const QString NODE_ACTION_ZOOM_90 = QString("90%");
    static const QString NODE_ACTION_ZOOM_100 = QString("100%");
    static const QString NODE_ACTION_ZOOM_150 = QString("150%");
    static const QString NODE_ACTION_ZOOM_200 = QString("200%");
    static const QString NODE_ACTION_ZOOM_250 = QString("250%");
    static const QString NODE_ACTION_ZOOM_300 = QString("300%");
    static const QString NODE_ACTION_COLLAPSE_ALL = QString("Collapse all nodes");
    static const QString NODE_ACTION_EXPAND_ALL = QString("Expand all nodes");
    static const QString NODE_ACTION_EXPAND_COMPOUNDS = QString("Expand compounds");
    static const QString NODE_ACTION_FISHEY_VIEW = QString("Fisheye view");
    static const QString NODE_ACTION_FISHEYE_DISABLED = QString("Disabled");
    static const QString NODE_ACTION_FISHEYE_NORMAL = QString("Normal");
    static const QString NODE_ACTION_FISHEYE_NORMAL_SUBTLE = QString("Normal (subtle)");
    static const QString NODE_ACTION_FISHEYE_LARGE = QString("Large");
    static const QString NODE_ACTION_FISHEYE_LARGE_SUBTLE = QString("Large (subtle)");

    //****************************************************************************/
    // Miscellanious
    static const int NODE_PEN_WIDTH_UNSELECTED = 2;
    static const int NODE_PEN_WIDTH_SELECTED = 5;
}

#endif