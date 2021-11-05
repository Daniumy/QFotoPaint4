#include "dajuste_lineal.h"
#include "ui_dajuste_lineal.h"
#include "imagenes.h"

dajuste_lineal::dajuste_lineal(int numfoto, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dajuste_lineal)
{
    ui->setupUi(this);
    nfoto = numfoto;
    ajuste_lineal(nfoto, 5, 5);
}

dajuste_lineal::~dajuste_lineal()
{
    delete ui;
}

void dajuste_lineal::on_spinBox_valueChanged(int arg1)
{
    ui->horizontalSlider->setValue(arg1);
}

void dajuste_lineal::on_spinBox_2_valueChanged(int arg1)
{
    ui->horizontalSlider_2->setValue(arg1);
}

void dajuste_lineal::on_horizontalSlider_valueChanged(int value)
{
    ui->spinBox->setValue(value);

    if (ui->spinBox->value() + ui->spinBox_2->value() > 100)
        ui->spinBox_2->setValue(100 - ui->spinBox->value());

    if (ui->checkBox->isChecked())
        ajuste_lineal(nfoto, ui->spinBox->value(), ui->spinBox_2->value());
}

void dajuste_lineal::on_horizontalSlider_2_valueChanged(int value)
{
    ui->spinBox_2->setValue(value);

    if (ui->spinBox->value() + ui->spinBox_2->value() > 100)
        ui->spinBox->setValue(100 - ui->spinBox_2->value());

    if (ui->checkBox->isChecked())
        ajuste_lineal(nfoto, ui->spinBox->value(), ui->spinBox_2->value());
}

void dajuste_lineal::on_dajuste_lineal_accepted()
{
    ajuste_lineal(nfoto, ui->spinBox->value(), ui->spinBox_2->value(), true);
}

void dajuste_lineal::on_dajuste_lineal_rejected()
{
    mostrar(nfoto);
}
