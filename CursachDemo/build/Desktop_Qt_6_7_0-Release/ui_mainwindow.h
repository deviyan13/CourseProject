/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QLabel *score;
    QLabel *labelScore;
    QPushButton *exitButton;
    QLabel *labelRecord;
    QLabel *record;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1600, 1000);
        MainWindow->setMinimumSize(QSize(1600, 1000));
        MainWindow->setMaximumSize(QSize(1600, 1000));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(390, -10, 819, 945));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        score = new QLabel(centralwidget);
        score->setObjectName("score");
        score->setGeometry(QRect(1240, 370, 331, 101));
        QFont font;
        font.setFamilies({QString::fromUtf8("Noto Kufi Arabic")});
        font.setPointSize(50);
        font.setBold(true);
        score->setFont(font);
        score->setAlignment(Qt::AlignCenter);
        labelScore = new QLabel(centralwidget);
        labelScore->setObjectName("labelScore");
        labelScore->setGeometry(QRect(1160, 290, 501, 141));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Noto Kufi Arabic")});
        font1.setPointSize(25);
        font1.setBold(true);
        labelScore->setFont(font1);
        labelScore->setAlignment(Qt::AlignCenter);
        labelScore->setWordWrap(true);
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(1260, 840, 311, 81));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("NotoSerifTamilSlanted Medium")});
        font2.setPointSize(28);
        exitButton->setFont(font2);
        labelRecord = new QLabel(centralwidget);
        labelRecord->setObjectName("labelRecord");
        labelRecord->setGeometry(QRect(1240, 30, 331, 171));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Noto Kufi Arabic")});
        font3.setPointSize(32);
        font3.setBold(true);
        labelRecord->setFont(font3);
        labelRecord->setStyleSheet(QString::fromUtf8(""));
        labelRecord->setAlignment(Qt::AlignCenter);
        labelRecord->setWordWrap(true);
        record = new QLabel(centralwidget);
        record->setObjectName("record");
        record->setGeometry(QRect(1240, 130, 331, 101));
        record->setFont(font);
        record->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1600, 22));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Game", nullptr));
        score->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labelScore->setText(QCoreApplication::translate("MainWindow", "\320\232\320\236\320\233\320\230\320\247\320\225\320\241\320\242\320\222\320\236 \320\236\320\247\320\232\320\236\320\222", nullptr));
        exitButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264 \320\262 \320\274\320\265\320\275\321\216", nullptr));
        labelRecord->setText(QCoreApplication::translate("MainWindow", "\320\240\320\225\320\232\320\236\320\240\320\224", nullptr));
        record->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
