#include "AdditionVisual.h"
#include <cmath>

AdditionVisualArea::AdditionVisualArea()
{
    setFlag(ItemHasContents);
    setWidth(400);
    setHeight(200);
}

void AdditionVisualArea::setup(double n1, double n2, QColor inColor1, QColor inColor2, QColor outColor)
{
    clear();
    int totalBoxes = std::ceil(n1) + std::ceil(n2);
    prepareSizeVariables(totalBoxes);

    double totalDelay = std::max(0.0,500*std::log2(totalBoxes));

    m_wholeTiles.reserve(totalBoxes - 2);
    for(int i = 0; i < std::floor(n1); i++)
    {
        QQmlComponent comp(qmlEngine(this), QUrl(QStringLiteral("qrc:/QML/TileRectangles/AdditionRectangle.qml")));

        QVariantMap map;
        map["width"] = m_spacing - 1.0;
        map["height"] = m_spacing - 1.0;
        map["initialPoint"] = QPointF(0.5 + m_spacing * (i % m_xBoxNum),
                                      0.5 + m_spacing * std::floor(i/m_xBoxNum));
        map["finalPoint"] = QPointF(399.5 - m_spacing - m_spacing * (i % m_xBoxNum),
                                    0.5 + m_spacing * std::floor(i/m_xBoxNum));
        map["iColor"] = inColor1;
        map["fColor"] = outColor;
        map["delay"] = 1.0*i / totalBoxes * totalDelay;
        map["border.width"] = m_borderWidth;
        QObject* obj = comp.createWithInitialProperties(map, qmlEngine(this)->rootContext());

        QQuickItem* visibleObj = static_cast<QQuickItem*>(obj);
        m_wholeTiles.append(visibleObj);

        visibleObj->setParent(this);
        visibleObj->setParentItem(this);
    }

    for(int i = 0; i < std::floor(n2); i++)
    {
        QQmlComponent comp(qmlEngine(this), QUrl(QStringLiteral("qrc:/QML/TileRectangles/AdditionRectangle.qml")));

        QVariantMap map;
        map["width"] = m_spacing - 1.0;
        map["height"] = m_spacing - 1.0;
        map["initialPoint"] = QPointF(0.5 + m_spacing * (i % m_xBoxNum),
                                      199.5 - m_spacing - m_spacing * std::floor(i/m_xBoxNum));
        map["finalPoint"] = QPointF(399.5 - m_spacing - m_spacing * ((int) (i + std::floor(n1)) % m_xBoxNum),
                                    0.5 + m_spacing * std::floor((i + std::floor(n1))/m_xBoxNum));
        map["iColor"] = inColor2;
        map["fColor"] = outColor;
        map["delay"] = 1.0*(i + std::floor(n1) + 1) / totalBoxes * totalDelay;
        map["border.width"] = m_borderWidth;
        QObject* obj = comp.createWithInitialProperties(map, qmlEngine(this)->rootContext());

        QQuickItem* visibleObj = static_cast<QQuickItem*>(obj);
        m_wholeTiles.append(visibleObj);

        visibleObj->setParent(this);
        visibleObj->setParentItem(this);
    }

    if(!qFuzzyIsNull(n1 - std::floor(n1)) && !qFuzzyIsNull(n2 - std::floor(n2)))
    {
        double frac1 = n1 - std::floor(n1);
        double frac2 = n2 - std::floor(n2);
        double box1Final;
        double box2Final;
        if(frac1 + frac2 < 1.0)
        {
            box1Final = frac1 + frac2;
            box2Final = 0.0;
        }
        else
        {
            box1Final = 1.0;
            box2Final = frac1 + frac2 - 1.0;
        }
        QQmlComponent comp(qmlEngine(this), QUrl(QStringLiteral("qrc:/QML/TileRectangles/AdditionRectangle.qml")));

        QVariantMap map;
        map["width"] =  (n1 - std::floor(n1)) * (m_spacing - 1.0);
        map["height"] = m_spacing - 1.0;
        map["initialPoint"] = QPointF(0.5 + m_spacing * ((int) std::floor(n1)  % m_xBoxNum),
                                      0.5 + m_spacing * std::floor(std::floor(n1) /m_xBoxNum));
        map["finalPoint"] = QPointF(399.5 - box1Final * (m_spacing - 1.0) - 1.0 - m_spacing * ( (int) (std::floor(n1) + std::floor(n2))  % m_xBoxNum),
                                    0.5 + m_spacing * std::floor((std::floor(n1) + std::floor(n2)) /m_xBoxNum));
        map["iColor"] = inColor1;
        map["fColor"] = outColor;
        map["delay"] = 1.0*std::floor(n1)  / totalBoxes * totalDelay;
        map["border.width"] = m_borderWidth;
        map["initialWidth"] = (n1 - std::floor(n1)) * (m_spacing - 1.0);
        map["finalWidth"] = box1Final * (m_spacing - 1.0);
        QObject* obj = comp.createWithInitialProperties(map, qmlEngine(this)->rootContext());

        QQuickItem* visibleObj = static_cast<QQuickItem*>(obj);
        m_wholeTiles.append(visibleObj);

        visibleObj->setParent(this);
        visibleObj->setParentItem(this);

        QQmlComponent comp2(qmlEngine(this), QUrl(QStringLiteral("qrc:/QML/TileRectangles/AdditionRectangle.qml")));

        QVariantMap map2;
        map2["width"] = (n2 - std::floor(n2)) * (m_spacing - 1.0);
        map2["height"] = m_spacing - 1.0;
        map2["initialPoint"] = QPointF(0.5 + m_spacing * ((int) std::floor(n2) % m_xBoxNum),
                                      199.5 - m_spacing - m_spacing * std::floor(std::floor(n2)/m_xBoxNum));
        map2["finalPoint"] = QPointF(399.5 - box2Final * (m_spacing - 1.0) - 1.0 - m_spacing * ((int) (std::floor(n2) + std::floor(n1) + 1) % m_xBoxNum),
                                    0.5 + m_spacing * std::floor((std::floor(n2) + std::floor(n1) + 1)/m_xBoxNum));
        map2["iColor"] = inColor2;
        map2["fColor"] = outColor;
        map2["delay"] = 1.0*(std::floor(n2) + std::floor(n1) + 1) / totalBoxes * totalDelay;
        map2["border.width"] = m_borderWidth;

        map2["initialWidth"] = (n2 - std::floor(n2)) * (m_spacing - 1.0);
        map2["finalWidth"] = box2Final * (m_spacing - 1.0);
        QObject* obj2 = comp2.createWithInitialProperties(map2, qmlEngine(this)->rootContext());

        QQuickItem* visibleObj2 = static_cast<QQuickItem*>(obj2);
        m_wholeTiles.append(visibleObj2);

        visibleObj2->setParent(this);
        visibleObj2->setParentItem(this);

    }
    else if(!qFuzzyIsNull(n1 - std::floor(n1)))
    {
        QQmlComponent comp(qmlEngine(this), QUrl(QStringLiteral("qrc:/QML/TileRectangles/AdditionRectangle.qml")));

        QVariantMap map;
        map["width"] =  (n1 - std::floor(n1)) * (m_spacing - 1.0);
        map["height"] = m_spacing - 1.0;
        map["initialPoint"] = QPointF(0.5 + m_spacing * ((int) std::floor(n1)  % m_xBoxNum),
                                      0.5 + m_spacing * std::floor(std::floor(n1) /m_xBoxNum));
        map["finalPoint"] = QPointF(399.5 - (n1 - std::floor(n1)) * (m_spacing - 1.0) - m_spacing * ( (int) (std::floor(n1) + std::floor(n2))  % m_xBoxNum),
                                    0.5 + m_spacing * std::floor((std::floor(n1) + std::floor(n2)) /m_xBoxNum));
        map["iColor"] = inColor1;
        map["fColor"] = outColor;
        map["delay"] = 1.0*std::floor(n1)  / totalBoxes * totalDelay;
        map["border.width"] = m_borderWidth;
        QObject* obj = comp.createWithInitialProperties(map, qmlEngine(this)->rootContext());

        QQuickItem* visibleObj = static_cast<QQuickItem*>(obj);
        m_wholeTiles.append(visibleObj);

        visibleObj->setParent(this);
        visibleObj->setParentItem(this);
    }
    else if(!qFuzzyIsNull(n2 - std::floor(n2)))
    {
        QQmlComponent comp(qmlEngine(this), QUrl(QStringLiteral("qrc:/QML/TileRectangles/AdditionRectangle.qml")));

        QVariantMap map;
        map["width"] = (n2 - std::floor(n2)) * (m_spacing - 1.0);
        map["height"] = m_spacing - 1.0;
        map["initialPoint"] = QPointF(0.5 + m_spacing * ((int) std::floor(n2) % m_xBoxNum),
                                      199.5 - m_spacing - m_spacing * std::floor(std::floor(n2)/m_xBoxNum));
        map["finalPoint"] = QPointF(399.5 - (n2 - std::floor(n2)) * (m_spacing - 1.0) - m_spacing * ((int) (std::floor(n2) + std::floor(n1)) % m_xBoxNum),
                                    0.5 + m_spacing * std::floor((std::floor(n2) + std::floor(n1))/m_xBoxNum));
        map["iColor"] = inColor2;
        map["fColor"] = outColor;
        map["delay"] = 1.0*(std::floor(n2) + std::floor(n1) + 1) / totalBoxes * totalDelay;
        map["border.width"] = m_borderWidth;
        QObject* obj = comp.createWithInitialProperties(map, qmlEngine(this)->rootContext());

        QQuickItem* visibleObj = static_cast<QQuickItem*>(obj);
        m_wholeTiles.append(visibleObj);

        visibleObj->setParent(this);
        visibleObj->setParentItem(this);
    }

    reset();
}

void AdditionVisualArea::clear()
{   
    for(int i = 0; i < m_wholeTiles.length(); i++)
        m_wholeTiles[i]->deleteLater();
    m_wholeTiles.clear();

    for(int i = 0; i < m_finalTiles.length(); i++)
        m_finalTiles[i]->deleteLater();
    m_finalTiles.clear();
}

void AdditionVisualArea::reset()
{
    for(int i = 0; i < m_wholeTiles.length(); i++)
    {
        QMetaObject::invokeMethod(m_wholeTiles[i], "startResetAnimation");
    }
    for(int i = 0; i < m_finalTiles.length(); i++)
    {
        QMetaObject::invokeMethod(m_finalTiles[i], "startResetAnimation");
    }
}

void AdditionVisualArea::action()
{
    for(int i = 0; i < m_wholeTiles.length(); i++)
    {
        QMetaObject::invokeMethod(m_wholeTiles[i], "startActionAnimation");
    }
    for(int i = 0; i < m_finalTiles.length(); i++)
    {
        QMetaObject::invokeMethod(m_finalTiles[i], "startActionAnimation");
    }
}

void AdditionVisualArea::prepareSizeVariables(int wholeBoxes)
{
    if(wholeBoxes <= 6)
    {
        m_borderWidth = 8;
        m_spacing = 80;
        m_xBoxNum = 5;
    }
    else if(wholeBoxes <= 40)
    {
        m_borderWidth = 4;
        m_spacing = 40;
        m_xBoxNum = 10;
    }
    else if(wholeBoxes <= 160)
    {
        m_borderWidth = 2;
        m_spacing = 20;
        m_xBoxNum = 20;
    }
    else if(wholeBoxes <= 720)
    {
        m_borderWidth = 1;
        m_spacing = 10;
        m_xBoxNum = 40;
    }
    else if(wholeBoxes <= 4000)
    {
        m_borderWidth = 0;
        m_spacing = 4;
        m_xBoxNum = 100;
    }
    else if(wholeBoxes <= 20000)
    {
        m_borderWidth = 0;
        m_spacing = 2;
        m_xBoxNum = 200;
    }
}
