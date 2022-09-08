#include "LogarithmBase10Idea.h"
#include <cmath>

LogarithmBase10Attributes::LogarithmBase10Attributes()
{
    m_listName = "Logarithm Base 10";
    m_displayName = "Logarithm\nBase 10";;
    m_authors << "dBob";
    m_description = "Calculates the logarithm base 10 of the inputted number";
    m_iconPath = "qrc:/Icons/LogarithmBase10.png";

    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesOut.push_back(Magic<NumberDataTypeAttributes>::cast().id());

    m_embeddedQMLPath = ":/QML/LogarithmBase10Minimized.qml";
    m_gear = true;
}

LogarithmBase10Idea::LogarithmBase10Idea()
{

}

const IdeaAttributes LogarithmBase10Idea::attributes()
{
    return Magic<LogarithmBase10Attributes>::cast();
}

void LogarithmBase10Idea::validate()
{
    auto n = m_input.lock();
    if(n)
    {
        if(n->number() > 0.0)
        {
            setStatus(IdeaStatus::Working, "Logging", "Currently calcuating the log base 10 of " + QString::number(n->number()));
            compute(n->number());
        }
        else
        {
            setStatus(IdeaStatus::Error, "Imaginary Answer", "The logarithm of a non-positive number is an imaginary number. Imaginary numbers are not currently supported");
            emit clear();
        }
    }
    else
    {
        setDefaultStatus();
        emit clear();
    }
}

void LogarithmBase10Idea::compute(double n)
{
    emit startSpinningGear();

    double log = std::log10(n);

    m_result = std::make_shared<NumberDataType>(log);
    emit newData(0);

    setupDisplay();

    emit stopSpinningGear();
}
