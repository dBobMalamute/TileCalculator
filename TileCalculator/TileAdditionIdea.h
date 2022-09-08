#ifndef TILEADDITIONIDEA_H
#define TILEADDITIONIDEA_H

#include "../Calculator/AdditionIdea.h"

struct TileAdditionAttributes : public IdeaAttributes
{
    TileAdditionAttributes();
};

class TileAdditionIdea : public AdditionIdea
{
    Q_OBJECT

public:
    TileAdditionIdea();
    const IdeaAttributes attributes() override;

    void resetDisplay() override;
};

#endif // ADDITIONIDEA_H
