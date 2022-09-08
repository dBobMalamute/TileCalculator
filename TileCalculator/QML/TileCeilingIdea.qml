import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12

import com.malamute.tileCalculator 1.0

Item
{
    id: root
    height: 240
    width: 544



    Connections
    {
        target: idea
        function onDisplay(inputNumber, outputNumber)
        {
            outputText.text = outputNumber.toPrecision(4)
            inputText.text = inputNumber.toPrecision(4)

            if(inputNumber < 0.0 || inputNumber >= 79998)
            {
                animationUnsupportedText.visible = true;
                ceilingVisualArea.clear();
            }
            else
            {
                animationUnsupportedText.visible = false;
                ceilingVisualArea.setup(inputNumber, outputNumber,
                                      idea.inPortLabelColors[0],
                                      idea.outPortLabelColors[0]);
            }
        }
        function onClear()
        {
            inputText.text = "";
            outputText.text = "";
            animationUnsupportedText.visible = false;
            ceilingVisualArea.clear();
        }
    }

    Rectangle
    {
        id: inputArea
        anchors.left: parent.left
        height: parent.height
        width: 64
        gradient: Gradient
        {
            GradientStop{position: 0.0; color: "black"}
            GradientStop{position: 0.5; color: "#282828"}
            GradientStop{position: 1.0; color: "black"}
        }

        Rectangle
        {
            id: inputBox
            anchors.centerIn: parent
            width: 60
            height: 60
            color: idea.inPortLabelColors[0]
            border.width: 6
            border.color: Qt.darker(idea.inPortLabelColors[0]);
        }

        Text
        {
            anchors.top: inputBox.bottom
            anchors.topMargin: 4
            id: inputText
            text: "";
            color: idea.inPortLabelColors[0]
            font.pointSize: 12
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

    Rectangle
    {
        id: outputArea
        anchors.right: parent.right
        height: parent.height
        width: 64
        gradient: Gradient
        {
            GradientStop{position: 0.0; color: "black"}
            GradientStop{position: 0.5; color: "#282828"}
            GradientStop{position: 1.0; color: "black"}
        }

        Rectangle
        {
            id: outputBox
            anchors.centerIn: parent
            width: 60
            height: 60
            color: idea.outPortLabelColors[0]
            border.width: 6
            border.color: Qt.darker(idea.outPortLabelColors[0]);
        }

        Text
        {
            anchors.top: outputBox.bottom
            anchors.topMargin: 4
            id: outputText
            text: "";
            color: idea.outPortLabelColors[0]
            font.pointSize: 12
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

    Rectangle
    {
        width: 408
        height: 208
        anchors.horizontalCenter: parent.horizontalCenter
        color: "#050512"
        radius: 4
        CeilVisualArea
        {
            id: ceilingVisualArea
            x: 4
            y: 4
        }
        Text
        {
            id: animationUnsupportedText;
            text: "Animation Unsupported";
            horizontalAlignment: Text.AlignHCenter
            color: "white"
            font.bold: true;
            font.pointSize: 12
            anchors.centerIn: ceilingVisualArea
            visible: false
        }
    }

    Rectangle
    {
        id: controlsRow
        width: buttonsRow.width + 10 //Row is width: 286
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        height: 34

        radius: 4
        color: "#050512"
        Row
        {
            id: buttonsRow
            x: 5
            spacing: 6

            Button
            {
                id: divideByBaseButton
                height: 32
                text: "Ceiling"
                anchors.verticalCenter: parent.verticalCenter;
                onClicked:
                {
                    ceilingVisualArea.action();
                }
                Material.background: idea.outPortLabelColors[0]
                Material.foreground: "#1a1a1a"
            }

            Button
            {
                id: resetButton
                height: 32
                text: "Reset"
                anchors.verticalCenter: parent.verticalCenter;
                onClicked:
                {
                    ceilingVisualArea.reset();
                }
                Material.background: Material.Grey
                Material.foreground:  "#1a1a1a"
            }
        }
    }
}
