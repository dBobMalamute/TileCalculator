#include <QQmlEngine>

#include "TileCalculatorPlugin.h"

#include "TileAdditionIdea.h"
#include "TileSubtractionIdea.h"
#include "TileMultiplicationIdea.h"
#include "TileDivisionIdea.h"
#include "TileDisplayIdea.h"
#include "TileInputIdea.h"
#include "TileSquaredIdea.h"
#include "TileSquareRootIdea.h"
#include "TileLogarithmBase10Idea.h"
#include "TileLogarithmBaseEIdea.h"
#include "TileLogarithmBase2Idea.h"
#include "TileExponentialIdea.h"
#include "TilePowerOfTwoIdea.h"
#include "TilePowerOfTenIdea.h"
#include "TilePowerIdea.h"
#include "TileFloorIdea.h"
#include "TileCeilingIdea.h"
#include "TileLogarithmBaseNIdea.h"

#include "TilePicturesAreas/FloorVisual.h"
#include "TilePicturesAreas/CeilVisual.h"
#include "TilePicturesAreas/AdditionVisual.h"
#include "TilePicturesAreas/SubtractionVisual.h"

QString TileCalculatorPlugin::PluginName()
{
    return "Tile Calculator";
}

QString TileCalculatorPlugin::PluginDescription()
{
    return "This library performs calculator operations while allowing the user to think about them"
           "as if they were done on tiles.";
}

QStringList TileCalculatorPlugin::authors()
{
    return QStringList("dBob");
}

void TileCalculatorPlugin::registerIdeas(std::shared_ptr<IdeaRegistry> ideaRegistry)
{
    ideaRegistry->registerIdea<TileCeilingIdea>();
    ideaRegistry->registerIdea<TileFloorIdea>();
    ideaRegistry->registerIdea<TilePowerIdea>();
    ideaRegistry->registerIdea<TileExponentialIdea>();
    ideaRegistry->registerIdea<TilePowerOfTwoIdea>();
    ideaRegistry->registerIdea<TilePowerOfTenIdea>();
    ideaRegistry->registerIdea<TileLogarithmBase2Idea>();
    ideaRegistry->registerIdea<TileLogarithmBaseEIdea>();
    ideaRegistry->registerIdea<TileLogarithmBase10Idea>();
    ideaRegistry->registerIdea<TileSquareRootIdea>();
    ideaRegistry->registerIdea<TileSquaredIdea>();
    ideaRegistry->registerIdea<TileAdditionIdea>();
    ideaRegistry->registerIdea<TileDivisionIdea>();
    ideaRegistry->registerIdea<TileMultiplicationIdea>();
    ideaRegistry->registerIdea<TileSubtractionIdea>();
    ideaRegistry->registerIdea<TileDisplayIdea>();
    ideaRegistry->registerIdea<TileInputIdea>();
    ideaRegistry->registerIdea<TileLogarithmBaseNIdea>();

    qmlRegisterType(QUrl("qrc:/QML/QMLTemplates/LogarithmTemplate.qml"), "com.malamute.calculator", 1, 0, "LogarithmTemplate");
    qmlRegisterType(QUrl("qrc:/QML/QMLTemplates/PowerOfTemplate.qml"), "com.malamute.calculator", 1, 0, "PowerOfTemplate");

    qmlRegisterType<FloorVisualArea>("com.malamute.tileCalculator", 1, 0, "FloorVisualArea");
    qmlRegisterType<CeilVisualArea>("com.malamute.tileCalculator", 1, 0, "CeilVisualArea");
    qmlRegisterType<AdditionVisualArea>("com.malamute.tileCalculator", 1, 0, "AdditionVisualArea");
    qmlRegisterType<SubtractionVisualArea>("com.malamute.tileCalculator", 1, 0, "SubtractionVisualArea");
}

void TileCalculatorPlugin::registerDataTypeAttributes(std::shared_ptr<DataTypeRegistry> dataTypeRegistry)
{
    dataTypeRegistry->registerDataTypeAttributes<NumberDataTypeAttributes>();
}

void TileCalculatorPlugin::registerToolbars(std::shared_ptr<ToolbarRegistry> toolbarRegistry)
{
    QStringList orderList;
    orderList << Magic<TileInputAttributes>::cast().listName();
    orderList << Magic<TileDisplayAttributes>::cast().listName();
    orderList << Magic<TileAdditionAttributes>::cast().listName();
    orderList << Magic<TileSubtractionAttributes>::cast().listName();
    orderList << Magic<TileMultiplicationAttributes>::cast().listName();
//    orderList << Magic<TileDivisionAttributes>::cast().listName();
    orderList << Magic<TilePowerOfTenAttributes>::cast().listName();
    orderList << Magic<TileExponentialAttributes>::cast().listName();
    orderList << Magic<TilePowerOfTwoAttributes>::cast().listName();
    orderList << Magic<TilePowerAttributes>::cast().listName();
    orderList << Magic<TileLogarithmBase10Attributes>::cast().listName();
    orderList << Magic<TileLogarithmBaseEAttributes>::cast().listName();
    orderList << Magic<TileLogarithmBase2Attributes>::cast().listName();
    orderList << Magic<TileLogarithmBaseNAttributes>::cast().listName();
    orderList << Magic<TileSquaredAttributes>::cast().listName();
//    orderList << Magic<TileSquareRootAttributes>::cast().listName();
    orderList << Magic<TileCeilingAttributes>::cast().listName();
    orderList << Magic<TileFloorAttributes>::cast().listName();

    toolbarRegistry->registerToolbar(PluginName(), orderList);
}
