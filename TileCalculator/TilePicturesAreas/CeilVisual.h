#ifndef CEILVISUALAREA_H
#define CEILVISUALAREA_H

#include <QQuickItem>
#include <QQmlEngine>
#include <QDebug>

class CeilVisualArea : public QQuickItem
{
    Q_OBJECT
public:
    CeilVisualArea();

signals:

public slots:
    void setup(double n, int o, QColor inColor, QColor outColor);

    void clear();
    void reset();
    void action();

private:
    void prepareSizeVariables(int totalBoxes);
    int m_xBoxNum;
    double m_spacing;
    int m_borderWidth;

    double tSize();

    QList<QQuickItem*> m_wholeTiles;
    QQuickItem* m_finalTile = nullptr;
};

#endif // CEILVISUALAREA_H
