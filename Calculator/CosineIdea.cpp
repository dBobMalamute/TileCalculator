#include "CosineIdea.h"
#include <cmath>

CosineAttributes::CosineAttributes()
{
    m_listName = "Cosine";
    m_displayName = "Cosine";
    m_authors << "dBob";
    m_description = "This idea calculates the cosine of the input number";
    m_iconPath = "qrc:/Icons/Cosine.png";

    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesOut.push_back(Magic<NumberDataTypeAttributes>::cast().id());


    m_embeddedQMLPath = ":/QML/CosineIdea.qml";
}

CosineIdea::CosineIdea()
{
    m_degreeMode = true;
}

const IdeaAttributes CosineIdea::attributes()
{
    return Magic<CosineAttributes>::cast();
}

void CosineIdea::validate()
{
    auto n = m_input.lock();

    if(n)
    {
        QString longMessage = "Calculating the Cosine of " + QString::number(n->number());
        if(degreeMode())
            longMessage.append(" in degrees");
        else
            longMessage.append(" in radians");

        setStatus(IdeaStatus::Working, "Calculating", longMessage);
        compute(n->number());
    }
    else
    {
        emit clear();
        setDefaultStatus();
    }
}

void CosineIdea::compute(double n)
{
    emit startSpinningGear();

    //Note that qCos operates in radian mode.
    double mod;
    double cos;
    if(degreeMode())
    {
        mod = std::fmod(n,360);
        mod = mod * M_PI / 180.0;
    }
    else
    {
        mod = std::fmod(n, 2.0*M_PI);
    }

    if(qFuzzyCompare(mod, M_PI_2))
        cos = 0.0;
    else if (qFuzzyCompare(mod, 3*M_PI_2))
        cos = 0.0;
    else if (qFuzzyCompare(mod, -1.0*M_PI_2))
        cos = 0.0;
    else if (qFuzzyCompare(mod, -3.0*M_PI_2))
        cos = 0.0;
    else
        cos = std::cos(mod);

    m_result = std::make_shared<NumberDataType>(cos);
    emit newData(0);

    setupDisplay();

    emit stopSpinningGear();
}
