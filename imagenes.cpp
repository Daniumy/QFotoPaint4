//---------------------------------------------------------------------------
#include "imagenes.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QFileDialog>
#include <assert.h>
#include <QClipboard>
#include <QImage>
#include <QDebug>
///////////////////////////////////////////////////////////////////
/////////  VARIABLES GLOBALES                        //////////////
///////////////////////////////////////////////////////////////////
Mat mataux;

bool first_time_punto = true;
bool first_time_arcoiris = true;
bool first_time_trazas = true;
int xtrazas,ytrazas;
ventana foto[MAX_VENTANAS];

tipo_herramienta herr_actual= HER_PUNTO;

int radio_pincel= 10;

Scalar color_pincel= CV_RGB(255, 255, 255);

int difum_pincel= 10;

bool preguntar_guardar= true;

static int numpos= 0; // Número actual en el orden de posición de las ventanas

///////////////////////////////////////////////////////////////////
/////////  FUNCIONES DE MANEJO DE VENTANAS           //////////////
///////////////////////////////////////////////////////////////////

void callback (int event, int x, int y, int flags, void *_nfoto);

void SetStatusBar1 (int masfotos);

//---------------------------------------------------------------------------

void inic_fotos (void)
{
    for (int i= 0; i<MAX_VENTANAS; i++)
        foto[i].usada= false;
}

//---------------------------------------------------------------------------

void fin_fotos (void)
{
    for (int i= 0; i<MAX_VENTANAS; i++) {
        if (foto[i].usada) {
            destroyWindow(foto[i].nombre);
            foto[i].usada= false;
        }
    }
}

//---------------------------------------------------------------------------

int primera_libre (void)
{
    for (int i= 0; i<MAX_VENTANAS; i++)
        if (!foto[i].usada)
            return i;
    return -1;
}

//---------------------------------------------------------------------------

void escribir_barra_estado (void)
{
    int usadas, modificadas;
    num_fotos(usadas, modificadas);
    w->setStatusBarText(QString::number(usadas)+" fotos abiertas, "+
                        QString::number(modificadas)+" modificadas.");
}

//---------------------------------------------------------------------------

void crear_nueva (int nfoto, int ancho, int alto, Scalar color)
{
    assert(nfoto>=0 && nfoto<MAX_VENTANAS && !foto[nfoto].usada);
    foto[nfoto].nombre= "nueva-"+to_string(nfoto)+".png";
    foto[nfoto].nombref= foto[nfoto].nombre;
    foto[nfoto].img.create(alto, ancho, CV_8UC3);
    foto[nfoto].img=  color;
    namedWindow(foto[nfoto].nombre, WINDOW_NO_POPUP+WINDOW_MOVE_RIGHT);
    foto[nfoto].orden= numpos++;
    imshow(foto[nfoto].nombre, foto[nfoto].img);
    foto[nfoto].usada= true;
    foto[nfoto].modificada= true;
    foto[nfoto].roi= Rect(0, 0, ancho, alto);
    setMouseCallback(foto[nfoto].nombre, callback, (void*) nfoto);
    escribir_barra_estado();
}

void reset_callback(int nfoto){
    setMouseCallback(foto[nfoto].nombre, callback, (void*) nfoto);
}
//---------------------------------------------------------------------------

void crear_nueva (int nfoto, Mat img)
{//&& !img.empty()
    assert(nfoto>=0 && nfoto<MAX_VENTANAS && !foto[nfoto].usada );
    foto[nfoto].nombre= "nueva-"+to_string(nfoto)+".png";
    foto[nfoto].nombref= foto[nfoto].nombre;
    foto[nfoto].img= img;
    namedWindow(foto[nfoto].nombre, WINDOW_NO_POPUP+WINDOW_MOVE_RIGHT);
    foto[nfoto].orden= numpos++;
    imshow(foto[nfoto].nombre, foto[nfoto].img);
    foto[nfoto].usada= true;
    foto[nfoto].modificada= true;
    foto[nfoto].roi= Rect(0, 0, img.cols, img.rows);
    setMouseCallback(foto[nfoto].nombre, callback, (void*) nfoto);
    escribir_barra_estado();
}

//---------------------------------------------------------------------------

void crear_nueva (int nfoto, string nombre)
{
    assert(nfoto>=0 && nfoto<MAX_VENTANAS && !foto[nfoto].usada);
    foto[nfoto].nombre= nombre;
    foto[nfoto].nombref= Lt1(nombre);
    foto[nfoto].img= imread(foto[nfoto].nombref);
    if (foto[nfoto].img.empty())
        return;
    namedWindow(foto[nfoto].nombre, WINDOW_NO_POPUP+WINDOW_MOVE_RIGHT);
    foto[nfoto].orden= numpos++;
    imshow(foto[nfoto].nombre, foto[nfoto].img);
    foto[nfoto].usada= true;
    foto[nfoto].modificada= false;
    foto[nfoto].roi= Rect(0, 0, foto[nfoto].img.cols, foto[nfoto].img.rows);
    setMouseCallback(foto[nfoto].nombre, callback, (void*) nfoto);
    escribir_barra_estado();
}

//---------------------------------------------------------------------------

void guardar_foto (int nfoto, string nombre)
{
    assert(nfoto>=0 && nfoto<MAX_VENTANAS && foto[nfoto].usada);
    foto[nfoto].modificada= false;
    // 1. Guardar la imagen con el mismo nombre que tiene
    if (nombre=="")
        imwrite(foto[nfoto].nombref, foto[nfoto].img);
    // 2. Guardar la imagen con un nombre distinto al actual
    else {
        imwrite(Lt1(nombre), foto[nfoto].img);
        setWindowTitle(foto[nfoto].nombre, nombre);
    }
    escribir_barra_estado();
}

//---------------------------------------------------------------------------

void cerrar_foto (int nfoto, bool destruir_ventana)
{
    assert(nfoto>=0 && nfoto<MAX_VENTANAS && foto[nfoto].usada);
    if (destruir_ventana)
        destroyWindow(foto[nfoto].nombre);
    foto[nfoto].usada= false;
    escribir_barra_estado();
}

//---------------------------------------------------------------------------

void mostrar (int nfoto)
{
    assert(nfoto>=0 && nfoto<MAX_VENTANAS && foto[nfoto].usada);
    imshow(foto[nfoto].nombre, foto[nfoto].img);
}

//---------------------------------------------------------------------------

int nombre_a_numero (string nombre)
{
    for (int i= 0; i<MAX_VENTANAS; i++)
        if (foto[i].usada && foto[i].nombre==nombre)
            return i;
    return -1;
}

//---------------------------------------------------------------------------

int foto_activa (void)
{
    int maxorden= -1, maxpos= -1;
    for (int i= 0; i<MAX_VENTANAS; i++) {
        if (foto[i].usada && foto[i].orden>maxorden) {
            maxorden= foto[i].orden;
            maxpos= i;
        }
    }
    return maxpos;
}

//---------------------------------------------------------------------------

int num_fotos (int &usadas, int &modificadas)
{
    usadas= 0;
    modificadas= 0;
    for (int i= 0; i<MAX_VENTANAS; i++) {
        if (foto[i].usada) {
            usadas++;
            if (foto[i].modificada)
                modificadas++;
        }
    }
    return usadas;
}

///////////////////////////////////////////////////////////////////
/////////  FUNCIONES DEL CALLBACK PRINCIPAL          //////////////
///////////////////////////////////////////////////////////////////

static int downx, downy;
// Posición inicial del ratón al pinchar sobre la imagen actual

//---------------------------------------------------------------------------

void ninguna_accion (int factual, int x, int y)
{
    Mat res= foto[factual].img.clone();
    circle(res, Point(x, y), radio_pincel, CV_RGB(255,255,255), 2, LINE_AA);
    imshow(foto[factual].nombre, res);
}

//---------------------------------------------------------------------------

void cb_close (int factual)
{
    if (foto[factual].usada && !foto[factual].img.empty()) {
        if (foto[factual].modificada && preguntar_guardar) {
            QString cadena= "El archivo " + QString::fromStdString(foto[factual].nombre) +
                    " ha sido modificado.\n¿Desea guardarlo?";
            int resp= QMessageBox::question(w, "Archivo modificado", cadena,
                                            QMessageBox::Yes | QMessageBox::No );
            if (resp==QMessageBox::Yes)
                guardar_foto(factual);
        }
        cerrar_foto(factual, false);
    }
}

//---------------------------------------------------------------------------

void cb_punto (int factual, int x, int y)
{

    Mat im= foto[factual].img; // Ojo: esto no es una copia, sino a la misma imagen
    if (difum_pincel==0)
        circle(im, Point(x, y), radio_pincel, color_pincel, -1, LINE_AA);
    else {
        int tam = radio_pincel + difum_pincel;
        int posx = tam, posy = tam;
        Rect roi(x - tam, y - tam, 2 * tam + 1, 2 * tam + 1);

        // Comprobamos que no se sale del tam. maximo
        if (roi.x < 0) {
            roi.width += roi.x;
            posx += roi.x;
            roi.x = 0;
        }

        if (roi.y < 0) {
            roi.height += roi.y;
            posy += roi.y;
            roi.y = 0;
        }

        if ((roi.x + roi.width) > im.cols) {
            roi.width = im.cols - roi.x;
        }

        if ((roi.y + roi.height) > im.rows) {
            roi.height = im.rows - roi.y;
        }

        im = im(roi);
        Mat res(im.size(), im.type(), color_pincel);
        Mat cop(im.size(), im.type(), CV_RGB(0,0,0));
        circle(cop, Point(posx, posy), radio_pincel, CV_RGB(255,255,255), -1, LINE_AA);
        blur(cop, cop, Size(difum_pincel*2+1, difum_pincel*2+1));
        multiply(res, cop, res, 1.0/255.0);
        bitwise_not(cop, cop);
        multiply(im, cop, im, 1.0/255.0);
        im= res + im;
    }
    //std::cout << "Thread2 # " << factual << std::endl;
    imshow(foto[factual].nombre, foto[factual].img);
    foto[factual].modificada= true;
}
//---------------------------------------------------------------------------

void cb_ver_punto (int factual, int x, int y)
{
    Mat res= foto[factual].img.clone();
    circle(res, Point(x, y), radio_pincel, color_pincel, -1, LINE_AA);
    imshow(foto[factual].nombre, res);
}

//---------------------------------------------------------------------------
void cb_suavizar(int nfoto, int x, int y)
{
    assert(nfoto>=0 && nfoto<MAX_VENTANAS && foto[nfoto].usada);
    Mat img = foto[nfoto].img;
    int tam = radio_pincel + difum_pincel;
    int posx = tam, posy = tam;
    Rect roi(x - tam, y - tam, 2 * tam + 1, 2 * tam + 1);
    // Comprobamos que no se sale del tam. maximo
    if (roi.x < 0) {
        roi.width += roi.x;
        posx += roi.x;
        roi.x = 0;
    }

    if (roi.y < 0) {
        roi.height += roi.y;
        posy += roi.y;
        roi.y = 0;
    }

    if ((roi.x + roi.width) > img.cols) {
        roi.width = img.cols - roi.x;
    }

    if ((roi.y + roi.height) > img.rows) {
        roi.height = img.rows - roi.y;
    }

    img = img(roi);
    Mat cop(img.size(), img.type(), CV_RGB(0,0,0));
    Mat res= img.clone();
    GaussianBlur(res, res,Size(difum_pincel*2+1, difum_pincel*2+1), 4);
    circle(cop, Point(posx, posy), radio_pincel, CV_RGB(255,255,255), -1, LINE_AA);
    blur(cop, cop, Size(difum_pincel*2+1, difum_pincel*2+1));
    multiply(res, cop, res, 1.0/255.0);
    bitwise_not(cop, cop);
    multiply(img, cop, img, 1.0/255.0);
    img= res + img;
    imshow(foto[nfoto].nombre, foto[nfoto].img);
    foto[nfoto].modificada= true;
}

//---------------------------------------------------------------------------

void cb_rellenar(int factual,int x, int y)
{
    anadir_accion_a_lista(factual);
    Mat img = foto[factual].img;
    Mat res= foto[factual].img.clone();
    double peso = difum_pincel / 100.0;
    floodFill(res,Point(x,y),color_pincel,0,Scalar::all(radio_pincel),Scalar::all(radio_pincel),0);
    //Cálculo de la media ponderada
    Mat cop;
    resize(res, cop, img.size());
    addWeighted(img, peso, cop, 1.0-peso, 0, img);
}

//---------------------------------------------------------------------------

void cb_linea (int factual, int x, int y)
{
    anadir_accion_a_lista(factual);
    Mat im= foto[factual].img;  // Ojo: esto no es una copia, sino a la misma imagen
    if (difum_pincel==0)
        line(im, Point(downx, downy), Point(x,y), color_pincel, radio_pincel*2+1);
    else {
        Mat res(im.size(), im.type(), color_pincel);
        Mat cop(im.size(), im.type(), CV_RGB(0,0,0));
        line(cop, Point(downx, downy), Point(x,y), CV_RGB(255,255,255), radio_pincel*2+1);
        blur(cop, cop, Size(difum_pincel*2+1, difum_pincel*2+1));
        multiply(res, cop, res, 1.0/255.0);
        bitwise_not(cop, cop);
        multiply(im, cop, im, 1.0/255.0);
        im= res + im;
    }
    imshow(foto[factual].nombre, im);
    foto[factual].modificada= true;
}

//---------------------------------------------------------------------------

void cb_ver_linea (int factual, int x, int y)
{
    Mat res= foto[factual].img.clone();
    line(res, Point(downx, downy), Point(x,y), color_pincel, radio_pincel*2+1);
    imshow(foto[factual].nombre, res);
}
//---------------------------------------------------------------------------
void cb_trazar(int factual,int x,int y)
{
    Mat im= foto[factual].img;
    if (difum_pincel==0)
        line(im, Point(xtrazas, ytrazas), Point(x,y), color_pincel, radio_pincel*2+1);
    else {
        Mat res(im.size(), im.type(), color_pincel);
        Mat cop(im.size(), im.type(), CV_RGB(0,0,0));
        line(cop, Point(xtrazas, ytrazas), Point(x,y), CV_RGB(255,255,255), radio_pincel*2+1);
        blur(cop, cop, Size(difum_pincel*2+1, difum_pincel*2+1));
        multiply(res, cop, res, 1.0/255.0);
        bitwise_not(cop, cop);
        multiply(im, cop, im, 1.0/255.0);
        im= res + im;
    }

    xtrazas=x;
    ytrazas=y;
    imshow(foto[factual].nombre, im);
    foto[factual].modificada= true;
}
//---------------------------------------------------------------------------

void cb_seleccionar (int factual, int x, int y)
{
    Mat im= foto[factual].img;
    Rect nuevo= Rect(min(downx, x), min(downy, y),
                     max(downx, x)-min(downx, x)+1, max(downy, y)-min(downy, y)+1);
    if (nuevo.x<0)
        nuevo.x= 0;
    if (nuevo.y<0)
        nuevo.y= 0;
    if (nuevo.x+nuevo.width>im.size().width)
        nuevo.width= im.size().width-nuevo.x;
    if (nuevo.y+nuevo.height>im.size().height)
        nuevo.height= im.size().height-nuevo.y;
    foto[factual].roi= nuevo;
}

//---------------------------------------------------------------------------

void cb_ver_seleccion (int factual, int x, int y, bool foto_roi)
{
    Mat res= foto[factual].img.clone();
    Point p1, p2;
    if (foto_roi) {
        p1.x= foto[factual].roi.x;
        p1.y= foto[factual].roi.y;
        p2.x= foto[factual].roi.x+foto[factual].roi.width-1;
        p2.y= foto[factual].roi.y+foto[factual].roi.height-1;
    }
    else {
        p1= Point(downx, downy);
        p2= Point(x, y);
    }
    rectangle(res, p1, p2, CV_RGB(255,foto_roi?0:255,0),2);
    imshow(foto[factual].nombre, res);
}

//---------------------------------------------------------------------------

void cb_rectangulo (int factual, int x, int y)
{
    anadir_accion_a_lista(factual);
    Mat im= foto[factual].img;  // Ojo: esto no es una copia, sino a la misma imagen
    if (difum_pincel==0)
        rectangle(im, Point(downx, downy), Point(x,y), color_pincel, radio_pincel*2-1);
    else {
        Mat res(im.size(), im.type(), color_pincel);
        Mat cop(im.size(), im.type(), CV_RGB(0,0,0));
        rectangle(cop, Point(downx, downy), Point(x,y), CV_RGB(255,255,255), radio_pincel*2-1);
        blur(cop, cop, Size(difum_pincel*2+1, difum_pincel*2+1));
        multiply(res, cop, res, 1.0/255.0);
        bitwise_not(cop, cop);
        multiply(im, cop, im, 1.0/255.0);
        im= res + im;
    }
    imshow(foto[factual].nombre, im);
    foto[factual].modificada= true;
}

//---------------------------------------------------------------------------

void cb_ver_rectangulo (int factual, int x, int y)
{
    Mat res= foto[factual].img.clone();
    rectangle(res, Point(downx, downy), Point(x,y), color_pincel, radio_pincel*2+1);
    imshow(foto[factual].nombre, res);
}

//---------------------------------------------------------------------------

void cb_elipse (int factual, int x, int y)
{
    anadir_accion_a_lista(factual);
    Mat im= foto[factual].img;  // Ojo: esto no es una copia, sino a la misma imagen
    if (difum_pincel==0)
        ellipse(im, Point(downx, downy), Size(abs(x - downx), abs(y - downy)), 0, 0, 360, color_pincel, radio_pincel-1);
    else {
        Mat res(im.size(), im.type(), color_pincel);
        Mat cop(im.size(), im.type(), CV_RGB(0,0,0));
        ellipse(cop, Point(downx, downy), Size(abs(x - downx), abs(y - downy)), 0, 0, 360, CV_RGB(255, 255, 255), radio_pincel-1);
        blur(cop, cop, Size(difum_pincel*2+1, difum_pincel*2+1));
        multiply(res, cop, res, 1.0/255.0);
        bitwise_not(cop, cop);
        multiply(im, cop, im, 1.0/255.0);
        im= res + im;
    }
    imshow(foto[factual].nombre, im);
    foto[factual].modificada= true;
}

//---------------------------------------------------------------------------

void cb_ver_elipse (int factual, int x, int y)
{
    Mat res= foto[factual].img.clone();
    ellipse(res, Point(downx, downy), Size(abs(x - downx), abs(y - downy)), 0, 0, 360, color_pincel, radio_pincel-1);
    imshow(foto[factual].nombre, res);
}

//---------------------------------------------------------------------------

int PALAI[3][24] = {
    { 255, 255, 255, 255, 255, 192, 128, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 64, 128, 192, 255, 255, 255, 255},
    { 0, 64, 128, 192, 255, 255, 255, 255, 255, 255, 255, 255, 255, 192,128, 64, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 64, 128, 192, 255, 255, 255, 255, 255, 255, 255, 255, 255, 192, 128, 64}
};

void cb_arcoiris (int factual, int x, int y)
{
    static int pos = 0;
    Mat im= foto[factual].img;  // Ojo: esto no es una copia, sino a la misma imagen
    if (difum_pincel==0)
        circle(im, Point(x, y), radio_pincel, CV_RGB(PALAI[0][pos], PALAI[1][pos], PALAI[2][pos]), -1, LINE_AA);
    else {
        int tam = radio_pincel + difum_pincel;
        int posx = tam, posy = tam;
        Rect roi(x - tam, y - tam, 2 * tam + 1, 2 * tam + 1);

        // Comprobamos que no se sale del tam. maximo
        if (roi.x < 0) {
            roi.width += roi.x;
            posx += roi.x;
            roi.x = 0;
        }

        if (roi.y < 0) {
            roi.height += roi.y;
            posy += roi.y;
            roi.y = 0;
        }

        if ((roi.x + roi.width) > im.cols) {
            roi.width = im.cols - roi.x;
        }

        if ((roi.y + roi.height) > im.rows) {
            roi.height = im.rows - roi.y;
        }

        im = im(roi);
        Mat res(im.size(), im.type(), CV_RGB(PALAI[0][pos], PALAI[1][pos], PALAI[2][pos]));
        Mat cop(im.size(), im.type(), CV_RGB(0,0,0));
        circle(cop, Point(posx, posy), radio_pincel, CV_RGB(255,255,255), -1, LINE_AA);
        blur(cop, cop, Size(difum_pincel*2+1, difum_pincel*2+1));
        multiply(res, cop, res, 1.0/255.0);
        bitwise_not(cop, cop);
        multiply(im, cop, im, 1.0/255.0);
        im= res + im;
    }
    pos = (pos + 1) % 24;
    imshow(foto[factual].nombre, foto[factual].img);
    foto[factual].modificada= true;
}

//---------------------------------------------------------------------------

void callback (int event, int x, int y, int flags, void *_nfoto)
{
    int factual= (int) _nfoto;

    // 1. Eventos y casos especiales
    // 1.1. Evento cerrar ventana
    if (event==EVENT_CLOSE) {
        cb_close(factual);
        return;
    }
    // 1.2. Evento obtiene el foco
    if (event==EVENT_FOCUS) {
        foto[factual].orden= numpos++;
    }
    // 1.3. El ratón se sale de la ventana
    if (x<0 || x>=foto[factual].img.size().width || y<0 || y>=foto[factual].img.size().height)
        return;
    // 1.4. Se inicia la pulsación del ratón
    if (event==EVENT_LBUTTONDOWN) {
        downx= x;
        downy= y;
    }

    // 2. Según la herramienta actual
    switch (herr_actual) {

    // 2.1. Herramienta PUNTO
    case HER_PUNTO:
        if (event == EVENT_LBUTTONUP)
            first_time_punto = true;
        else if (flags==EVENT_FLAG_LBUTTON){
            if (first_time_punto)
            {
                anadir_accion_a_lista(factual);
                first_time_punto = false;
            }
            cb_punto(factual, x, y);
        }
        else
            ninguna_accion(factual, x, y);
        break;

        // 2.2. Herramienta LINEA
    case HER_LINEA:
        if (event==EVENT_LBUTTONUP)
            cb_linea(factual, x, y);
        else if (event==EVENT_MOUSEMOVE && flags==EVENT_FLAG_LBUTTON)
            cb_ver_linea(factual, x, y);
        else
            ninguna_accion(factual, x, y);
        break;

        // 2.3. Herramienta SELECCION
    case HER_SELECCION:
        if (event==EVENT_LBUTTONUP)
            cb_seleccionar(factual, x, y);
        else if (event==EVENT_MOUSEMOVE)
            cb_ver_seleccion(factual, x, y, flags!=EVENT_FLAG_LBUTTON);
        break;

        // 2.4. Herramienta RECTANGULO
    case HER_RECTANGULO:
        if (event==EVENT_LBUTTONUP)
            cb_rectangulo(factual, x, y);
        else if (event==EVENT_MOUSEMOVE && flags==EVENT_FLAG_LBUTTON)
            cb_ver_rectangulo(factual, x, y);
        else
            ninguna_accion(factual, x, y);
        break;

        // 2.5. HERRAMIENTA ELIPSE
    case HER_ELIPSE:
        if (event==EVENT_LBUTTONUP)
            cb_elipse(factual, x, y);
        else if (event==EVENT_MOUSEMOVE && flags==EVENT_FLAG_LBUTTON)
            cb_ver_elipse(factual, x, y);
        else
            ninguna_accion(factual, x, y);
        break;

        // 2.6. Herramienta ARCOIRIS
    case HER_ARCOIRIS:
        if (event == EVENT_LBUTTONUP)
            first_time_arcoiris = true;
        else if (flags==EVENT_FLAG_LBUTTON)
        {
            if (first_time_arcoiris)
            {
               anadir_accion_a_lista(factual);
               first_time_arcoiris = false;
            }
            cb_arcoiris(factual, x, y);
        }
        else
            ninguna_accion(factual, x, y);
        break;
    case HER_RELLENAR:
        if (event==EVENT_LBUTTONUP)
            cb_rellenar(factual,x,y);
        else if (event==EVENT_MOUSEMOVE && flags==EVENT_FLAG_LBUTTON)
            ninguna_accion(factual, x, y);
        else
            ninguna_accion(factual, x, y);
        break;
    case HER_SUAVIZADO:
        if ((event==EVENT_MOUSEMOVE && flags==EVENT_FLAG_LBUTTON) || flags==EVENT_FLAG_LBUTTON)
            cb_suavizar(factual, x, y);
        else
            ninguna_accion(factual, x, y);
        break;
    case HER_TRAZAS:
        if (event == EVENT_LBUTTONUP)
            first_time_trazas = true;
        else if (flags==EVENT_FLAG_LBUTTON){
            if (first_time_trazas)
            {
                xtrazas = downx;
                ytrazas = downy;
                anadir_accion_a_lista(factual);
                first_time_trazas = false;
            }
            cb_trazar(factual, x, y);
        }
        else
            ninguna_accion(factual, x, y);
        break;
    }

}


///////////////////////////////////////////////////////////////////
/////////  FUNCIONES DE PROCESAMIENTO DE IMAGENES    //////////////
///////////////////////////////////////////////////////////////////

void invertir (int nfoto, int nres)
{
    Mat img(foto[nfoto].img.size(), foto[nfoto].img.type());
    bitwise_not(foto[nfoto].img, img);
    crear_nueva(nres, img);
}

//---------------------------------------------------------------------------

void rotar_angulo (int nfoto, Mat &imgRes, double angulo, double escala, int modo)
{
    rotar_angulo(foto[nfoto].img, imgRes, angulo, escala, modo);
}

//---------------------------------------------------------------------------

void rotar_angulo (Mat imagen, Mat &imgRes, double angulo, double escala, int modo)
{
    double w= imagen.size().width, h= imagen.size().height;
    Size sres;
    if (modo==0) {     // Reescalar con proporción al original
        sres.width= int(w*escala);
        sres.height= int(h*escala);
    }
    else if (modo==1)  // Reescalar y ampliar para caber entera
        sres.width= sres.height= int(sqrt(w*w + h*h)*escala);
    else               // Reescalar y recortar para no mostrar borde
        sres.width= sres.height= int(min(w, h)*escala/sqrt(2.0));
    imgRes.create(sres, imagen.type());
    double sa= sin(angulo*M_PI/180), ca= cos(angulo*M_PI/180);
    double cx= -w/2*ca-h/2*sa, cy= w/2*sa-h/2*ca;
    Mat M= getRotationMatrix2D(Point2f(0,0), angulo, escala);
    M.at<double>(0,2)= sres.width/2+cx*escala;
    M.at<double>(1,2)= sres.height/2+cy*escala;
    imgRes= color_pincel;
    warpAffine(imagen, imgRes, M, sres);
}

//---------------------------------------------------------------------------

void rotar_exacto (int nfoto, int nres, int grado)
{
    Mat entrada= foto[nfoto].img;
    Mat salida;
    if (grado==0)
        salida= entrada.clone();
    else if (grado==1) {
        transpose(entrada, salida);
        flip(salida, salida, 1);
    }
    else if (grado==2)
        flip(entrada, salida, -1);
    else if (grado==3) {
        transpose(entrada, salida);
        flip(salida, salida, 0);
    }
    crear_nueva(nres, salida);
}


void ver_perspectiva(int nfoto1, int nfoto2, Point2f pt1[],Point2f pt2[],bool guardar)
{
    Mat M = getPerspectiveTransform(pt1, pt2);
    Mat res = foto[nfoto2].img.clone();
    warpPerspective(foto[nfoto1].img, res, M, res.size(),INTER_LINEAR, BORDER_TRANSPARENT);




    if (guardar) {
        res.copyTo(foto[nfoto2].img);
        foto[nfoto2].modificada = true;
        mostrar(nfoto2);
    }
    else {
        for (int i = 0; i<4;i++)
            line(res,pt2[i],pt2[(i+1)%4],CV_RGB(0,0,0),2);
        for (int i = 0; i<4;i++)
            circle(res,pt2[i],5,CV_RGB(0,255,0),-1);
        namedWindow("Perspectiva",0);
        imshow("Perspectiva",res);
    }

}
//---------------------------------------------------------------------------

void ver_brillo_contraste_gama (int nfoto, double suma, double prod, double gama, bool guardar)
{
    assert(nfoto>=0 && nfoto<MAX_VENTANAS && foto[nfoto].usada);
    Mat img;
    foto[nfoto].img.convertTo(img, CV_8UC3, prod, suma);
    Mat img32F;
    img.convertTo(img32F, CV_32F, 1.0/255);
    pow(img32F, gama, img32F);
    img32F.convertTo(img, CV_8U, 255);
    imshow(foto[nfoto].nombre, img);
    if (guardar) {
        img.copyTo(foto[nfoto].img);
        foto[nfoto].modificada= true;
    }
}
//---------------------------------------------------------------------------
void ver_pinchar_estirar(int nfoto, int cx, int cy, double radio, double a, bool guardar)
{
    Mat S(foto[nfoto].img.rows,foto[nfoto].img.cols,CV_32FC1);
    radio*=radio;
    a*=radio;
    for (int y = 0; y <S.rows;y++)
        for (int x= 0; x<S.cols;x++)
            //S.at<float>(y,x)= sin(0.03+sqrt((x-cx)*(x-cx)+(y-cy)*(y-cy))+a);
            S.at<float>(y,x)= exp(-((x-cx)*(x-cx)+(y-cy)*(y-cy))/radio);

    Mat Gx,Gy;
    Sobel(S,Gx,CV_32F,1,0);
    Sobel(S,Gy,CV_32F,0,1);
    multiply(S,Gx,Gx,a);
    multiply(S,Gy,Gy,a);

    for (int y = 0; y <S.rows;y++)
        for (int x= 0; x<S.cols;x++){
            Gx.at<float>(y,x)= x + Gx.at<float>(y,x);
            Gy.at<float>(y,x)= y + Gy.at<float>(y,x);
        }
    Mat res;
    remap(foto[nfoto].img,res,Gx,Gy,INTER_LINEAR,BORDER_REFLECT);
    imshow("Pinchar/estirar",res);
    if (guardar) {
        res.copyTo(foto[nfoto].img);
        foto[nfoto].modificada = true;
    }
}
//---------------------------------------------------------------------------

void ver_suavizado (int nfoto, int ntipo, int tamx, int tamy, bool guardar)
{
    assert(nfoto>=0 && nfoto<MAX_VENTANAS && foto[nfoto].usada);
    Mat img= foto[nfoto].img.clone();
    if (ntipo==1) {
        GaussianBlur(foto[nfoto].img, img, Size(tamx, tamy), 0);}
    else if (ntipo==2)
        blur(foto[nfoto].img, img, Size(tamx, tamy));
    else if (ntipo==3)
        medianBlur(foto[nfoto].img, img, min(301, tamx));
    imshow(foto[nfoto].nombre, img);
    if (guardar) {
        img.copyTo(foto[nfoto].img);
        foto[nfoto].modificada= true;
    }
}

//---------------------------------------------------------------------------

void ver_bajorrelieve (int nfoto, double angulo, double grado, int ntextura, bool guardar)
{
    QString NOMBRES[4] = {":/new/prefix1/imagenes/arena.jpg", ":/new/prefix1/imagenes/cielo.jpg", ":/new/prefix1/imagenes/madera.jpg", ":/new/prefix1/imagenes/gris.png"};
    QImage imq= QImage(NOMBRES[ntextura]);
    Mat imgFondo(imq.height(),imq.width(),CV_8UC4,imq.scanLine(0));
    cvtColor(imgFondo, imgFondo, COLOR_RGBA2RGB);

    Mat rotada;
    rotar_angulo(nfoto, rotada, angulo, 1.0, 1);
    Mat gris;
    cvtColor(rotada, gris, COLOR_BGR2GRAY);
    Mat sobel;
    Sobel(gris, sobel, CV_16S, 1, 0, 3, grado, 0, BORDER_REFLECT);
    rotar_angulo(sobel, rotada, -angulo, 1.0, 0);

    int w = foto[nfoto].img.cols, h = foto[nfoto].img.rows;
    int w2 = rotada.cols, h2 = rotada.rows;
    Mat res = rotada(Rect((w2 - w) / 2, (h2 - h) / 2, w, h)).clone();

    Mat canales[3] = {res, res, res};
    merge(canales, 3, gris);

    resize(imgFondo, imgFondo, Size(gris.cols, gris.rows));
    imgFondo.convertTo(imgFondo, CV_16SC3);
    imgFondo = imgFondo + gris;
    imgFondo.convertTo(res, CV_8UC3);

    if (!guardar) {
        namedWindow("Bajorrelieve", 0);
        imshow("Bajorrelieve", res);
    } else {
        crear_nueva(primera_libre(), res);
    }
}

//---------------------------------------------------------------------------

void ver_histograma (int nfoto, int nres, int canal)
{
    QImage imq = QImage(":/new/prefix1/imagenes/histbase.png");
    Mat imghist(imq.height(),imq.width(),CV_8UC4,imq.scanLine(0));
    cvtColor(imghist, imghist, COLOR_RGBA2RGB);

    Mat img = foto[nfoto].img;
    Mat gris;
    Mat hist;
    cvtColor(img, gris, COLOR_BGR2GRAY);  // Conversión a gris
    int canales[1] = {0};
    int bins[1] = {256};
    float rango[2] = {0, 256};
    const float *rangos[] = {rango};

    if (canal == 3) {
        calcHist(&gris, 1, canales, noArray(), hist, 1, bins, rangos);
    } else {
        calcHist(&img, 1, &canal, noArray(), hist, 1, bins, rangos);
    }

    double minVal, maxVal;
    minMaxLoc(hist, &minVal, &maxVal);

    Scalar color = CV_RGB(canal == 2 ? 255 : 0, canal == 1 ? 255 : 0, canal == 0 ? 255 : 0);

    for (int i= 0; i<256; i++) {
        // qDebug("Celda %d: %g", i, hist.at<float>(i));
        double valor = hist.at<float>(i) / maxVal;
        rectangle(imghist, Point(3 + i * 391 / 256, 185 - valor * 182),
                  Point(3 + (i + 1) * 391 / 256, 185),
                  color,
                  -1);
    }
    crear_nueva(nres, imghist);
}
//---------------------------------------------------------------------------
void ver_histograma_2D (int nfoto, int nres, int agrupacion)
{
    Mat img = foto[nfoto].img;
    Mat hist;
    int canales[2];
    switch (agrupacion)
    {
    case 0:
        canales[0] = 2; //R
        canales[1] = 1; //G
        break;
    case 1:
        canales[0] = 2; //R
        canales[1] = 0; //B
        break;
    case 2:
        canales[0] = 1; //G
        canales[1] = 0; //B
        break;
    }
    int bins[2]= {64, 64};
    float rango[2]= {0, 256};
    const float *rangos[]= {rango, rango};
    calcHist(&img, 1, canales, noArray(), hist, 2, bins, rangos);

    Mat pinta(64, 64, CV_8UC1);
    double minval, maxval;
    minMaxLoc(hist, &minval, &maxval);
    for (int r= 0; r<64; r++)
        for (int g= 0; g<64; g++)
            pinta.at<uchar>(r, g)= 255-255*hist.at<float>(r, g)/maxval;
    crear_nueva(nres, pinta);
}


//---------------------------------------------------------------------------

void ver_histograma_ecualizado(int nfoto, int nres,int tipo)
{
    Mat img = foto[nfoto].img;
    Mat res;
    if (tipo == 1) {
        Mat hls;
        cvtColor(img, hls, COLOR_BGR2HLS_FULL);
        vector<Mat> canales;
        split(hls,canales);
        canales[0].convertTo(canales[0],CV_8U);
        canales[1].convertTo(canales[0],CV_8U);
        canales[2].convertTo(canales[0],CV_8U);
        equalizeHist(canales[0],canales[0]);
        equalizeHist(canales[1],canales[1]);
        equalizeHist(canales[2],canales[2]);
        merge(canales, hls);
        cvtColor(hls,res,COLOR_HLS2BGR_FULL);
    }
    else {
        Mat gris, hist;
        cvtColor(img, gris, COLOR_BGR2GRAY);
        int canales[1]= {0}, bins[1]= {256};
        float rango[2]= {0, 256};
        const float *rangos[]= {rango};
        calcHist(&gris, 1, canales, noArray(), hist, 1, bins, rangos);
        hist*= 255.0/norm(hist, NORM_L1);
        Mat lut(1, 256, CV_8UC1);
        float acum= 0.0;
        for (int i= 0; i<256; i++) {
            lut.at<uchar>(0, i)= acum;
            acum+= hist.at<float>(i);
        }
        LUT(img, lut, res);

    }
    crear_nueva(nres, res);
}


//---------------------------------------------------------------------------

void ajuste_lineal (int nfoto, double pmin, double pmax, bool guardar)
{
    Mat gris;
    Mat hist;
    cvtColor(foto[nfoto].img, gris, COLOR_BGR2GRAY);  // Conversión a gris
    int canales[1]= {0};
    int bins[1]= {256};
    float rango[2]= {0, 256};
    const float *rangos[]= {rango};
    calcHist(&gris, 1, canales, noArray(), hist, 1, bins, rangos);
    pmin = pmin / 100 * gris.cols * gris.rows;
    pmax = pmax / 100 * gris.cols * gris.rows;

    double acum = 0;
    int vmin;
    for (vmin = 0; vmin < 256 && acum < pmin; vmin++) {
        acum += hist.at<float>(vmin);
    }

    acum = 0;
    int vmax;
    for (vmax = 255; vmax > 0 && acum < pmax; vmax--) {
        acum += hist.at<float>(vmax);
    }

    if (vmax <= vmin)
        vmax = vmin + 1;

    double a = 255.0 / (vmax - vmin);
    double b = -vmin * a;

    Mat imgres;
    foto[nfoto].img.convertTo(imgres, CV_8UC3, a, b);
    imshow(foto[nfoto].nombre, imgres);

    if (guardar) {
        imgres.copyTo(foto[nfoto].img);
        foto[nfoto].modificada = true;
    }
}

//---------------------------------------------------------------------------

void escala_color (int nfoto, int nres)
{
    Mat gris;
    cvtColor(foto[nfoto].img, gris, COLOR_BGR2GRAY);
    cvtColor(gris, gris, COLOR_GRAY2BGR);

    // Tabla LUT
    Mat lut(1, 256, CV_8UC3);
    int vr = color_pincel.val[2], vg = color_pincel.val[1], vb = color_pincel.val[0];
    for (int A = 0; A < 256; A++) {
        if (A < 128) {
            lut.at<Vec3b>(A) = Vec3b(vb * A / 128, vg * A / 128, vr * A / 128);
        } else {
            lut.at<Vec3b>(A) = Vec3b(vb + (255 - vb) * (A - 128) / 128,
                                     vg + (255 - vg) * (A - 128) / 128,
                                     vr + (255 - vr) * (A - 128) / 128);
        }
    }

    Mat img;
    LUT(gris, lut, img);
    crear_nueva(nres, img);
}

//---------------------------------------------------------------------------

void media_ponderada (int nf1, int nf2, int nueva, double peso)
{
    Mat img= foto[nf1].img.clone();
    Mat cop;
    resize(foto[nf2].img, cop, img.size());
    addWeighted(img, peso, cop, 1.0-peso, 0, img);
    crear_nueva(nueva, img);
}

//---------------------------------------------------------------------------
void ver_mat_sat_lum(int nfoto, int matiz, double sat, double lum, bool guardar) {
    Mat hls;
    cvtColor(foto[nfoto].img, hls, COLOR_BGR2HLS_FULL);
    vector<Mat> canales;
    split(hls,canales);
    canales[0].convertTo(canales[0],CV_16S);
    canales[0] += matiz;
    bitwise_and(canales[0],Scalar(255),canales[0]);
    canales[0].convertTo(canales[0],CV_8U);
    canales[1] *= lum;
    canales[2] *= sat;
    merge(canales, hls);
    Mat res;
    cvtColor(hls,res,COLOR_HLS2BGR_FULL);
    imshow(foto[nfoto].nombre,res);
    if (guardar) {
        res.copyTo(foto[nfoto].img);
        foto[nfoto].modificada = true;
    }
}
//---------------------------------------------------------------------------

string Lt1(string cadena)
{
    QString temp= QString::fromUtf8(cadena.c_str());
    return temp.toLatin1().data();
}

//---------------------------------------------------------------------------

void copiar_a_nueva (int nfoto, int nres)
{
    crear_nueva(nres, foto[nfoto].img(foto[nfoto].roi).clone());
}

//---------------------------------------------------------------------------

void nueva_desde_portapapeles(int pl)
{
    const QClipboard *clipboard = QApplication::clipboard();
    QImage image = clipboard->image();
    if (!image.isNull()){
        cv::Mat mat(image.height(), image.width(),CV_8UC4, image.bits());
        cvtColor(mat, mat, COLOR_RGBA2RGB);
        crear_nueva(pl,mat);
    }
}

//---------------------------------------------------------------------------
void copiar_al_portapapeles(int nfoto){
    mataux = foto[nfoto].img.clone();
    cvtColor(mataux, mataux, COLOR_RGB2RGBA);
    QClipboard *clipboard = QApplication::clipboard();
    QImage img((uchar*)mataux.data, mataux.cols, mataux.rows, QImage::Format_RGB32);
    clipboard->setImage(img);
}


//---------------------------------------------------------------------------
void deshacer_accion(int factual) {
    if (!foto[factual].lista.isEmpty()){

        foto[factual].img = foto[factual].lista.takeLast(); //el punto y arcoiris
        imshow(foto[factual].nombre,foto[factual].img.clone());
    }
}

//---------------------------------------------------------------------------
void anadir_accion_a_lista(int factual) {

    Mat res= foto[factual].img.clone();
    if (foto[factual].lista.size() >= 3)
    {
        foto[factual].lista.removeFirst();
    }
    foto[factual].lista.append(res);
}

//---------------------------------------------------------------------------
void convertir_color_falso(int factual,int nres,int color_map, bool guardar)
{

        Mat img = foto[factual].img;
        Mat res;
        applyColorMap(img,res,color_map);
        imshow(foto[factual].nombre,res);
        if (guardar) {
            res.copyTo(foto[factual].img);
            foto[factual].modificada = true;
        }
}

void transformar_modelo_color(int factual,int nres, int tipo)
{
    Mat img = foto[factual].img.clone();
    switch(tipo) {
    case 0:
        cvtColor(img, img, COLOR_RGB2HLS);
        break;

    case 1:
        cvtColor(img, img, COLOR_RGB2HSV);
        break;

    case 2:
        cvtColor(img, img, COLOR_RGB2XYZ);
        break;

    case 3:
        cvtColor(img, img, COLOR_RGB2YUV);
        break;
    case 4:
        cvtColor(img, img, COLOR_RGB2Lab);
        break;
    case 5:
        cvtColor(img, img, COLOR_RGB2YCrCb);
        break;
    }
    crear_nueva(nres,img);
}

//---------------------------------------------------------------------------
QList<QString> ver_informacion(int factual)
{
    Mat imagen = foto[factual].img;
    QList<QString> lista;
    char buffer[15];
    sprintf(buffer,"%d x %d",imagen.rows,imagen.cols);
    lista.push_front(buffer);

    int profundidad = imagen.depth();
    string profundidadString;
    switch (profundidad) {
    case 0:
        profundidadString = "CV_8U";
        break;
    case 1:
        profundidadString = "CV_8S";
        break;
    case 2:
        profundidadString = "CV_16U";
        break;
    case 3:
        profundidadString = "CV_16S";
        break;
    case 4:
        profundidadString = "CV_32S";
        break;
    case 5:
        profundidadString = "CV_32F";
        break;
    case 6:
        profundidadString = "CV_64F";
        break;
    }
    lista.push_front(QString::fromStdString(profundidadString));

    string canales = to_string(imagen.channels());
    lista.push_front(QString::fromStdString(canales));

    size_t sizeInBytes = imagen.step[0] * imagen.rows;
    lista.push_front(QString::fromStdString(to_string(sizeInBytes)));

    Scalar color = mean(imagen);
    QColor media_color = QColor(color[2],color[1],color[0]);
    QString estilo= "background-color: rgb(";
    estilo+= QString::number(media_color.red())+",";
    estilo+= QString::number(media_color.green())+",";
    estilo+= QString::number(media_color.blue())+")";

    lista.push_front(estilo);
    return lista;
}

//---------------------------------------------------------------------------
void morfologia_matematica(int nfoto, int dilatacion,int erosion,int cerrar, int abrir, bool guardar) {
    Mat im = foto[nfoto].img;
    Mat res;
    Point anchor = Point(-1,-1);
    if (dilatacion != 0) {
        dilate(im,res,Mat(),anchor,dilatacion);
    }
    if (erosion != 0) {
        erode(im,res,Mat(),anchor,erosion);
    }
    if (cerrar != 0) {
        morphologyEx(im,res,MORPH_CLOSE,Mat(),anchor,abrir);
    }
    if (abrir != 0) {
        morphologyEx(im,res,MORPH_OPEN,Mat(),anchor,abrir);
    }
    imshow(foto[nfoto].nombre,res);
    if (guardar) {
        res.copyTo(foto[nfoto].img);
        foto[nfoto].modificada = true;
    }
}

void perfilar(int nfoto, int radio, double porcentaje,bool guardar) {

    Mat img = foto[nfoto].img;
    Mat lap, suma;
    Laplacian(img, lap, CV_16S,radio);
    img.convertTo(img, CV_16S);
    suma= img - porcentaje*lap;
    suma.convertTo(suma, CV_8U);

    imshow(foto[nfoto].nombre,suma);
    if (guardar) {
        suma.copyTo(foto[nfoto].img);
        foto[nfoto].modificada = true;
    }
}

void buscar_patron(int nfoto1, int nfoto2) {
    //Las imágenes img y templ deben ser de 1 solo canal, de 8 bits de profundidad o bien reales de 32 bits.
    Mat img = foto[nfoto1].img;
    Mat patron = foto[nfoto2].img;
    Mat resultado;
    matchTemplate(img, patron, resultado, TM_CCOEFF_NORMED);
    double min, max;
    Point pmax;
    minMaxLoc(resultado, &min, &max, nullptr, &pmax);
    while (max>0.5) {
        rectangle(img, pmax,Point(pmax.x+patron.cols,pmax.y+patron.rows),CV_RGB(255,0,0), 3);

        rectangle(resultado, Point(pmax.x-patron.cols,pmax.y-patron.rows),
                  Point(pmax.x+patron.cols,pmax.y+patron.rows),CV_RGB(0,0,0), -1);

        minMaxLoc(resultado, &min, &max, nullptr, &pmax);
        namedWindow("Patrón marcado", WINDOW_NORMAL);
        imshow("Patrón marcado", img);
    }
}
//--------------------------------------------------------------------------- Dejamos este comentado ya que es una versión que hicimos pero sin el re-escalado, previo a que viésemos el anexo.
//void rotar_x_angulo(int nfoto,int angulo,bool guardar)
//{
//    Mat img = foto[nfoto].img;

//    Point2f centro((img.cols-1)/2.0, (img.rows-1)/2.0);
//    Mat rot = getRotationMatrix2D(centro, angulo, 1.0);

//    Rect2f bbox = RotatedRect(cv::Point2f(), img.size(), angulo).boundingRect2f();

//    rot.at<double>(0,2) += bbox.width/2.0 - img.cols/2.0;
//    rot.at<double>(1,2) += bbox.height/2.0 - img.rows/2.0;

//    Mat res;
//    warpAffine(img, res, rot, bbox.size());
//    imshow(foto[nfoto].nombre,res);
//    if (guardar) {
//        res.copyTo(foto[nfoto].img);
//        foto[nfoto].modificada = true;
//    }
//}

void rotar_x_angulo(int nfoto,int angulo,int escala,bool guardar)
{
    Mat img = foto[nfoto].img;
    Mat res;
    double w= img.size().width, h= img.size().height;
    double sa= sin(angulo*M_PI/180), ca= cos(angulo*M_PI/180);
    double cx= -w/2*ca-h/2*sa, cy= w/2*sa-h/2*ca;
    sa= fabs(sa); ca= fabs(ca);
    Size tam((w*ca+h*sa)*escala, (h*ca+w*sa)*escala);
    Mat M= getRotationMatrix2D(Point2f(0,0), angulo, escala);
    M.at<double>(0,2)= tam.width/2+cx*escala;
    M.at<double>(1,2)= tam.height/2+cy*escala;
    warpAffine(img, res, M, tam);
    imshow(foto[nfoto].nombre,res);
    if (guardar) {
        res.copyTo(foto[nfoto].img);
        foto[nfoto].modificada = true;
    }
}

//---------------------------------------------------------------------------

void obtener_espectro(int nfoto,int nres)
{
    Mat im = foto[nfoto].img;
    Mat img;
    cvtColor(im, img, COLOR_BGR2GRAY);
    Mat escala;
    img.convertTo(escala, CV_32FC1, 1.0/255);
    Mat imagenDFT;
    dft(escala, imagenDFT, DFT_COMPLEX_OUTPUT);
    vector<Mat> canales;
    split(imagenDFT, canales);
    pow(canales[0], 2, canales[0]);
    pow(canales[1], 2, canales[1]);
    pow(canales[0]+canales[1], 0.5, imagenDFT);
    Mat res;
    imagenDFT.convertTo(res, CV_8UC1, -1, 255);

    /*reorganizar los cuadrantes de la imagen de Fourier
    para que el origen esté en el centro de la imagen*/
    res = res(Rect(0, 0, res.cols & -2, res.rows & -2));
    int cx = res.cols/2;
    int cy = res.rows/2;
    Mat q0(res, Rect(0, 0, cx, cy));   // Top-Left - Create a ROI per quadrant
    Mat q1(res, Rect(cx, 0, cx, cy));  // Top-Right
    Mat q2(res, Rect(0, cy, cx, cy));  // Bottom-Left
    Mat q3(res, Rect(cx, cy, cx, cy)); // Bottom-Right
    Mat tmp;                           // swap quadrants (Top-Left with Bottom-Right)
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);
    q1.copyTo(tmp);                    // swap quadrant (Top-Right with Bottom-Left)
    q2.copyTo(q1);
    tmp.copyTo(q2);

    crear_nueva(nres,res);

}

void balance_blancos(int nfoto,int nres)
{
    Mat img = foto[nfoto].img;
    Mat yuv;
    cvtColor(img,yuv,COLOR_BGR2YUV);
    vector<Mat> canales;
    split(yuv,canales);

    Scalar media_U = mean(canales[1]);
    Scalar media_V = mean(canales[2]);

    canales[1] += 128 - media_U[0];
    canales[2] += 128 - media_V[0];

    merge(canales, yuv);
    Mat res;
    cvtColor(yuv,res,COLOR_YUV2BGR);
    crear_nueva(nres,res);
}




