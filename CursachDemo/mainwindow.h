#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

#include "gamefield.h"
#include "ltypefigure.h"
#include "ttypefigure.h"
#include "square2typefigure.h"
#include "miniltypefigure.h"
#include "inverseltypefigure.h"
#include "stypefigure.h"
#include "inversestypefigure.h"
#include "stick4typefigure.h"
#include "bigltypefigure.h"

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

    void clearGame();
    void updateRecord();
    void loadRecord();

    void startNewGame();
    void generateThreeFigures();
    void generateFigureWithType(int numberOfType, int rotation, int posX);

    void loadGameFromFile();
    void loadGameIntoFile();

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
    void on_exitButton_clicked();
};
#endif // MAINWINDOW_H
