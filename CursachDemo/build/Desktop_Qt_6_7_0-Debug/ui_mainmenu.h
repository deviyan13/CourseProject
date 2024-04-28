/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QWidget *centralwidget;
    QLabel *title;
    QPushButton *aboutButton;
    QPushButton *exitButton;
    QPushButton *playButton;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName("MainMenu");
        MainMenu->resize(1600, 1000);
        MainMenu->setMinimumSize(QSize(1600, 1000));
        MainMenu->setMaximumSize(QSize(1600, 1000));
        MainMenu->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainMenu);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        title = new QLabel(centralwidget);
        title->setObjectName("title");
        title->setGeometry(QRect(370, 90, 821, 291));
        QFont font;
        font.setFamilies({QString::fromUtf8("Noto Serif Tibetan")});
        font.setPointSize(80);
        font.setBold(true);
        title->setFont(font);
        title->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        aboutButton = new QPushButton(centralwidget);
        aboutButton->setObjectName("aboutButton");
        aboutButton->setGeometry(QRect(530, 470, 500, 100));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(aboutButton->sizePolicy().hasHeightForWidth());
        aboutButton->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Noto Serif Yezidi")});
        font1.setPointSize(39);
        font1.setBold(true);
        font1.setItalic(false);
        aboutButton->setFont(font1);
        aboutButton->setStyleSheet(QString::fromUtf8(""));
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(530, 600, 500, 100));
        sizePolicy.setHeightForWidth(exitButton->sizePolicy().hasHeightForWidth());
        exitButton->setSizePolicy(sizePolicy);
        exitButton->setFont(font1);
        exitButton->setStyleSheet(QString::fromUtf8(""));
        playButton = new QPushButton(centralwidget);
        playButton->setObjectName("playButton");
        playButton->setGeometry(QRect(530, 340, 500, 100));
        sizePolicy.setHeightForWidth(playButton->sizePolicy().hasHeightForWidth());
        playButton->setSizePolicy(sizePolicy);
        playButton->setFont(font1);
        playButton->setStyleSheet(QString::fromUtf8(""));
        MainMenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainMenu);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1600, 22));
        MainMenu->setMenuBar(menubar);

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QMainWindow *MainMenu)
    {
        MainMenu->setWindowTitle(QCoreApplication::translate("MainMenu", "Menu", nullptr));
        title->setText(QCoreApplication::translate("MainMenu", "\320\241\321\203\320\264\320\276\320\272\321\203-\320\242\320\265\321\202\321\200\320\270\321\201", nullptr));
        aboutButton->setText(QCoreApplication::translate("MainMenu", "\320\236\320\261 \320\270\320\263\321\200\320\265", nullptr));
        exitButton->setText(QCoreApplication::translate("MainMenu", "\320\222\321\213\320\271\321\202\320\270", nullptr));
        playButton->setText(QCoreApplication::translate("MainMenu", "\320\230\320\263\321\200\320\260\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
