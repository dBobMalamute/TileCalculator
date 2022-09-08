QT += quick widgets quickcontrols2

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


HEADERS += \
    Calculator/AbsoluteValueIdea.h \
    Calculator/AdditionIdea.h \
    Calculator/CalculatorPlugin.h \
    Calculator/CeilingIdea.h \
    Calculator/CosineIdea.h \
    Calculator/DivisionIdea.h \
    Calculator/ExponentialIdea.h \
    Calculator/FloorIdea.h \
    Calculator/FractionInputIdea.h \
    Calculator/IdeaTemplates/InverseTrigIdeaTemplate.h \
    Calculator/IdeaTemplates/OneToOneIdeaTemplate.h \
    Calculator/IdeaTemplates/TrigIdeaTemplate.h \
    Calculator/InverseCosineIdea.h \
    Calculator/InverseSineIdea.h \
    Calculator/InverseTangentIdea.h \
    Calculator/LabeledNumberDisplayIdea.h \
    Calculator/LabeledNumberInputIdea.h \
    Calculator/LogarithmBase10Idea.h \
    Calculator/LogarithmBase2Idea.h \
    Calculator/LogarithmBaseEIdea.h \
    Calculator/LogarithmBaseNIdea.h \
    Calculator/MathematicalConstantsIdea.h \
    Calculator/MultiplicationIdea.h \
    Calculator/NumberDisplayIdea.h \
    Calculator/NumberInputIdea.h \
    Calculator/NumberWeighterIdea.h \
    Calculator/PowerIdea.h \
    Calculator/PowerOfTenIdea.h \
    Calculator/PowerOfTwoIdea.h \
    Calculator/ReciprocalIdea.h \
    Calculator/SineIdea.h \
    Calculator/SliderNumberInputIdea.h \
    Calculator/SquareRootFractionInputIdea.h \
    Calculator/SquareRootIdea.h \
    Calculator/SquareRootNumberInputIdea.h \
    Calculator/SquaredIdea.h \
    Calculator/SubtractionIdea.h \
    Calculator/TangentIdea.h \
    Calculator/IdeaTemplates/TwoToOneIdeaTemplate.h \
    DataTypes/DistributionDataType.h \
    DataTypes/NumberDataType.h \
    DataTypes/NumbersDataType.h \
    MalamuteCore/Casing.h \
    MalamuteCore/CasingBackend.h \
    MalamuteCore/CasingState.h \
    MalamuteCore/Commands/AddCasingCommand.h \
    MalamuteCore/Commands/AddDefaultDisplayCommand.h \
    MalamuteCore/Commands/AddDefaultSourceCommand.h \
    MalamuteCore/Commands/AddPostItCommand.h \
    MalamuteCore/Commands/AddSelectionCommand.h \
    MalamuteCore/Commands/AddWireCommand.h \
    MalamuteCore/Commands/ChangeColorsCommand.h \
    MalamuteCore/Commands/ChangeParamsCommand.h \
    MalamuteCore/Commands/DeleteCasingCommand.h \
    MalamuteCore/Commands/DeletePostItCommand.h \
    MalamuteCore/Commands/DeleteSelectionCommand.h \
    MalamuteCore/Commands/DeleteWireCommand.h \
    MalamuteCore/Commands/MinimizeCasingCommand.h \
    MalamuteCore/Commands/MoveSelectionCommand.h \
    MalamuteCore/Commands/ResizeCasingCommand.h \
    MalamuteCore/Commands/ShiftWireCommand.h \
    MalamuteCore/Corkboard.h \
    MalamuteCore/CorkboardBackend.h \
    MalamuteCore/CorkboardHandler.h \
    MalamuteCore/InheritedClasses/DataType.h \
    MalamuteCore/InheritedClasses/DataTypeAttributes.h \
    MalamuteCore/InheritedClasses/Idea.h \
    MalamuteCore/InheritedClasses/IdeaAttributes.h \
    MalamuteCore/InheritedClasses/Magic.h \
    MalamuteCore/InheritedClasses/MalamutePlugin.h \
    MalamuteCore/Plug.h \
    MalamuteCore/PostIt.h \
    MalamuteCore/QMLRegisterHelper.h \
    MalamuteCore/Registries/DataTypeRegistry.h \
    MalamuteCore/Registries/IdeaRegistry.h \
    MalamuteCore/Registries/ToolbarRegistry.h \
    MalamuteCore/Styling/CasingStyle.h \
    MalamuteCore/Styling/ControlsStyle.h \
    MalamuteCore/Styling/CorkboardStyle.h \
    MalamuteCore/Styling/GearStyle.h \
    MalamuteCore/Styling/LabelStyle.h \
    MalamuteCore/Styling/PostItStyle.h \
    MalamuteCore/Styling/WireStyle.h \
    MalamuteCore/SurfaceAndStyleSetup.h \
    MalamuteCore/Wire.h \
    MalamuteCore/WireBackend.h \
    MalamuteCore/WireCasingInteraction.h \
    MalamuteCore/WireState.h \
    TileCalculator/IdeaTemplates/TileOneToOneIdeaTemplate.h \
    TileCalculator/IdeaTemplates/TileTwoToOneIdeaTemplate.h \
    TileCalculator/TileAdditionIdea.h \
    TileCalculator/TileCalculatorPlugin.h \
    TileCalculator/TileCeilingIdea.h \
    TileCalculator/TileDisplayIdea.h \
    TileCalculator/TileDivisionIdea.h \
    TileCalculator/TileExponentialIdea.h \
    TileCalculator/TileFloorIdea.h \
    TileCalculator/TileInputIdea.h \
    TileCalculator/TileLogarithmBase10Idea.h \
    TileCalculator/TileLogarithmBase2Idea.h \
    TileCalculator/TileLogarithmBaseEIdea.h \
    TileCalculator/TileLogarithmBaseNIdea.h \
    TileCalculator/TileMultiplicationIdea.h \
    TileCalculator/TilePicturesAreas/AdditionVisual.h \
    TileCalculator/TilePicturesAreas/CeilVisual.h \
    TileCalculator/TilePicturesAreas/FloorVisual.h \
    TileCalculator/TilePicturesAreas/SubtractionVisual.h \
    TileCalculator/TilePowerIdea.h \
    TileCalculator/TilePowerOfTenIdea.h \
    TileCalculator/TilePowerOfTwoIdea.h \
    TileCalculator/TileSquareRootIdea.h \
    TileCalculator/TileSquaredIdea.h \
    TileCalculator/TileSubtractionIdea.h \
    Utilities/ColoredSquareIdea.h \
    Utilities/TextAreaIdea.h \
    Utilities/TextLineIdea.h \
    Utilities/UtilitiesPlugin.h

SOURCES += \
    Calculator/AbsoluteValueIdea.cpp \
    Calculator/AdditionIdea.cpp \
    Calculator/CalculatorPlugin.cpp \
    Calculator/CeilingIdea.cpp \
    Calculator/CosineIdea.cpp \
    Calculator/DivisionIdea.cpp \
    Calculator/ExponentialIdea.cpp \
    Calculator/FloorIdea.cpp \
    Calculator/FractionInputIdea.cpp \
    Calculator/IdeaTemplates/InverseTrigIdeaTemplate.cpp \
    Calculator/IdeaTemplates/OneToOneIdeaTemplate.cpp \
    Calculator/IdeaTemplates/TrigIdeaTemplate.cpp \
    Calculator/InverseCosineIdea.cpp \
    Calculator/InverseSineIdea.cpp \
    Calculator/InverseTangentIdea.cpp \
    Calculator/LabeledNumberDisplayIdea.cpp \
    Calculator/LabeledNumberInputIdea.cpp \
    Calculator/LogarithmBase10Idea.cpp \
    Calculator/LogarithmBase2Idea.cpp \
    Calculator/LogarithmBaseEIdea.cpp \
    Calculator/LogarithmBaseNIdea.cpp \
    Calculator/MathematicalConstantsIdea.cpp \
    Calculator/MultiplicationIdea.cpp \
    Calculator/NumberDisplayIdea.cpp \
    Calculator/NumberInputIdea.cpp \
    Calculator/NumberWeighterIdea.cpp \
    Calculator/PowerIdea.cpp \
    Calculator/PowerOfTenIdea.cpp \
    Calculator/PowerOfTwoIdea.cpp \
    Calculator/ReciprocalIdea.cpp \
    Calculator/SineIdea.cpp \
    Calculator/SliderNumberInputIdea.cpp \
    Calculator/SquareRootFractionInputIdea.cpp \
    Calculator/SquareRootIdea.cpp \
    Calculator/SquareRootNumberInputIdea.cpp \
    Calculator/SquaredIdea.cpp \
    Calculator/SubtractionIdea.cpp \
    Calculator/TangentIdea.cpp \
    Calculator/IdeaTemplates/TwoToOneIdeaTemplate.cpp \
    DataTypes/DistributionDataType.cpp \
    DataTypes/NumberDataType.cpp \
    DataTypes/NumbersDataType.cpp \
    MalamuteCore/Casing.cpp \
    MalamuteCore/CasingBackend.cpp \
    MalamuteCore/CasingState.cpp \
    MalamuteCore/Commands/AddCasingCommand.cpp \
    MalamuteCore/Commands/AddDefaultDisplayCommand.cpp \
    MalamuteCore/Commands/AddDefaultSourceCommand.cpp \
    MalamuteCore/Commands/AddPostItCommand.cpp \
    MalamuteCore/Commands/AddSelectionCommand.cpp \
    MalamuteCore/Commands/AddWireCommand.cpp \
    MalamuteCore/Commands/ChangeColorsCommand.cpp \
    MalamuteCore/Commands/ChangeParamsCommand.cpp \
    MalamuteCore/Commands/DeleteCasingCommand.cpp \
    MalamuteCore/Commands/DeletePostItCommand.cpp \
    MalamuteCore/Commands/DeleteSelectionCommand.cpp \
    MalamuteCore/Commands/DeleteWireCommand.cpp \
    MalamuteCore/Commands/MinimizeCasingCommand.cpp \
    MalamuteCore/Commands/MoveSelectionCommand.cpp \
    MalamuteCore/Commands/ResizeCasingCommand.cpp \
    MalamuteCore/Commands/ShiftWireCommand.cpp \
    MalamuteCore/Corkboard.cpp \
    MalamuteCore/CorkboardBackend.cpp \
    MalamuteCore/CorkboardHandler.cpp \
    MalamuteCore/InheritedClasses/DataType.cpp \
    MalamuteCore/InheritedClasses/DataTypeAttributes.cpp \
    MalamuteCore/InheritedClasses/Idea.cpp \
    MalamuteCore/InheritedClasses/IdeaAttributes.cpp \
    MalamuteCore/InheritedClasses/MalamutePlugin.cpp \
    MalamuteCore/PostIt.cpp \
    MalamuteCore/Registries/DataTypeRegistry.cpp \
    MalamuteCore/Registries/IdeaRegistry.cpp \
    MalamuteCore/Registries/ToolbarRegistry.cpp \
    MalamuteCore/Styling/CasingStyle.cpp \
    MalamuteCore/Styling/ControlsStyle.cpp \
    MalamuteCore/Styling/CorkboardStyle.cpp \
    MalamuteCore/Styling/GearStyle.cpp \
    MalamuteCore/Styling/LabelStyle.cpp \
    MalamuteCore/Styling/PostItStyle.cpp \
    MalamuteCore/Styling/WireStyle.cpp \
    MalamuteCore/Wire.cpp \
    MalamuteCore/WireBackend.cpp \
    MalamuteCore/WireCasingInteraction.cpp \
    MalamuteCore/WireState.cpp \
    MalamuteCore/main.cpp \
    TileCalculator/IdeaTemplates/TileOneToOneIdeaTemplate.cpp \
    TileCalculator/IdeaTemplates/TileTwoToOneIdeaTemplate.cpp \
    TileCalculator/TileAdditionIdea.cpp \
    TileCalculator/TileCalculatorPlugin.cpp \
    TileCalculator/TileCeilingIdea.cpp \
    TileCalculator/TileDisplayIdea.cpp \
    TileCalculator/TileDivisionIdea.cpp \
    TileCalculator/TileExponentialIdea.cpp \
    TileCalculator/TileFloorIdea.cpp \
    TileCalculator/TileInputIdea.cpp \
    TileCalculator/TileLogarithmBase10Idea.cpp \
    TileCalculator/TileLogarithmBase2Idea.cpp \
    TileCalculator/TileLogarithmBaseEIdea.cpp \
    TileCalculator/TileLogarithmBaseNIdea.cpp \
    TileCalculator/TileMultiplicationIdea.cpp \
    TileCalculator/TilePicturesAreas/AdditionVisual.cpp \
    TileCalculator/TilePicturesAreas/CeilVisual.cpp \
    TileCalculator/TilePicturesAreas/FloorVisual.cpp \
    TileCalculator/TilePicturesAreas/SubtractionVisual.cpp \
    TileCalculator/TilePowerIdea.cpp \
    TileCalculator/TilePowerOfTenIdea.cpp \
    TileCalculator/TilePowerOfTwoIdea.cpp \
    TileCalculator/TileSquareRootIdea.cpp \
    TileCalculator/TileSquaredIdea.cpp \
    TileCalculator/TileSubtractionIdea.cpp \
    Utilities/ColoredSquareIdea.cpp \
    Utilities/TextAreaIdea.cpp \
    Utilities/TextLineIdea.cpp \
    Utilities/UtilitiesPlugin.cpp

RESOURCES += \
    Calculator/CalculatorResources.qrc \
    MalamuteCore/MalamuteCoreResources.qrc \
    TileCalculator/TileCalculatorResources.qrc \
    Utilities/UtilitiesResources.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
