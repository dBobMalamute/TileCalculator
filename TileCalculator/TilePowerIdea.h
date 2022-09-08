#ifndef TILEPOWERIDEA_H
#define TILEPOWERIDEA_H

#include "Calculator/PowerIdea.h"

struct TilePowerAttributes : public IdeaAttributes
{
    TilePowerAttributes();
};

class TilePowerIdea : public PowerIdea
{
    Q_OBJECT

public:
    TilePowerIdea();
    const IdeaAttributes attributes() override;

    void resetDisplay() override;
};

#endif // POWERIDEA_H
