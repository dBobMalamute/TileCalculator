#ifndef TILELOGARITHMBASENIDEA_H
#define TILELOGARITHMBASENIDEA_H

#include "Calculator/LogarithmBaseNIdea.h"

struct TileLogarithmBaseNAttributes : public IdeaAttributes
{
    TileLogarithmBaseNAttributes();
};

class TileLogarithmBaseNIdea : public LogarithmBaseNIdea
{
    Q_OBJECT

public:
    explicit TileLogarithmBaseNIdea();
    const IdeaAttributes attributes() override;

    void resetDisplay() override;;
};

#endif // LOGARITHMBASENIDEA_H
