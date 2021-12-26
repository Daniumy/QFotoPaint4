/********************************************************************************
** Form generated from reading UI file 'dcolorfalso.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DCOLORFALSO_H
#define UI_DCOLORFALSO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_dcolorfalso
{
public:
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;

    void setupUi(QDialog *dcolorfalso)
    {
        if (dcolorfalso->objectName().isEmpty())
            dcolorfalso->setObjectName(QString::fromUtf8("dcolorfalso"));
        dcolorfalso->resize(400, 300);
        buttonBox = new QDialogButtonBox(dcolorfalso);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(110, 240, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        pushButton = new QPushButton(dcolorfalso);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 50, 75, 23));
        label = new QLabel(dcolorfalso);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 10, 191, 16));
        pushButton_2 = new QPushButton(dcolorfalso);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(40, 80, 75, 23));
        pushButton_3 = new QPushButton(dcolorfalso);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(40, 110, 75, 23));
        pushButton_4 = new QPushButton(dcolorfalso);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(40, 140, 75, 23));
        pushButton_5 = new QPushButton(dcolorfalso);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(40, 170, 75, 23));
        pushButton_6 = new QPushButton(dcolorfalso);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(40, 200, 75, 23));
        pushButton_7 = new QPushButton(dcolorfalso);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(270, 50, 75, 23));
        pushButton_8 = new QPushButton(dcolorfalso);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(270, 80, 75, 23));
        pushButton_9 = new QPushButton(dcolorfalso);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(270, 110, 75, 23));
        pushButton_10 = new QPushButton(dcolorfalso);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(270, 140, 75, 23));
        pushButton_11 = new QPushButton(dcolorfalso);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(270, 170, 75, 23));
        pushButton_12 = new QPushButton(dcolorfalso);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setGeometry(QRect(270, 200, 75, 23));

        retranslateUi(dcolorfalso);
        QObject::connect(buttonBox, SIGNAL(accepted()), dcolorfalso, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dcolorfalso, SLOT(reject()));

        QMetaObject::connectSlotsByName(dcolorfalso);
    } // setupUi

    void retranslateUi(QDialog *dcolorfalso)
    {
        dcolorfalso->setWindowTitle(QCoreApplication::translate("dcolorfalso", "Aplicar color falso", nullptr));
        pushButton->setText(QCoreApplication::translate("dcolorfalso", "OTO\303\221O", nullptr));
        label->setText(QCoreApplication::translate("dcolorfalso", "DIFERENTES OPCIONES A APLICAR", nullptr));
        pushButton_2->setText(QCoreApplication::translate("dcolorfalso", "BONE", nullptr));
        pushButton_3->setText(QCoreApplication::translate("dcolorfalso", "JET", nullptr));
        pushButton_4->setText(QCoreApplication::translate("dcolorfalso", "INVIERNO", nullptr));
        pushButton_5->setText(QCoreApplication::translate("dcolorfalso", "ARCOIRIS", nullptr));
        pushButton_6->setText(QCoreApplication::translate("dcolorfalso", "OC\303\211ANO", nullptr));
        pushButton_7->setText(QCoreApplication::translate("dcolorfalso", "VERANO", nullptr));
        pushButton_8->setText(QCoreApplication::translate("dcolorfalso", "PRIMAVERA", nullptr));
        pushButton_9->setText(QCoreApplication::translate("dcolorfalso", "ROSA", nullptr));
        pushButton_10->setText(QCoreApplication::translate("dcolorfalso", "CALIENTE", nullptr));
        pushButton_11->setText(QCoreApplication::translate("dcolorfalso", "MAGMA", nullptr));
        pushButton_12->setText(QCoreApplication::translate("dcolorfalso", "INFERNO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dcolorfalso: public Ui_dcolorfalso {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DCOLORFALSO_H
