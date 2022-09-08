#ifndef CEILINGIDEA_H
#define CEILINGIDEA_H

#include "IdeaTemplates/OneToOneIdeaTemplate.h"

struct CeilingAttributes : public IdeaAttributes
{
    CeilingAttributes();
};

class CeilingIdea : public OneToOneIdeaTemplate
{
    Q_OBJECT

public:
    CeilingIdea();
    const IdeaAttributes attributes() override;

private:
    void validate() override;
    void compute(double n);
};

#endif // CEILINGIDEA_H
