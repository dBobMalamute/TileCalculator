#ifndef POWEROFTENIDEA_H
#define POWEROFTENIDEA_H

#include "IdeaTemplates/OneToOneIdeaTemplate.h"

struct PowerOfTenAttributes : public IdeaAttributes
{
    PowerOfTenAttributes();
};

class PowerOfTenIdea : public OneToOneIdeaTemplate
{
    Q_OBJECT

public:
    explicit PowerOfTenIdea();
    const IdeaAttributes attributes() override;

private:
    void validate() override;
    void compute(double n1);
};

#endif // POWEROFTWOIDEA_H
