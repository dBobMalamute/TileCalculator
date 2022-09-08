#ifndef TILEDISPLAYIDEA_H
#define TILEDISPLAYIDEA_H

#include "Calculator/NumberDisplayIdea.h"

struct TileDisplayAttributes : public IdeaAttributes
{
    TileDisplayAttributes();
};

class TileDisplayIdea : public NumberDisplayIdea
{
    Q_OBJECT

public:
    TileDisplayIdea();
    const IdeaAttributes attributes() override;
};

#endif
