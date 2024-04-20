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

    // Фон для graphicsView
    QRadialGradient gradient(ui->graphicsView->rect().center(), 500);
    gradient.setColorAt(0, QColor(255, 255, 255));
    gradient.setColorAt(1, QColor(147, 191, 255, 120));
    ui->graphicsView->setBackgroundBrush(QBrush(gradient));

    scene->update();
    field->resetShadowsAndLight();

    scene->addItem(field);
    ui->graphicsView->setScene(scene);

    valueOfFiguresOnTheScene = 0;
    generateThreeFigures();


    setStyleSheet("MainWindow {background-color: "
                  "qradialgradient(cx: 0.5, cy: 0.5, radius: 1, "
                  "fx: 0.5, fy: 0.5, "
                  "stop: 0 rgba(255, 255, 255, 255), stop: 1 rgba(147, 191, 255, 255)); }"



                  "QPushButton { "
                  "background: qradialgradient(cx: 0.5, cy: 0.5, radius: 0.5, "
                  "fx: 0.5, fy: 0.5, "
                  "stop: 0 rgba(180, 210, 255, 255), stop: 1 rgba(128, 178, 255, 255)); "
                  "color: white; "
                  "padding: 10px 20px; "
                  "border-radius: 20%; "
                  "} "

                  "QPushButton:hover { "
                  "background: qradialgradient(cx: 0.5, cy: 0.5, radius: 0.5, "
                  "fx: 0.5, fy: 0.5, "
                  "stop: 0 rgba(128, 178, 255, 200), stop: 1 rgba(76, 146, 255, 200)); "
                  "} "

                  "QPushButton:pressed { "
                  "background: qradialgradient(cx: 0.5, cy: 0.5, radius: 0.5, "
                  "fx: 0.5, fy: 0.5, "
                  "stop: 0 rgba(180, 210, 255, 255), stop: 1 rgba(128, 178, 255, 255)); "
                  "}"


                  );

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::generateThreeFigures()
{
    figures.clear();
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


        scene->addItem(figures.back());
        connect(figures.back(), &FigureItem::isPlaced, this, &MainWindow::oneOfFiguresWasPlaced);

        figures.back()->setRotation((rand() % 4) * 90);
        figures.back()->UpdateCoordinatesOfSquares();
    }
}

void MainWindow::oneOfFiguresWasPlaced()
{
    int countOfFiguresCannotBePlaced = 0;
    valueOfFiguresOnTheScene--;

    if(valueOfFiguresOnTheScene == 0)
    {
        generateThreeFigures();
    }

    for(int i = 0; i < figures.size(); i++)
    {
        if(!figures[i]->getIsLive())
        {
            figures.remove(i);
        }
    }

    for(int i = 0; i < figures.size(); i++)
    {
        if(!figures[i]->isCanBePlaced())
        {
            countOfFiguresCannotBePlaced++;
        }
    }

    if(valueOfFiguresOnTheScene == countOfFiguresCannotBePlaced)
        QTimer::singleShot(10, [=](){QMessageBox::information(this, "title", "you lose!");});
}

void MainWindow::on_pushButton_clicked()
{
    emit exit();
}

