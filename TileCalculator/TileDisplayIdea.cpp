#include "TileDisplayIdea.h"

TileDisplayAttributes::TileDisplayAttributes()
{
    m_listName = "Tile Display";
    m_displayName = "";
    m_authors << "dBob";
    m_description = "Displays a single number";
    m_iconPath = "qrc:/Icons/NumberDisplay.png";

    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_labelsIn << "";
    m_customLabels = true;

    m_embeddedQMLPath = ":/QML/NumberDisplayMinimized.qml";
}

TileDisplayIdea::TileDisplayIdea()
{

}

const IdeaAttributes TileDisplayIdea::attributes()
{
    return Magic<TileDisplayAttributes>::cast();
}
