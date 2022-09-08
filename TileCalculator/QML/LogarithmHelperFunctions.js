var borderWidth
var xSpacing;
var xBoxNum;
var ySpacing;

function createBoxes(numBoxes)
{
    let boxComponent;
    let boxObject;

    let wholeBoxes = Math.floor(numBoxes);

    if(wholeBoxes <= 10)
    {
        borderWidth = 8;
        xSpacing = 80;
        xBoxNum = 5;
        ySpacing = 80;
    }
    else if(wholeBoxes <= 50)
    {
        borderWidth = 4;
        xSpacing = 40;
        xBoxNum = 10;
        ySpacing = 40;
    }
    else if(wholeBoxes <= 200)
    {
        borderWidth = 2;
        xSpacing = 20;
        xBoxNum = 20;
        ySpacing = 20;
    }
    else if (wholeBoxes <= 800)
    {
        borderWidth = 1;
        xSpacing = 10;
        xBoxNum = 40;
        ySpacing = 10;
    }
    else if (wholeBoxes <= 5000)
    {
        borderWidth = 0;
        xSpacing = 4;
        xBoxNum = 100;
        ySpacing = 4;
    }
    else if (wholeBoxes <= 20000)
    {
        borderWidth = 0;
        xSpacing = 2;
        xBoxNum = 200;
        ySpacing = 2;
    }

    let i =0;
    for(i = 0; i < wholeBoxes; i++)
    {
        boxComponent = Qt.createComponent("LogarithmBox.qml");
        boxObject = boxComponent.createObject(animationArea, {boxNumber: i+1,
                                                  borderWidth: borderWidth,
                                                  x: xSpacing*(i%xBoxNum) + 0.5, y: ySpacing*Math.floor((i/xBoxNum)) + 0.5,
                                                  width: xSpacing - 1, height: ySpacing - 1})
    }

    boxComponent = Qt.createComponent("LogarithmFractionBox.qml");
    boxObject = boxComponent.createObject(fractionRemainingAnimationArea, {
                                              borderWidth: borderWidth,
                                              x: xSpacing*(Math.floor(wholeBoxes) % xBoxNum),
                                              y: ySpacing*(Math.floor(wholeBoxes / xBoxNum)),
                                              width: xSpacing * (numBoxes % 1), height: ySpacing})
}

function clearBoxes()
{
    for(let i = 0; i < animationArea.children.length; i++)
    {
        animationArea.children[i].destroy();
    }
    removeFractionBox();
}

function remove(currentNum)
{
    for(let i = 0; i < animationArea.children.length; i++)
    {
        animationArea.children[i].maybeFadeOut(currentNum);
    }
    removeFractionBox();

    let boxComponent;
    let boxObject;

    boxComponent = Qt.createComponent("LogarithmFractionBox.qml");
    boxObject = boxComponent.createObject(fractionRemainingAnimationArea, {
                                              borderWidth: borderWidth,
                                              x: xSpacing*(Math.floor(currentNum) % xBoxNum),
                                              y: ySpacing*(Math.floor(currentNum/xBoxNum)),
                                              width: xSpacing * (currentNum % 1), height: ySpacing})
}

function removeFractionBox()
{
    for(let i = 0; i < fractionRemainingAnimationArea.children.length; i++)
    {
        fractionRemainingAnimationArea.children[i].destroy();
    }
}

function setupActionPicture(N)
{
    let boxComponent;
    let boxObject;

    let boxSize = 20;
    if(N < 3)
    {
        let i;
        //Setup top of action picture.
        for(i = 0; i < Math.floor(N); i++)
        {
            boxComponent = Qt.createComponent("LogarithmDisplayBox.qml");
            boxObject = boxComponent.createObject(topRectanglesContainer, {
                                                      borderWidth: boxSize / 10,
                                                      x: (32 - 10*N) + boxSize*i,
                                                      y: 0,
                                                      width: boxSize, height: boxSize})
        }
        if(N%1 !== 0)
        {
            boxComponent = Qt.createComponent("LogarithmDisplayBox.qml");
            boxObject = boxComponent.createObject(topRectanglesContainer, {
                                                      borderWidth: boxSize / 10,
                                                      x: (32 - 10*N) + boxSize*Math.floor(N),
                                                      y: 0,
                                                      width: boxSize*(N%1), height: boxSize})
        }
        //Setup middle action picture.
        boxComponent = Qt.createComponent("LogarithmDisplayBox.qml");
        boxObject = boxComponent.createObject(midRectanglesContainer, {
                                                  borderWidth: boxSize / 10,
                                                  x: (32 - 10*N),
                                                  y: 0,
                                                  width: boxSize, height: boxSize})
        for(i = 1; i < Math.floor(N); i++)
        {
            boxComponent = Qt.createComponent("LogarithmDisplayBox.qml");
            boxObject = boxComponent.createObject(midRectanglesContainer, {
                                                      borderWidth: boxSize / 10,
                                                      x: (32 - 10*N) + boxSize*i,
                                                      y: 0,
                                                      width: boxSize, height: boxSize})
            boxObject.setPartiallyFaded();
        }
        if(N%1 !== 0)
        {
            boxComponent = Qt.createComponent("LogarithmDisplayBox.qml");
            boxObject = boxComponent.createObject(midRectanglesContainer, {
                                                      borderWidth: boxSize / 10,
                                                      x: (32 - 10*N) + boxSize*Math.floor(N),
                                                      y: 0,
                                                      width: boxSize*(N%1), height: boxSize})
            boxObject.setPartiallyFaded();
        }
    }
    else if (N === 10)
    {
        let i;
        boxSize = 10;
        //Setup top of action picture.
        for(i = 0; i < N; i++)
        {
            boxComponent = Qt.createComponent("LogarithmDisplayBox.qml");
            boxObject = boxComponent.createObject(topRectanglesContainer, {
                                                      borderWidth: boxSize / 10,
                                                      x: 7 + boxSize * (i % 5),
                                                      y: 10 * Math.floor(i / 5.0),
                                                      width: boxSize, height: boxSize})
        }
        //Setup middle action picture.
        boxComponent = Qt.createComponent("LogarithmDisplayBox.qml");
        boxObject = boxComponent.createObject(midRectanglesContainer, {
                                                  borderWidth: boxSize / 10,
                                                  x: 7,
                                                  y: 0,
                                                  width: boxSize, height: boxSize})
        for(i = 1; i < N; i++)
        {
            boxComponent = Qt.createComponent("LogarithmDisplayBox.qml");
            boxObject = boxComponent.createObject(midRectanglesContainer, {
                                                      borderWidth: boxSize / 10,
                                                      x: 7 + boxSize * (i % 5),
                                                      y: 10 * Math.floor(i / 5.0),
                                                      width: boxSize, height: boxSize})
            boxObject.setPartiallyFaded();
        }
    }

    //Setup final box. Same most cases.
    boxComponent = Qt.createComponent("LogarithmDisplayBox.qml");
    boxObject = boxComponent.createObject(botRectanglesContainer, {
                                              borderWidth: boxSize / 10,
                                              x: 32 - boxSize/2,
                                              y: 0 + (20 - boxSize) / 2,
                                              width: boxSize, height: boxSize})
}

function clearActionPicture()
{
    let i;
    for(i = 0; i < topRectanglesContainer.children.length; i++)
        topRectanglesContainer.children[i].destroy();
    for(i = 0; i < midRectanglesContainer.children.length; i++)
        midRectanglesContainer.children[i].destroy();
    for(i = 0; i < botRectanglesContainer.children.length; i++)
        botRectanglesContainer.children[i].destroy();
}
