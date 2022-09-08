#include "LogarithmBaseEIdea.h"
#include <cmath>

LogarithmBaseEAttributes::LogarithmBaseEAttributes()
{
    m_listName = "Natural Logarithm";
    m_displayName = "Natural\nLogarithm";
    m_authors << "dBob";
    m_description = "Calculates the logarithm base e of the inputted number. This is frequently called the natural logarithm (ln).";
    m_iconPath = "qrc:/Icons/LogarithmBaseE.png";

    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesOut.push_back(Magic<NumberDataTypeAttributes>::cast().id());

    m_embeddedQMLPath = ":/QML/LogarithmBaseEMinimized.qml";

    m_gear = true;
}

LogarithmBaseEIdea::LogarithmBaseEIdea()
{

}

const IdeaAttributes LogarithmBaseEIdea::attributes()
{
    return Magic<LogarithmBaseEAttributes>::cast();
}

void LogarithmBaseEIdea::validate()
{
    auto n1 = m_input.lock();
    if(n1)
    {
        if(n1->number() > 0.0)
        {
            setStatus(IdeaStatus::Working, "Logging", "Currently calcuating the log base e of " + QString::number(n1->number()));

            compute(n1->number());
        }
        else
        {
            setStatus(IdeaStatus::Error, "Imaginary Answer", "The logarithm of a non-positive number is an imaginary number. "
                                                             "Imaginary numbers are not currently supported");
            emit clear();
        }
    }
    else
    {
        setDefaultStatus();
        emit clear();
    }
}

void LogarithmBaseEIdea::compute(double n1)
{
    emit startSpinningGear();

    double log = std::log(n1);

    m_result = std::make_shared<NumberDataType>(log);
    emit newData(0);

    setupDisplay();

    emit stopSpinningGear();
}
