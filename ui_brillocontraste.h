/********************************************************************************
** Form generated from reading UI file 'brillocontraste.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BRILLOCONTRASTE_H
#define UI_BRILLOCONTRASTE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_brillocontraste
{
public:
    QDialogButtonBox *buttonBox;
    QSlider *horizontalSlider;
    QLabel *label;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QSlider *horizontalSlider_2;
    QLabel *label_2;
    QCheckBox *checkBox;
    QSlider *horizontalSlider_3;
    QLabel *label_3;
    QSpinBox *spinBox_3;

    void setupUi(QDialog *brillocontraste)
    {
        if (brillocontraste->objectName().isEmpty())
            brillocontraste->setObjectName(QString::fromUtf8("brillocontraste"));
        brillocontraste->setWindowModality(Qt::NonModal);
        brillocontraste->resize(358, 250);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(brillocontraste->sizePolicy().hasHeightForWidth());
        brillocontraste->setSizePolicy(sizePolicy);
        brillocontraste->setMinimumSize(QSize(358, 250));
        brillocontraste->setMaximumSize(QSize(358, 250));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/imagenes/logo.gif"), QSize(), QIcon::Normal, QIcon::Off);
        brillocontraste->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(brillocontraste);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 212, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalSlider = new QSlider(brillocontraste);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(10, 30, 271, 21));
        horizontalSlider->setMinimum(-200);
        horizontalSlider->setMaximum(200);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);
        horizontalSlider->setTickInterval(20);
        label = new QLabel(brillocontraste);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 271, 16));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);
        spinBox = new QSpinBox(brillocontraste);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(290, 10, 61, 22));
        spinBox->setMinimum(-200);
        spinBox->setMaximum(200);
        spinBox_2 = new QSpinBox(brillocontraste);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(290, 60, 61, 22));
        spinBox_2->setMinimum(-100);
        spinBox_2->setMaximum(100);
        horizontalSlider_2 = new QSlider(brillocontraste);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(10, 80, 271, 21));
        horizontalSlider_2->setMinimum(-100);
        horizontalSlider_2->setMaximum(100);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_2->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_2->setTickInterval(10);
        label_2 = new QLabel(brillocontraste);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 60, 271, 16));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignCenter);
        checkBox = new QCheckBox(brillocontraste);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(190, 220, 101, 17));
        checkBox->setChecked(true);
        horizontalSlider_3 = new QSlider(brillocontraste);
        horizontalSlider_3->setObjectName(QString::fromUtf8("horizontalSlider_3"));
        horizontalSlider_3->setGeometry(QRect(10, 130, 271, 21));
        horizontalSlider_3->setMinimum(-100);
        horizontalSlider_3->setMaximum(100);
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        horizontalSlider_3->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_3->setTickInterval(20);
        label_3 = new QLabel(brillocontraste);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 110, 271, 16));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label_3->setAlignment(Qt::AlignCenter);
        spinBox_3 = new QSpinBox(brillocontraste);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setGeometry(QRect(290, 110, 61, 22));
        spinBox_3->setMinimum(-200);
        spinBox_3->setMaximum(200);

        retranslateUi(brillocontraste);
        QObject::connect(buttonBox, SIGNAL(accepted()), brillocontraste, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), brillocontraste, SLOT(reject()));

        QMetaObject::connectSlotsByName(brillocontraste);
    } // setupUi

    void retranslateUi(QDialog *brillocontraste)
    {
        brillocontraste->setWindowTitle(QCoreApplication::translate("brillocontraste", "Brillo/contraste...", nullptr));
        label->setText(QCoreApplication::translate("brillocontraste", "Brillo", nullptr));
        label_2->setText(QCoreApplication::translate("brillocontraste", "Contraste", nullptr));
        checkBox->setText(QCoreApplication::translate("brillocontraste", "Previsualizar", nullptr));
        label_3->setText(QCoreApplication::translate("brillocontraste", "Gama", nullptr));
    } // retranslateUi

};

namespace Ui {
    class brillocontraste: public Ui_brillocontraste {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BRILLOCONTRASTE_H
