#include "dbajorrelive.h"
#include "ui_dbajorrelive.h"
#include "imagenes.h"

dbajorrelive::dbajorrelive(int numfoto, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dbajorrelive)
{
    ui->setupUi(this);
    nfoto = numfoto;
    ntextura = 2;
    ver_bajorrelieve(nfoto, 0, ui->horizontalSlider->value() / 50.0,
                     ntextura);
}

dbajorrelive::~dbajorrelive()
{
    delete ui;
}

void dbajorrelive::on_horizontalSlider_valueChanged(int value)
{
    ver_bajorrelieve(nfoto, ui->dial->value(), ui->horizontalSlider->value() / 50.0,
                     ntextura);
}

void dbajorrelive::on_dial_valueChanged(int value)
{
    ver_bajorrelieve(nfoto, ui->dial->value(), ui->horizontalSlider->value() / 50.0,
                     ntextura);
}

void dbajorrelive::on_radioButton_clicked()
{
    ntextura = 0;
    ver_bajorrelieve(nfoto, ui->dial->value(), ui->horizontalSlider->value() / 50.0,
                     ntextura);
}

void dbajorrelive::on_radioButton_2_clicked()
{
    ntextura = 1;
    ver_bajorrelieve(nfoto, ui->dial->value(), ui->horizontalSlider->value() / 50.0,
                     ntextura);
}

void dbajorrelive::on_radioButton_3_clicked()
{
    ntextura = 2;
    ver_bajorrelieve(nfoto, ui->dial->value(), ui->horizontalSlider->value() / 50.0,
                     ntextura);
}

void dbajorrelive::on_radioButton_4_clicked()
{
    ntextura = 3;
    ver_bajorrelieve(nfoto, ui->dial->value(), ui->horizontalSlider->value() / 50.0,
                     ntextura);
}

void dbajorrelive::on_buttonBox_rejected()
{
    destroyWindow("Bajorrelieve");
}

void dbajorrelive::on_buttonBox_accepted()
{
    ver_bajorrelieve(nfoto, ui->dial->value(), ui->horizontalSlider->value() / 50.0,
                     ntextura, true);
    destroyWindow("Bajorrelieve");
}
