import QtQuick 2.12

Rectangle
{
    id: root
    property double delay: 1000;
    property int borderWidth: 0;
    property color iColor: "black";
    property color fColor: "black";
    property point initialPoint;
    property point finalPoint;
    property double finalWidth: width;
    property double initialWidth: width;

    width: 60
    height: 40
    x: initialPoint.x
    y: initialPoint.y
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
        root.width = initialWidth;
        root.color = iColor;
        root.border.color = Qt.darker(iColor);
        root.x = initialPoint.x
        root.y = initialPoint.y;
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
        ParallelAnimation
        {
            PropertyAnimation
            {
                target: root
                property: "color"
                to: fColor
                duration: 5000
            }
            NumberAnimation
            {
                target: root
                property: "x"
                to: finalPoint.x
                duration: 5000
            }
            NumberAnimation
            {
                target: root
                property: "y"
                to: finalPoint.y
                duration: 5000
            }
            NumberAnimation
            {
                target: root
                property: "width"
                to: finalWidth;
                duration: 5000;
            }
        }
        PropertyAnimation
        {
            target: root
            property: "border.color"
            to: Qt.darker(fColor);
            duration: 3000
        }
        NumberAnimation
        {
            target: root
            property: "opacity"
            to: 1.0
            duration: 500
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
