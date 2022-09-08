#include "AbsoluteValueIdea.h"

AbsoluteValueAttributes::AbsoluteValueAttributes()
{
    m_listName = "Absolute Value";
    m_displayName = "Absolute\nValue";
    m_authors << "dBob";
    m_description = "If a number is positive, returns the number. If the number is negative, return -1 times the number";
    m_iconPath = "qrc:/Icons/AbsoluteValue.png";

    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesOut.push_back(Magic<NumberDataTypeAttributes>::cast().id());

    m_gear = true;

    m_embeddedQMLPath = ":/QML/AbsoluteValueIdea.qml";
}

AbsoluteValueIdea::AbsoluteValueIdea()
{

}

const IdeaAttributes AbsoluteValueIdea::attributes()
{
    return Magic<AbsoluteValueAttributes>::cast();
}

void AbsoluteValueIdea::validate()
{
    auto n = m_input.lock();

    if(n)
    {
        setStatus(IdeaStatus::Working,"Calculating","Currently calculating the absolute value of " + QString::number(n->number()));
        compute(n->number());
    }
    else
    {
        setDefaultStatus();
        emit clear();
    }
}

void AbsoluteValueIdea::compute(double n)
{
    emit startSpinningGear();

    double abs;
    if(n > 0.0)
        abs = n;
    else
        abs = -1.0*n;

    m_result = std::make_shared<NumberDataType>(abs);

    setupDisplay();

    emit newData(0);
    emit stopSpinningGear();
}

