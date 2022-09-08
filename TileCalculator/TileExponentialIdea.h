#ifndef TILEEXPONENTIALIDEA_H
#define TILEEXPONENTIALIDEA_H

#include "Calculator/ExponentialIdea.h"

struct TileExponentialAttributes : public IdeaAttributes
{
    TileExponentialAttributes();
};

class TileExponentialIdea : public ExponentialIdea
{
    Q_OBJECT

public:
    explicit TileExponentialIdea();
    const IdeaAttributes attributes() override;

    void resetDisplay() override;
};

#endif // TILEEXPONENTIALIDEA_H
