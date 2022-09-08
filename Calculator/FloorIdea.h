#ifndef FLOORIDEA_H
#define FLOORIDEA_H

#include "IdeaTemplates/OneToOneIdeaTemplate.h"

struct FloorAttributes : public IdeaAttributes
{
    FloorAttributes();
};

class FloorIdea : public OneToOneIdeaTemplate
{
    Q_OBJECT

public:
    FloorIdea();
    const IdeaAttributes attributes() override;

private:
    void validate() override;
    void compute(double n);
};

#endif // FLOORIDEA_H
