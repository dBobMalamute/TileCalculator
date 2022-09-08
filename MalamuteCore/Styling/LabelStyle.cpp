#include "LabelStyle.h"

LabelStyle::LabelStyle()
{
    m_colorList = {QColor("#d4985d"),
                   QColor("#e70c0c"),
                   QColor("#e76f0c"),
                   QColor("#e7b80c"),
                   QColor("#a6e70c"),
                   QColor("#0ce717"),
                   QColor("#0ce7c9"),
                   QColor("#0c52e7"),
                   QColor("#850ce7"),
                   QColor("#e70cc5"),
                   QColor("#e70c47"),

                   QColor("#26d326"),
                   QColor("#0bafd1"),
                   QColor("#ea42cb"),
                   QColor("#26d3a7"),
                   QColor("#e76f0c"),
                   QColor("#a942ea"),

                   QColor("#d28888"),
                   QColor("#d29cf4"),
                   QColor("#8cea8c"),
                   QColor("#8ae6f9"),
                   QColor("#d1d693"),
                   QColor("#ab9af4"),
                   QColor("#f49ce4"),
                   QColor("#a4efdc"),

                   QColor("#d4b35d"),
                   QColor("#b15e43"),
                   QColor("#d242ea"),
                   QColor("#26d363"),
                   QColor("#0b80d1"),
                   QColor("#7cb143"),
                   QColor("#f5580a"),
                   QColor("#8e1155"),
                   QColor("#1e9fa5")};
}

QColor LabelStyle::defaultColor()
{
    return QColor("#a6b0cb");
}

QColor LabelStyle::getColor()
{
    colorListIndex++;
    if(colorListIndex == m_colorList.length())
        colorListIndex = 0;

    return m_colorList.at(colorListIndex);
}
