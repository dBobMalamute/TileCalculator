#ifndef TILECEILINGIDEA_H
#define TILECEILINGIDEA_H

#include "../Calculator/CeilingIdea.h"

struct TileCeilingAttributes : public IdeaAttributes
{
    TileCeilingAttributes();
};

class TileCeilingIdea : public CeilingIdea
{
    Q_OBJECT

public:
    TileCeilingIdea();
    const IdeaAttributes attributes() override;

    void resetDisplay() override;
};

#endif // CEILINGIDEA_H
