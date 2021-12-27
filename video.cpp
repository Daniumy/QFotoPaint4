//---------------------------------------------------------------------------

#include "video.h"
#include <math.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include <QFileDialog>
#include "mainwindow.h"

///////////////////////////////////////////////////////////////////
/////////  VARIABLES GLOBALES PRIVADAS               //////////////
///////////////////////////////////////////////////////////////////

static VideoCapture camara;
// Capturador de cámara usado actualmente

static Mat img_media;
// Imagen media acumulada de la cámara, con profundidad 32F

static int frames_img_media;
// Número de frames que se han acumulado en la media img_media

string FiltroVideo= "Todos los formatos (*.avi *.mpg *.wmv *.mov *.mp4);;Archivos AVI (*.avi);;Archivos MPG (*.mpg *.mpeg);;Archivos WMV (*.wmv);;Archivos MOV (*.mov);;Otros (*.*)";
///////////////////////////////////////////////////////////////////
/////////  FUNCIONES DE PROCESAMIENTO DE VIDEO       //////////////
///////////////////////////////////////////////////////////////////

void rotar_video (int nfoto, string nombre, int modo, int nframes, int codec, double fps)
{
    assert(nfoto>=0 && nfoto<MAX_VENTANAS && foto[nfoto].usada && !nombre.empty() && nframes>0);
    Mat rotada;
    rotar_angulo(nfoto, rotada, 0, 1, modo);
    VideoWriter writer(nombre, codec, fps, rotada.size());
    if (writer.isOpened()) {
        for (int i= 0; i<=nframes; i++) {
            rotar_angulo(nfoto, rotada, i*360.0/nframes, 1, modo);
            namedWindow("Imagen a vídeo - Rotación", WINDOW_NORMAL);
            imshow("Imagen a vídeo - Rotación", rotada);
            waitKey(1);
            writer << rotada;
        }
        writer.release();
        destroyWindow("Imagen a vídeo - Rotación");
    }
}

//---------------------------------------------------------------------------

int inic_camara (int numero)
{
    if (camara.isOpened())
        camara.release();
    camara.open(numero);
    if (camara.isOpened()) {
        Mat img;
        namedWindow("Imagen de cámara", WINDOW_NORMAL);
        camara >> img;
        resizeWindow("Imagen de cámara", img.size().width, img.size().height);
        imshow("Imagen de cámara", img);
        return int(1000.0/30);
    }
    else
        return 0;
}

//---------------------------------------------------------------------------

void fin_camara (void)
{
    if (camara.isOpened()) {
        camara.release();
        namedWindow("Imagen de cámara",WINDOW_NORMAL);
        destroyWindow("Imagen de cámara");
    }
    namedWindow("Imagen media",WINDOW_NORMAL);
    destroyWindow("Imagen media");
}

//---------------------------------------------------------------------------

void acumular_media (bool primera)
{
    assert(camara.isOpened());
    Mat frame;
    camara >> frame;
    namedWindow("Imagen de cámara", WINDOW_NORMAL);
    imshow("Imagen de cámara", frame);
    if (primera) {
        frames_img_media= 1;
        frame.convertTo(img_media, CV_32FC3);
    }
    else {
        frames_img_media++;
        Mat frame32F;
        frame.convertTo(frame32F, CV_32FC3);
        img_media= frame32F + img_media;
        img_media.convertTo(frame, CV_8UC3, 1.0/frames_img_media);
    }
    namedWindow("Imagen media", WINDOW_NORMAL);
    imshow("Imagen media", frame);
}

//---------------------------------------------------------------------------

void media_a_nueva (int nfoto)
{
    Mat res(img_media.size(), CV_8UC3);
    img_media.convertTo(res, CV_8UC3, 1.0/frames_img_media);
    crear_nueva (nfoto, res);
}

//---------------------------------------------------------------------------

void movimiento(string nombre, int nres)
{
    VideoCapture cap(nombre);
    if (cap.isOpened()) {
        Mat frame;
        cap.read(frame);
        Mat acum(frame.rows,frame.cols,CV_32SC3, Scalar(0,0,0));
        Mat anterior = frame.clone();
        while (cap.read(frame) && waitKey(1)==-1) {
            namedWindow("Frame actual",0);
            imshow("Frame actual", frame);
            Mat dif;
            absdiff(frame,anterior,dif);
            dif.convertTo(dif,CV_32SC3);
            acum += dif;
            frame.copyTo(anterior);
            Mat tmp;
            normalize(acum,tmp,255,0,NORM_MINMAX,CV_8U);
            namedWindow("Acumulado",0);
            imshow("Acumulado",tmp);

        }
        Mat res;
        normalize(acum,res,255,0,NORM_MINMAX, CV_8U);
        crear_nueva(nres,res);
        destroyWindow("Frame actual");
        destroyWindow("Acumulado");
    }
    else {

    }
}

//---------------------------------------------------------------------------
void mostrar_camara (void)
{
    Mat img;
    camara >> img;
    namedWindow("Imagen de cámara", WINDOW_NORMAL);
    imshow("Imagen de cámara", img);
}

//---------------------------------------------------------------------------

void capturar_de_camara (int nres)
{
    VideoCapture cap(0);

    if (cap.isOpened()) {
        Mat frame;
        int tecla;

        while ((tecla = waitKey(1)) == -1) {
            if (!cap.read(frame))
                return;

            namedWindow("Pulse una tecla para capturar", 0);
            imshow("Pulse una tecla para capturar", frame);
        }

        if (tecla != 27) {
            crear_nueva(nres, frame);
        }

        destroyWindow("Pulse una tecla para capturar");
    }
}

//---------------------------------------------------------------------------

void caras() {
    QString nombreGuardadoVideo= QFileDialog::getSaveFileName(w, "Guardar vídeo", ".", QString::fromLatin1(FiltroVideo.c_str()));
    QString nombre= QFileDialog::getOpenFileName(nullptr, "Abrir video", ".", QString::fromStdString(FiltroVideo));
    int codigocc = VideoWriter::fourcc('M','P','E','G');

    VideoCapture cap(nombre.toLatin1().data());
    CascadeClassifier cascade("C:/OpenCV/OpenCV4.1.1G/data/haarcascades/haarcascade_frontalface_alt.xml");
    std::vector<Rect> caras;
    Mat img;

    VideoWriter writer(nombreGuardadoVideo.toLatin1().data(), codigocc, 30, img.size());
    while (cap.read(img) && waitKey(1)==-1) {
           cascade.detectMultiScale(img, caras, 1.2);
           for (int i= 0; i<caras.size(); i++)
                  rectangle(img, caras[i], CV_RGB(255,0,0), 2);

           namedWindow("Imagen", WINDOW_NORMAL);
           imshow("Imagen", img);

           if (writer.isOpened()) {
               waitKey(1);
               writer << img;
           }
    }
    writer.release();
}
