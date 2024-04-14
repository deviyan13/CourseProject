#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QTimer>
#include "typesoffigures.h"
#include <QEventLoop>
#include <QMediaPlayer>
#include <QAudioOutput>

class GameField : public QObject, public QGraphicsItemGroup
{
    Q_OBJECT

public:
    GameField(qreal qUnit);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;



    void resetColors();

    void setShadowForSquare(int j, int i);
    void setShadowForFigure(TypesOfFigures::type type, int x, int y);

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

    QMediaPlayer* deletingPlayer;
    QAudioOutput* output;
};

#endif // GAMEFIELD_H
