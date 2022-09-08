#include "TileOneToOneIdeaTemplate.h"

TileOneToOneIdeaTemplate::TileOneToOneIdeaTemplate()
{

}

void TileOneToOneIdeaTemplate::onNewDataIn(std::shared_ptr<DataType> dataType, PlugNumber)
{
    auto number = std::dynamic_pointer_cast<NumberDataType>(dataType);
    m_input = number;

    validate();
}

std::shared_ptr<DataType> TileOneToOneIdeaTemplate::dataOut(PlugNumber)
{
    return std::static_pointer_cast<DataType>(m_result);
}



