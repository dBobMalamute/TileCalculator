#include "FloorVisual.h"
#include <cmath>

FloorVisualArea::FloorVisualArea()
{
    setFlag(ItemHasContents);
    setWidth(400);
    setHeight(200);
}

void FloorVisualArea::setup(double n, int o, QColor inColor, QColor outColor)
{
    clear();
    prepareSizeVariables(o + 1);

    double totalDelay = std::max(0.0,500*std::log2(o));

    m_wholeTiles.reserve(o);
    for(int i = 0; i < o; i++)
    {
        QQmlComponent comp(qmlEngine(this), QUrl(QStringLiteral("qrc:/QML/TileRectangles/FloorCeilRectangle.qml")));

        QVariantMap map;
        map["width"] = tSize();
        map["height"] = tSize();
        map["x"] = 0.5 + m_spacing * (i % m_xBoxNum);
        map["y"] = 0.5 + m_spacing * std::floor(i/m_xBoxNum);
        map["iColor"] = inColor;
        map["fColor"] = outColor;
        map["delay"] = 1.0*i / o * totalDelay;
        map["border.width"] = m_borderWidth;
        QObject* obj = comp.createWithInitialProperties(map, qmlEngine(this)->rootContext());

        QQuickItem* visibleObj = static_cast<QQuickItem*>(obj);
        m_wholeTiles.append(visibleObj);

        visibleObj->setParent(this);
        visibleObj->setParentItem(this);
    }
    if(!qFuzzyIsNull(n - o))
    {
        QQmlComponent comp(qmlEngine(this), QUrl(QStringLiteral("qrc:/QML/TileRectangles/FloorFinalRectangle.qml")));

        QVariantMap map;
        map["width"] = (n - o) * (tSize());
        map["initialWidth"] = (n - o) * (tSize());
        map["height"] = tSize();
        map["x"] = 0.5 + m_spacing * (o % m_xBoxNum);
        map["y"] = 0.5 + m_spacing * std::floor(o/m_xBoxNum);
        map["iColor"] = inColor;
        map["fColor"] = outColor;
        map["delay"] = totalDelay;
        map["border.width"] = m_borderWidth;

        QObject* obj = comp.createWithInitialProperties(map, qmlEngine(this)->rootContext());

        QQuickItem* visibleObj = static_cast<QQuickItem*>(obj);
        m_finalTile = visibleObj;
        visibleObj->setParent(this);
        visibleObj->setParentItem(this);
    }

    reset();
}

void FloorVisualArea::clear()
{   
    for(int i = 0; i < m_wholeTiles.length(); i++)
        m_wholeTiles[i]->deleteLater();

    m_wholeTiles.clear();
    if(m_finalTile)
    {
        m_finalTile->deleteLater();
        m_finalTile = nullptr;
    }
}

void FloorVisualArea::reset()
{
    for(int i = 0; i < m_wholeTiles.length(); i++)
    {
        QMetaObject::invokeMethod(m_wholeTiles[i], "startResetAnimation");
    }
    if(m_finalTile)
        QMetaObject::invokeMethod(m_finalTile, "startResetAnimation");
}

void FloorVisualArea::floor()
{
    for(int i = 0; i < m_wholeTiles.length(); i++)
    {
        QMetaObject::invokeMethod(m_wholeTiles[i], "startActionAnimation");
    }
    if(m_finalTile)
        QMetaObject::invokeMethod(m_finalTile, "startActionAnimation");
}

void FloorVisualArea::prepareSizeVariables(int totalBoxes)
{
    if(totalBoxes <= 10)
    {
        m_borderWidth = 8;
        m_spacing = 80;
        m_xBoxNum = 5;
    }
    else if(totalBoxes <= 50)
    {
        m_borderWidth = 4;
        m_spacing = 40;
        m_xBoxNum = 10;
    }
    else if(totalBoxes <= 200)
    {
        m_borderWidth = 2;
        m_spacing = 20;
        m_xBoxNum = 20;
    }
    else if(totalBoxes <= 800)
    {
        m_borderWidth = 1;
        m_spacing = 10;
        m_xBoxNum = 40;
    }
    else if(totalBoxes <= 5000)
    {
        m_borderWidth = 0;
        m_spacing = 4;
        m_xBoxNum = 100;
    }
    else if(totalBoxes <= 20000)
    {
        m_borderWidth = 0;
        m_spacing = 2;
        m_xBoxNum = 200;
    }
}

double FloorVisualArea::tSize()
{
    return m_spacing - 1.0;
}
