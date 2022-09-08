#ifndef EXPONENTIALIDEA_H
#define EXPONENTIALIDEA_H

#include "IdeaTemplates/OneToOneIdeaTemplate.h"

struct ExponentialAttributes : public IdeaAttributes
{
    ExponentialAttributes();
};

class ExponentialIdea : public OneToOneIdeaTemplate
{
    Q_OBJECT

public:
    explicit ExponentialIdea();
    const IdeaAttributes attributes() override;

private:
    void validate() override;
    void compute(double n1);
};

#endif // EXPONENTIALIDEA_H
