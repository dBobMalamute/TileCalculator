#include "TileLogarithmBaseNIdea.h"
#include <cmath>

TileLogarithmBaseNAttributes::TileLogarithmBaseNAttributes()
{
    m_listName = "Tile Logarithm Base N";
    m_displayName = "Logarithm Base N";
    m_authors << "dBob";
    m_description = "Calculates the logarithm base 2 of the inputted number";
    m_iconPath = "qrc:/Icons/LogarithmBaseN.png";

    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesOut.push_back(Magic<NumberDataTypeAttributes>::cast().id());

    m_embeddedQMLPath = ":/QML/TileLogarithmBaseNIdea.qml";
    m_minimizedQMLPath = ":/QML/LogarithmBaseNMinimized.qml";
    m_minimizable = true;
    m_minimizedName = "Logarithm\nBase N";
    m_differentNameOnMinimized = true;

    m_externalQMLPaths << ":/QML/LogarithmBaseNControls.qml";
    m_externalQMLLocations.push_back({true, false, 10,0});

    m_gear = true;
}


TileLogarithmBaseNIdea::TileLogarithmBaseNIdea()
{

}

const IdeaAttributes TileLogarithmBaseNIdea::attributes()
{
    return Magic<TileLogarithmBaseNAttributes>::cast();
}

void TileLogarithmBaseNIdea::resetDisplay()
{
    if(valid())
    {
        double n = m_input.lock()->number();
        double log = std::log(n) / std::log(m_n);
        emit display(n, log);
    }
}




