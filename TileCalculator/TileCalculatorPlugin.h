#ifndef TILECALCULATOR_H
#define TILECALCULATOR_H

#include "../MalamuteCore/InheritedClasses/MalamutePlugin.h"

class TileCalculatorPlugin : public MalamutePlugin
{
    Q_OBJECT

public:
    QString PluginName() override;
    QString PluginDescription() override;
    QStringList authors() override;
    void registerIdeas(std::shared_ptr<IdeaRegistry> ideaRegistry) override;
    void registerDataTypeAttributes(std::shared_ptr<DataTypeRegistry> dataTypeRegistry) override;
    void registerToolbars(std::shared_ptr<ToolbarRegistry> toolbarRegistry) override;
};


#endif // TILECALCULATOR_H
