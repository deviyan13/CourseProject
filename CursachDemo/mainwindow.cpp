#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    field = new GameField(ui->graphicsView);
    qreal qUnit = field->height() / 14.0;

    for(int i = 0; i < 3; i++)
    {
        figures.push_back(new LtypeFigure(qUnit, field, QPointF(0.5 * qUnit + i * 4 * qUnit, 10.5 * qUnit)));
        field->addItem(figures.back());
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
