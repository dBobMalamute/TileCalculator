import QtQuick 2.12

Rectangle
{
    id: root
    width: 100
    height: 100
    color: "teal"

    border.color: Qt.darker(color);
    border.width: 8
    opacity: 0.0;

    property color iColor: "black"
    property color fColor: "black"
    property double delay: 0

    function setBorderWidth(borderWidth)
    {
        border.width = borderWidth;
    }

    function startActionAnimation()
    {
        actionAnimation.start();
    }
    function startResetAnimation()
    {
        resetAnimation.start();
    }

    PropertyAnimation
    {
        id: actionAnimation
        property: "color"
        target: root;
        from: iColor;
        to: fColor
        duration: 3000
    }

    SequentialAnimation
    {
        id: resetAnimation
        PropertyAction
        {
            property: "color"
            value: iColor
            target: root
        }
        PropertyAction
        {
            property: "opacity"
            value: 0.0
            target: root
        }
        PauseAnimation
        {
            duration: delay
        }
        NumberAnimation
        {
            target: root
            property: "opacity"
            duration: 500
            to: 1.0;
        }
    }
}
