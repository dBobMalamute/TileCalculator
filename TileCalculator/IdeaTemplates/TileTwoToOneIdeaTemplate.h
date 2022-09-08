#ifndef TILETWOTOONEIDEATEMPLATE_H
#define TILETWOTOONEIDEATEMPLATE_H

#include "../../MalamuteCore/InheritedClasses/Idea.h"
#include "../../DataTypes/NumberDataType.h"

class TileTwoToOneIdeaTemplate : public Idea
{
    Q_OBJECT

public:
    TileTwoToOneIdeaTemplate();

    void onNewDataIn(std::shared_ptr<DataType> dataType, PlugNumber) override;
    std::shared_ptr<DataType> dataOut(PlugNumber plugNumber) override;

signals:
    void display(double input1, double input2, double output);
    void clear();

protected:
    std::weak_ptr<NumberDataType> m_input1;
    std::weak_ptr<NumberDataType> m_input2;

    std::shared_ptr<NumberDataType> m_result;

    virtual void validate() = 0;
};

#endif // TWOTOONEIDEATEMPLATE_H
