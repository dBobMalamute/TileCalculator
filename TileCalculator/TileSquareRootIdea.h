#ifndef TILESQUAREROOTIDEA_H
#define TILESQUAREROOTIDEA_H

#include "Calculator/SquareRootIdea.h"

struct TileSquareRootAttributes : public IdeaAttributes
{
    TileSquareRootAttributes();
};

class TileSquareRootIdea : public SquareRootIdea
{
    Q_OBJECT

public:
    explicit TileSquareRootIdea();
    const IdeaAttributes attributes() override;
};

#endif // SQUAREROOTIDEA_H
