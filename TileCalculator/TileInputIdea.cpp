#include "TileInputIdea.h"

#include <QJsonValue>

TileInputAttributes::TileInputAttributes()
{
    m_listName = "Tile Input";
    m_displayName = "";
    m_authors << "dBob";
    m_description = "This idea allows the user to enter a number. When selected, press enter to update the number"
                  " and propogate the change to other ideas.";
    m_iconPath = "qrc:/Icons/NumberInput.png";

    m_dataTypesOut.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_labelsOut << "";
    m_customLabels = true;

    m_embeddedQMLPath = ":/QML/NumberInputMinimized.qml";
}

TileInputIdea::TileInputIdea()
{

}

const IdeaAttributes TileInputIdea::attributes()
{
    return Magic<TileInputAttributes>::cast();
}
