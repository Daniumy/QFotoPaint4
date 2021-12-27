#include "dcurva_tunal.h"
#include "ui_dcurva_tunal.h"
#include "imagenes.h"

int nfoto_ct;
Mat lut;

void mostrar_lut()
{
    QImage imq= QImage(":/new/prefix1/imagenes/curvatonal.png");
    Mat img(imq.height(),imq.width(),CV_8UC4,imq.scanLine(0));
    cvtColor(img, img, COLOR_RGBA2RGB);
    for (int i = 0; i<255;i++)
        line(img,Point(71+i,266-lut.at<uchar>(i)),Point(71+i+1,266-lut.at<uchar>(i+1)),
             CV_RGB(255,0,0),2);
    namedWindow("Curva tonal",0);
    imshow("Curva tonal",img);
}

void cb_curva_tonal(int evento, int x, int y, int flags,void*p)
{
    static bool pintando = false;
    static int xant, yant;
    if (flags == EVENT_FLAG_LBUTTON && x>=71 && x<= 326 &&
            y>= 11 && y<=266) {
        x = x -71;
        y = 266 - y;
        lut.at<uchar>(x)=y;

        if (pintando && xant != x)
        {
            if (xant<x){
                for (int i= xant + 1;i<x;i++) {
                    double alfa = double(i - xant)/double(x-xant);
                    lut.at<uchar>(i)=y* alfa+ (1-alfa)*yant;
                }
            }
            else {
                for (int i= x + 1;i<xant;i++) {
                    double alfa = double(i - xant)/double(x-xant);
                    lut.at<uchar>(i)=y* alfa+ (1-alfa)*yant;
                }
            }
        }

        ver_curva_tonal(nfoto_ct,lut);
        mostrar_lut();
        pintando = true;
        xant = x;
        yant = y;
    }
    else pintando = false;
}

dcurva_tunal::dcurva_tunal(int numfoto,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dcurva_tunal)
{
    ui->setupUi(this);
    nfoto_ct = numfoto;
    lut.create(1,256,CV_8U);
    for (int i = 0; i<256;i++)
        lut.at<uchar>(i)=(i%64)*4;
    ver_curva_tonal(nfoto_ct,lut);
    mostrar_lut();
    resizeWindow("Curva tonal",500,500);
    setMouseCallback("Curva tonal",cb_curva_tonal);
    setMouseCallback(foto[nfoto_ct].nombre,NULL);
}

dcurva_tunal::~dcurva_tunal()
{
    delete ui;
}

void dcurva_tunal::on_dcurva_tunal_accepted()
{
    ver_curva_tonal(nfoto_ct,lut,true);
    destroyWindow("Curva tonal");
    reset_callback(nfoto_ct);
}

void dcurva_tunal::on_dcurva_tunal_rejected()
{
    mostrar(nfoto_ct);
    destroyWindow("Curva tonal");
    reset_callback(nfoto_ct);
}

void dcurva_tunal::on_pushButton_clicked()
{
    for (int i = 0; i <256; i++)
        lut.at<uchar>(i) = i;
    if (ui->checkBox->isChecked())
        ver_curva_tonal(nfoto_ct,lut);
    mostrar_lut();
    setMouseCallback("Curva tonal",cb_curva_tonal);
}

void dcurva_tunal::on_pushButton_2_clicked()
{
    for (int i = 0; i <256; i++)
        lut.at<uchar>(i) = 255-i;
    if (ui->checkBox->isChecked())
        ver_curva_tonal(nfoto_ct,lut);
    mostrar_lut();
    setMouseCallback("Curva tonal",cb_curva_tonal);
}

void dcurva_tunal::on_pushButton_3_clicked()
{
    for (int i = 0; i <256; i++)
        lut.at<uchar>(i) = (i%64)*4;
    if (ui->checkBox->isChecked())
        ver_curva_tonal(nfoto_ct,lut);
    mostrar_lut();
    setMouseCallback("Curva tonal",cb_curva_tonal);
}

void dcurva_tunal::on_checkBox_stateChanged(int arg1)
{
    if (arg1)
        ver_curva_tonal(nfoto_ct,lut);
    else
        mostrar(nfoto_ct);
}
