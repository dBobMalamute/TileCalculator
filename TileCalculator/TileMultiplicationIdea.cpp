#include "TileMultiplicationIdea.h"

TileMultiplicationAttributes::TileMultiplicationAttributes()
{
    m_listName = "Tile Multiplication";
    m_displayName = "Multiplication";
    m_authors << "dBob";
    m_description = "This idea represents multiplication of two decimal-type numbers.";
    m_iconPath = "qrc:/Icons/Multiplication.png";

    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesOut.push_back(Magic<NumberDataTypeAttributes>::cast().id());

    m_gear = true;

    m_embeddedQMLPath = ":/QML/TileMultiplicationIdea.qml";
    m_minimizedQMLPath = ":/QML/MultiplicationMinimized.qml";
    m_minimizable = true;
}

TileMultiplicationIdea::TileMultiplicationIdea()
{

}

const IdeaAttributes TileMultiplicationIdea::attributes()
{
    return Magic<TileMultiplicationAttributes>::cast();
}

void TileMultiplicationIdea::resetDisplay()
{
    if(valid())
    {
        setupDisplay();
    }
}
