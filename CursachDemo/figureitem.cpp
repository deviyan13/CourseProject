#include "figureitem.h"
#include "qgraphicsscene.h"
#include "gamefield.h"

FigureItem::FigureItem(GameField* field, QPointF pos)
{
    this->field = field;
    this->startPlacePos = pos;
    setPos(startPlacePos);

    this->setZValue(1);

    relasePlayer = new QMediaPlayer();
    output = new QAudioOutput();
    relasePlayer->setAudioOutput(output);
    relasePlayer->setSource(QUrl::fromLocalFile("../../media/soundFall1.mp3"));
    output->setVolume(0.3);

    setCursor(Qt::OpenHandCursor);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
}

FigureItem::~FigureItem(){}

void FigureItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setScale(1);
    this->setZValue(2);

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
    if(event->button() == Qt::LeftButton)
    {
        setCursor(Qt::OpenHandCursor);
        this->setScale(0.9);
        this->setZValue(1);

        if(getField()->isAboveAnFigure())
        {
            relasePlayer->play();
            emit isPlaced();

            deleteLater(); //изучить, точно ли удаляется фигрука
            this->hide();
            scene()->removeItem(this);
            getField()->fillCellsByNewFigure();
        }
        else
        {
            setPos(startPlacePos);
        }
    }

    QGraphicsItem::mouseReleaseEvent(event);
}

void FigureItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF newPos = QPointF(event->scenePos().x() + xFromMouse, event->scenePos().y() + yFromMouse);
    QRectF sceneRect = scene()->sceneRect();

    qUnit = scene()->height() / 14.0;

    if (sceneRect.contains(QPoint(newPos.x(), newPos.y())) &&
        sceneRect.contains(QPoint(newPos.x() + boundingRect().width(), newPos.y())) &&
        sceneRect.contains(QPoint(newPos.x() + boundingRect().width(), newPos.y() + boundingRect().height())) &&
        sceneRect.contains(QPoint(newPos.x(), newPos.y() + boundingRect().y())))
    {
        setPos(newPos.x(), newPos.y());

        QPointF currentPos = pos();
        qreal xIndexOfSquare = round((currentPos.x() - 2 * qUnit) / qUnit);
        qreal yIndexOfSquare = round((currentPos.y() - qUnit) / qUnit);

        if(xIndexOfSquare >= 0 && xIndexOfSquare <= 9 - boundingRect().width() / qUnit &&
            yIndexOfSquare >= 0 && yIndexOfSquare <= 9 - boundingRect().height() / qUnit)
        {
            getField()->setShadowForFigure(getTypeOfFigure(), xIndexOfSquare, yIndexOfSquare);
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

        else if(getTypeOfFigure() == TypesOfFigures::type::TType)
        {
            leftBorder = sceneRect.left();
            rightBorder = sceneRect.right() - 3 * qUnit;
            topBorder = sceneRect.top();
            bottomBorder = sceneRect.bottom() - 2 * qUnit;
        }

        boundedPos.setX(qBound(leftBorder, newPos.x(), rightBorder));
        boundedPos.setY(qBound(topBorder, newPos.y(), bottomBorder));
        this->setPos(boundedPos);

        getField()->resetColors();
    }

    QGraphicsItem::mouseMoveEvent(event);
}

// void FigureItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
// {
//     if(event->button() == Qt::LeftButton)
//     {
//         setRotation(rotation() + 90);
//         update();
//     }

//     qDebug() << boundingRect();

//     QGraphicsItem::mouseDoubleClickEvent(event);
// }

GameField *FigureItem::getField()
{
    return this->field;
}
