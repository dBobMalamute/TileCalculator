import QtQuick 2.12

Rectangle
{
    id: root

    property double delay: 1000;
    property int borderWidth: 0;
    property color iColor: "black";
    property color fColor: "black";
    property rect initialCoords: Qt.rect(1,1,0,0);

    opacity:  0.0;

    color: iColor
    border.color: Qt.darker(iColor);
    border.width: borderWidth;

    function startActionAnimation()
    {
        resetAnimation.stop();
        actionAnimation.start();
    }

    function startResetAnimation()
    {
        actionAnimation.stop();
        root.opacity = 0.0;
        root.width = initialCoords.width;
        root.height = initialCoords.height
        root.color = iColor;
        root.border.color = Qt.darker(iColor);
        root.x = initialCoords.x
        root.y = initialCoords.y;
        resetAnimation.start();
    }

    SequentialAnimation
    {
        id: actionAnimation
        NumberAnimation
        {
            target: root
            property: "opacity"
            to: 0.75
            duration: 500
        }
        PropertyAnimation
        {
            target: root
            property: "color"
            to: fColor
            duration: 1000
        }
        PauseAnimation
        {
            duration: 200
        }
        ParallelAnimation
        {
            NumberAnimation
            {
                target: root
                property: "x"
                to: -30
                duration: 4000
            }
            NumberAnimation
            {
                target: root
                property: "y"
                to: 150
                duration: 4000
            }
            NumberAnimation
            {
                target: root
                property: "width"
                to: 0;
                duration: 4000;
            }
            NumberAnimation
            {
                target: root
                property: "height"
                to: 0;
                duration: 4000;
            }
            NumberAnimation
            {
                target: root
                property: "opacity"
                to: 1.0
                duration: 6000
            }
        }
    }

    SequentialAnimation
    {
        id: resetAnimation
        PauseAnimation
        {
            duration: delay;
        }
        PropertyAction
        {
            target: root
            property: "opacity"
            value: 1.0;
        }
    }
}
