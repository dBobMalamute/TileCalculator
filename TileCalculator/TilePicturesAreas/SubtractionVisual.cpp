#include "SubtractionVisual.h"
#include <cmath>

SubtractionVisualArea::SubtractionVisualArea()
{
    setFlag(ItemHasContents);
    setWidth(400);
    setHeight(200);
}

void SubtractionVisualArea::setup(double n1, double n2, QColor inColor1, QColor inColor2, QColor outColor)
{
    m_n2 = n2;

    clear();
    int totalBoxes = std::ceil(n1);
    prepareSizeVariables(totalBoxes);

    double totalDelay = std::max(0.0,500*std::log2(totalBoxes));

    m_tiles.reserve(totalBoxes - 2);
    for(int i = 0; i < std::floor(n2); i++)
    {
        QQmlComponent comp(qmlEngine(this), QUrl(QStringLiteral("qrc:/QML/TileRectangles/SubtractionLeaveRectangle.qml")));

        QVariantMap map;
        map["initialCoords"] = QRectF(0.5 + m_spacing * (i % m_xBoxNum),
                                      0.5 + m_spacing * std::floor(i/m_xBoxNum),
                                      m_spacing - 1.0, m_spacing - 1.0);
        map["iColor"] = inColor1;
        map["fColor"] = inColor2;
        map["delay"] = 1.0*i / totalBoxes * totalDelay;
        map["border.width"] = m_borderWidth;
        QObject* obj = comp.createWithInitialProperties(map, qmlEngine(this)->rootContext());

        QQuickItem* visibleObj = static_cast<QQuickItem*>(obj);
        m_tiles.append(visibleObj);

        visibleObj->setParent(this);
        visibleObj->setParentItem(this);
    }
    if(!qFuzzyIsNull(n2 - std::floor(n2)))
    {
        m_fracUpWidth = std::min(1.0, n1 - std::floor(n2));
        {
            QQmlComponent comp(qmlEngine(this), QUrl(QStringLiteral("qrc:/QML/TileRectangles/SubtractionLeaveRectangle.qml")));

            QVariantMap map;
            map["initialCoords"] = QRectF(0.5 + m_spacing * ((int) std::floor(n2) % m_xBoxNum),
                                          0.5 + m_spacing * std::floor(std::floor(n2)/m_xBoxNum),
                                          (m_spacing - 1.0) * m_fracUpWidth, m_spacing - 1.0);
            map["iColor"] = inColor1;
            map["fColor"] = inColor2;
            map["delay"] = 1.0*std::floor(n2) / totalBoxes * totalDelay;
            map["border.width"] = m_borderWidth;
            QObject* obj = comp.createWithInitialProperties(map, qmlEngine(this)->rootContext());

            QQuickItem* visibleObj = static_cast<QQuickItem*>(obj);
            m_tiles.append(visibleObj);
            m_fracLowTile = visibleObj;

            visibleObj->setParent(this);
            visibleObj->setParentItem(this);
        }
        {
            QQmlComponent comp(qmlEngine(this), QUrl(QStringLiteral("qrc:/QML/TileRectangles/SubtractionStayRectangle.qml")));

            QVariantMap map;
            map["initialCoords"] = QRectF(0.5 + m_spacing * ((int) std::floor(n2) % m_xBoxNum) + (m_spacing - 1.0) * (n2 - std::floor(n2)),
                                          0.5 + m_spacing * std::floor(std::floor(n2)/m_xBoxNum),
                                          0.0, m_spacing - 1.0);

            if (std::ceil(n2) <= n1)
            {
                map["finalCoords"] = QPointF(399.5 - m_spacing - m_spacing * ((int)(std::floor(n1) - std::ceil(n2)) % m_xBoxNum) + (m_spacing - 1.0) * (1.0 - (n1 - std::floor(n1))) - (m_spacing - 1.0) * (m_fracUpWidth  - (m_n2 - std::floor(m_n2))),
                                             0.5 + m_spacing * std::floor((std::floor(n1) - std::ceil(n2))/m_xBoxNum));
            }
            else
            {
                //Only fraction edge case.
                map["finalCoords"] = QPointF(399.5 - (m_spacing - 1) * (n1 - n2), 0.5 );
            }

            map["iColor"] = inColor1;
            map["fColor"] = outColor;
            map["delay"] = 1.0*std::floor(n2)  / totalBoxes * totalDelay;
            map["border.width"] = m_borderWidth;
            QObject* obj = comp.createWithInitialProperties(map, qmlEngine(this)->rootContext());

            QQuickItem* visibleObj = static_cast<QQuickItem*>(obj);
            m_tiles.append(visibleObj);
            m_fracUpTile = visibleObj;

            visibleObj->setParent(this);
            visibleObj->setParentItem(this);
        }
    }
    for(int i = std::ceil(n2); i < std::floor(n1); i++)
    {
        QQmlComponent comp(qmlEngine(this), QUrl(QStringLiteral("qrc:/QML/TileRectangles/SubtractionStayRectangle.qml")));

        QVariantMap map;
        map["initialCoords"] = QRectF(0.5 + m_spacing * (i % m_xBoxNum),
                                      0.5 + m_spacing * std::floor(i/m_xBoxNum),
                                      m_spacing - 1.0, m_spacing - 1.0);
        map["finalCoords"] = QPointF(399.5 - m_spacing - m_spacing * ((int)(i - std::ceil(n2)) % m_xBoxNum),
                                     0.5 + m_spacing * std::floor((i - std::ceil(n2))/m_xBoxNum));

        map["iColor"] = inColor1;
        map["fColor"] = outColor;
        map["delay"] = 1.0*i / totalBoxes * totalDelay;
        map["border.width"] = m_borderWidth;
        QObject* obj = comp.createWithInitialProperties(map, qmlEngine(this)->rootContext());

        QQuickItem* visibleObj = static_cast<QQuickItem*>(obj);
        m_tiles.append(visibleObj);

        visibleObj->setParent(this);
        visibleObj->setParentItem(this);
    }
    if(!qFuzzyIsNull(n1 - std::floor(n1)) && (std::ceil(n2) <= n1))
    {
        QQmlComponent comp(qmlEngine(this), QUrl(QStringLiteral("qrc:/QML/TileRectangles/SubtractionStayRectangle.qml")));

        QVariantMap map;
        map["initialCoords"] = QRectF(0.5 + m_spacing * ((int) std::floor(n1) % m_xBoxNum),
                                      0.5 + m_spacing * std::floor(std::floor(n1)/m_xBoxNum),
                                      (m_spacing - 1.0) * (n1 - std::floor(n1)), m_spacing - 1.0);
        map["finalCoords"] = QPointF(399.5 - m_spacing - m_spacing * ((int)(std::floor(n1) - std::ceil(n2)) % m_xBoxNum) + (m_spacing - 1.0) * (1.0 - (n1 - std::floor(n1))),
                                     0.5 + m_spacing * std::floor((std::floor(n1) - std::ceil(n2))/m_xBoxNum));

        map["iColor"] = inColor1;
        map["fColor"] = outColor;
        map["delay"] = 1.0*std::floor(n1) / totalBoxes * totalDelay;
        map["border.width"] = m_borderWidth;
        QObject* obj = comp.createWithInitialProperties(map, qmlEngine(this)->rootContext());

        QQuickItem* visibleObj = static_cast<QQuickItem*>(obj);
        m_tiles.append(visibleObj);
        m_fracAboveTile = visibleObj;

        visibleObj->setParent(this);
        visibleObj->setParentItem(this);
    }

    reset();
}

void SubtractionVisualArea::clear()
{   
    for(int i = 0; i < m_tiles.length(); i++)
        m_tiles[i]->deleteLater();
    m_tiles.clear();

    m_fracLowTile = nullptr;
    m_fracUpTile = nullptr;
    m_fracAboveTile = nullptr;
}

void SubtractionVisualArea::reset()
{
    if(m_fracLowTile)
    {
        m_fracLowTile->setWidth((m_spacing - 1.0) * (m_n2 - std::floor(m_n2)));
    }
    if(m_fracUpTile)
    {
        m_fracUpTile->setWidth(0.0);
    }

    for(int i = 0; i < m_tiles.length(); i++)
    {
        QMetaObject::invokeMethod(m_tiles[i], "startResetAnimation");
    }
}

void SubtractionVisualArea::action()
{
    if(m_fracLowTile)
    {
        m_fracLowTile->setWidth((m_spacing - 1.0) * (m_n2 - std::floor(m_n2)));
    }
    if(m_fracUpTile)
    {
        m_fracUpTile->setWidth((m_spacing - 1.0) * (m_fracUpWidth  - (m_n2 - std::floor(m_n2))));
    }

    for(int i = 0; i < m_tiles.length(); i++)
    {
        QMetaObject::invokeMethod(m_tiles[i], "startActionAnimation");
    }
}

void SubtractionVisualArea::prepareSizeVariables(int totalBoxes)
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
