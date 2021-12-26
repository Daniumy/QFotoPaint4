/********************************************************************************
** Form generated from reading UI file 'acercade.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACERCADE_H
#define UI_ACERCADE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_acercade
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QCommandLinkButton *commandLinkButton;
    QFrame *frame;

    void setupUi(QDialog *acercade)
    {
        if (acercade->objectName().isEmpty())
            acercade->setObjectName(QString::fromUtf8("acercade"));
        acercade->resize(350, 190);
        acercade->setMinimumSize(QSize(350, 190));
        acercade->setMaximumSize(QSize(350, 190));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/imagenes/logo.gif"), QSize(), QIcon::Normal, QIcon::Off);
        acercade->setWindowIcon(icon);
        label = new QLabel(acercade);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 10, 221, 41));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(acercade);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 50, 171, 31));
        QFont font1;
        font1.setPointSize(12);
        label_2->setFont(font1);
        label_3 = new QLabel(acercade);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 120, 331, 21));
        label_4 = new QLabel(acercade);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(170, 145, 141, 31));
        commandLinkButton = new QCommandLinkButton(acercade);
        commandLinkButton->setObjectName(QString::fromUtf8("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(10, 140, 91, 41));
        commandLinkButton->setAutoDefault(true);
        commandLinkButton->setDefault(false);
        frame = new QFrame(acercade);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 101, 101));
        frame->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/imagenes/logo.bmp);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        retranslateUi(acercade);

        QMetaObject::connectSlotsByName(acercade);
    } // setupUi

    void retranslateUi(QDialog *acercade)
    {
        acercade->setWindowTitle(QCoreApplication::translate("acercade", "Acerca de QFotoPaint...", nullptr));
        label->setText(QCoreApplication::translate("acercade", "QFotoPaint", nullptr));
        label_2->setText(QCoreApplication::translate("acercade", "Versi\303\263n 4.0", nullptr));
        label_3->setText(QCoreApplication::translate("acercade", "(2019) by GinesGM, D.I.S., Universidad de Murcia", nullptr));
        label_4->setText(QCoreApplication::translate("acercade", "Versi\303\263n extensible", nullptr));
        commandLinkButton->setText(QCoreApplication::translate("acercade", "Salir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class acercade: public Ui_acercade {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACERCADE_H
