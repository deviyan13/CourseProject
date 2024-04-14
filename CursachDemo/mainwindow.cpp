#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(nullptr));

    scene = new QGraphicsScene(ui->graphicsView);
    scene->setSceneRect(ui->graphicsView->rect());



    qUnit = scene->height() / 14.0;

    field = new GameField(qUnit);
    scene->addItem(field);

    ui->graphicsView->setScene(scene);

    valueOfFiguresOnTheScene = 0;

    generateThreeFigures();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::generateThreeFigures()
{
    valueOfFiguresOnTheScene = 3;

    for(int i = 0; i < 3; i++)
    {
        int numberOfType = rand() % 2;

        if(numberOfType == 0)
        {
            figures.push_back(new LtypeFigure(qUnit, field, QPointF((qUnit) + 1 * qUnit + i * 4 * qUnit, 10.5 * qUnit)));
        }
        else if(numberOfType == 1)
        {
            figures.push_back(new TtypeFigure(qUnit, field, QPointF((0) + 1 * qUnit + i * 4 * qUnit, 10.5 * qUnit)));
        }

        connect(figures.back(), &FigureItem::isPlaced, this, &MainWindow::oneOfFiguresWasPlaced);


        scene->addItem(figures.back());
    }
}

void MainWindow::oneOfFiguresWasPlaced()
{
    valueOfFiguresOnTheScene--;

    if(valueOfFiguresOnTheScene == 0)
    {
        generateThreeFigures();
    }
}
