#include "mainwindow.h"
#include "dialogaboutloss.h"
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


    scene->update();
    field->resetShadowsAndLight();

    scene->addItem(field);
    ui->graphicsView->setScene(scene);

    valueOfFiguresOnTheScene = 0;



    connect(field, &GameField::scoreChanged, [=](){
        ui->score->setText(QString::number(field->getScore()));
    });

    connect(field, &GameField::recordChanged, [=](){
        ui->record->setText(QString::number(field->getRecord()));

        updateRecord();
    });



    // Фон для graphicsView
    QRadialGradient gradient(ui->graphicsView->rect().center(), 500);
    gradient.setColorAt(0, QColor(255, 255, 255));
    gradient.setColorAt(1, QColor(147, 191, 255, 120));
    ui->graphicsView->setBackgroundBrush(QBrush(gradient));

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

void MainWindow::clearGame()
{
    for(int i = 0; i < figures.size(); i++)
    {
        scene->removeItem(figures[i]);
    }

    figures.clear();
    field->clear();
}

void MainWindow::updateRecord()
{
    QFile recordFile("../../files/record.txt");
    if (!recordFile.open(QIODevice::ReadWrite)) {
        throw QFileDevice::OpenError;
    }

    QTextStream inResult(&recordFile);
    QTextStream outResult(&recordFile);
    int result;
    inResult >> result;

    if(result < field->getScore())
    {
        recordFile.resize(0);
        outResult << field->getScore();
    }
}

void MainWindow::loadRecord()
{
    QFile recordFile("../../files/record.txt");
    if (!recordFile.open(QIODevice::ReadWrite)) {
        throw QFileDevice::OpenError;
    }

    QTextStream inResult(&recordFile);
    int result;
    inResult >> result;
    field->setRecord(result);

    recordFile.close();
}

void MainWindow::startNewGame()
{
    clearGame();
    field->setScore(0);

    valueOfFiguresOnTheScene = 0;
    generateThreeFigures();
    loadRecord();
}

void MainWindow::generateThreeFigures()
{
    figures.clear();
    valueOfFiguresOnTheScene = 0;

    for(int i = 0; i < 3; i++)
    {
        int numberOfType = rand() % 9;
        generateFigureWithType(numberOfType, ((rand() % 4) * 90), 1 * qUnit + i * 4 * qUnit);
    }
}

void MainWindow::generateFigureWithType(int numberOfType, int rotation, int posX)
{
    valueOfFiguresOnTheScene++;

    if(numberOfType == 0)
    {
        figures.push_back(new LtypeFigure(qUnit, field, QPointF(posX, 10.5 * qUnit)));
    }
    else if(numberOfType == 1)
    {
        figures.push_back(new TtypeFigure(qUnit, field, QPointF(posX, 10.5 * qUnit)));
    }
    else if(numberOfType == 2)
    {
        figures.push_back(new Square2TypeFigure(qUnit, field, QPointF(posX, 10.5 * qUnit)));
    }
    else if(numberOfType == 3)
    {
        figures.push_back(new MiniLTypeFigure(qUnit, field, QPointF(posX, 10.5 * qUnit)));
    }
    else if(numberOfType == 4)
    {
        figures.push_back(new InverseLTypeFigure(qUnit, field, QPointF(posX, 10.5 * qUnit)));
    }
    else if(numberOfType == 5)
    {
        figures.push_back(new STypeFigure(qUnit, field, QPointF(posX, 10.5 * qUnit)));
    }
    else if(numberOfType == 6)
    {
        figures.push_back(new InverseSTypeFigure(qUnit, field, QPointF(posX, 10.5 * qUnit)));
    }
    else if(numberOfType == 7)
    {
        figures.push_back(new Stick4TypeFigure(qUnit, field, QPointF(posX, 10.5 * qUnit)));
    }
    else if(numberOfType == 8)
    {
        figures.push_back(new BigLTypeFigure(qUnit, field, QPointF(posX, 10.5 * qUnit)));
    }

    scene->addItem(figures.back());
    connect(figures.back(), &FigureItem::isPlaced, this, &MainWindow::oneOfFiguresWasPlaced);

    figures.back()->setRotation(rotation);
    figures.back()->UpdateCoordinatesOfSquares();

    qDebug() << "added" << numberOfType << rotation << posX;

}

void MainWindow::loadGameFromFile()
{
    clearGame();

    QFile file("../../files/save.txt");
    if (!file.open(QIODevice::ReadOnly)) {
        throw QFileDevice::OpenError;
    }

    QTextStream in(&file);

    int newScore;
    in >> newScore;
    field->setScore(newScore);


    QVector<QString> stringsOfField;
    for(int i = 0; i < 9; i++)
    {
        QString stringOfField;
        in >> stringOfField;

        stringsOfField.push_back(stringOfField);
    }
    field->setFieldFullness(stringsOfField);


    valueOfFiguresOnTheScene = 0;
    figures.clear();
    int numberOfType, rotation, posX;

    while(!in.atEnd())
    {
        in >> numberOfType >> rotation >> posX;
        generateFigureWithType(numberOfType, rotation, posX);
    }

    file.close();

    loadRecord();

}

void MainWindow::loadGameIntoFile()
{
    QFile file("../../files/save.txt");
    if (!file.open(QIODevice::WriteOnly)) {
        throw QFileDevice::OpenError;
    }

    file.resize(0);
    QTextStream out(&file);

    out << field->getScore() << '\n';

    QVector<QString> arrayOfFieldFullness = field->getArrayOfFieldFullness();

    for(int i = 0; i < 9; i++)
    {
        out << arrayOfFieldFullness[i] << '\n';
    }

    for(int i = 0; i < figures.size(); i++)
    {
        if(figures[i]->getTypeOfFigure() == TypesOfFigures::type::LType)
        {
            out << 0 << ' ';
        }
        else if(figures[i]->getTypeOfFigure() == TypesOfFigures::type::TType)
        {
            out << 1 << ' ';
        }
        else if(figures[i]->getTypeOfFigure() == TypesOfFigures::type::Square2Type)
        {
            out << 2 << ' ';
        }
        else if(figures[i]->getTypeOfFigure() == TypesOfFigures::type::MiniLType)
        {
            out << 3 << ' ';
        }
        else if(figures[i]->getTypeOfFigure() == TypesOfFigures::type::InverseLType)
        {
            out << 4 << ' ';
        }
        else if(figures[i]->getTypeOfFigure() == TypesOfFigures::type::SType)
        {
            out << 5 << ' ';
        }
        else if(figures[i]->getTypeOfFigure() == TypesOfFigures::type::InverseSType)
        {
            out << 6 << ' ';
        }
        else if(figures[i]->getTypeOfFigure() == TypesOfFigures::type::Stick4Type)
        {
            out << 7 << ' ';
        }
        else if(figures[i]->getTypeOfFigure() == TypesOfFigures::type::BigLTypeFigure)
        {
            out << 8 << ' ';
        }

        out << figures[i]->rotation() << ' ' << figures[i]->pos().x();

        if(i != figures.size() - 1) out << '\n';
    }

    file.close();
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
    {
        updateRecord();
        QFile save("../../files/save.txt");
        save.resize(0);
        save.close();

        DialogAboutLoss* dialog = new DialogAboutLoss();

        connect(dialog, &DialogAboutLoss::accepted, [=](){
            emit exit();
        });

        QTimer::singleShot(100, [=](){dialog->exec();});
    }
    else loadGameIntoFile();
}

void MainWindow::on_exitButton_clicked()
{
    emit exit();
}
