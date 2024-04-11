#include "figureitem.h"
#include "qgraphicsscene.h"
#include "gamefield.h"

FigureItem::FigureItem(GameField* field, QPointF pos)
{
    this->field = field;
    this->basePos = pos;
    setPos(basePos);

    this->setZValue(1);

    this->setScale(0.9);

    setCursor(Qt::OpenHandCursor);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
}

FigureItem::~FigureItem(){}

void FigureItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setScale(1);

    if(event->button() == Qt::LeftButton)
    {
        setCursor(Qt::ClosedHandCursor);
        xFromMouse = this->scenePos().x() - event->scenePos().x();
        yFromMouse = this->scenePos().y() - event->scenePos().y();
    }

    QGraphicsItem::mousePressEvent(event);
}

void FigureItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    setCursor(Qt::OpenHandCursor);
    this->setScale(0.9);

    if(getField()->isAboveAnFigure())
    {
        deleteLater();
        this->hide();//добавить удаление фигурки!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        getField()->removeItem(this);
        getField()->fillCellsByNewFigure();

        // emit requestToDelete();
    }
    else
    {
        setPos(basePos);
    }

    QGraphicsItem::mouseReleaseEvent(event);
}

void FigureItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF newPos = QPointF(event->scenePos().x() + xFromMouse, event->scenePos().y() + yFromMouse);
    QRectF sceneRect = getField()->sceneRect();

    qUnit = getField()->height() / 14.0;

    if (sceneRect.contains(QPoint(newPos.x(), newPos.y())) &&
        sceneRect.contains(QPoint(newPos.x() + boundingRect().width(), newPos.y())) &&
        sceneRect.contains(QPoint(newPos.x() + boundingRect().width(), newPos.y() + boundingRect().height())) &&
        sceneRect.contains(QPoint(newPos.x(), newPos.y() + boundingRect().y())))
    {
        setPos(newPos.x(), newPos.y());

        QPointF currentPos = pos();
        qreal xIndexOfSquare = round((currentPos.x() - qUnit) / qUnit);
        qreal yIndexOfSquare = round((currentPos.y() - qUnit) / qUnit);

        if(xIndexOfSquare >= 0 && xIndexOfSquare <= 9 - boundingRect().width() / qUnit &&
            yIndexOfSquare >= 0 && yIndexOfSquare <= 9 - boundingRect().height() / qUnit &&
            !getField()->AreCellsFilled(getTypeOfFigure(), xIndexOfSquare, yIndexOfSquare))
        {
            if(this->getTypeOfFigure() == TypesOfFigures::type::LType)
            {
                getField()->resetColors();
                getField()->setShadowForSquare(xIndexOfSquare, yIndexOfSquare);
                getField()->setShadowForSquare(xIndexOfSquare, yIndexOfSquare + 1);
                getField()->setShadowForSquare(xIndexOfSquare, yIndexOfSquare + 2);
                getField()->setShadowForSquare(xIndexOfSquare + 1, yIndexOfSquare + 2);
            }
        }

        else
        {
            getField()->resetColors();
        }

    }
    else
    {
        QPointF boundedPos;
        qreal leftBorder, rightBorder, topBorder, bottomBorder;

        if(getTypeOfFigure() == TypesOfFigures::type::LType)
        {
            leftBorder = sceneRect.left();
            rightBorder = sceneRect.right() - 2 * qUnit;
            topBorder = sceneRect.top();
            bottomBorder = sceneRect.bottom() - 3 * qUnit;
        }

        boundedPos.setX(qBound(leftBorder, newPos.x(), rightBorder));
        boundedPos.setY(qBound(topBorder, newPos.y(), bottomBorder));
        this->setPos(boundedPos);

        getField()->resetColors();
    }

    QGraphicsItem::mouseMoveEvent(event);
}

GameField *FigureItem::getField()
{
    return this->field;
}
