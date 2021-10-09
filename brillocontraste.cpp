#include "brillocontraste.h"
#include "ui_brillocontraste.h"

#include "imagenes.h"

brillocontraste::brillocontraste(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::brillocontraste)
{
    ui->setupUi(this);
    nfoto= foto_activa();
    suma= 0.0;
    multiplica= 1.0;
    if (parent)
        move(parent->x()+DESP_X_HIJO, parent->y()+DESP_Y_HIJO);
}

brillocontraste::~brillocontraste()
{
    delete ui;
}

void brillocontraste::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void brillocontraste::actualiza_suma_multiplica()
{
    double brillo= ui->horizontalSlider->value();
    double contraste= ui->horizontalSlider_2->value()/100.0;
    if (contraste>0) {
        multiplica= 1.0/(1.01-contraste);
        suma= multiplica*(brillo-128*contraste);
    }
    else {
        multiplica= 1.0+contraste;
        suma= multiplica*brillo-128.0*contraste;
    }
}

void brillocontraste::on_spinBox_valueChanged(int valor)
{
    ui->horizontalSlider->setValue(valor);
}

void brillocontraste::on_spinBox_2_valueChanged(int valor)
{
    ui->horizontalSlider_2->setValue(valor);
}

void brillocontraste::on_horizontalSlider_valueChanged(int value)
{
    ui->spinBox->setValue(value);
    actualiza_suma_multiplica();
    if (ui->checkBox->isChecked())
        ver_brillo_contraste(nfoto, suma, multiplica);
}

void brillocontraste::on_horizontalSlider_2_valueChanged(int value)
{
    ui->spinBox_2->setValue(value);
    actualiza_suma_multiplica();
    if (ui->checkBox->isChecked())
        ver_brillo_contraste(nfoto, suma, multiplica);
}

void brillocontraste::on_buttonBox_rejected()
{
    mostrar(nfoto);
}

void brillocontraste::on_buttonBox_accepted()
{
    actualiza_suma_multiplica();
    ver_brillo_contraste(nfoto, suma, multiplica, true);
}

void brillocontraste::on_checkBox_stateChanged(int arg1)
{
    if (arg1)
        ver_brillo_contraste(nfoto, suma, multiplica);
    else
        mostrar(nfoto);
}
