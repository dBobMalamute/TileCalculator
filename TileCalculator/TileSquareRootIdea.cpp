#include "TileSquareRootIdea.h"
#include <cmath>

TileSquareRootAttributes::TileSquareRootAttributes()
{
    m_listName = "Tile Square Root";
    m_displayName = "Square Root";
    m_authors << "dBob";
    m_description = "Calculates the square roots of a number. A square root of a number is the number "
                  "which when multiplied by itself produces the original number";

    m_iconPath = "qrc:/Icons/SquareRoot.png";

    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesOut.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesOut.push_back(Magic<NumberDataTypeAttributes>::cast().id());

    m_gear = true;

    m_embeddedQMLPath = ":/QML/TileSquareRootIdea.qml";
}

TileSquareRootIdea::TileSquareRootIdea()
{

}

const IdeaAttributes TileSquareRootIdea::attributes()
{
    return Magic<TileSquareRootAttributes>::cast();
}


//void TileSquareRootIdea::compute(double n1)
//{
//    double sqrt = std::sqrt(n1);
//    double negSqrt = sqrt * -1.0;
//    if(sqrt < 0.0)
//    {
//        emit displayNumbers(n1, negSqrt);
//        m_posResult = std::make_shared<NumberDataType>(negSqrt);
//        m_negResult = std::make_shared<NumberDataType>(sqrt);
//    }
//    else
//    {
//        emit displayNumbers(n1, sqrt);
//        m_posResult = std::make_shared<NumberDataType>(sqrt);
//        m_negResult = std::make_shared<NumberDataType>(negSqrt);
//    }
//}

