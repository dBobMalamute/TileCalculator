#include "TileLogarithmBase10Idea.h"
#include <cmath>

TileLogarithmBase10Attributes::TileLogarithmBase10Attributes()
{
    m_listName = "Tile Logarithm Base 10";
    m_displayName = "Logarithm Base 10";
    m_authors << "dBob";
    m_description = "Calculates the logarithm base 10 of the inputted number";
    m_iconPath = "qrc:/Icons/LogarithmBase10.png";

    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesOut.push_back(Magic<NumberDataTypeAttributes>::cast().id());

    m_embeddedQMLPath = ":/QML/TileLogarithmBase10Idea.qml";
    m_minimizedQMLPath = ":/QML/LogarithmBase10Minimized.qml";
    m_minimizable = true;
    m_minimizedName = "Logarithm\nBase 10";
    m_differentNameOnMinimized = true;

    m_gear = true;
}

TileLogarithmBase10Idea::TileLogarithmBase10Idea()
{

}

const IdeaAttributes TileLogarithmBase10Idea::attributes()
{
    return Magic<TileLogarithmBase10Attributes>::cast();
}

void TileLogarithmBase10Idea::resetDisplay()
{
    if(valid())
    {
        double n = m_input.lock()->number();
        double log = std::log10(n);
        emit display(n, log);
    }
}

