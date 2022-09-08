#ifndef INVERSETRIGIDEATEMPLATE_H
#define INVERSETRIGIDEATEMPLATE_H

#include "../../MalamuteCore/InheritedClasses/Idea.h"
#include "../../DataTypes/NumberDataType.h"

class InverseTrigIdeaTemplate : public Idea
{
    Q_OBJECT
    Q_PROPERTY(bool degreeMode READ degreeMode WRITE setDegreeMode NOTIFY degreeModeChanged)
    Q_PROPERTY(int nAnswer READ nAnswer WRITE setNAnswer NOTIFY nAnswerChanged)

public:
    InverseTrigIdeaTemplate();

    QJsonObject save() const override;
    void load(const QJsonObject &) override;

    void onNewDataIn(std::shared_ptr<DataType> dataType, PlugNumber plugNumber) override;
    std::shared_ptr<DataType> dataOut(PlugNumber plugNumber) override;

    void updateOnOutPortLabelColor() override;
    void updateOnInPortLabelColor() override;

    bool degreeMode() const;
    int nAnswer() const;

public slots:
    void setDegreeMode(bool degreeMode);
    void setNAnswer(int nAnswer);

signals:
    void degreeModeChanged(bool degreeMode);
    void nAnswerChanged(int nAnswer);
    void display(double input, double output);
    void clear();

protected:
    std::weak_ptr<NumberDataType> m_input;
    std::shared_ptr<NumberDataType> m_result;

    virtual void validate() = 0;
    void setupDisplay();

    bool m_degreeMode;
    int m_nAnswer;
};
#endif // INVERSETRIGIDEATEMPLATE_H
