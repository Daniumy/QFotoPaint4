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



void dmorfologia::on_buttonBox_accepted()
{
    morfologia_matematica(nfoto,ui->horizontalSlider->value(),
                          ui->horizontalSlider_2->value(),
                          ui->horizontalSlider_3->value(),
                          ui->horizontalSlider_4->value(),true);
    reset_callback(nfoto);
}

void dmorfologia::on_buttonBox_rejected()
{
    mostrar(nfoto);
    reset_callback(nfoto);
}
