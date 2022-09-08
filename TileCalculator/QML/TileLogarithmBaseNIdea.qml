import QtQuick 2.12
import com.malamute.calculator 1.0

LogarithmTemplate
{
    logarithmBase: idea.n
    divideByBottonText: "Divide by " + parseFloat(idea.n.toPrecision(4));
}
