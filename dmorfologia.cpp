#include "dmorfologia.h"
#include "ui_dmorfologia.h"
#include "imagenes.h"

dmorfologia::dmorfologia(int numfoto, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dmorfologia)
{
    ui->setupUi(this);
    nfoto = numfoto;
    setMouseCallback(foto[nfoto].nombre,NULL);
}

dmorfologia::~dmorfologia()
{
    delete ui;
}


void dmorfologia::on_pushButton_clicked()
{
    morfologia_matematica(nfoto, 0,ui->horizontalSlider->value());
}

void dmorfologia::on_pushButton_2_clicked()
{
    morfologia_matematica(nfoto,1,ui->horizontalSlider_2->value());
}

void dmorfologia::on_pushButton_3_clicked()
{
    morfologia_matematica(nfoto,2,ui->horizontalSlider_3->value());
}

void dmorfologia::on_pushButton_4_clicked()
{
    morfologia_matematica(nfoto,3,ui->horizontalSlider_4->value());
}
