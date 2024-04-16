#include "gamefield.h"

GameField::GameField(qreal qUnit)
{
    this->qUnit = qUnit;

    deletingPlayer = new QMediaPlayer();
    output = new QAudioOutput();
    deletingPlayer->setAudioOutput(output);
    deletingPlayer->setSource(QUrl::fromLocalFile("../../media/chpok-nays.wav"));
    output->setVolume(0.5);

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            arrayOfBackgroundSquares[i][j] = new QGraphicsRectItem(2 * qUnit + j * qUnit, qUnit + i * qUnit, qUnit, qUnit);
            arrayOfBackgroundSquares[i][j]->setPen(QPen(QColor(156, 156, 156), 3));

            if(((i == 3 || i == 4 || i == 5) && (j == 0 || j == 1 || j == 2)) ||
                ((i == 3 || i == 4 || i == 5) && (j == 6 || j == 7 || j == 8)) ||
                ((j == 3 || j == 4 || j == 5) && (i == 0 || i == 1 || i == 2)) ||
                ((j == 3 || j == 4 || j == 5) && (i == 6 || i == 7 || i == 8)))
                arrayOfBackgroundSquares[i][j]->setBrush(QColor(235, 235, 235));

            this->addToGroup(arrayOfBackgroundSquares[i][j]);
            arrayOfBackgroundSquares[i][j]->setZValue(0);
        }
    }

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            arrayOfFieldFullness[i][j] = '.';
            arrayOfSetCells[i][j] = nullptr;
        }
    }
}

QRectF GameField::boundingRect() const
{
    return scene()->sceneRect();
}

void GameField::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void GameField::setShadowForSquare(int j, int i)
{
    if(((i == 3 || i == 4 || i == 5) && (j == 0 || j == 1 || j == 2)) ||
        ((i == 3 || i == 4 || i == 5) && (j == 6 || j == 7 || j == 8)) ||
        ((j == 3 || j == 4 || j == 5) && (i == 0 || i == 1 || i == 2)) ||
        ((j == 3 || j == 4 || j == 5) && (i == 6 || i == 7 || i == 8)))
    {
        arrayOfBackgroundSquares[i][j]->setBrush(QColor("#97C4FF"));
    }
    else
    {
        arrayOfBackgroundSquares[i][j]->setBrush(QColor("#B7D7FF"));
    }

    arrayOfBackgroundSquares[i][j]->setPen(QPen(QColor("#519DFF"), 3));
}

void GameField::setShadowForFigure(QVector<std::pair<int, int>> coordinatesOfSquares, int x, int y)
{
    resetColors();

    if(!AreCellsFilled(coordinatesOfSquares, x, y))
    {
        for(int i = 0; i < coordinatesOfSquares.size(); i++)
        {
            setShadowForSquare(x + coordinatesOfSquares[i].first, y + coordinatesOfSquares[i].second);
        }
    }
}

bool GameField::AreCellsFilled(QVector<std::pair<int, int>> coordinatesOfSquares, int x, int y)
{
    for(int i = 0; i < coordinatesOfSquares.size(); i++)
    {
        if(arrayOfFieldFullness[y + coordinatesOfSquares[i].second][x + coordinatesOfSquares[i].first] != '.') return true;
    }

    return false;
}

void GameField::searchAndMarkAllStrikes()
{
    bool areStrikesFound = false;

    for(int i = 0; i < 9; i++)
    {
        if(isStrikeInTheRow(i))
        {
            fillStrikedRow(i);
            areStrikesFound = true;
        }

        if(isStrikeInTheColumn(i))
        {
            fillStrikedColumn(i);
            areStrikesFound = true;
        }
    }

    for(int i = 0; i < 9; i += 3)
    {
        for(int j = 0; j < 9; j += 3)
        {
            if(isStrikeInTheSquareWithVertices(j, i))
            {
                fillStrikedSquareWithVertices(j, i);
                areStrikesFound = true;
            }
        }
    }

    if(areStrikesFound) deleteAllStrikes();
}

bool GameField::isStrikeInTheRow(int row)
{
    for(int j = 0; j < 9; j++)
    {
        if(arrayOfFieldFullness[row][j] == '.') return false;
    }

    return true;
}

bool GameField::isStrikeInTheColumn(int column)
{
    for(int i = 0; i < 9; i++)
    {
        if(arrayOfFieldFullness[i][column] == '.') return false;
    }

    return true;
}

bool GameField::isStrikeInTheSquareWithVertices(int x, int y)
{
    for(int i = x; i < x + 3; i++)
    {
        for(int j = y; j < y + 3; j++)
        {
            if(arrayOfFieldFullness[i][j] == '.') return false;
        }
    }

    return true;
}

void GameField::deleteAllStrikes()
{
    QTimer* deleting = new QTimer();

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(arrayOfFieldFullness[i][j] == '-')
            {
                connect(deleting, &QTimer::timeout, [=](){
                    arrayOfSetCells[i][j]->setScale(arrayOfSetCells[i][j]->scale() - 0.1);

                    if(arrayOfSetCells[i][j]->scale() < 0.1)
                    {
                        deleting->stop();
                        removeFromGroup(arrayOfSetCells[i][j]);
                        //scene()->removeItem(arrayOfSetCells[i][j]);
                        delete arrayOfSetCells[i][j];
                        arrayOfSetCells[i][j] = nullptr;
                    }
                });

                arrayOfFieldFullness[i][j] = '.';
            }
        }
    }

    deleting->start(20);
    deletingPlayer->play();
}

void GameField::fillStrikedRow(int row)
{
    for(int j = 0; j < 9; j++)
    {
        arrayOfFieldFullness[row][j] = '-';
    }
}

void GameField::fillStrikedColumn(int column)
{
    for(int i = 0; i < 9; i++)
    {
        arrayOfFieldFullness[i][column] = '-';
    }
}

void GameField::fillStrikedSquareWithVertices(int x, int y)
{
    for(int i = x; i < x + 3; i++)
    {
        for(int j = y; j < y + 3; j++)
        {
            arrayOfFieldFullness[i][j] = '-';
        }
    }
}

void GameField::resetColors()
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            arrayOfBackgroundSquares[i][j]->setPen(QPen(QColor(156, 156, 156), 3));
            arrayOfBackgroundSquares[i][j]->setBrush(Qt::white);

            if(((i == 3 || i == 4 || i == 5) && (j == 0 || j == 1 || j == 2)) ||
                ((i == 3 || i == 4 || i == 5) && (j == 6 || j == 7 || j == 8)) ||
                ((j == 3 || j == 4 || j == 5) && (i == 0 || i == 1 || i == 2)) ||
                ((j == 3 || j == 4 || j == 5) && (i == 6 || i == 7 || i == 8)))
            {
                arrayOfBackgroundSquares[i][j]->setBrush(QColor(235, 235, 235));
            }
        }
    }
}

bool GameField::isAboveAnFigure()
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(arrayOfBackgroundSquares[i][j]->brush().color() == "#97C4FF" || arrayOfBackgroundSquares[i][j]->brush().color() == "#B7D7FF")
            {
                return true;
            }
        }
    }

    return false;
}

void GameField::fillCellsByNewFigure()
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(arrayOfBackgroundSquares[i][j]->brush().color() == "#97C4FF" || arrayOfBackgroundSquares[i][j]->brush().color() == "#B7D7FF")
            {
                arrayOfFieldFullness[i][j] = '1';
                // arrayOfSetCells[i][j] = new QGraphicsRectItem(2 * qUnit + j * qUnit, qUnit + i * qUnit, qUnit, qUnit);
                arrayOfSetCells[i][j] = new QGraphicsRectItem(0, 0, qUnit, qUnit);
                arrayOfSetCells[i][j]->setPos(2 * qUnit + j * qUnit, qUnit + i * qUnit);

                arrayOfSetCells[i][j]->setTransformOriginPoint(qUnit / 2.0, qUnit / 2.0);
                arrayOfSetCells[i][j]->setBrush(QColor("#4395FF"));
                arrayOfSetCells[i][j]->setPen(QPen(QColor("#0E77FF"), 3));


                addToGroup(arrayOfSetCells[i][j]);
                arrayOfSetCells[i][j]->setZValue(0);
            }
        }
    }

    searchAndMarkAllStrikes();

    resetColors();
}
