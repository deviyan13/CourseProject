#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    field = new GameField(ui->graphicsView);

    LtypeFigure* testFigure = new LtypeFigure(field->height() / 14.0, field);

    for(int i = 0; i < 3; i++)
    {
        field->addItem(new LtypeFigure(field->height() / 14.0, field));
        field->items()[i]->setPos(i * 70, field->height() + 1 - 210);
    }

    testFigure->setPos(0, field->height() + 1 - 210);

    //field->addItem(testFigure);
}

MainWindow::~MainWindow()
{
    delete ui;
}
