#ifndef TANGENTIDEA_H
#define TANGENTIDEA_H

#include "IdeaTemplates/TrigIdeaTemplate.h"

struct TangentAttributes : public IdeaAttributes
{
    TangentAttributes();
};

class TangentIdea : public TrigIdeaTemplate
{
    Q_OBJECT

public:
    TangentIdea();
    const IdeaAttributes attributes() override;

private:
    void validate() override;
    void compute(double n);
};

#endif // TANGENTIDEA_H
