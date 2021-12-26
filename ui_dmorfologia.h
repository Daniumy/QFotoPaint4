/********************************************************************************
** Form generated from reading UI file 'dmorfologia.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DMORFOLOGIA_H
#define UI_DMORFOLOGIA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_dmorfologia
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QSlider *horizontalSlider;
    QSlider *horizontalSlider_2;
    QSlider *horizontalSlider_3;
    QLabel *label_3;
    QSlider *horizontalSlider_4;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;

    void setupUi(QDialog *dmorfologia)
    {
        if (dmorfologia->objectName().isEmpty())
            dmorfologia->setObjectName(QString::fromUtf8("dmorfologia"));
        dmorfologia->resize(400, 300);
        buttonBox = new QDialogButtonBox(dmorfologia);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(-60, 250, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(dmorfologia);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 20, 241, 16));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(dmorfologia);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 70, 241, 16));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignCenter);
        horizontalSlider = new QSlider(dmorfologia);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(80, 40, 241, 21));
        horizontalSlider->setMinimum(0);
        horizontalSlider->setMaximum(5);
        horizontalSlider->setValue(0);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);
        horizontalSlider->setTickInterval(20);
        horizontalSlider_2 = new QSlider(dmorfologia);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(80, 100, 241, 21));
        horizontalSlider_2->setMinimum(0);
        horizontalSlider_2->setMaximum(5);
        horizontalSlider_2->setValue(0);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_2->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_2->setTickInterval(20);
        horizontalSlider_3 = new QSlider(dmorfologia);
        horizontalSlider_3->setObjectName(QString::fromUtf8("horizontalSlider_3"));
        horizontalSlider_3->setGeometry(QRect(80, 160, 241, 21));
        horizontalSlider_3->setMinimum(0);
        horizontalSlider_3->setMaximum(5);
        horizontalSlider_3->setValue(0);
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        horizontalSlider_3->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_3->setTickInterval(20);
        label_3 = new QLabel(dmorfologia);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(80, 130, 241, 16));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label_3->setAlignment(Qt::AlignCenter);
        horizontalSlider_4 = new QSlider(dmorfologia);
        horizontalSlider_4->setObjectName(QString::fromUtf8("horizontalSlider_4"));
        horizontalSlider_4->setGeometry(QRect(80, 220, 241, 21));
        horizontalSlider_4->setMinimum(0);
        horizontalSlider_4->setMaximum(5);
        horizontalSlider_4->setValue(0);
        horizontalSlider_4->setOrientation(Qt::Horizontal);
        horizontalSlider_4->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_4->setTickInterval(20);
        label_4 = new QLabel(dmorfologia);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(80, 190, 241, 16));
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(dmorfologia);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 40, 61, 16));
        label_6 = new QLabel(dmorfologia);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 100, 61, 16));
        label_7 = new QLabel(dmorfologia);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 160, 61, 16));
        label_8 = new QLabel(dmorfologia);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 220, 61, 16));

        retranslateUi(dmorfologia);
        QObject::connect(buttonBox, SIGNAL(rejected()), dmorfologia, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), dmorfologia, SLOT(accept()));

        QMetaObject::connectSlotsByName(dmorfologia);
    } // setupUi

    void retranslateUi(QDialog *dmorfologia)
    {
        dmorfologia->setWindowTitle(QCoreApplication::translate("dmorfologia", "Morfolog\303\255a matem\303\241tica", nullptr));
        label->setText(QCoreApplication::translate("dmorfologia", "Dilataci\303\263n", nullptr));
        label_2->setText(QCoreApplication::translate("dmorfologia", "Erosi\303\263n", nullptr));
        label_3->setText(QCoreApplication::translate("dmorfologia", "Cerrar", nullptr));
        label_4->setText(QCoreApplication::translate("dmorfologia", "Abrir", nullptr));
        label_5->setText(QCoreApplication::translate("dmorfologia", "Iteraciones", nullptr));
        label_6->setText(QCoreApplication::translate("dmorfologia", "Iteraciones", nullptr));
        label_7->setText(QCoreApplication::translate("dmorfologia", "Iteraciones", nullptr));
        label_8->setText(QCoreApplication::translate("dmorfologia", "Iteraciones", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dmorfologia: public Ui_dmorfologia {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DMORFOLOGIA_H
