#ifndef LOGARITHMBASEEIDEA_H
#define LOGARITHMBASEEIDEA_H

#include "IdeaTemplates/OneToOneIdeaTemplate.h"

struct LogarithmBaseEAttributes : public IdeaAttributes
{
    LogarithmBaseEAttributes();
};

class LogarithmBaseEIdea : public OneToOneIdeaTemplate
{
    Q_OBJECT

public:
    explicit LogarithmBaseEIdea();
    const IdeaAttributes attributes() override;

private:
    void validate() override;
    void compute(double n1);
};

#endif // NATURALLOGARITHMIDEA_H
