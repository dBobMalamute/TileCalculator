#include "InverseTangentIdea.h"
#include <cmath>

InverseTangentAttributes::InverseTangentAttributes()
{
    m_listName = "Inverse Tangent";
    m_displayName = "Inverse Tangent";
    m_authors << "dBob";
    m_description = "This idea calculates the inverse tangent (atan) of the input number";
    m_iconPath = "qrc:/Icons/InverseTangent.png";

    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesOut.push_back(Magic<NumberDataTypeAttributes>::cast().id());

    m_gear = true;

    m_embeddedQMLPath = ":/QML/InverseTangentIdea.qml";
}

InverseTangentIdea::InverseTangentIdea()
{

}

const IdeaAttributes InverseTangentIdea::attributes()
{
    return Magic<InverseTangentAttributes>::cast();
}

void InverseTangentIdea::validate()
{
    auto n = m_input.lock();
    if(n)
    {
        QString longMessage = "Calculating the Inverse Tangent of " + QString::number(n->number());
        if(degreeMode())
        {
            longMessage.append(" in degrees");
            longMessage.append("There are infinitely many answers. They are the answer + or - 180 an infinite number of times");
        }
        else
        {
            longMessage.append(" in radians");
            longMessage.append("There are infinitely many answers. They are the answer + or - PI an infinite number of times");
        }
        setStatus(IdeaStatus::Warning, "Multiple Answers", longMessage);
        compute(n->number());
    }
    else
    {
        setDefaultStatus();
        emit clear();
    }
}

void InverseTangentIdea::compute(double n)
{
    emit startSpinningGear();

    double result;
    if(degreeMode())
        result = 180 * m_nAnswer + 57.29577951*atan(n);
    else //Radians.
        result = M_PI * m_nAnswer + atan(n);

    m_result = std::make_shared<NumberDataType>(result);
    emit newData(0);

    setupDisplay();

    emit stopSpinningGear();
}

