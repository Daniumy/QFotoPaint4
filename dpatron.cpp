#include "dpatron.h"
#include "ui_dpatron.h"
#include "imagenes.h"
#include <QFileDialog>
#include "mainwindow.h"

dpatron::dpatron(int numfoto, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dpatron)
{
    nfoto = numfoto;
    padre = parent;
    ui->setupUi(this);
}
int abrir_imagen(QWidget * padre){

    int pl= primera_libre();
    if (pl!=-1) {
        QString nombre= QFileDialog::getOpenFileName(padre ,"Abrir imagen", ".",FiltroImagen);
        if (!nombre.isEmpty())
            crear_nueva(pl, nombre.toUtf8().data());
    }
    return pl;
}
dpatron::~dpatron()
{
    delete ui;
}

void dpatron::on_toolButton_clicked()
{
    int nres = abrir_imagen(padre);
    if (nres != -1)
    {
        buscar_patron(nfoto,nres);
    }
}
