#include "TileExponentialIdea.h"
#include <cmath>

TileExponentialAttributes::TileExponentialAttributes()
{
    m_listName = "Tile Exponential";
    m_displayName = "Exponential";
    m_authors << "dBob";
    m_description = "This idea calculates e (2.721828) to the inputted number.";
    m_iconPath = "qrc:/Icons/Exponential.png";

    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesOut.push_back(Magic<NumberDataTypeAttributes>::cast().id());

    m_gear = true;

    m_embeddedQMLPath = ":/QML/TileExponentialIdea.qml";

    m_minimizedQMLPath = ":/QML/ExponentialMinimized.qml";
    m_minimizable = true;
}

TileExponentialIdea::TileExponentialIdea()
{

}

const IdeaAttributes TileExponentialIdea::attributes()
{
    return Magic<TileExponentialAttributes>::cast();
}

void TileExponentialIdea::resetDisplay()
{
    if(valid())
    {
        double n = m_input.lock()->number();
        double exp = std::exp(n);
        emit display(n, exp);
    }
}
