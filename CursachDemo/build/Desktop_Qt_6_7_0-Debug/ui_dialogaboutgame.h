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
        DialogAboutGame->resize(880, 450);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DialogAboutGame->sizePolicy().hasHeightForWidth());
        DialogAboutGame->setSizePolicy(sizePolicy);
        DialogAboutGame->setMinimumSize(QSize(880, 450));
        DialogAboutGame->setMaximumSize(QSize(880, 450));
        DialogAboutGame->setStyleSheet(QString::fromUtf8(""));
        buttonBox = new QDialogButtonBox(DialogAboutGame);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(320, 370, 231, 61));
        QFont font;
        font.setPointSize(32);
        buttonBox->setFont(font);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);
        label = new QLabel(DialogAboutGame);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 20, 821, 361));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Noto Serif Armenian")});
        font1.setPointSize(16);
        font1.setBold(true);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);"));
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label->setWordWrap(true);

        retranslateUi(DialogAboutGame);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DialogAboutGame, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DialogAboutGame, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DialogAboutGame);
    } // setupUi

    void retranslateUi(QDialog *DialogAboutGame)
    {
        DialogAboutGame->setWindowTitle(QCoreApplication::translate("DialogAboutGame", "About", nullptr));
        label->setText(QCoreApplication::translate("DialogAboutGame", "\320\246\320\265\320\273\321\214 \320\270\320\263\321\200\321\213 \320\262 \321\202\320\276\320\274, \321\207\321\202\320\276\320\261\321\213 \320\275\320\260\320\261\321\200\320\260\321\202\321\214 \320\274\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\265 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\276\321\207\320\272\320\276\320\262, \320\262\321\213\321\201\321\202\320\260\320\262\320\273\321\217\321\217 \321\204\320\270\320\263\321\203\321\200\321\213 \320\275\320\260 \320\277\320\276\320\273\320\265. \320\230\320\263\321\200\320\260 \320\267\320\260\320\272\320\260\320\275\321\207\320\270\320\262\320\260\320\265\321\202\321\201\321\217, \320\272\320\276\320\263\320\264\320\260 \320\275\320\260 \320\277\320\276\320\273\320\265 \320\275\320\265 \320\276\321\201\321\202\320\260\321\221\321\202\321\201\321\217 \320\274\320\265\321\201\321\202\320\260, \321\207\321\202\320\276\320\261\321\213 \320\277\320\276\321\201\321\202\320\260"
                        "\320\262\320\270\321\202\321\214 \320\276\321\207\320\265\321\200\320\265\320\264\320\275\321\203\321\216 \321\204\320\270\320\263\321\203\321\200\321\203. \320\232\320\276\320\263\320\264\320\260 \320\262\320\260\320\274 \321\203\320\264\320\260\321\221\321\202\321\201\321\217 \320\277\320\276\320\273\320\275\320\276\321\201\321\202\321\214\321\216 \320\267\320\260\320\277\320\276\320\273\320\275\320\270\321\202\321\214 \320\262\320\265\321\200\321\202\320\270\320\272\320\260\320\273\321\214\320\275\321\203\321\216/\320\263\320\276\321\200\320\270\320\267\320\276\320\275\321\202\320\260\320\273\321\214\320\275\321\203\321\216 \320\273\320\270\320\275\320\270\321\216 \320\270\320\273\320\270 \320\276\320\264\320\270\320\275 \320\270\320\267 \320\274\320\260\320\273\321\213\321\205 \320\272\320\262\320\260\320\264\321\200\320\260\321\202\320\276\320\262, \320\276\320\275\320\270 \320\276\321\201\320\262\320\276\320\261\320\276\320\266\320\264\320\260\321\216\321\202\321\201\321\217.\n"
"\n"
"\320\237\321\200\320"
                        "\270\320\274\320\265\321\207\320\260\320\275\320\270\320\265: \320\264\320\262\320\276\320\271\320\275\321\213\320\274 \320\272\320\273\320\270\320\272\320\276\320\274 \320\277\320\276 \321\204\320\270\320\263\321\203\321\200\320\265 \320\262\321\213 \320\274\320\276\320\266\320\265\321\202\320\265 \320\277\320\276\320\262\320\276\321\200\320\260\321\207\320\270\320\262\320\260\321\202\321\214 \320\265\321\221 \320\277\320\276 \321\207\320\260\321\201\320\276\320\262\320\276\320\271 \321\201\321\202\321\200\320\265\320\273\320\272\320\265 \320\275\320\260 90 \320\263\321\200\320\260\320\264\321\203\321\201\320\276\320\262.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogAboutGame: public Ui_DialogAboutGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGABOUTGAME_H
