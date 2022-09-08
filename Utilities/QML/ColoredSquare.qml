import QtQuick 2.12
import com.testing.test 1.0

Rectangle
{
    width: 100
    height: 100
    color: "teal"

    LoadTestingRectangle
    {
        rad: 12
        anchors.centerIn: parent
    }
    MouseArea
    {
        objectName: "MouseArea Testing purposes"
        id: mouseArea
        width: 100
        height: 100
        onClicked:
        {
            idea.getQCustomObject(mouseArea)
        }
        Rectangle
        {
            anchors.fill: parent
            color: "brown"
        }
    }

}
