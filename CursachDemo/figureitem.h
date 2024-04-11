#ifndef FIGUREITEM_H
#define FIGUREITEM_H

#include "gamefield.h"
#include <QGraphicsItem>
#include <QPainter>
#include <QPainterPath>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>
#include <QGraphicsScene>
#include "typesoffigures.h"

class FigureItem : public QGraphicsItem, public QObject
{    
public:

    virtual QRectF boundingRect() const override = 0;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override = 0;
    virtual QPainterPath shape() const override = 0;

    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    virtual TypesOfFigures::type getTypeOfFigure() = 0;

    GameField *getField();

    FigureItem(GameField* field, QPointF pos);
    ~FigureItem();

private:
    qreal xFromMouse, yFromMouse;

protected:
    qreal qUnit = 0;
    GameField* field;
    QPointF basePos;

signals:
    void requestToDelete();
};

#endif // FIGUREITEM_H
