/********************************************************************************
** Form generated from reading UI file 'dperspectiva.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DPERSPECTIVA_H
#define UI_DPERSPECTIVA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_dperspectiva
{
public:
    QDialogButtonBox *buttonBox;
    QListWidget *listWidget;
    QListWidget *listWidget_2;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *dperspectiva)
    {
        if (dperspectiva->objectName().isEmpty())
            dperspectiva->setObjectName(QString::fromUtf8("dperspectiva"));
        dperspectiva->setEnabled(true);
        dperspectiva->resize(638, 377);
        buttonBox = new QDialogButtonBox(dperspectiva);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(216, 310, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        listWidget = new QListWidget(dperspectiva);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(50, 100, 256, 192));
        listWidget_2 = new QListWidget(dperspectiva);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setGeometry(QRect(300, 100, 256, 192));
        label_2 = new QLabel(dperspectiva);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 80, 251, 20));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(127, 127, 127);\n"
"color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(dperspectiva);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(300, 80, 251, 20));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(127, 127, 127);\n"
"color: rgb(255, 255, 255);"));
        label_3->setAlignment(Qt::AlignCenter);

        retranslateUi(dperspectiva);
        QObject::connect(buttonBox, SIGNAL(accepted()), dperspectiva, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dperspectiva, SLOT(reject()));

        QMetaObject::connectSlotsByName(dperspectiva);
    } // setupUi

    void retranslateUi(QDialog *dperspectiva)
    {
        dperspectiva->setWindowTitle(QCoreApplication::translate("dperspectiva", "Trnasformaci\303\263n perspectiva", nullptr));
        label_2->setText(QCoreApplication::translate("dperspectiva", "Imagen de origen", nullptr));
        label_3->setText(QCoreApplication::translate("dperspectiva", "Imagen de destino", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dperspectiva: public Ui_dperspectiva {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DPERSPECTIVA_H
