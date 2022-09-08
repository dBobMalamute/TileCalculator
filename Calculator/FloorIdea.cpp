#include "FloorIdea.h"
#include <cmath>

FloorAttributes::FloorAttributes()
{
    m_listName = "Floor";
    m_displayName = "Floor";
    m_authors << "dBob";
    m_description = "Calculates the whole number below this number";
    m_iconPath = "qrc:/Icons/Floor.png";

    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesOut.push_back(Magic<NumberDataTypeAttributes>::cast().id());

    m_gear = true;

    m_embeddedQMLPath = ":/QML/FloorMinimized.qml";
}


FloorIdea::FloorIdea()
{

}

const IdeaAttributes FloorIdea::attributes()
{
    return Magic<FloorAttributes>::cast();
}

void FloorIdea::validate()
{
    auto n = m_input.lock();

    if(n)
    {
        setStatus(IdeaStatus::Working, "Flooring", "Calculating the floor of " + QString::number(n->number()));
        compute(n->number());
    }
    else
    {
        setDefaultStatus();
        emit clear();
    }
}

void FloorIdea::compute(double n)
{
    emit startSpinningGear();
    int answer = std::floor(n);

    m_result = std::make_shared<NumberDataType>(answer);
    emit newData(0);

    setupDisplay();

    emit stopSpinningGear();
}

