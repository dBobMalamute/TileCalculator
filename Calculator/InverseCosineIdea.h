#ifndef INVERSECOSINEIDEA_H
#define INVERSECOSINEIDEA_H

#include "IdeaTemplates/InverseTrigIdeaTemplate.h"

struct InverseCosineAttributes : public IdeaAttributes
{
    InverseCosineAttributes();
};

class InverseCosineIdea : public InverseTrigIdeaTemplate
{
    Q_OBJECT

public:
    InverseCosineIdea();
    const IdeaAttributes attributes() override;

private:
    void validate() override;
    void compute(double n);
};

#endif // INVERSECOSINEIDEA_H
