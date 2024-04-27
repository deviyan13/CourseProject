/********************************************************************************
** Form generated from reading UI file 'dialogchoosinggamestart.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCHOOSINGGAMESTART_H
#define UI_DIALOGCHOOSINGGAMESTART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogChoosingGameStart
{
public:
    QWidget *centralwidget;
    QPushButton *continueButton;
    QPushButton *newGameButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DialogChoosingGameStart)
    {
        if (DialogChoosingGameStart->objectName().isEmpty())
            DialogChoosingGameStart->setObjectName("DialogChoosingGameStart");
        DialogChoosingGameStart->resize(1600, 1000);
        DialogChoosingGameStart->setMinimumSize(QSize(1600, 1000));
        DialogChoosingGameStart->setMaximumSize(QSize(1600, 1000));
        centralwidget = new QWidget(DialogChoosingGameStart);
        centralwidget->setObjectName("centralwidget");
        continueButton = new QPushButton(centralwidget);
        continueButton->setObjectName("continueButton");
        continueButton->setGeometry(QRect(280, 270, 500, 400));
        QFont font;
        font.setFamilies({QString::fromUtf8("Noto Serif Yezidi")});
        font.setPointSize(34);
        font.setBold(true);
        continueButton->setFont(font);
        newGameButton = new QPushButton(centralwidget);
        newGameButton->setObjectName("newGameButton");
        newGameButton->setGeometry(QRect(840, 270, 500, 400));
        newGameButton->setFont(font);
        DialogChoosingGameStart->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DialogChoosingGameStart);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1600, 22));
        DialogChoosingGameStart->setMenuBar(menubar);
        statusbar = new QStatusBar(DialogChoosingGameStart);
        statusbar->setObjectName("statusbar");
        DialogChoosingGameStart->setStatusBar(statusbar);

        retranslateUi(DialogChoosingGameStart);

        QMetaObject::connectSlotsByName(DialogChoosingGameStart);
    } // setupUi

    void retranslateUi(QMainWindow *DialogChoosingGameStart)
    {
        DialogChoosingGameStart->setWindowTitle(QCoreApplication::translate("DialogChoosingGameStart", "MainWindow", nullptr));
        continueButton->setText(QCoreApplication::translate("DialogChoosingGameStart", "\320\237\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\321\214 \320\270\320\263\321\200\321\203", nullptr));
        newGameButton->setText(QCoreApplication::translate("DialogChoosingGameStart", "\320\235\320\276\320\262\320\260\321\217 \320\270\320\263\321\200\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogChoosingGameStart: public Ui_DialogChoosingGameStart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCHOOSINGGAMESTART_H
