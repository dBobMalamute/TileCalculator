#ifndef TILEFLOORIDEA_H
#define TILEFLOORIDEA_H

#include "../Calculator/FloorIdea.h"

struct TileFloorAttributes : public IdeaAttributes
{
    TileFloorAttributes();
};

class TileFloorIdea : public FloorIdea
{
    Q_OBJECT

public:
    TileFloorIdea();
    const IdeaAttributes attributes() override;

    void resetDisplay() override;

};

#endif // FLOORIDEA_H
