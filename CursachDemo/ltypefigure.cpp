#include "ltypefigure.h"

LtypeFigure::LtypeFigure(qreal qUnit, GameField* field, QPointF pos) : FigureItem(field, pos)
{
    this->setTransformOriginPoint(0.5 * qUnit, 1.5 * qUnit);
    this->setScale(0.9);

    this->field = field;
    this->qUnit = qUnit;
}

QRectF LtypeFigure::boundingRect() const
{
    return QRectF(0, 0, 2 * qUnit, 3 * qUnit);
}

void LtypeFigure::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(QColor("#4395FF"));
    painter->setPen(QPen(QColor("#0E77FF"), 3));


    painter->drawRect(0, 0, qUnit, qUnit);
    painter->drawRect(0, qUnit, qUnit, qUnit);
    painter->drawRect(0, 2 * qUnit, qUnit, qUnit);
    painter->drawRect(qUnit, 2 * qUnit, qUnit, qUnit);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

TypesOfFigures::type LtypeFigure::getTypeOfFigure()
{
    return TypesOfFigures::type::LType;
}

QPainterPath LtypeFigure::shape() const
{
    QPainterPath path;
    path.addRect(0, 0, qUnit, qUnit);
    path.addRect(0, qUnit, qUnit, qUnit);
    path.addRect(0, 2 * qUnit, qUnit, qUnit);
    path.addRect(qUnit, 2 * qUnit, qUnit, qUnit);

    return path;
}
