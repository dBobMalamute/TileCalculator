#include "LogarithmBaseNIdea.h"
#include <cmath>

LogarithmBaseNAttributes::LogarithmBaseNAttributes()
{
    m_listName = "Logarithm Base N";
    m_displayName = "Logarithm\nBase N";
    m_authors << "dBob";
    m_description = "Calculates the logarithm base 2 of the inputted number";
    m_iconPath = "qrc:/Icons/LogarithmBaseN.png";

    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesOut.push_back(Magic<NumberDataTypeAttributes>::cast().id());

    m_embeddedQMLPath = ":/QML/LogarithmBaseNMinimized.qml";

    m_externalQMLPaths << ":/QML/LogarithmBaseNControls.qml";
    m_externalQMLLocations.push_back({true, false, 10,0});

    m_gear = true;
}


LogarithmBaseNIdea::LogarithmBaseNIdea() :
    m_n(4.0)
{

}

const IdeaAttributes LogarithmBaseNIdea::attributes()
{
    return Magic<LogarithmBaseNAttributes>::cast();
}

QJsonObject LogarithmBaseNIdea::save() const
{
    QJsonObject saveJson = Idea::save();
    saveJson["n"] = m_n;

    return saveJson;
}

void LogarithmBaseNIdea::load(const QJsonObject &obj)
{
    Idea::load(obj);

    QJsonValue v = obj["n"];
    if(!v.isUndefined())
    {
        m_n = v.toDouble();
        emit nChanged(m_n);
    }

    validate();
}

void LogarithmBaseNIdea::validate()
{
    auto n1 = m_input.lock();
    if(n1)
    {
        if(n1->number() > 0.0)
        {
            setStatus(IdeaStatus::Working, "Logging", "Currently calcuating the log base N of " + QString::number(n1->number()));
            compute(n1->number());
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

void LogarithmBaseNIdea::compute(double n1)
{
    emit startSpinningGear();

    double log = std::log(n1) / std::log(m_n);

    m_result = std::make_shared<NumberDataType>(log);
    emit newData(0);

    setupDisplay();

    emit stopSpinningGear();
}

double LogarithmBaseNIdea::n() const
{
    return m_n;
}

void LogarithmBaseNIdea::setN(double n)
{
    if (qFuzzyCompare(m_n, n))
        return;

    if(n < 1.0)
    {
        emit nChanged(m_n);
        return;
    }
    QJsonObject oldParams;
    oldParams["n"] = m_n;

    m_n = n;
    emit nChanged(m_n);

    QJsonObject newParams;
    newParams["n"] = m_n;
    reportParamsChanged(oldParams, newParams);

    validate();
}



