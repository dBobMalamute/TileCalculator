#ifndef TILESQUAREDIDEA_H
#define TILESQUAREDIDEA_H

#include "../Calculator/SquaredIdea.h"

struct TileSquaredAttributes : public IdeaAttributes
{
    TileSquaredAttributes();
};

class TileSquaredIdea : public SquaredIdea
{
    Q_OBJECT

public:
    explicit TileSquaredIdea();
    const IdeaAttributes attributes() override;

    void resetDisplay() override;
};

#endif // SQUAREDIDEA_H
