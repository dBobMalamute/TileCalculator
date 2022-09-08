#ifndef TILELOGARITHMBASEEIDEA_H
#define TILELOGARITHMBASEEIDEA_H

#include "Calculator/ExponentialIdea.h"

struct TileLogarithmBaseEAttributes : public IdeaAttributes
{
    TileLogarithmBaseEAttributes();
};

class TileLogarithmBaseEIdea : public ExponentialIdea
{
    Q_OBJECT

public:
    explicit TileLogarithmBaseEIdea();
    const IdeaAttributes attributes() override;

    void resetDisplay() override;
};

#endif // NATURALLOGARITHMIDEA_H
