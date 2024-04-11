#include "gamefield.h"

GameField::GameField(QGraphicsView *view)
{
    view->setScene(this);

    this->setSceneRect(view->rect());
    qUnit = sceneRect().height() / 14.0;

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            arrayOfBackgroundSquares[i][j] = new QGraphicsRectItem(qUnit + j * qUnit, qUnit + i * qUnit, qUnit, qUnit);
            arrayOfBackgroundSquares[i][j]->setPen(QPen(QColor(156, 156, 156), 3));

            if(((i == 3 || i == 4 || i == 5) && (j == 0 || j == 1 || j == 2)) ||
                ((i == 3 || i == 4 || i == 5) && (j == 6 || j == 7 || j == 8)) ||
                ((j == 3 || j == 4 || j == 5) && (i == 0 || i == 1 || i == 2)) ||
                ((j == 3 || j == 4 || j == 5) && (i == 6 || i == 7 || i == 8)))
                arrayOfBackgroundSquares[i][j]->setBrush(QColor(235, 235, 235));

            this->addItem(arrayOfBackgroundSquares[i][j]);
            arrayOfBackgroundSquares[i][j]->setZValue(0);
        }
    }

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            arrayField[i][j] = '.';
            arrayOfSetCells[i][j] = nullptr;
        }
    }
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
    else arrayOfBackgroundSquares[i][j]->setBrush(QColor("#B7D7FF"));

    arrayOfBackgroundSquares[i][j]->setPen(QPen(QColor("#519DFF"), 3));
}

bool GameField::AreCellsFilled(TypesOfFigures::type type, int x, int y)
{
    if(type == TypesOfFigures::type::LType)
    {
        if(arrayField[y][x] == '1') return true;
        if(arrayField[y + 1][x] == '1') return true;
        if(arrayField[y + 2][x] == '1') return true;
        if(arrayField[y + 2][x + 1] == '1') return true;

        return false;
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
                arrayField[i][j] = '1';
                arrayOfSetCells[i][j] = new QGraphicsRectItem(qUnit + j * qUnit, qUnit + i * qUnit, qUnit, qUnit);

                arrayOfSetCells[i][j]->setBrush(QColor("#4395FF"));
                arrayOfSetCells[i][j]->setPen(QPen(QColor("#0E77FF"), 3));

                addItem(arrayOfSetCells[i][j]);
                arrayOfSetCells[i][j]->setZValue(0);
            }
        }
    }

    resetColors();
}
