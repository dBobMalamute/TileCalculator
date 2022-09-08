#ifndef ABSOLUTEVALUEIDEA_H
#define ABSOLUTEVALUEIDEA_H

#include "IdeaTemplates/OneToOneIdeaTemplate.h"

struct AbsoluteValueAttributes : public IdeaAttributes
{
    AbsoluteValueAttributes();
};

class AbsoluteValueIdea : public OneToOneIdeaTemplate
{
    Q_OBJECT

public:
    AbsoluteValueIdea();
    const IdeaAttributes attributes() override;

private:
    void validate() override;
    void compute(double n);
};

#endif // ABSOLUTEVALUEIDEA_H
