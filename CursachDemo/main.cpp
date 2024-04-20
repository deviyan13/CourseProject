#include "mainmenu.h"
#include "mainwindow.h"

#include <QApplication>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    MainMenu menu;


    QScreen *screen =QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int height1 = screenGeometry.height();
    int width1 = screenGeometry.width();

    w.resize(width1 / 2.0 ,height1 / 2.0);
    menu.resize(width1 / 2.0 ,height1 / 2.0);
    menu.show();

    QObject::connect(&menu, &MainMenu::play, [&w, &menu](){
        w.showNormal();
        menu.hide();

    });

    QObject::connect(&w, &MainWindow::exit, [&w, &menu](){
        menu.showNormal();
        w.hide();

    });

    return a.exec();
}
