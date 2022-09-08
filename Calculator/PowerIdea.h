#ifndef POWERIDEA_H
#define POWERIDEA_H

#include "IdeaTemplates/TwoToOneIdeaTemplate.h"

struct PowerAttributes : public IdeaAttributes
{
    PowerAttributes();
};

class PowerIdea : public TwoToOneIdeaTemplate
{
    Q_OBJECT

    Q_PROPERTY(double base READ base WRITE setBase NOTIFY baseChanged)

public:
    PowerIdea();
    const IdeaAttributes attributes() override;

    double base() const;

public slots:
    void setBase(double base);

signals:
    void baseChanged(double base);

private:
    void validate() override;
    void compute(double n1, double n2);
    double m_base;
};

#endif // POWERIDEA_H
