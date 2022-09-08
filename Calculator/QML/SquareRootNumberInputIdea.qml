import QtQuick 2.12
import QtQuick.Controls 2.12

FocusScope
{
    id: root
    width: 30+Math.max(10, numberInput.implicitWidth)
    height: 5+numberInput.implicitHeight;

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
            id: numberInput
            y: 6

            anchors.horizontalCenter: parent.horizontalCenter
            font.bold: true
            font.pointSize: 12
            verticalAlignment: TextInput.AlignVCenter
            horizontalAlignment: TextInput.AlignHCenter
            color: idea.outPortLabelColors[0]
            selectByMouse: true
            validator: DoubleValidator{decimals: 10}
            text: idea.number;
            focus: true

            onEditingFinished:
            {
                idea.setNumber(text)
            }

            onActiveFocusChanged:
            {
                if(!numberInput.activeFocus && numberInput.text === "")
                {
                    numberInput.text = "0"
                    idea.setNumber(0);
                }
            }
        }
    }
    Image
    {
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        height: 20
        fillMode: Image.PreserveAspectFit
        source: "qrc:/Images/SquareRootImage.png"
    }
}



