#include "dpinchar.h"
#include "ui_dpinchar.h"
#include "imagenes.h"
int nfoto;
int cx, cy;
double radio;
double grado;

void cb_pinchar (int evento,int x, int y, int flags, void *pt)
{
    if (flags==EVENT_FLAG_LBUTTON) {
        cx = x;
        cy = y;
        ver_pinchar_estirar(nfoto,cx,cy,radio,grado);
    }

}
dpinchar::dpinchar(int numfoto, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dpinchar)
{
    ui->setupUi(this);
    nfoto = numfoto;
    cx = foto[nfoto].img.cols/2;
    cy = foto[nfoto].img.rows/2;
    radio = ui->horizontalSlider->value();
    grado = ui->horizontalSlider_2->value()/1000.0;
    ver_pinchar_estirar(nfoto,cx,cy,radio,grado);
    setMouseCallback("Pinchar/estirar", cb_pinchar);

}

dpinchar::~dpinchar()
{
    delete ui;
}

void dpinchar::on_horizontalSlider_valueChanged(int value)
{
    radio = value;
    ver_pinchar_estirar(nfoto,cx,cy,radio,grado);
}

void dpinchar::on_horizontalSlider_2_valueChanged(int value)
{
    grado = value/1000.0;
    ver_pinchar_estirar(nfoto,cx,cy,radio,grado);
}

void dpinchar::on_buttonBox_accepted()
{
    ver_pinchar_estirar(nfoto,cx,cy,radio,grado,true);
    destroyWindow("Pinchar/estirar");
    mostrar(nfoto);
}

void dpinchar::on_buttonBox_rejected()
{
    destroyWindow("Pinchar/estirar");
}
