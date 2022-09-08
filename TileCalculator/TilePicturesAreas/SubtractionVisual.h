#ifndef SUBTRACTIONVISUALAREA_H
#define SUBTRACTIONVISUALAREA_H

#include <QQuickItem>
#include <QQmlEngine>
#include <QDebug>

class SubtractionVisualArea : public QQuickItem
{
    Q_OBJECT
public:
    SubtractionVisualArea();

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
    double m_n2;
    double m_fracUpWidth;

    QList<QQuickItem*> m_tiles;
    QQuickItem* m_fracLowTile = nullptr;
    QQuickItem* m_fracUpTile = nullptr;
    QQuickItem* m_fracAboveTile = nullptr;
};

#endif // SUBTRACTIONVISUALAREA_H
