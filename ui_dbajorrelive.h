/********************************************************************************
** Form generated from reading UI file 'dbajorrelive.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBAJORRELIVE_H
#define UI_DBAJORRELIVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_dbajorrelive
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QDial *dial;
    QLabel *label_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;

    void setupUi(QDialog *dbajorrelive)
    {
        if (dbajorrelive->objectName().isEmpty())
            dbajorrelive->setObjectName(QString::fromUtf8("dbajorrelive"));
        dbajorrelive->resize(312, 248);
        buttonBox = new QDialogButtonBox(dbajorrelive);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(60, 210, 171, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(dbajorrelive);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 271, 16));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);
        horizontalSlider = new QSlider(dbajorrelive);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(20, 40, 271, 21));
        horizontalSlider->setMinimum(0);
        horizontalSlider->setMaximum(200);
        horizontalSlider->setValue(50);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);
        horizontalSlider->setTickInterval(20);
        label_2 = new QLabel(dbajorrelive);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 70, 131, 16));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignCenter);
        dial = new QDial(dbajorrelive);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setGeometry(QRect(50, 90, 81, 91));
        dial->setMaximum(360);
        dial->setWrapping(true);
        dial->setNotchesVisible(true);
        label_3 = new QLabel(dbajorrelive);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(160, 70, 131, 16));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label_3->setAlignment(Qt::AlignCenter);
        radioButton = new QRadioButton(dbajorrelive);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(170, 100, 82, 17));
        radioButton_2 = new QRadioButton(dbajorrelive);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(170, 120, 82, 17));
        radioButton_3 = new QRadioButton(dbajorrelive);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(170, 140, 82, 17));
        radioButton_3->setChecked(true);
        radioButton_4 = new QRadioButton(dbajorrelive);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setGeometry(QRect(170, 160, 82, 17));

        retranslateUi(dbajorrelive);
        QObject::connect(buttonBox, SIGNAL(accepted()), dbajorrelive, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dbajorrelive, SLOT(reject()));

        QMetaObject::connectSlotsByName(dbajorrelive);
    } // setupUi

    void retranslateUi(QDialog *dbajorrelive)
    {
        dbajorrelive->setWindowTitle(QCoreApplication::translate("dbajorrelive", "Efecto de bajorrelieve", nullptr));
        label->setText(QCoreApplication::translate("dbajorrelive", "Grado del efecto", nullptr));
        label_2->setText(QCoreApplication::translate("dbajorrelive", "\303\201ngulo", nullptr));
        label_3->setText(QCoreApplication::translate("dbajorrelive", "Textura de fondo", nullptr));
        radioButton->setText(QCoreApplication::translate("dbajorrelive", "Arena", nullptr));
        radioButton_2->setText(QCoreApplication::translate("dbajorrelive", "Cielo", nullptr));
        radioButton_3->setText(QCoreApplication::translate("dbajorrelive", "Madera", nullptr));
        radioButton_4->setText(QCoreApplication::translate("dbajorrelive", "Gris", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dbajorrelive: public Ui_dbajorrelive {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBAJORRELIVE_H
