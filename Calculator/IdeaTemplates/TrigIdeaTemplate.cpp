#include "TrigIdeaTemplate.h"

TrigIdeaTemplate::TrigIdeaTemplate() :
    m_degreeMode(true)
{

}

QJsonObject TrigIdeaTemplate::save() const
{
    QJsonObject saveJson = Idea::save();
    saveJson["d"] = m_degreeMode;

    return saveJson;
}

void TrigIdeaTemplate::load(const QJsonObject &p)
{
    Idea::load(p);

    QJsonValue v = p["d"];
    if(!v.isUndefined())
    {
        m_degreeMode = v.toBool();
        emit degreeModeChanged(m_degreeMode);

        validate();
    }
}

void TrigIdeaTemplate::onNewDataIn(std::shared_ptr<DataType> dataType, PlugNumber)
{
    auto number = std::dynamic_pointer_cast<NumberDataType>(dataType);
    m_input = number;

    validate();
}

std::shared_ptr<DataType> TrigIdeaTemplate::dataOut(PlugNumber)
{
    return std::static_pointer_cast<DataType>(m_result);
}

bool TrigIdeaTemplate::degreeMode() const
{
    return m_degreeMode;
}

void TrigIdeaTemplate::setDegreeMode(bool degreeMode)
{
    if (m_degreeMode == degreeMode)
        return;

    QJsonObject oldParams = save();

    m_degreeMode = degreeMode;
    emit degreeModeChanged(m_degreeMode);

    QJsonObject newParams = save();
    emit reportParamsChanged(oldParams,newParams);

    validate();
}

void TrigIdeaTemplate::setupDisplay()
{
    emit display(m_input.lock()->number(),
                 m_result->number());
}

void TrigIdeaTemplate::updateOnOutPortLabelColor()
{
    if(valid())
        setupDisplay();
}

void TrigIdeaTemplate::updateOnInPortLabelColor()
{
    if(valid())
        setupDisplay();
}
