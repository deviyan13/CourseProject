#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

#include "gamefield.h"
#include "ltypefigure.h"
#include "ttypefigure.h"
#include "square2typefigure.h"
#include "miniltypefigure.h"
#include "inverseltypefigure.h"
#include "stypefigure.h"
#include "inversestypefigure.h"
#include "stick4typefigure.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void generateThreeFigures();

private:
    Ui::MainWindow *ui;
    GameField* field;
    QGraphicsScene* scene;

    QVector<FigureItem*> figures;
    int valueOfFiguresOnTheScene;

    qreal qUnit;

public slots:

    void oneOfFiguresWasPlaced();

signals:
    void exit();

private slots:
    void on_pushButton_clicked();
};
#endif // MAINWINDOW_H
