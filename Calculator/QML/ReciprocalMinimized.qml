import QtQuick 2.12
import com.malamute.calculator 1.0

TwoToOneTemplate
{
    Connections
    {
        target: idea
        function onDisplay(inputNumber, outputNumber)
        {
            input1Text = "1"
            input2Text = "÷ <font color=\"" + idea.inPortLabelColors[0] + "\">" +
                    parseFloat(inputNumber.toPrecision(4)) + "</font>";
            outputText = "= <font color=\"" + idea.outPortLabelColors[0] + "\">" +
                    parseFloat(outputNumber.toPrecision(4)) + "</font>";
        }
        function onClear()
        {
            input1Text = ""
            input2Text = "÷ ";
            outputText = "= ";
        }
    }
}
