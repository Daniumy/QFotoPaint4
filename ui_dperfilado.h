/********************************************************************************
** Form generated from reading UI file 'dperfilado.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DPERFILADO_H
#define UI_DPERFILADO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_dperfilado
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QSlider *horizontalSlider_2;

    void setupUi(QDialog *dperfilado)
    {
        if (dperfilado->objectName().isEmpty())
            dperfilado->setObjectName(QString::fromUtf8("dperfilado"));
        dperfilado->resize(400, 300);
        buttonBox = new QDialogButtonBox(dperfilado);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(100, 180, 171, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(dperfilado);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 60, 271, 16));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);
        horizontalSlider = new QSlider(dperfilado);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(60, 80, 271, 21));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(9);
        horizontalSlider->setSingleStep(2);
        horizontalSlider->setPageStep(2);
        horizontalSlider->setValue(1);
        horizontalSlider->setSliderPosition(1);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);
        horizontalSlider->setTickInterval(2);
        label_2 = new QLabel(dperfilado);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 110, 271, 16));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignCenter);
        horizontalSlider_2 = new QSlider(dperfilado);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(60, 140, 271, 21));
        horizontalSlider_2->setMinimum(0);
        horizontalSlider_2->setMaximum(100);
        horizontalSlider_2->setValue(50);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_2->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_2->setTickInterval(10);

        retranslateUi(dperfilado);
        QObject::connect(buttonBox, SIGNAL(accepted()), dperfilado, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dperfilado, SLOT(reject()));

        QMetaObject::connectSlotsByName(dperfilado);
    } // setupUi

    void retranslateUi(QDialog *dperfilado)
    {
        dperfilado->setWindowTitle(QCoreApplication::translate("dperfilado", "Ventana de perfilado", nullptr));
        label->setText(QCoreApplication::translate("dperfilado", "Radio", nullptr));
        label_2->setText(QCoreApplication::translate("dperfilado", "Porcentaje", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dperfilado: public Ui_dperfilado {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DPERFILADO_H
