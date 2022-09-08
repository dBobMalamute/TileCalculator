import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12

Rectangle
{
    width:  Math.max(topNumInput.width,botNumInput.width) + slider.width
    height: topNumInput.height + botNumInput.height + 2;
    radius: 4

    color: "#1a1a1a"
    border.width: 2
    border.color: "#333333"

    TextInput
    {
        id: topNumInput
        font.bold: true
        font.pointSize: 12;
        color: "#a6b0cb"
        selectByMouse: true
        validator: DoubleValidator{top: 1.0; bottom: 0.0}
        onEditingFinished:
        {
            idea.setWeight(text);
        }

        Connections
        {
            target: idea
            function onWeightChanged()
            {
                topNumInput.text = idea.topWeightString();
            }
        }
        Component.onCompleted:
        {
            text = idea.topWeightString();
        }
    }
    TextInput
    {
        id: botNumInput
        anchors.top: topNumInput.bottom;
        anchors.topMargin: 4
        anchors.bottomMargin: 4
        font.bold: true
        font.pointSize: 12
        color: "#a6b0cb"
        selectByMouse: true
        validator: DoubleValidator{top: 1.0; bottom: 0.0}

        onEditingFinished:
        {
            idea.setWeight(1.0 - text);
        }

        Connections
        {
            target: idea
            function onWeightChanged()
            {
                botNumInput.text = idea.botWeightString();
            }
        }
        Component.onCompleted:
        {
            text = idea.botWeightString();
        }

    }

    Slider
    {
        id: slider
        width: 40
        height: parent.height + 10; y: -5
        x: 40
        orientation: Qt.Vertical
        from: 0.0; to: 1.0;
        value: idea.weight
        onMoved:
        {
            idea.setWeight(value)
        }
        Material.accent: "#a6b0cb"
        Material.foreground: "#a6b0cb"
    }
}



