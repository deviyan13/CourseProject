/********************************************************************************
** Form generated from reading UI file 'dialogaboutloss.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGABOUTLOSS_H
#define UI_DIALOGABOUTLOSS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_DialogAboutLoss
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *DialogAboutLoss)
    {
        if (DialogAboutLoss->objectName().isEmpty())
            DialogAboutLoss->setObjectName("DialogAboutLoss");
        DialogAboutLoss->resize(1025, 681);
        buttonBox = new QDialogButtonBox(DialogAboutLoss);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(350, 560, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);
        label = new QLabel(DialogAboutLoss);
        label->setObjectName("label");
        label->setGeometry(QRect(150, 140, 761, 321));
        QFont font;
        font.setFamilies({QString::fromUtf8("Noto Serif Yezidi")});
        font.setPointSize(70);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(DialogAboutLoss);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DialogAboutLoss, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DialogAboutLoss, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DialogAboutLoss);
    } // setupUi

    void retranslateUi(QDialog *DialogAboutLoss)
    {
        DialogAboutLoss->setWindowTitle(QCoreApplication::translate("DialogAboutLoss", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DialogAboutLoss", "\320\222\321\213 \320\277\321\200\320\276\320\270\320\263\321\200\320\260\320\273\320\270!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogAboutLoss: public Ui_DialogAboutLoss {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGABOUTLOSS_H
