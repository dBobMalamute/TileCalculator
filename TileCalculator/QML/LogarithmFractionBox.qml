import QtQuick 2.0

Rectangle
{
    id: root

    property int borderWidth: 0;

    width: 60
    height: 40

    color: idea.inPortLabelColors[0]
    border.color: Qt.darker(idea.inPortLabelColors[0]);
    border.width: borderWidth;

    function fadeOut()
    {
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
        NumberAnimation
        {
            target: root
            property: "opacity"
            to: 0.0;
            duration: 2500
        }
        ScriptAction
        {
            script: root.destroy();
        }
    }
}
