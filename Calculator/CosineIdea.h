#ifndef COSINEIDEA_H
#define COSINEIDEA_H

#include "IdeaTemplates/TrigIdeaTemplate.h"

struct CosineAttributes : public IdeaAttributes
{
    CosineAttributes();
};

class CosineIdea : public TrigIdeaTemplate
{
    Q_OBJECT

public:
    CosineIdea();
    const IdeaAttributes attributes() override;

private:
    void validate() override;
    void compute(double n);
};

#endif // COSINEIDEA_H
