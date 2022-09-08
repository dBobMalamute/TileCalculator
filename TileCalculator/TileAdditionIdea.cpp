#include "TileAdditionIdea.h"

TileAdditionAttributes::TileAdditionAttributes()
{
    m_listName = "Tile Addition";
    m_displayName = "Addition";
    m_authors << "dBob";
    m_description = "Addition of two decimal-type numbers";
    m_iconPath = "qrc:/Icons/Addition.png";

    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesOut.push_back(Magic<NumberDataTypeAttributes>::cast().id());

    m_gear = true;

    m_embeddedQMLPath = ":/QML/TileAdditionIdea.qml";
    m_minimizedQMLPath = ":/QML/AdditionMinimized.qml";
    m_minimizable = true;
}

TileAdditionIdea::TileAdditionIdea()
{

}

const IdeaAttributes TileAdditionIdea::attributes()
{
    return Magic<TileAdditionAttributes>::cast();
}


void TileAdditionIdea::resetDisplay()
{
    if(valid())
    {
        setupDisplay();
    }
}
