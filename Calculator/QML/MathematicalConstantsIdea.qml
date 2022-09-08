import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12

Rectangle
{
    width: 90
    height: 30;
    color: "#1a1a1a"
    border.width: 2
    border.color: "#333333"
    radius: 4

    ComboBox
    {
        id: comboBox

        anchors.verticalCenter: parent.verticalCenter;
        property bool complete: false

        Material.accent: idea.outPortLabelColors[0]
        Material.foreground: idea.outPortLabelColors[0]

        editable: false
        flat: true
        width: 82
        model: ["PI", "e", "PI/2", "PI/4", "1/PI", "1/e"];
        onCurrentTextChanged:
        {
            if(complete)
            {
                idea.setIndex(comboBox.currentIndex);
            }
        }

        Component.onCompleted:
        {
            comboBox.currentIndex = idea.getIndex();
            complete = true;
        }

        Connections
        {
            target: idea
            function onIndexChanged(i)
            {
                comboBox.currentIndex = i;
            }
        }
    }
}



