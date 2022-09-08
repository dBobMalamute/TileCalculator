#include "PowerIdea.h"
#include <cmath>

PowerAttributes::PowerAttributes()
{
    m_listName = "Power";
    m_displayName = "Power";
    m_authors << "dBob";
    m_description = "Calculates takes the first input to the second input power";
    m_iconPath = "qrc:/Icons/Power.png";


    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesOut.push_back(Magic<NumberDataTypeAttributes>::cast().id());

    m_labelsIn << "base" << "pow";
    m_labelsOut << "#";
    m_customLabels = true;

    m_embeddedQMLPath = ":/QML/PowerMinimized.qml";

    m_gear = true;
}


PowerIdea::PowerIdea()
{

}

const IdeaAttributes PowerIdea::attributes()
{
    return Magic<PowerAttributes>::cast();
}

void PowerIdea::validate()
{
    auto n1 = m_input1.lock(); //Base
    auto n2 = m_input2.lock(); // Power

    if(n1 && n2)
    {
        setStatus(IdeaStatus::Working,"Calculating","Calculating " + QString::number(n1->number()) +
                  " to the " + QString::number(n2->number()) + "th power");
        compute(n1->number(),n2->number());
    }
    else
    {
        emit clear();
        setDefaultStatus();
    }
}

void PowerIdea::compute(double n1, double n2)
{
    emit startSpinningGear();

    setBase(n1);
    double output = std::pow(n1,n2);

    m_result = std::make_shared<NumberDataType>(output);

    setupDisplay();

    emit newData(0);
    emit stopSpinningGear();
}

double PowerIdea::base() const
{
    return m_base;
}

void PowerIdea::setBase(double base)
{
    if (qFuzzyCompare(m_base, base))
        return;

    m_base = base;
    emit baseChanged(m_base);
}

