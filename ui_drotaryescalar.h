/********************************************************************************
** Form generated from reading UI file 'drotaryescalar.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DROTARYESCALAR_H
#define UI_DROTARYESCALAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_drotaryescalar
{
public:
    QDialogButtonBox *buttonBox;
    QSlider *horizontalSlider;
    QLabel *label;
    QSlider *horizontalSlider_2;
    QLabel *label_2;

    void setupUi(QDialog *drotaryescalar)
    {
        if (drotaryescalar->objectName().isEmpty())
            drotaryescalar->setObjectName(QString::fromUtf8("drotaryescalar"));
        drotaryescalar->resize(400, 300);
        buttonBox = new QDialogButtonBox(drotaryescalar);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(110, 190, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalSlider = new QSlider(drotaryescalar);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(60, 70, 271, 21));
        horizontalSlider->setMinimum(-360);
        horizontalSlider->setMaximum(360);
        horizontalSlider->setValue(0);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);
        horizontalSlider->setTickInterval(10);
        label = new QLabel(drotaryescalar);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 50, 271, 16));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);
        horizontalSlider_2 = new QSlider(drotaryescalar);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(60, 140, 271, 21));
        horizontalSlider_2->setMinimum(1);
        horizontalSlider_2->setMaximum(10);
        horizontalSlider_2->setValue(1);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_2->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_2->setTickInterval(1);
        label_2 = new QLabel(drotaryescalar);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 120, 271, 16));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignCenter);

        retranslateUi(drotaryescalar);
        QObject::connect(buttonBox, SIGNAL(accepted()), drotaryescalar, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), drotaryescalar, SLOT(reject()));

        QMetaObject::connectSlotsByName(drotaryescalar);
    } // setupUi

    void retranslateUi(QDialog *drotaryescalar)
    {
        drotaryescalar->setWindowTitle(QCoreApplication::translate("drotaryescalar", "Rotar y escalar imagen", nullptr));
        label->setText(QCoreApplication::translate("drotaryescalar", "\303\201ngulo de rotaci\303\263n", nullptr));
        label_2->setText(QCoreApplication::translate("drotaryescalar", "Escala", nullptr));
    } // retranslateUi

};

namespace Ui {
    class drotaryescalar: public Ui_drotaryescalar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DROTARYESCALAR_H
