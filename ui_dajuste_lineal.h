/********************************************************************************
** Form generated from reading UI file 'dajuste_lineal.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DAJUSTE_LINEAL_H
#define UI_DAJUSTE_LINEAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_dajuste_lineal
{
public:
    QDialogButtonBox *buttonBox;
    QSlider *horizontalSlider;
    QSpinBox *spinBox_2;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *spinBox;
    QSlider *horizontalSlider_2;
    QCheckBox *checkBox;

    void setupUi(QDialog *dajuste_lineal)
    {
        if (dajuste_lineal->objectName().isEmpty())
            dajuste_lineal->setObjectName(QString::fromUtf8("dajuste_lineal"));
        dajuste_lineal->resize(378, 174);
        buttonBox = new QDialogButtonBox(dajuste_lineal);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(-170, 140, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalSlider = new QSlider(dajuste_lineal);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(10, 50, 271, 21));
        horizontalSlider->setMinimum(0);
        horizontalSlider->setMaximum(100);
        horizontalSlider->setValue(5);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);
        horizontalSlider->setTickInterval(20);
        spinBox_2 = new QSpinBox(dajuste_lineal);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(290, 80, 61, 22));
        spinBox_2->setMinimum(0);
        spinBox_2->setMaximum(100);
        spinBox_2->setValue(5);
        label = new QLabel(dajuste_lineal);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 271, 16));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(dajuste_lineal);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 80, 271, 16));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignCenter);
        spinBox = new QSpinBox(dajuste_lineal);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(290, 30, 61, 22));
        spinBox->setMinimum(0);
        spinBox->setMaximum(100);
        spinBox->setValue(5);
        horizontalSlider_2 = new QSlider(dajuste_lineal);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(10, 100, 271, 21));
        horizontalSlider_2->setMinimum(0);
        horizontalSlider_2->setMaximum(100);
        horizontalSlider_2->setValue(5);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_2->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_2->setTickInterval(10);
        checkBox = new QCheckBox(dajuste_lineal);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(220, 150, 101, 17));
        checkBox->setChecked(true);

        retranslateUi(dajuste_lineal);
        QObject::connect(buttonBox, SIGNAL(accepted()), dajuste_lineal, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dajuste_lineal, SLOT(reject()));

        QMetaObject::connectSlotsByName(dajuste_lineal);
    } // setupUi

    void retranslateUi(QDialog *dajuste_lineal)
    {
        dajuste_lineal->setWindowTitle(QCoreApplication::translate("dajuste_lineal", "Ajuste lineal dle histograma", nullptr));
        label->setText(QCoreApplication::translate("dajuste_lineal", "Percentil m\303\255nimo", nullptr));
        label_2->setText(QCoreApplication::translate("dajuste_lineal", "Percentil m\303\241ximo", nullptr));
        checkBox->setText(QCoreApplication::translate("dajuste_lineal", "Previsualizar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dajuste_lineal: public Ui_dajuste_lineal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DAJUSTE_LINEAL_H
