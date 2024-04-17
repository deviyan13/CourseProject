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
    qUnit = scene->height() / 15.0;

    field = new GameField(qUnit);

    connect(field, &GameField::scoreChanged, [=](){

        ui->score->setText(QString::number(field->getScore()));

    });

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
        int numberOfType = rand() % 8;

        if(numberOfType == 0)
        {
            figures.push_back(new LtypeFigure(qUnit, field, QPointF(1 * qUnit + i * 4 * qUnit, 10.5 * qUnit)));
        }
        else if(numberOfType == 1)
        {
            figures.push_back(new TtypeFigure(qUnit, field, QPointF(1 * qUnit + i * 4 * qUnit, 10.5 * qUnit)));
        }
        else if(numberOfType == 2)
        {
            figures.push_back(new Square2TypeFigure(qUnit, field, QPointF(1 * qUnit + i * 4 * qUnit, 10.5 * qUnit)));
        }
        else if(numberOfType == 3)
        {
            figures.push_back(new MiniLTypeFigure(qUnit, field, QPointF(1 * qUnit + i * 4 * qUnit, 10.5 * qUnit)));
        }
        else if(numberOfType == 4)
        {
            figures.push_back(new InverseLTypeFigure(qUnit, field, QPointF(1 * qUnit + i * 4 * qUnit, 10.5 * qUnit)));
        }
        else if(numberOfType == 5)
        {
            figures.push_back(new STypeFigure(qUnit, field, QPointF(1 * qUnit + i * 4 * qUnit, 10.5 * qUnit)));
        }
        else if(numberOfType == 6)
        {
            figures.push_back(new InverseSTypeFigure(qUnit, field, QPointF(1 * qUnit + i * 4 * qUnit, 10.5 * qUnit)));
        }
        else if(numberOfType == 7)
        {
            figures.push_back(new Stick4TypeFigure(qUnit, field, QPointF(1 * qUnit + i * 4 * qUnit, 10.5 * qUnit)));
        }


        figures.back()->setRotation((rand() % 4) * 90);
        figures.back()->UpdateCoordinatesOfSquares();

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
