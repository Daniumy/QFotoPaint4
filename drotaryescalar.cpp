#include "drotaryescalar.h"
#include "ui_drotaryescalar.h"
#include "imagenes.h"

drotaryescalar::drotaryescalar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::drotaryescalar)
{
    nfoto = foto_activa();
    ui->setupUi(this);
}

drotaryescalar::~drotaryescalar()
{
    delete ui;
}

void drotaryescalar::on_horizontalSlider_valueChanged(int value)
{
    rotar_x_angulo(nfoto,ui->horizontalSlider->value(),ui->horizontalSlider_2->value());
}

void drotaryescalar::on_horizontalSlider_2_valueChanged(int value)
{
    rotar_x_angulo(nfoto,ui->horizontalSlider->value(),ui->horizontalSlider_2->value());
}

void drotaryescalar::on_buttonBox_accepted()
{
    rotar_x_angulo(nfoto,ui->horizontalSlider->value(),ui->horizontalSlider_2->value(),true);
    reset_callback(nfoto);
}

void drotaryescalar::on_buttonBox_rejected()
{
    mostrar(nfoto);
    reset_callback(nfoto);
}


