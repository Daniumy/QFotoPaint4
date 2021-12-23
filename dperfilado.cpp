#include "dperfilado.h"
#include "ui_dperfilado.h"
#include "imagenes.h"
dperfilado::dperfilado(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dperfilado)
{
    ui->setupUi(this);
}

dperfilado::~dperfilado()
{
    delete ui;
}

void dperfilado::on_horizontalSlider_valueChanged(int value)
{
    perfilar(foto_activa(),ui->horizontalSlider->value(),ui->horizontalSlider_2->value()/100.0);
}

void dperfilado::on_horizontalSlider_2_valueChanged(int value)
{
    perfilar(foto_activa(),ui->horizontalSlider->value(),ui->horizontalSlider_2->value()/100.0);
}

void dperfilado::on_buttonBox_accepted()
{
    perfilar(foto_activa(),ui->horizontalSlider->value(),ui->horizontalSlider_2->value()/100.0,true);
    reset_callback(foto_activa());
}

void dperfilado::on_buttonBox_rejected()
{
    mostrar(foto_activa());
    reset_callback(foto_activa());
}
