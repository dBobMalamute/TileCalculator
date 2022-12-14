#ifndef COLOREDSQUAREIDEA_H
#define COLOREDSQUAREIDEA_H

#include "../MalamuteCore/InheritedClasses/Idea.h"
#include <QQuickItem>

struct ColoredSquareAttributes : public IdeaAttributes
{
    ColoredSquareAttributes();
};

class ColoredSquareIdea : public Idea
{
    Q_OBJECT

public:
    explicit ColoredSquareIdea();
    const IdeaAttributes attributes() override;

    QJsonObject save() const override;
    void load(const QJsonObject &) override;

public slots:
    void getQCustomObject(QQuickItem* item);

signals:

private:

};

#endif // COLOREDSQUAREIDEA_H
