#include "dialoginformation.h"
#include "ui_dialoginformation.h"

#include "imagenes.h"
dialoginformation::dialoginformation(int numfoto, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialoginformation)
{
    nfoto = numfoto;
    ui->setupUi(this);
}

dialoginformation::~dialoginformation()
{
    delete ui;
}

void dialoginformation::on_pushButton_clicked()
{
    QList<QString> lista = ver_informacion(nfoto);

    ui->label->setText(lista.takeLast());

    ui->label_2->setText(lista.takeLast());

    ui->label_3->setText(lista.takeLast());

    ui->label_4->setText(lista.takeLast());

    ui->pushButton_2->setStyleSheet(lista.takeLast());
}
