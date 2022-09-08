#include "TileFloorIdea.h"
#include <cmath>

TileFloorAttributes::TileFloorAttributes()
{
    m_listName = "Tile Floor";
    m_displayName = "Floor";
    m_authors << "dBob";
    m_description = "Calculates the whole number below this number";
    m_iconPath = "qrc:/Icons/Floor.png";

    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesOut.push_back(Magic<NumberDataTypeAttributes>::cast().id());

    m_gear = true;

    m_embeddedQMLPath = ":/QML/TileFloorIdea.qml";
    m_minimizedQMLPath = ":/QML/FloorMinimized.qml";
    m_minimizable = true;
}


TileFloorIdea::TileFloorIdea()
{

}

const IdeaAttributes TileFloorIdea::attributes()
{
    return Magic<TileFloorAttributes>::cast();
}

void TileFloorIdea::resetDisplay()
{
    if(valid())
    {
        double n = m_input.lock()->number();
        int answer = std::floor(n);

        emit display(n, answer);
    }
}
