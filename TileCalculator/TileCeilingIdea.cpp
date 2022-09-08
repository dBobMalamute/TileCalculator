#include "TileCeilingIdea.h"
#include <cmath>

TileCeilingAttributes::TileCeilingAttributes()
{
    m_listName = "Tile Ceiling";
    m_displayName = "Ceiling";
    m_authors << "dBob";
    m_description = "Calculates the whole number above the input number";
    m_iconPath = "qrc:/Icons/Ceiling.png";

    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesOut.push_back(Magic<NumberDataTypeAttributes>::cast().id());

    m_gear = true;

    m_embeddedQMLPath = ":/QML/TileCeilingIdea.qml";
    m_minimizedQMLPath = ":/QML/CeilingMinimized.qml";
    m_minimizable = true;
}

TileCeilingIdea::TileCeilingIdea()
{

}

const IdeaAttributes TileCeilingIdea::attributes()
{
    return Magic<TileCeilingAttributes>::cast();
}

void TileCeilingIdea::resetDisplay()
{
    if(valid())
    {
        double n = m_input.lock()->number();
        int answer = std::ceil(n);

        emit display(n, answer);
    }
}
