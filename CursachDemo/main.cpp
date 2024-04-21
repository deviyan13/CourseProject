#include "dialogchoosinggamestart.h"
#include "mainmenu.h"
#include "mainwindow.h"

#include <QApplication>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    MainMenu menu;
    DialogChoosingGameStart chooseOfGameStart;


    QScreen *screen =QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int height1 = screenGeometry.height();
    int width1 = screenGeometry.width();

    w.resize(width1 / 2.0 ,height1 / 2.0);
    menu.resize(width1 / 2.0 ,height1 / 2.0);
    chooseOfGameStart.resize(width1 / 2.0 ,height1 / 2.0);

    menu.show();

    QObject::connect(&menu, &MainMenu::play, [&w, &menu, &chooseOfGameStart](){
        //w.showNormal();
        QFile file("../../files/save.txt");
        if (file.size() != 0)
        {
            chooseOfGameStart.showNormal();
            QObject::connect(&chooseOfGameStart, &DialogChoosingGameStart::continueGame, [&w, &chooseOfGameStart](){

                w.loadGameFromFile();
                w.showNormal();

                QTimer::singleShot(500, &chooseOfGameStart, &DialogChoosingGameStart::hide);

            });

            QObject::connect(&chooseOfGameStart, &DialogChoosingGameStart::restartGame, [&w, &chooseOfGameStart](){
                w.startNewGame();
                w.showNormal();

                QTimer::singleShot(500, &chooseOfGameStart, &DialogChoosingGameStart::hide);
            });
        }
        else
        {
            w.startNewGame();
            w.showNormal();
        }
        file.close();

        QTimer::singleShot(500, &menu, &MainMenu::hide);
    });

    QObject::connect(&w, &MainWindow::exit, [&w, &menu](){
        menu.showNormal();
        QTimer::singleShot(500, &w, &MainWindow::hide);

    });

    return a.exec();
}
