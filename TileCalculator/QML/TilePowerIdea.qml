import QtQuick 2.12
import com.malamute.calculator 1.0

PowerOfTemplate
{
    powerOfNumber: idea.base
    multiplyByBottonText: "Multiply by " + parseFloat((idea.base).toPrecision(4));
}
