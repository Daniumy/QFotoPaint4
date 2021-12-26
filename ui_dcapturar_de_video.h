/********************************************************************************
** Form generated from reading UI file 'dcapturar_de_video.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DCAPTURAR_DE_VIDEO_H
#define UI_DCAPTURAR_DE_VIDEO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_dcapturar_de_video
{
public:
    QDialogButtonBox *buttonBox;
    QSlider *horizontalSlider;
    QSpinBox *spinBox;
    QLabel *label;

    void setupUi(QDialog *dcapturar_de_video)
    {
        if (dcapturar_de_video->objectName().isEmpty())
            dcapturar_de_video->setObjectName(QString::fromUtf8("dcapturar_de_video"));
        dcapturar_de_video->resize(378, 119);
        buttonBox = new QDialogButtonBox(dcapturar_de_video);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(100, 80, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalSlider = new QSlider(dcapturar_de_video);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(10, 40, 271, 21));
        horizontalSlider->setMinimum(0);
        horizontalSlider->setMaximum(100);
        horizontalSlider->setValue(0);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);
        horizontalSlider->setTickInterval(20);
        spinBox = new QSpinBox(dcapturar_de_video);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(290, 20, 61, 22));
        spinBox->setMinimum(0);
        spinBox->setMaximum(100);
        spinBox->setValue(0);
        label = new QLabel(dcapturar_de_video);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 271, 16));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(dcapturar_de_video);
        QObject::connect(buttonBox, SIGNAL(accepted()), dcapturar_de_video, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dcapturar_de_video, SLOT(reject()));

        QMetaObject::connectSlotsByName(dcapturar_de_video);
    } // setupUi

    void retranslateUi(QDialog *dcapturar_de_video)
    {
        dcapturar_de_video->setWindowTitle(QCoreApplication::translate("dcapturar_de_video", "Capturar de v\303\255deo", nullptr));
        label->setText(QCoreApplication::translate("dcapturar_de_video", "Posici\303\263n en el v\303\255deo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dcapturar_de_video: public Ui_dcapturar_de_video {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DCAPTURAR_DE_VIDEO_H
