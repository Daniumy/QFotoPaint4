#include "dmat_sat_lum.h"
#include "ui_dmat_sat_lum.h"
#include "imagenes.h"

dmat_sat_lum::dmat_sat_lum(int numfoto,  QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dmat_sat_lum)
{
    ui->setupUi(this);
    nfoto = numfoto;
    setMouseCallback(foto[nfoto].nombre,NULL);
}

dmat_sat_lum::~dmat_sat_lum()
{
    delete ui;
}

void dmat_sat_lum::on_horizontalSlider_valueChanged(int value)
{
    ver_mat_sat_lum(nfoto,ui->dial->value(),
                    ui->horizontalSlider->value()/100.0,
                    ui->horizontalSlider_2->value()/100.0);
}

void dmat_sat_lum::on_horizontalSlider_2_valueChanged(int value)
{
    ver_mat_sat_lum(nfoto,ui->dial->value(),
                    ui->horizontalSlider->value()/100.0,
                    ui->horizontalSlider_2->value()/100.0);
}

void dmat_sat_lum::on_dial_valueChanged(int value)
{
    ver_mat_sat_lum(nfoto,ui->dial->value(),
                    ui->horizontalSlider->value()/100.0,
                    ui->horizontalSlider_2->value()/100.0);
}

void dmat_sat_lum::on_dmat_sat_lum_accepted()
{
    ver_mat_sat_lum(nfoto,ui->dial->value(),
                    ui->horizontalSlider->value()/100.0,
                    ui->horizontalSlider_2->value()/100.0,true);
    reset_callback(nfoto);
}

void dmat_sat_lum::on_dmat_sat_lum_rejected()
{
    mostrar(nfoto);
    reset_callback(nfoto);
}
