/********************************************************************************
** Form generated from reading UI file 'dialogaboutgame.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGABOUTGAME_H
#define UI_DIALOGABOUTGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_DialogAboutGame
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *DialogAboutGame)
    {
        if (DialogAboutGame->objectName().isEmpty())
            DialogAboutGame->setObjectName("DialogAboutGame");
        DialogAboutGame->resize(869, 606);
        buttonBox = new QDialogButtonBox(DialogAboutGame);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(320, 510, 231, 61));
        QFont font;
        font.setPointSize(32);
        buttonBox->setFont(font);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);
        label = new QLabel(DialogAboutGame);
        label->setObjectName("label");
        label->setGeometry(QRect(380, 250, 201, 81));

        retranslateUi(DialogAboutGame);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DialogAboutGame, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DialogAboutGame, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DialogAboutGame);
    } // setupUi

    void retranslateUi(QDialog *DialogAboutGame)
    {
        DialogAboutGame->setWindowTitle(QCoreApplication::translate("DialogAboutGame", "About", nullptr));
        label->setText(QCoreApplication::translate("DialogAboutGame", "\321\205\321\203\320\271 \321\202\320\260\320\274 \320\277\320\273\320\260\320\262\320\260\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogAboutGame: public Ui_DialogAboutGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGABOUTGAME_H
