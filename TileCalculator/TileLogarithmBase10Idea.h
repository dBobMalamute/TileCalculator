#ifndef TILELOGARITHMBASE10IDEA_H
#define TILELOGARITHMBASE10IDEA_H

#include "Calculator/LogarithmBase10Idea.h"

struct TileLogarithmBase10Attributes : public IdeaAttributes
{
    TileLogarithmBase10Attributes();
};

class TileLogarithmBase10Idea : public LogarithmBase10Idea
{
    Q_OBJECT
public:
    explicit TileLogarithmBase10Idea();
    const IdeaAttributes attributes() override;

    void resetDisplay() override;
};

#endif // LOGARITHMBASE10IDEA_H
