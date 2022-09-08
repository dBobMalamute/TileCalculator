import QtQuick 2.0

Rectangle
{
    id: root
    property int boxNumber: 0;
    property int borderWidth: 0

    width: 60
    height: 40

    color: idea.inPortLabelColors[0]
    border.color: Qt.darker(idea.inPortLabelColors[0]);
    border.width: borderWidth;

    function maybeFadeOut(removeAbove)
    {
        if(removeAbove < boxNumber)
            fadeOutAnimation.start();
    }
    SequentialAnimation
    {
        id: fadeOutAnimation

        PropertyAnimation
        {
            target: root
            property: "color"
            to: idea.outPortLabelColors[0]
            duration: 1000
        }
        ParallelAnimation
        {
            NumberAnimation
            {
                target: root
                property: "opacity"
                to: 0.0;
                duration: 2500
            }
            NumberAnimation
            {
                target: root
                property: "width"
                to: 0.0;
                duration: 2500
            }
            NumberAnimation
            {
                target: root
                property: "x"
                to: root.x + root.width;
                duration: 2500
            }
            NumberAnimation
            {
                target: root
                property: "height"
                to: 0.0;
                duration: 2500
            }
        }


        ScriptAction
        {
            script: root.destroy();
        }
    }
}
