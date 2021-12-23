#include "dperspectiva.h"
#include "ui_dperspectiva.h"

int npers1,npers2;
Point2f ptpers[2][4];


void mostrar_origen(){
    Mat copia = foto[npers1].img.clone();
    for (int i = 0; i<4;i++)
        line(copia,ptpers[0][i],ptpers[0][(i+1)%4],CV_RGB(0,0,0),2);
    for (int i = 0; i<4;i++)
        circle(copia,ptpers[0][i],5,CV_RGB(255,0,0),-1);
    namedWindow("Origen",0);
    imshow("Origen",copia);
}

void cb_perspectiva (int evento, int x, int y , int flags, void *ptvoid)
{
    int npos = (int)ptvoid;
    if (flags == EVENT_FLAG_LBUTTON) {
        int mindist = 200;
        int ptmin = 0;
        for (int i= 0; i<4;i++) {
            int distancia = abs((x,y) - ptpers[npos][i].x) + abs(y-ptpers[npos][i].y);
            if (distancia < mindist) {
                mindist = distancia;
                ptmin = i;
            }
        }
        if (mindist <200){
            ptpers[npos][ptmin].x = x;
            ptpers[npos][ptmin].y = y;
            if (npos==0) mostrar_origen();
            ver_perspectiva(npers1,npers2,ptpers[0],ptpers[1]);
        }
    }
}

dperspectiva::dperspectiva(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dperspectiva)
{
    ui->setupUi(this);
    int cont = 0;
    for (int i = 0; i<MAX_VENTANAS;i++) {
        if (foto[i].usada){
            ui->listWidget->addItem(QString::fromStdString(foto[i].nombre));
            ui->listWidget_2->addItem(QString::fromStdString(foto[i].nombre));
            corresp[cont++] = i;
        }
    }
    npers1 = corresp[0];
    npers2 = foto_activa();
    int W= foto[npers1].img.cols-1;
    int H = foto[npers1].img.rows-1;
    ptpers[0][0]= Point2f(0,0);
    ptpers[0][1]= Point2f(W,0);
    ptpers[0][2]= Point2f(W,H);
    ptpers[0][3]= Point2f(0,H);
    W = foto[npers2].img.cols - 1;
    H = foto[npers2].img.rows - 1;
    ptpers[1][0]= Point2f(0,0);
    ptpers[1][1]= Point2f(W,0);
    ptpers[1][2]= Point2f(W,H);
    ptpers[1][3]= Point2f(0,H);

    mostrar_origen();
    setMouseCallback("Origen",cb_perspectiva,(void*)0);
    ver_perspectiva(npers1,npers2,ptpers[0],ptpers[1]);
    setMouseCallback("Perspectiva",cb_perspectiva,(void*)1);
}

dperspectiva::~dperspectiva()
{
    delete ui;
}

void dperspectiva::on_listWidget_currentRowChanged(int currentRow)
{
    npers1 = corresp[currentRow];
    mostrar_origen();
    setMouseCallback("Origen",cb_perspectiva,(void*)0);
    ver_perspectiva(npers1,npers2,ptpers[0],ptpers[1]);
}



void dperspectiva::on_listWidget_2_currentRowChanged(int currentRow)
{
    npers2 = corresp[currentRow];
    ver_perspectiva(npers1,npers2,ptpers[0],ptpers[1]);
    setMouseCallback("Perspectiva",cb_perspectiva,(void*)1);

}

void dperspectiva::on_dperspectiva_rejected()
{
    destroyWindow("Origen");
    destroyWindow("Perspectiva");
}

void dperspectiva::on_dperspectiva_accepted()
{
    ver_perspectiva(npers1,npers2,ptpers[0],ptpers[1],true);
    destroyWindow("Origen");
    destroyWindow("Perspectiva");
}
