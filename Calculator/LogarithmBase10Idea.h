#ifndef LOGARITHMBASE10IDEA_H
#define LOGARITHMBASE10IDEA_H

#include "IdeaTemplates/OneToOneIdeaTemplate.h"

struct LogarithmBase10Attributes : public IdeaAttributes
{
    LogarithmBase10Attributes();
};

class LogarithmBase10Idea : public OneToOneIdeaTemplate
{
    Q_OBJECT
public:
    explicit LogarithmBase10Idea();
    const IdeaAttributes attributes() override;

private:
    void validate() override;
    void compute(double n);
};

#endif // LOGARITHMBASE10IDEA_H
