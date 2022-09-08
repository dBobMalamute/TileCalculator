import QtQuick 2.12
import com.malamute.calculator 1.0

InverseTrigFunctionTemplate
{
    Connections
    {
        target: idea
        function onDisplay(inputNumber, outputNumber)
        {
            inputText = "cos^-1(<font color=\"" + idea.inPortLabelColors[0] + "\">" +
                    parseFloat(inputNumber.toPrecision(4)) + "</font>" + ")";
            outputText = "= <font color=\"" + idea.outPortLabelColors[0] + "\">"
                    + parseFloat(outputNumber.toPrecision(4)) + "</font>";
        }
        function onClear()
        {
            inputText = "";
            outputText = "= ";
        }
    }
}
