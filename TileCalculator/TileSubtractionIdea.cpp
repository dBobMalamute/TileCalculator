#include "TileSubtractionIdea.h"

TileSubtractionAttributes::TileSubtractionAttributes()
{
    m_listName = "Tile Subtraction";
    m_displayName = "Subtraction";
    m_authors << "dBob";
    m_description = "This idea represents subtraction of one decimal type number from another.";
    m_iconPath = "qrc:/Icons/Subtraction.png";

    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesOut.push_back(Magic<NumberDataTypeAttributes>::cast().id());

    m_gear = true;

    m_embeddedQMLPath = ":/QML/TileSubtractionIdea.qml";
    m_minimizedQMLPath = ":/QML/SubtractionMinimized.qml";
    m_minimizable = true;
}

TileSubtractionIdea::TileSubtractionIdea()
{

}

const IdeaAttributes TileSubtractionIdea::attributes()
{
    return Magic<TileSubtractionAttributes>::cast();
}

void TileSubtractionIdea::resetDisplay()
{
    if(valid())
    {
        double n1 = m_input1.lock()->number();
        double n2 = m_input2.lock()->number();
        emit display(n1, n2, n1-n2);
    }
}
