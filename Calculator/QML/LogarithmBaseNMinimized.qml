import QtQuick 2.12
import com.malamute.calculator 1.0

OneToOneTemplate
{
    Connections
    {
        target: idea
        function onDisplay(inputNumber, outputNumber)
        {
            inputText = "Log<sub>" + parseFloat((idea.n).toPrecision(4)) + "</sub>("
                    + "<font color=\"" + idea.inPortLabelColors[0] + "\">" +
                    parseFloat(inputNumber.toPrecision(4)) + "</font>" + ")";
            outputText = "= <font color=\"" + idea.outPortLabelColors[0] + "\">"
                    + parseFloat(outputNumber.toPrecision(4)) + "</font>";
        }
        function onClear()
        {
            inputText = "Log<sub>" + parseFloat((idea.n).toPrecision(4))  + "</sub>";
            outputText = "= ";
        }
    }
}
