#include "PowerOfTenIdea.h"
#include <cmath>

PowerOfTenAttributes::PowerOfTenAttributes()
{
    m_listName = "Power of 10";
    m_displayName = "Power of 10";
    m_authors << "dBob";
    m_description = "This idea calculates 10 to the inputted number.";
    m_iconPath = "qrc:/Icons/PowerOfTen.png";

    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesOut.push_back(Magic<NumberDataTypeAttributes>::cast().id());

    m_embeddedQMLPath = ":/QML/PowerOfTenMinimized.qml";

    m_gear = true;
}

PowerOfTenIdea::PowerOfTenIdea()
{

}

const IdeaAttributes PowerOfTenIdea::attributes()
{
    return Magic<PowerOfTenAttributes>::cast();
}

void PowerOfTenIdea::validate()
{
    auto n1 = m_input.lock();
    if(n1)
    {
        setStatus(IdeaStatus::Working, "Calculating", "Calculating 10 to the " +
                  QString::number(n1->number()) + " power.");
        compute(n1->number());
    }
    else
    {
        setDefaultStatus();
        emit clear();
    }
}

void PowerOfTenIdea::compute(double n1)
{
    emit startSpinningGear();

    double exp = std::pow(10.0,n1);
    m_result = std::make_shared<NumberDataType>(exp);
    emit newData(0);

    setupDisplay();

    emit stopSpinningGear();
}
