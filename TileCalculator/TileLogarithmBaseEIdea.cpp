#include "TileLogarithmBaseEIdea.h"
#include <cmath>

TileLogarithmBaseEAttributes::TileLogarithmBaseEAttributes()
{
    m_listName = "Tile Natural Logarithm";
    m_displayName = "Natural Logarithm";
    m_authors << "dBob";
    m_description = "Calculates the logarithm base e of the inputted number. This is frequently called the natural logarithm (ln).";
    m_iconPath = "qrc:/Icons/LogarithmBaseE.png";

    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesOut.push_back(Magic<NumberDataTypeAttributes>::cast().id());

    m_embeddedQMLPath = ":/QML/TileLogarithmBaseEIdea.qml";
    m_minimizedQMLPath = ":/QML/LogarithmBaseEMinimized.qml";
    m_minimizable = true;
    m_minimizedName = "Natural\nLogarithm";
    m_differentNameOnMinimized = true;

    m_gear = true;
}

TileLogarithmBaseEIdea::TileLogarithmBaseEIdea()
{

}

const IdeaAttributes TileLogarithmBaseEIdea::attributes()
{
    return Magic<TileLogarithmBaseEAttributes>::cast();
}


void TileLogarithmBaseEIdea::resetDisplay()
{
    if(valid())
    {
        double n = m_input.lock()->number();
        double log = std::log(n);
        emit display(n, log);
    }
}

