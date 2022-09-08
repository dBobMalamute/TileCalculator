#ifndef LOGARITHMBASENIDEA_H
#define LOGARITHMBASENIDEA_H

#include "IdeaTemplates/OneToOneIdeaTemplate.h"

struct LogarithmBaseNAttributes : public IdeaAttributes
{
    LogarithmBaseNAttributes();
};

class LogarithmBaseNIdea : public OneToOneIdeaTemplate
{
    Q_OBJECT

    Q_PROPERTY(double n READ n WRITE setN NOTIFY nChanged)

public:
    explicit LogarithmBaseNIdea();
    const IdeaAttributes attributes() override;

    QJsonObject save() const override;
    void load(const QJsonObject &) override;

    double n() const;

public slots:
    void setN(double n);

signals:
    void nChanged(double n);

private:
    void validate() override;
    void compute(double n1);

protected:
    double m_n;
};

#endif // LOGARITHMBASENIDEA_H
