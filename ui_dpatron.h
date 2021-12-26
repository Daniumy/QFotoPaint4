/********************************************************************************
** Form generated from reading UI file 'dpatron.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DPATRON_H
#define UI_DPATRON_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_dpatron
{
public:
    QToolButton *toolButton;
    QLabel *label;

    void setupUi(QDialog *dpatron)
    {
        if (dpatron->objectName().isEmpty())
            dpatron->setObjectName(QString::fromUtf8("dpatron"));
        dpatron->resize(331, 194);
        toolButton = new QToolButton(dpatron);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(130, 90, 71, 51));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/imagenes/abrir.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(32, 32));
        toolButton->setAutoRaise(true);
        label = new QLabel(dpatron);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 60, 191, 16));

        retranslateUi(dpatron);

        QMetaObject::connectSlotsByName(dpatron);
    } // setupUi

    void retranslateUi(QDialog *dpatron)
    {
        dpatron->setWindowTitle(QCoreApplication::translate("dpatron", "Buscar patr\303\263n", nullptr));
        toolButton->setText(QCoreApplication::translate("dpatron", "...", nullptr));
        label->setText(QCoreApplication::translate("dpatron", "Selecciona aqu\303\255 la imagen patr\303\263n", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dpatron: public Ui_dpatron {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DPATRON_H
