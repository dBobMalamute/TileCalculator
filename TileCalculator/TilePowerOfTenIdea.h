#ifndef TILEPOWEROFTENIDEA_H
#define TILEPOWEROFTENIDEA_H

#include "Calculator/PowerOfTenIdea.h"

struct TilePowerOfTenAttributes : public IdeaAttributes
{
    TilePowerOfTenAttributes();
};

class TilePowerOfTenIdea : public PowerOfTenIdea
{
    Q_OBJECT

public:
    explicit TilePowerOfTenIdea();
    const IdeaAttributes attributes() override;

    void resetDisplay() override;
};

#endif // POWEROFTWOIDEA_H
