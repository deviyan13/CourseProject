#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "typesoffigures.h"

class GameField : public QGraphicsScene
{
public:
    GameField(QGraphicsView* view);
    void PaintField();

    void setShadowForSquare(int j, int i);
    bool AreCellsFilled(TypesOfFigures::type type, int x, int y);

    void resetColors();

    bool isAboveAnFigure();
    void fillCellsByNewFigure();

private:
    char arrayField[9][9];
    QGraphicsRectItem* arrayOfBackgroundSquares[9][9], *arrayOfSetCells[9][9];

    qreal qUnit;
};

#endif // GAMEFIELD_H
