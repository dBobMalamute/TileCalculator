#ifndef SINEIDEA_H
#define SINEIDEA_H

#include "IdeaTemplates/TrigIdeaTemplate.h"

struct SineAttributes : public IdeaAttributes
{
    SineAttributes();
};

class SineIdea : public TrigIdeaTemplate
{
    Q_OBJECT

public:
    SineIdea();
    const IdeaAttributes attributes() override;

private:
    void validate() override;
    void compute(double n);
};

#endif // SINEIDEA_H
