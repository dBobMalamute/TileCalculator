#ifndef INVERSETANGENTIDEA_H
#define INVERSETANGENTIDEA_H

#include "IdeaTemplates/InverseTrigIdeaTemplate.h"

struct InverseTangentAttributes : public IdeaAttributes
{
    InverseTangentAttributes();
};

class InverseTangentIdea : public InverseTrigIdeaTemplate
{
    Q_OBJECT

public:
    InverseTangentIdea();
    const IdeaAttributes attributes() override;

private:
    void validate() override;
    void compute(double n);
};

#endif // INVERSETANGENTIDEA_H
