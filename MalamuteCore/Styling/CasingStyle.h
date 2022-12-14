#ifndef CASINGSTYLE_H
#define CASINGSTYLE_H

#include <QObject>
#include <QColor>
#include <QFont>

class CasingStyle : public QObject
{
    Q_OBJECT
public:
    explicit CasingStyle(QObject *parent = nullptr);

signals:

public slots:
    double bordersWidth() const;
    double frameRadius() const;
    QColor borderColor() const;
    QColor borderSelectedColor() const;

    QColor gradientTopColor(int i);
    QColor gradientBottomColor(int i);

    int glowRadius() const;
    double glowSpread() const;
    QColor glowColor() const;

    double portSize() const;
    double portSpacing() const;
    double portBorderWidth() const;

    QColor nameColor() const;
    QFont nameFont() const;

    QFont portLabelsFont() const;

    QFont validationTextFont() const;
    QColor validationTextColor() const;

    double buttonSize() const;
    QColor buttonColor() const;
    double buttonHoverDarkenFactor() const;

    double resizerSize() const;
    QColor resizerColor() const;
    QColor resizerBorderColor() const;

private:
    double m_bordersWidth = 4;
    double m_frameRadius = 15;
    QColor m_borderColor = QColor("#845a35");
    QColor m_borderSelectedColor = QColor("#cc5708");

    std::vector<QColor> m_gradientTopColors;
    std::vector<QColor> m_gradientBottomColors;

    int m_glowRadius = 6;
    double m_glowSpread = 0.4;
    QColor m_glowColor = QColor("#323232");

    double m_portSize = 15;
    double m_portSpacing = 5;
    double m_portBorderWidth = 3;

    QColor m_nameColor = QColor("black");
    QFont m_nameFont;

    QFont m_portLabelsFont;

    QColor m_portLabelsColor = QColor("black");
    QFont m_validationTextFont;
    QColor m_validationTextColor = QColor("black");

    double m_buttonSize = 22;
    QColor m_buttonColor = QColor("#845a35");
    double m_buttonHoverDarkenFactor = 1.5;

    double m_resizerSize = 14;
    QColor m_resizerColor = QColor("black");
    QColor m_resizerBorderColor = QColor("grey");
};

#endif // CASINGSTYLE_H
