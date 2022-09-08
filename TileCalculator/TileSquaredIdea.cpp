#include "TileSquaredIdea.h"

TileSquaredAttributes::TileSquaredAttributes()
{
    m_listName = "Tile Square";
    m_displayName = "Square";
    m_authors << "dBob";
    m_description = "Calcuates the square of a number. The number multiplied by itself.";
    m_iconPath = "qrc:/Icons/Squared.png";

    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesOut.push_back(Magic<NumberDataTypeAttributes>::cast().id());

    m_gear = true;

    m_embeddedQMLPath = ":/QML/TileSquaredIdea.qml";
    m_minimizedQMLPath = ":/QML/SquaredMinimized.qml";
    m_minimizable = true;
}

TileSquaredIdea::TileSquaredIdea()
{

}

const IdeaAttributes TileSquaredIdea::attributes()
{
    return Magic<TileSquaredAttributes>::cast();
}

void TileSquaredIdea::resetDisplay()
{
    if(valid())
    {
        double n1 = m_input.lock()->number();
        double sqr = n1*n1;
        emit display(n1, sqr);
    }
}

