import QtQuick 2.12

Rectangle
{
    id: root;
    height: 57
    radius: 4
    width: Math.max(Math.max(input.width + 14, output1.width, output2.width) + 10, 50)

    color: "#1a1a1a"
    border.width: 2
    border.color: "#333333"

    Connections
    {
        target: idea
        function onDisplayNumbers(inputNumber, outputNumber)
        {
            squareRootImage.visible = true;
            input.text = "<font color=\"" + idea.inPortLabelColors[0] + "\">" +
                    parseFloat(inputNumber.toPrecision(4)) + "</font>";
            output1.text = "= <font color=\"" + idea.outPortLabelColors[0] + "\">"
                    + parseFloat(outputNumber.toPrecision(4)) + "</font>";
            output2.text = "= <font color=\"" + idea.outPortLabelColors[1] + "\">"
                    + parseFloat((-1.0*outputNumber).toPrecision(4)) + "</font>";
        }
        function onClearNumbers()
        {
            squareRootImage.visible = false;
            input.text = "";
            output1.text = "= ";
            output2.text = "= ";
        }
    }

    Image
    {
        id: squareRootImage
        visible: false
        source: "qrc:/Images/SquareRootImage.png"
        height: 16
        y: 4
        fillMode: Image.PreserveAspectFit

        x: Math.min(input.x - 10, root.width - width)
    }

    Text
    {
        id: input;
        anchors.top: parent.top
        anchors.topMargin: 4
        anchors.right: parent.right
        anchors.rightMargin: 5
        textFormat: Text.RichText

        font.bold: true
        font.pointSize: 10
        color: "#a6b0cb"

        text: ""
    }

    Rectangle
    {
        color: "#a6b0cb"
        anchors.right: input.right
        anchors.left: input.left
        height: 2
        anchors.top: input.bottom
        anchors.topMargin: 0
    }

    Text
    {
        id: output1;

        anchors.right: parent.right
        anchors.rightMargin: 5
        anchors.top: input.bottom
        anchors.topMargin: 2

        font.bold: true
        font.pointSize: 10
        color: "#a6b0cb"
        textFormat: Text.RichText


        text: "= "
    }

    Text
    {
        id: output2

        anchors.right: parent.right
        anchors.rightMargin: 5
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 2

        font.bold: true
        font.pointSize: 10
        color: "#a6b0cb"
        textFormat: Text.RichText

        text: "= "
    }
}
