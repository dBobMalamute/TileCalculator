#include "CeilingIdea.h"
#include <cmath>

CeilingAttributes::CeilingAttributes()
{
    m_listName = "Ceiling";
    m_displayName = "Ceiling";
    m_authors << "dBob";
    m_description = "Calculates the whole number above the input number";
    m_iconPath = "qrc:/Icons/Ceiling.png";

    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesOut.push_back(Magic<NumberDataTypeAttributes>::cast().id());

    m_gear = true;

    m_embeddedQMLPath = ":/QML/CeilingMinimized.qml";
}

CeilingIdea::CeilingIdea()
{

}

const IdeaAttributes CeilingIdea::attributes()
{
    return Magic<CeilingAttributes>::cast();
}

void CeilingIdea::validate()
{
    auto n = m_input.lock();
    if(n)
    {
        setStatus(IdeaStatus::Working, "Calculating", "Calculating the ceiling of " + QString::number(n->number()));
        compute(n->number());
    }
    else
    {
        setDefaultStatus();
        emit clear();
    }
}

void CeilingIdea::compute(double n)
{
    emit startSpinningGear();
    int answer = std::ceil(n);

    m_result = std::make_shared<NumberDataType>(answer);
    emit newData(0);

    setupDisplay();

    emit stopSpinningGear();
}

