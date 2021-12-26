/********************************************************************************
** Form generated from reading UI file 'dialoginformation.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGINFORMATION_H
#define UI_DIALOGINFORMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_dialoginformation
{
public:
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_2;

    void setupUi(QDialog *dialoginformation)
    {
        if (dialoginformation->objectName().isEmpty())
            dialoginformation->setObjectName(QString::fromUtf8("dialoginformation"));
        dialoginformation->resize(400, 300);
        lineEdit = new QLineEdit(dialoginformation);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(0, 30, 131, 20));
        lineEdit->setReadOnly(true);
        pushButton = new QPushButton(dialoginformation);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 250, 171, 23));
        lineEdit_2 = new QLineEdit(dialoginformation);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(0, 70, 131, 20));
        lineEdit_2->setReadOnly(true);
        label = new QLabel(dialoginformation);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 30, 47, 13));
        lineEdit_3 = new QLineEdit(dialoginformation);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(0, 110, 131, 20));
        lineEdit_3->setReadOnly(true);
        lineEdit_4 = new QLineEdit(dialoginformation);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(0, 150, 131, 20));
        lineEdit_4->setReadOnly(true);
        lineEdit_5 = new QLineEdit(dialoginformation);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(0, 190, 131, 20));
        lineEdit_5->setReadOnly(true);
        label_2 = new QLabel(dialoginformation);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(180, 70, 47, 13));
        label_3 = new QLabel(dialoginformation);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(180, 110, 47, 13));
        label_4 = new QLabel(dialoginformation);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(180, 150, 47, 13));
        pushButton_2 = new QPushButton(dialoginformation);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(180, 190, 51, 21));

        retranslateUi(dialoginformation);

        QMetaObject::connectSlotsByName(dialoginformation);
    } // setupUi

    void retranslateUi(QDialog *dialoginformation)
    {
        dialoginformation->setWindowTitle(QCoreApplication::translate("dialoginformation", "Ver informaci\303\263n", nullptr));
        lineEdit->setText(QCoreApplication::translate("dialoginformation", "Tama\303\261o de la imagen:", nullptr));
        pushButton->setText(QCoreApplication::translate("dialoginformation", "Ver informaci\303\263n de la imagen", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("dialoginformation", "Profundidad de la imagen:", nullptr));
        label->setText(QCoreApplication::translate("dialoginformation", "?", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("dialoginformation", "N\303\272mero de canales:", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("dialoginformation", "Memoria ocupada, bytes:", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("dialoginformation", "Color medio de la imagen:", nullptr));
        label_2->setText(QCoreApplication::translate("dialoginformation", "?", nullptr));
        label_3->setText(QCoreApplication::translate("dialoginformation", "?", nullptr));
        label_4->setText(QCoreApplication::translate("dialoginformation", "?", nullptr));
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class dialoginformation: public Ui_dialoginformation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGINFORMATION_H
