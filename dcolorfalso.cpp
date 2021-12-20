#include "dcolorfalso.h"
#include "ui_dcolorfalso.h"
#include "imagenes.h"

dcolorfalso::dcolorfalso(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dcolorfalso)
{
    nfoto = foto_activa();
    ui->setupUi(this);
}

dcolorfalso::~dcolorfalso()
{
    delete ui;
}

void dcolorfalso::on_pushButton_clicked()
{
    ultimo_usado = COLORMAP_AUTUMN;
    convertir_color_falso(nfoto,primera_libre(),COLORMAP_AUTUMN);
}

void dcolorfalso::on_pushButton_2_clicked()
{
    ultimo_usado = COLORMAP_BONE;
    convertir_color_falso(nfoto,primera_libre(),COLORMAP_BONE);
}

void dcolorfalso::on_pushButton_3_clicked()
{
    ultimo_usado = COLORMAP_JET;
    convertir_color_falso(nfoto,primera_libre(),COLORMAP_JET);
}
void dcolorfalso::on_pushButton_4_clicked()
{
    ultimo_usado = COLORMAP_WINTER;
    convertir_color_falso(nfoto,primera_libre(),COLORMAP_WINTER);
}
void dcolorfalso::on_pushButton_5_clicked()
{
    ultimo_usado = COLORMAP_RAINBOW;
    convertir_color_falso(nfoto,primera_libre(),COLORMAP_RAINBOW);
}
void dcolorfalso::on_pushButton_6_clicked()
{
    ultimo_usado = COLORMAP_OCEAN;
    convertir_color_falso(nfoto,primera_libre(),COLORMAP_OCEAN);
}
void dcolorfalso::on_pushButton_7_clicked()
{
    ultimo_usado = COLORMAP_SUMMER;
    convertir_color_falso(nfoto,primera_libre(),COLORMAP_SUMMER);
}
void dcolorfalso::on_pushButton_8_clicked()
{
    ultimo_usado = COLORMAP_SPRING;
    convertir_color_falso(nfoto,primera_libre(),COLORMAP_SPRING);
}
void dcolorfalso::on_pushButton_9_clicked()
{
    ultimo_usado = COLORMAP_PINK;
    convertir_color_falso(nfoto,primera_libre(),COLORMAP_PINK);
}
void dcolorfalso::on_pushButton_10_clicked()
{
    ultimo_usado = COLORMAP_HOT;
    convertir_color_falso(nfoto,primera_libre(),COLORMAP_HOT);
}
void dcolorfalso::on_pushButton_11_clicked()
{
    ultimo_usado = COLORMAP_MAGMA;
    convertir_color_falso(nfoto,primera_libre(),COLORMAP_MAGMA);
}
void dcolorfalso::on_pushButton_12_clicked()
{
    ultimo_usado = COLORMAP_INFERNO;
    convertir_color_falso(nfoto,primera_libre(),COLORMAP_INFERNO);
}


void dcolorfalso::on_buttonBox_accepted()
{
    convertir_color_falso(nfoto,primera_libre(),ultimo_usado, true);
    reset_callback(nfoto);
}

void dcolorfalso::on_buttonBox_rejected()
{
    mostrar(nfoto);
    reset_callback(nfoto);
}
