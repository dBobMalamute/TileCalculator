import QtQuick 2.12
import QtQuick.Controls 2.12

FocusScope
{
    width: Math.max(10, numeratorInput.implicitWidth, denominatorInput.implicitWidth)
    height: numeratorInput.implicitHeight - 4 + denominatorInput.implicitHeight;

    Rectangle
    {
        anchors.fill: parent
        anchors.margins: -2

        radius: 4

        color: "#1a1a1a"
        border.width: 2
        border.color: "#333333"

        MouseArea
        {
            anchors.fill: parent
            cursorShape: Qt.IBeamCursor;
            acceptedButtons: Qt.NoButton
        }

        TextInput
        {
            id: numeratorInput

            anchors.horizontalCenter: parent.horizontalCenter
            font.bold: true
            font.pointSize: 12
            verticalAlignment: TextInput.AlignVCenter
            horizontalAlignment: TextInput.AlignHCenter
            color: idea.outPortLabelColors[0]
            selectByMouse: true
            validator: DoubleValidator{decimals: 10}
            text: idea.numerator;
            focus: true

            onEditingFinished:
            {
                idea.setNumerator(text)
            }
            onActiveFocusChanged:
            {
                if(numeratorInput.activeFocus && numeratorInput.text === "0")
                {
                    numeratorInput.text = "";
                }
                if(!numeratorInput.activeFocus && numeratorInput.text === "")
                {
                    numeratorInput.text = "0"
                    idea.setNumerator(0);
                }
            }
        }

        Rectangle
        {
            anchors.centerIn: parent
            height: 2
            width: parent.width - 6
            color: "#a6b0cb"
        }

        TextInput
        {
            id: denominatorInput

            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            font.bold: true
            font.pointSize: 12
            verticalAlignment: TextInput.AlignVCenter
            horizontalAlignment: TextInput.AlignHCenter
            color: idea.outPortLabelColors[0]
            selectByMouse: true
            validator: DoubleValidator{decimals: 10}
            text: idea.denominator;
            focus: true

            onEditingFinished:
            {
                idea.setDenominator(text)
            }

            onActiveFocusChanged:
            {
                if(!denominatorInput.activeFocus && denominatorInput.text === "")
                {
                    denominatorInput.text = "0"
                    idea.setDenominator(0);
                }
            }
        }
    }
}



