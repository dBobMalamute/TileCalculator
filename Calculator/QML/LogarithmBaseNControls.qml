import QtQuick 2.12
import com.malamute.controlsStyles 1.0

Rectangle
{
    width: 80
    height: 60

    radius: ControlsStyle.radius()
    border.color: ControlsStyle.borderColor()
    border.width: ControlsStyle.borderWidth()

    gradient: Gradient
    {
        GradientStop{ position: 0.05; color: ControlsStyle.gradientTop()}
        GradientStop{position: 0.5; color: ControlsStyle.gradientMid()}
        GradientStop{ position: 0.95; color: ControlsStyle.gradientBottom()}
    }

    Text
    {
        text: "N:"
        font.pointSize: 12
        color: "#a6b0cb"
        x: 10
        anchors.verticalCenter: parent.verticalCenter
    }
    TextInput
    {
        text: idea.n;
        font.pointSize: 12
        color: idea.outPortLabelColors[0]
        x: 30
        anchors.verticalCenter: parent.verticalCenter
        selectByMouse: true;
        onEditingFinished:
        {
            idea.setN(text);
        }
        validator: DoubleValidator{bottom: 1.0; top: 10000}
    }
}
