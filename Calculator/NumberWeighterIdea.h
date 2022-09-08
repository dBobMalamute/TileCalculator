#ifndef NUMBERWEIGHTERIDEA_H
#define NUMBERWEIGHTERIDEA_H

#include "IdeaTemplates/TwoToOneIdeaTemplate.h"

struct NumberWeighterAttributes : public IdeaAttributes
{
    NumberWeighterAttributes();
};

class NumberWeighterIdea : public TwoToOneIdeaTemplate
{
    Q_OBJECT

    Q_PROPERTY(double weight READ weight WRITE setWeight NOTIFY weightChanged)

public:
    NumberWeighterIdea();
    const IdeaAttributes attributes() override;

    QJsonObject save() const override;
    void load(const QJsonObject &) override;

    double weight() const;

public slots:
    void setWeight(double weight);
    QString topWeightString() const;
    QString botWeightString() const;

signals:
    void weightChanged();

private:
    void validate() override;
    void compute(double weight, double n1, double n2);

    double m_weight;
};

#endif // NUMBERWEIGHTERIDEA_H
