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
        xFromMouse = this->sceneBoundingRect().x() - event->scenePos().x();
        yFromMouse = this->sceneBoundingRect().y() - event->scenePos().y();
    }

    QGraphicsItem::mousePressEvent(event);
}

void FigureItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF newPos = QPointF(event->scenePos().x() + xFromMouse, event->scenePos().y() + yFromMouse);

    QRectF sceneRect = scene()->sceneRect();

    QRectF shapeBoundingRect = mapToScene(shape().boundingRect()).boundingRect();
    QPointF topLeftShape = shapeBoundingRect.topLeft();

    qUnit = scene()->height() / 14.0;

    QRectF newShapeRect = QRectF(newPos.x() + (shapeBoundingRect.x() - sceneBoundingRect().x()),
                               newPos.y() + (shapeBoundingRect.y() - sceneBoundingRect().y()),
                               shapeBoundingRect.width(), shapeBoundingRect.height());

    if(sceneRect.contains(newShapeRect))
    {
        setPos(newPos.x(), newPos.y());

        qreal xIndexOfSquare = round((topLeftShape.x() - 2.0 * qUnit) / qUnit);
        qreal yIndexOfSquare = round((topLeftShape.y() - 1.0 * qUnit) / qUnit);

        if(xIndexOfSquare >= 0 && xIndexOfSquare <= 9 - shapeBoundingRect.width() / (1.0 * qUnit) &&
            yIndexOfSquare >= 0 && yIndexOfSquare <= 9 - shapeBoundingRect.height() / (1.0 * qUnit))
        {
            UpdateCoordinatesOfSquares();
            getField()->setShadowForFigure(leftTopPointsOfSquares, xIndexOfSquare, yIndexOfSquare);
        }

        else
        {
            getField()->resetShadowsAndLight();
        }
    }
    else
    {
        QPointF boundedPos;
        qreal leftBorder, rightBorder, topBorder, bottomBorder;

        leftBorder = sceneRect.left() - (shapeBoundingRect.x() - sceneBoundingRect().x());
        rightBorder = sceneRect.right() - (shapeBoundingRect.width() + (shapeBoundingRect.x() - sceneBoundingRect().x()));
        topBorder = sceneRect.top() - (shapeBoundingRect.y() - sceneBoundingRect().y());
        bottomBorder = sceneRect.bottom() - (shapeBoundingRect.height() + (shapeBoundingRect.y() - sceneBoundingRect().y()));;


        boundedPos.setX(qBound(leftBorder, newPos.x(), rightBorder));
        boundedPos.setY(qBound(topBorder, newPos.y(), bottomBorder));

        this->setPos(boundedPos);

        getField()->resetShadowsAndLight();
    }

    QGraphicsItem::mouseMoveEvent(event);
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
            relasePlayer->setSource(QUrl::fromLocalFile("../../media/soundFall1.mp3"));
            relasePlayer->play();
            emit isPlaced();

            deleteLater();
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

void FigureItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        setRotation(rotation() + 90);
        UpdateCoordinatesOfSquares();
    }

    QGraphicsItem::mouseDoubleClickEvent(event);
}

void FigureItem::UpdateCoordinatesOfSquares()
{
    QRectF shapeBoundingRect = mapToScene(shape().boundingRect()).boundingRect();
    QPainterPath path = mapToScene(shape());
    path.moveTo(0,0);

    leftTopPointsOfSquares.clear();
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(path.contains(QRectF(shapeBoundingRect.x() + j * qUnit + 1, shapeBoundingRect.y() + i * qUnit + 1, qUnit - 2, qUnit - 2)))
            {
                leftTopPointsOfSquares.push_back(std::make_pair(j, i));
            }
        }
    }
}

GameField *FigureItem::getField()
{
    return this->field;
}
