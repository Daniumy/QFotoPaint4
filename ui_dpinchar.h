/********************************************************************************
** Form generated from reading UI file 'dpinchar.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DPINCHAR_H
#define UI_DPINCHAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_dpinchar
{
public:
    QDialogButtonBox *buttonBox;
    QSlider *horizontalSlider;
    QSlider *horizontalSlider_2;
    QLabel *label_2;
    QLabel *label;

    void setupUi(QDialog *dpinchar)
    {
        if (dpinchar->objectName().isEmpty())
            dpinchar->setObjectName(QString::fromUtf8("dpinchar"));
        dpinchar->resize(323, 189);
        buttonBox = new QDialogButtonBox(dpinchar);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(60, 120, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalSlider = new QSlider(dpinchar);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(10, 30, 271, 21));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(1000);
        horizontalSlider->setValue(200);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);
        horizontalSlider->setTickInterval(20);
        horizontalSlider_2 = new QSlider(dpinchar);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(10, 80, 271, 21));
        horizontalSlider_2->setMinimum(-60);
        horizontalSlider_2->setMaximum(60);
        horizontalSlider_2->setValue(30);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_2->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_2->setTickInterval(10);
        label_2 = new QLabel(dpinchar);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 60, 271, 16));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignCenter);
        label = new QLabel(dpinchar);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 271, 16));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(dpinchar);
        QObject::connect(buttonBox, SIGNAL(accepted()), dpinchar, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dpinchar, SLOT(reject()));

        QMetaObject::connectSlotsByName(dpinchar);
    } // setupUi

    void retranslateUi(QDialog *dpinchar)
    {
        dpinchar->setWindowTitle(QCoreApplication::translate("dpinchar", "Efecto de pinchar estira", nullptr));
        label_2->setText(QCoreApplication::translate("dpinchar", "Grado del efecto", nullptr));
        label->setText(QCoreApplication::translate("dpinchar", "Radio del efecto", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dpinchar: public Ui_dpinchar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DPINCHAR_H
