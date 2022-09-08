#ifndef TILEINPUTIDEA_H
#define TILEINPUTIDEA_H

#include "Calculator/NumberInputIdea.h"

struct TileInputAttributes : public IdeaAttributes
{
    TileInputAttributes();
};

class TileInputIdea: public NumberInputIdea
{
    Q_OBJECT

public:
    TileInputIdea();
    const IdeaAttributes attributes() override;
};

#endif //NUMBERINPUTIDEA_H





