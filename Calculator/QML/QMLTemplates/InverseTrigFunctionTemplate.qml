import QtQuick 2.12
import QtQuick.Controls 2.13

Item
{
    height: 90
    width: 100;

    property alias inputText: input.text;
    property alias outputText: output.text;

    Rectangle
    {
        id: paperArea
        anchors.horizontalCenter: parent.horizontalCenter
        width: Math.max(Math.max(input.width, output.width) + 10, 50);
        height: 34
        radius: 4

        color: "#1a1a1a"
        border.width: 2
        border.color: "#333333"

        Text
        {
            id: input;
            anchors.right: parent.right
            anchors.rightMargin: 5

            font.bold: true
            font.pointSize: 10
            color: "#a6b0cb"
            textFormat: Text.RichText

            text: ""
        }
        Rectangle
        {
            color: "#a6b0cb"
            anchors.right: input.right
            anchors.left: input.left
            height: 2
            anchors.top: input.bottom
            anchors.topMargin: 1
        }
        Text
        {
            id: output

            anchors.right: parent.right
            anchors.rightMargin: 5
            anchors.top: input.bottom
            anchors.topMargin: 1

            font.bold: true
            font.pointSize: 10
            color: "#a6b0cb"
            textFormat: Text.RichText

            text: "= "
        }
    }

    SpinBox
    {
        anchors.bottom: radianDegreeItem.top
        anchors.bottomMargin: -14
        scale: 0.6
        anchors.horizontalCenter: parent.horizontalCenter
        to: 2147483646
        from: -2147483646
        editable: true;
        value: idea.nAnswer
        onValueModified:
        {
            idea.setNAnswer(value);
        }
    }

    Item
    {
        id: radianDegreeItem
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        height: 30

        Switch
        {
            id: element
            text: ""
            anchors.horizontalCenter: parent.horizontalCenter
            y: -10
            scale: 0.5
            onToggled:
            {
                //Checked == Radians.
                if(checked)
                {
                    text.text = "Radian"
                    idea.setDegreeMode(false);
                }
                else
                {
                    text.text = "Degree"
                    idea.setDegreeMode(true);
                }
            }
            Connections
            {
                target: idea
                function onDegreeModeChanged(degreeMode)
                {
                    if(degreeMode === false)
                    {
                        element.checked = true;
                        text.text = "Radian";
                    }
                    else
                    {
                        element.checked = false;
                        text.text = "Degree"
                    }
                }
            }
        }
        Text
        {
            id: text
            y: 15
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: -10
            text: "Degree"
        }
    }
}
