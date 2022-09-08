#include "TangentIdea.h"
#include <cmath>

TangentAttributes::TangentAttributes()
{
    m_listName = "Tangent";
    m_displayName = "Tangent";
    m_authors << "dBob";
    m_description = "This idea calculates the tangent of the input number";
    m_iconPath = "qrc:/Icons/Tangent.png";

    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesOut.push_back(Magic<NumberDataTypeAttributes>::cast().id());

    m_embeddedQMLPath = ":/QML/TangentIdea.qml";

    m_gear = true;
}

TangentIdea::TangentIdea()
{
    m_degreeMode = true;
}

const IdeaAttributes TangentIdea::attributes()
{
    return Magic<TangentAttributes>::cast();
}

void TangentIdea::validate()
{
    auto n = m_input.lock();

    if(n)
    {
        //Note that qTan operates in radian mode.
        // Get number between 0 and 2PI. in radian mode.
        double mod;
        if(degreeMode())
        {
            mod = fmod(n->number(),360);
            mod = mod * M_PI / 180.0;
        }
        else
        {
            mod = fmod(n->number(), 2.0*M_PI);
        }

        if(qFuzzyCompare(mod,M_PI_2) || qFuzzyCompare(mod, 3.0* M_PI_2) ||
                qFuzzyCompare(mod, -1.0* M_PI_2) || qFuzzyCompare(mod, -3.0* M_PI_2))
        {
            setStatus(IdeaStatus::Error, "Undefined", "The tangent of the input is undefined. This is not allowed");
            emit clear();

        }
        else
        {
            QString longMessage = "Calculating the Tangent of " + QString::number(n->number());
            if(degreeMode())
                longMessage.append(" in degrees");
            else
                longMessage.append(" in radians");
            setStatus(IdeaStatus::Working, "Calculating", longMessage);
            compute(mod);
        }
    }
    else
    {
        emit clear();
        setDefaultStatus();
    }
}

void TangentIdea::compute(double n)
{
    emit startSpinningGear();

    double tan;

    if(qFuzzyIsNull(n))
        tan = 0.0;
    else if (qFuzzyCompare(n, M_PI))
        tan = 0.0;
    else if (qFuzzyCompare(n, -1.0*M_PI))
        tan = 0.0;
    else
        tan = std::tan(n);

    m_result = std::make_shared<NumberDataType>(tan);
    emit newData(0);

    setupDisplay();

    emit stopSpinningGear();
}


