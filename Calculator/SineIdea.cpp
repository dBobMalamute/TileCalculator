#include "SineIdea.h"
#include <cmath>

SineAttributes::SineAttributes()
{
    m_listName = "Sine";
    m_displayName = "Sine";
    m_authors << "dBob";
    m_description = "This idea calculates the sine of the input number";
    m_iconPath = "qrc:/Icons/Sine.png";

    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesOut.push_back(Magic<NumberDataTypeAttributes>::cast().id());

    m_embeddedQMLPath = ":/QML/SineIdea.qml";

    m_gear = true;
}

SineIdea::SineIdea()
{
    m_degreeMode = true;
}

const IdeaAttributes SineIdea::attributes()
{
    return Magic<SineAttributes>::cast();
}

void SineIdea::validate()
{
    auto n = m_input.lock();

    if(n)
    {
        QString longMessage = "Calculating the Sine of " + QString::number(n->number());
        if(degreeMode())
            longMessage.append(" in degrees");
        else
            longMessage.append(" in radians");

        setStatus(IdeaStatus::Working, "Calculating",longMessage);
        compute(n->number());
    }
    else
    {
        emit clear();
        setDefaultStatus();
    }
}

void SineIdea::compute(double n)
{
    emit startSpinningGear();

    //Note that qSin operates in radian mode.
    double mod;
    double sin;
    if(degreeMode())
    {
        mod = fmod(n,360);
        mod = mod * M_PI / 180.0;
    }
    else
    {
        mod = fmod(n, 2.0*M_PI);
    }

    if(qFuzzyIsNull(mod))
        sin = 0.0;
    else if (qFuzzyCompare(mod, M_PI))
        sin = 0.0;
    else if (qFuzzyCompare(mod, -1.0*M_PI))
        sin = 0.0;
    else
        sin = std::sin(mod);

    m_result = std::make_shared<NumberDataType>(sin);
    emit newData(0);

    setupDisplay();

    emit stopSpinningGear();
}
