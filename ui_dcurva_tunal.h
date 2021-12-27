/********************************************************************************
** Form generated from reading UI file 'dcurva_tunal.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DCURVA_TUNAL_H
#define UI_DCURVA_TUNAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_dcurva_tunal
{
public:
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QCheckBox *checkBox;

    void setupUi(QDialog *dcurva_tunal)
    {
        if (dcurva_tunal->objectName().isEmpty())
            dcurva_tunal->setObjectName(QString::fromUtf8("dcurva_tunal"));
        dcurva_tunal->resize(400, 161);
        buttonBox = new QDialogButtonBox(dcurva_tunal);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(120, 110, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        pushButton = new QPushButton(dcurva_tunal);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 30, 91, 23));
        pushButton_2 = new QPushButton(dcurva_tunal);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(250, 30, 91, 23));
        pushButton_3 = new QPushButton(dcurva_tunal);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(40, 70, 91, 23));
        checkBox = new QCheckBox(dcurva_tunal);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(290, 120, 70, 17));
        checkBox->setChecked(true);

        retranslateUi(dcurva_tunal);
        QObject::connect(buttonBox, SIGNAL(accepted()), dcurva_tunal, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dcurva_tunal, SLOT(reject()));

        QMetaObject::connectSlotsByName(dcurva_tunal);
    } // setupUi

    void retranslateUi(QDialog *dcurva_tunal)
    {
        dcurva_tunal->setWindowTitle(QCoreApplication::translate("dcurva_tunal", "Transformaci\303\263n de curva tonal", nullptr));
        pushButton->setText(QCoreApplication::translate("dcurva_tunal", "Identidad", nullptr));
        pushButton_2->setText(QCoreApplication::translate("dcurva_tunal", "Inversa", nullptr));
        pushButton_3->setText(QCoreApplication::translate("dcurva_tunal", "Diente de sierra", nullptr));
        checkBox->setText(QCoreApplication::translate("dcurva_tunal", "Previsualizar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dcurva_tunal: public Ui_dcurva_tunal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DCURVA_TUNAL_H
