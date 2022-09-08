#include "TilePowerIdea.h"
#include <cmath>

TilePowerAttributes::TilePowerAttributes()
{
    m_listName = "Tile Power";
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

    m_embeddedQMLPath = ":/QML/TilePowerIdea.qml";
    m_minimizedQMLPath = ":/QML/PowerMinimized.qml";
    m_minimizable = true;

    m_gear = true;
}


TilePowerIdea::TilePowerIdea()
{

}

const IdeaAttributes TilePowerIdea::attributes()
{
    return Magic<TilePowerAttributes>::cast();
}

void TilePowerIdea::resetDisplay()
{
    if(valid())
    {
        double base = m_input1.lock()->number();
        double pow = m_input2.lock()->number();
        double output = std::pow(base,pow);
        emit display(base, pow, output);
    }
}


