#include "InverseTrigIdeaTemplate.h"

InverseTrigIdeaTemplate::InverseTrigIdeaTemplate() :
    m_degreeMode(true),
    m_nAnswer(0)
{

}

QJsonObject InverseTrigIdeaTemplate::save() const
{
    QJsonObject saveJson = Idea::save();
    saveJson["d"] = m_degreeMode;
    saveJson["n"] = m_nAnswer;
    return saveJson;
}

void InverseTrigIdeaTemplate::load(const QJsonObject &p)
{
    Idea::load(p);

    QJsonValue v = p["d"];
    if(!v.isUndefined())
    {
        m_degreeMode = v.toBool();
        emit degreeModeChanged(m_degreeMode);
    }
    v = p["n"];
    if(!v.isUndefined())
    {
        m_nAnswer = v.toInt();
        emit nAnswerChanged(m_nAnswer);
    }

    validate();
}

void InverseTrigIdeaTemplate::onNewDataIn(std::shared_ptr<DataType> dataType, PlugNumber)
{
    auto number = std::dynamic_pointer_cast<NumberDataType>(dataType);
    m_input = number;

    validate();
}

std::shared_ptr<DataType> InverseTrigIdeaTemplate::dataOut(PlugNumber)
{
    return std::static_pointer_cast<DataType>(m_result);
}

bool InverseTrigIdeaTemplate::degreeMode() const
{
    return m_degreeMode;
}

int InverseTrigIdeaTemplate::nAnswer() const
{
    return m_nAnswer;
}

void InverseTrigIdeaTemplate::setDegreeMode(bool degreeMode)
{
    if (m_degreeMode == degreeMode)
        return;

    QJsonObject oldParams;
    oldParams["d"] = m_degreeMode;

    m_degreeMode = degreeMode;
    emit degreeModeChanged(m_degreeMode);

    QJsonObject newParams;
    newParams["d"] = m_degreeMode;
    emit reportParamsChanged(oldParams,newParams);

    validate();
}

void InverseTrigIdeaTemplate::setNAnswer(int nAnswer)
{
    if (m_nAnswer == nAnswer)
        return;

    QJsonObject oldParams;
    oldParams["n"] = nAnswer;

    m_nAnswer = nAnswer;
    emit nAnswerChanged(m_nAnswer);

    QJsonObject newParams;
    newParams["n"] = nAnswer;
    emit reportParamsChanged(oldParams,newParams);

    validate();
}

void InverseTrigIdeaTemplate::setupDisplay()
{
    emit display(m_input.lock()->number(),
                 m_result->number());
}

void InverseTrigIdeaTemplate::updateOnOutPortLabelColor()
{
    if(valid())
        setupDisplay();
}

void InverseTrigIdeaTemplate::updateOnInPortLabelColor()
{
    if(valid())
        setupDisplay();
}
