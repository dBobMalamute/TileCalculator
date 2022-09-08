#include "ReciprocalIdea.h"

ReciprocalAttributes::ReciprocalAttributes()
{
    m_listName = "Reciprocal";
    m_displayName = "Reciprocal";
    m_authors << "dBob";
    m_description = "Calculates the reciprocal of a number.";
    m_iconPath = "qrc:/Icons/Reciprocal.png";

    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesOut.push_back(Magic<NumberDataTypeAttributes>::cast().id());

    m_embeddedQMLPath = ":/QML/ReciprocalMinimized.qml";

    m_gear = true;
}

ReciprocalIdea::ReciprocalIdea()
{

}

const IdeaAttributes ReciprocalIdea::attributes()
{
    return Magic<ReciprocalAttributes>::cast();
}

void ReciprocalIdea::validate()
{
    auto n1 = m_input.lock();
    if(n1)
    {
        if(qFuzzyCompare(n1->number(),0))
        {
            setStatus(IdeaStatus::Error, "Division by 0", "The inverse of 0 is not defined. L'hopitals rule may help in this situation");
            emit clear();
        }
        else
        {
            setStatus(IdeaStatus::Working, "Inversing", "Calculating the inverse of " + QString::number(n1->number()));
            compute(n1->number());
        }
    }
    else
    {
        setDefaultStatus();
        emit clear();
    }
}

void ReciprocalIdea::compute(double n1)
{
    emit startSpinningGear();
    m_result = std::make_shared<NumberDataType>(1.0/n1);

    setupDisplay();

    emit newData(0);
    emit stopSpinningGear();
}
