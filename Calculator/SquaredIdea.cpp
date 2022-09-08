#include "SquaredIdea.h"

SquaredAttributes::SquaredAttributes()
{
    m_listName = "Square";
    m_displayName = "Square";
    m_authors << "dBob";
    m_description = "Calcuates the square of a number. The number multiplied by itself.";
    m_iconPath = "qrc:/Icons/Squared.png";

    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesOut.push_back(Magic<NumberDataTypeAttributes>::cast().id());

    m_gear = true;

    m_embeddedQMLPath = ":/QML/SquaredMinimized.qml";
}

SquaredIdea::SquaredIdea()
{

}

const IdeaAttributes SquaredIdea::attributes()
{
    return Magic<SquaredAttributes>::cast();
}

void SquaredIdea::validate()
{
    auto n1 = m_input.lock();
    if(n1)
    {
        setStatus(IdeaStatus::Working, "Squaring", "Squaring: " + QString::number(n1->number()));
        compute(n1->number());
    }
    else
    {
        setDefaultStatus();
        emit clear();
    }
}

void SquaredIdea::compute(double n1)
{
    emit startSpinningGear();
    double sqr = n1*n1;

    m_result = std::make_shared<NumberDataType>(sqr);

    setupDisplay();

    emit newData(0);
    emit stopSpinningGear();
}


