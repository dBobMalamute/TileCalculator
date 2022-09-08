#ifndef INVERSESINEIDEA_H
#define INVERSESINEIDEA_H

#include "IdeaTemplates/InverseTrigIdeaTemplate.h"

struct InverseSineAttributes : public IdeaAttributes
{
    InverseSineAttributes();
};

class InverseSineIdea : public InverseTrigIdeaTemplate
{
    Q_OBJECT

public:
    InverseSineIdea();
    const IdeaAttributes attributes() override;

private:
    void validate() override;
    void compute(double n);
};

#endif // INVERSESINEIDEA_H
