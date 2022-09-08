#ifndef TILESUBTRACTIONIDEA_H
#define TILESUBTRACTIONIDEA_H

#include "../Calculator/SubtractionIdea.h"

struct TileSubtractionAttributes : public IdeaAttributes
{
    TileSubtractionAttributes();
};

class TileSubtractionIdea : public SubtractionIdea
{
    Q_OBJECT

public:
    TileSubtractionIdea();
    const IdeaAttributes attributes() override;

    void resetDisplay() override;
};

#endif // ADDITIONIDEA_H
