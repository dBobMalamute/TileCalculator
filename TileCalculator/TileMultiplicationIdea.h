#ifndef TILEMULTIPLICATIONIDEA_H
#define TILEMULTIPLICATIONIDEA_H

#include "Calculator/MultiplicationIdea.h"

struct TileMultiplicationAttributes : public IdeaAttributes
{
    TileMultiplicationAttributes();
};

class TileMultiplicationIdea : public MultiplicationIdea
{
    Q_OBJECT

public:
    TileMultiplicationIdea();
    const IdeaAttributes attributes() override;

    void resetDisplay() override;
};

#endif // MULTIPLICATIONIDEA_H
