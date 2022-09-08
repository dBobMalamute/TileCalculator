#ifndef TILEDIVISIONIDEA_H
#define TILEDIVISIONIDEA_H

#include "../Calculator/DivisionIdea.h"

struct TileDivisionAttributes : public IdeaAttributes
{
    TileDivisionAttributes();
};

class TileDivisionIdea : public DivisionIdea
{
    Q_OBJECT
public:
    TileDivisionIdea();
    const IdeaAttributes attributes() override;
};

#endif // DIVISIONIDEA_H
