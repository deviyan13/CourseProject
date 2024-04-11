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
    void resetColors();

    void setShadowForSquare(int j, int i);
    bool AreCellsFilled(TypesOfFigures::type type, int x, int y);
    bool isAboveAnFigure();
    void fillCellsByNewFigure();

    void searchAndMarkAllStrikes();
    bool isStrikeInTheRow(int row);
    bool isStrikeInTheColumn(int column);
    bool isStrikeInTheSquareWithVertices(int x, int y);

    void deleteAllStrikes();

    void fillStrikedRow(int row);
    void fillStrikedColumn(int column);
    void fillStrikedSquareWithVertices(int x, int y);



private:
    char arrayOfFieldFullness[9][9];
    QGraphicsRectItem* arrayOfBackgroundSquares[9][9], *arrayOfSetCells[9][9];

    qreal qUnit;
};

#endif // GAMEFIELD_H
