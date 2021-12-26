/********************************************************************************
** Form generated from reading UI file 'dmat_sat_lum.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DMAT_SAT_LUM_H
#define UI_DMAT_SAT_LUM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_dmat_sat_lum
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_2;
    QSlider *horizontalSlider;
    QLabel *label;
    QSlider *horizontalSlider_2;
    QLabel *label_3;
    QDial *dial;

    void setupUi(QDialog *dmat_sat_lum)
    {
        if (dmat_sat_lum->objectName().isEmpty())
            dmat_sat_lum->setObjectName(QString::fromUtf8("dmat_sat_lum"));
        dmat_sat_lum->resize(400, 279);
        buttonBox = new QDialogButtonBox(dmat_sat_lum);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(60, 220, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_2 = new QLabel(dmat_sat_lum);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 60, 271, 16));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignCenter);
        horizontalSlider = new QSlider(dmat_sat_lum);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(10, 30, 271, 21));
        horizontalSlider->setMinimum(0);
        horizontalSlider->setMaximum(300);
        horizontalSlider->setValue(100);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);
        horizontalSlider->setTickInterval(20);
        label = new QLabel(dmat_sat_lum);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 271, 16));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);
        horizontalSlider_2 = new QSlider(dmat_sat_lum);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(10, 90, 271, 21));
        horizontalSlider_2->setMinimum(0);
        horizontalSlider_2->setMaximum(300);
        horizontalSlider_2->setValue(100);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_2->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_2->setTickInterval(20);
        label_3 = new QLabel(dmat_sat_lum);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 120, 271, 16));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label_3->setAlignment(Qt::AlignCenter);
        dial = new QDial(dmat_sat_lum);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setGeometry(QRect(110, 140, 61, 71));
        dial->setMaximum(255);
        dial->setWrapping(true);
        dial->setNotchesVisible(true);

        retranslateUi(dmat_sat_lum);
        QObject::connect(buttonBox, SIGNAL(accepted()), dmat_sat_lum, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dmat_sat_lum, SLOT(reject()));

        QMetaObject::connectSlotsByName(dmat_sat_lum);
    } // setupUi

    void retranslateUi(QDialog *dmat_sat_lum)
    {
        dmat_sat_lum->setWindowTitle(QCoreApplication::translate("dmat_sat_lum", "Ajuste de matiz/saturaci\303\263n/luminosidad", nullptr));
        label_2->setText(QCoreApplication::translate("dmat_sat_lum", "Luminosidad", nullptr));
        label->setText(QCoreApplication::translate("dmat_sat_lum", "Saturaci\303\263n", nullptr));
        label_3->setText(QCoreApplication::translate("dmat_sat_lum", "Matiz", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dmat_sat_lum: public Ui_dmat_sat_lum {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DMAT_SAT_LUM_H
