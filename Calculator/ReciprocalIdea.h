#ifndef INVERSEIDEA_H
#define INVERSEIDEA_H

#include "IdeaTemplates/OneToOneIdeaTemplate.h"

struct ReciprocalAttributes : public IdeaAttributes
{
    ReciprocalAttributes();
};

class ReciprocalIdea : public OneToOneIdeaTemplate
{
    Q_OBJECT

public:
    explicit ReciprocalIdea();
    const IdeaAttributes attributes() override;

private:
    void validate() override;
    void compute(double n1);
};

#endif // INVERSEIDEA_H
