#include "InverseCosineIdea.h"
#include <cmath>

InverseCosineAttributes::InverseCosineAttributes()
{
    m_listName = "Inverse Cosine";
    m_displayName = "Inverse Cosine";
    m_authors << "dBob";
    m_description = "This idea calculates the inverse cosine (acos) of the input number";
    m_iconPath = "qrc:/Icons/InverseCosine.png";

    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesOut.push_back(Magic<NumberDataTypeAttributes>::cast().id());

    m_gear = true;
    m_embeddedQMLPath = ":/QML/InverseCosineIdea.qml";
}

InverseCosineIdea::InverseCosineIdea()
{

}

const IdeaAttributes InverseCosineIdea::attributes()
{
    return Magic<InverseCosineAttributes>::cast();
}

void InverseCosineIdea::validate()
{
    auto n = m_input.lock();

    if(n)
    {
        if(n->number() < -1.0 || n->number() > 1.0)
        {
            setStatus(IdeaStatus::Error, "Complex Answer", "The inverse cosine of a number outside of the range -1 to 1 is a complex number");
            emit clear();
        }
        else
        {
            QString longMessage = "Calculating the inverse cosine of " + QString::number(n->number());

            if(degreeMode())
            {
                longMessage.append(" in degrees");
                longMessage.append("There are infinitely many answers. They are the answer + or - 360 an infinite number of times");

            }
            else
            {
                longMessage.append(" in radians");
                longMessage.append("There are infinitely many answers. They are the answer + or - 2PI an infinite number of times");
            }
            setStatus(IdeaStatus::Warning, "Multiple Answers", longMessage);
            compute(n->number());
        }
    }
    else
    {
        setDefaultStatus();
        emit clear();
    }
}

void InverseCosineIdea::compute(double n)
{
    emit startSpinningGear();

    double result;
    if(degreeMode())
    {
        result = 57.29577951 * acos(n);
        if(m_nAnswer % 2 == 0)
            result += m_nAnswer/2.0 * 360;
        else
            result = -result + (m_nAnswer+1)/2.0 * 360;
    }
    else //Radians.
    {
        result = acos(n);
        if(m_nAnswer % 2 == 0)
            result += m_nAnswer * M_PI;
        else
            result = -result + (m_nAnswer+1) * M_PI;
    }

    m_result = std::make_shared<NumberDataType>(result);
    emit newData(0);

    setupDisplay();

    emit stopSpinningGear();
}


