#include "TilePowerOfTenIdea.h"
#include <cmath>

TilePowerOfTenAttributes::TilePowerOfTenAttributes()
{
    m_listName = "Tile Power of 10";
    m_displayName = "Power of 10";
    m_authors << "dBob";
    m_description = "This idea calculates 10 to the inputted number.";
    m_iconPath = "qrc:/Icons/PowerOfTen.png";

    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesOut.push_back(Magic<NumberDataTypeAttributes>::cast().id());


    m_embeddedQMLPath = ":/QML/TilePowerOfTenIdea.qml";

    m_minimizedQMLPath = ":/QML/PowerOfTenMinimized.qml";
    m_minimizable = true;

    m_gear = true;
}

TilePowerOfTenIdea::TilePowerOfTenIdea()
{

}

const IdeaAttributes TilePowerOfTenIdea::attributes()
{
    return Magic<TilePowerOfTenAttributes>::cast();
}

void TilePowerOfTenIdea::resetDisplay()
{
    if(valid())
    {
        double n = m_input.lock()->number();
        double exp = std::pow(10.0, n);
        emit display(n, exp);
    }
}

