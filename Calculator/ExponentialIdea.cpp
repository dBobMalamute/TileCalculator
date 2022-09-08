#include "ExponentialIdea.h"
#include <cmath>

ExponentialAttributes::ExponentialAttributes()
{
    m_listName = "Exponential";
    m_displayName = "Exponential";
    m_authors << "dBob";
    m_description = "This idea calculates e (2.721828) to the inputted number.";
    m_iconPath = "qrc:/Icons/Exponential.png";

    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesOut.push_back(Magic<NumberDataTypeAttributes>::cast().id());

    m_gear = true;

    m_embeddedQMLPath = ":/QML/ExponentialMinimized.qml";
}

ExponentialIdea::ExponentialIdea()
{

}

const IdeaAttributes ExponentialIdea::attributes()
{
    return Magic<ExponentialAttributes>::cast();
}

void ExponentialIdea::validate()
{
    auto n1 = m_input.lock();
    if(n1)
    {
        setStatus(IdeaStatus::Working, "Exponentiating", "Calculating e to the " + QString::number(n1->number()) + " power.");
        compute(n1->number());
    }
    else
    {
        setDefaultStatus();
        emit clear();
    }
}

void ExponentialIdea::compute(double n1)
{
    emit startSpinningGear();

    double exp = std::exp(n1);

    m_result = std::make_shared<NumberDataType>(exp);
    emit newData(0);

    setupDisplay();

    emit stopSpinningGear();
}
