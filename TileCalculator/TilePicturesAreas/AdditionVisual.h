#ifndef ADDITIONVISUALAREA_H
#define ADDITIONVISUALAREA_H

#include <QQuickItem>
#include <QQmlEngine>
#include <QDebug>

class AdditionVisualArea : public QQuickItem
{
    Q_OBJECT
public:
    AdditionVisualArea();

signals:

public slots:
    void setup(double n1, double n2, QColor inColor, QColor inColor2, QColor outColor);

    void clear();
    void reset();
    void action();

private:
    void prepareSizeVariables(int wholeBoxes);
    int m_xBoxNum;
    double m_spacing;
    int m_borderWidth;

    QList<QQuickItem*> m_wholeTiles;
    QList<QQuickItem*> m_finalTiles;
};

#endif // ADDITIONVISUALAREA_H
