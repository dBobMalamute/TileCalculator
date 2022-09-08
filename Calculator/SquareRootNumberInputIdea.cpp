#include "SquareRootNumberInputIdea.h"

#include <cmath>

SquareRootNumberInputAttributes::SquareRootNumberInputAttributes()
{
    m_listName = "Square Root Number Input";
    m_displayName = "";
    m_authors << "dBob";
    m_description = "This idea allows the user to enter a number. When selected, press enter to update the number"
                  " and propogate the change to other ideas.";
    m_iconPath = "qrc:/Icons/SquareRootNumberInput.png";

    m_dataTypesOut.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_labelsOut << "";
    m_customLabels = true;

    m_embeddedQMLPath = ":/QML/SquareRootNumberInputIdea.qml";
}

SquareRootNumberInputIdea::SquareRootNumberInputIdea() :
    m_number(2.0)
{
    setStatus(IdeaStatus::Working, "Sourcing", "");
}

const IdeaAttributes SquareRootNumberInputIdea::attributes()
{
    return Magic<SquareRootNumberInputAttributes>::cast();
}

QJsonObject SquareRootNumberInputIdea::save() const
{
    QJsonObject ideaJson;
    ideaJson["n"] = m_number;
    return ideaJson;
}

void SquareRootNumberInputIdea::load(QJsonObject const &p)
{
    QJsonValue v = p["n"];

    if (!v.isUndefined())
    {
        m_number = v.toDouble();
        emit numberChanged(m_number);

        compute();
    }
}

std::shared_ptr<DataType> SquareRootNumberInputIdea::dataOut(PlugNumber)
{
    return m_numberOutput;
}

double SquareRootNumberInputIdea::number() const
{
    return m_number;
}

void SquareRootNumberInputIdea::setNumber(double number)
{
    if(!qFuzzyCompare(m_number, number))
    {
        QJsonObject oldParams = this->save();

        m_number = number;
        emit numberChanged(m_number);

        QJsonObject newParams = this->save();
        emit reportParamsChanged(oldParams,newParams);

        validate();
    }
}

void SquareRootNumberInputIdea::validate()
{
    if(m_number < 0.0)
    {
        setStatus(IdeaStatus::Error, "Imaginary", "The square root of a negative number is an imaginary number");
    }
    else
    {
        setStatus(IdeaStatus::Working, "Sourcing", "");
        compute();
    }
}

void SquareRootNumberInputIdea::compute()
{
    m_numberOutput = std::make_shared<NumberDataType>(sqrt(m_number));
    emit newData(0);
}
