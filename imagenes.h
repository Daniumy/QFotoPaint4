#ifndef IMAGENES_H
#define IMAGENES_H

#include <string>
#include <QList>
using namespace std;
#include <opencv2/opencv.hpp>
using namespace cv;

///////////////////////////////////////////////////////////////////
/////////  DEFINICIONES PUBLICAS                     //////////////
///////////////////////////////////////////////////////////////////

#define MAX_VENTANAS 100
// Número máximo de ventanas permitido

#define DESP_X_HIJO 70
#define DESP_Y_HIJO 50
// Desplazamiento en X e Y de las ventanas hijas de la ventana principal


///////////////////////////////////////////////////////////////////
/////////  TIPOS DE DATOS PROPIOS                    //////////////
///////////////////////////////////////////////////////////////////

// STRUCT ventana
//    Representa la información asociada a una imagen que está siendo
//    editada actualmente en la aplicación

struct ventana {
    bool usada;          // Indica si se está usando actualmente esta posición
    bool modificada;     // Ha sido modificada después de abrirla o crearla
    string nombre;       // Nombre de la ventana codificada en UTF8
    string nombref;      // Nombre del fichero de imagen codificado en Latin1
    int orden;           // Número de orden entre las ventanas abiertas
    Rect roi;            // Región de interés seleccionada
    Mat img;             // Imagen almacenada en esta posición
    QList<Mat> lista;    // Lista de imagenes anteriores a cierta acción
};

// ENUM tipo_herramienta
//    Enumerado con los distintos tipos posibles de herramientas
//    que se pueden usar. Añadir nuevas aquí

enum tipo_herramienta {HER_PUNTO, HER_LINEA, HER_SELECCION, HER_RECTANGULO, HER_ELIPSE, HER_ARCOIRIS};


///////////////////////////////////////////////////////////////////
/////////  VARIABLES PÚBLICAS                        //////////////
///////////////////////////////////////////////////////////////////

extern ventana foto[MAX_VENTANAS];
// El array foto guarda la información de todas las imágenes abiertas
// actualmente o que pueden ser abiertas, hasta un máximo de MAX_VENTANAS

extern tipo_herramienta herr_actual;
// Herramienta que se ha seleccionado actualmente

extern int radio_pincel;
// Radio actual para pintar puntos y líneas

extern Scalar color_pincel;
// Color actual del pincel

extern int difum_pincel;
// Difuminado actual del pincel

extern bool preguntar_guardar;
// Al cerrar una imagen modificada, preguntar si se guarda o no

///////////////////////////////////////////////////////////////////
/////////  FUNCIONES DE MANEJO DE VENTANAS           //////////////
///////////////////////////////////////////////////////////////////

void inic_fotos (void);
// Inicializa el array foto, de imágenes abiertas actualmente

void fin_fotos (void);
// Libera las imágenes del array foto

int primera_libre (void);
// Busca la primera entrada libre del array foto

void crear_nueva (int nfoto, int ancho, int alto, Scalar color);
// Crea una nueva entrada, en la posición nfoto, con el ancho y el alto dados,
// de profundidad CV_8U y 3 canales. color indica el color de fondo

void crear_nueva (int nfoto, Mat img);
// Crea una nueva entrada, en la posición nfoto, usando la imagen dada en img

void crear_nueva (int nfoto, string nombre);
// Crea una nueva entrada, en la posición nfoto, leyéndola del archivo nombre.
// Si no se puede leer, no hace nada

void mostrar (int nfoto);
// Muestra la imagen de la entrada nfoto en la ventana correspondiente

void guardar_foto (int nfoto, string nombre= "");
// Guarda en disco la imagen de nfoto, con el nombre dado. Si el nombre
// es "", usa el nombre de la imagen en el array foto

void cerrar_foto (int nfoto, bool destruir_ventana= true);
// Elimina la entrada en la posición nfoto. destruir_ventana indica si debe
// destruirse la ventana de HighGUI (ya que si lo ha hecho el usuario, no
// debe volver a hacerse)

int nombre_a_numero (string nombre);
// Dado un nombre de ventana, busca su número en el array foto.
// Si no lo encuentra devuelve -1

int foto_activa (void);
// Devuelve el número de la ventana de imagen activa (la que esté en primer
// lugar). Si no hay ninguna devuelve -1

int num_fotos (int &usadas, int &modificadas);
// Devuelve el número de fotos que hay abiertas y modificadas actualmente

void reset_callback(int nfoto);
//Vuelve a poner el callback a una ventana
///////////////////////////////////////////////////////////////////
/////////  FUNCIONES DE PROCESAMIENTO DE IMAGENES    //////////////
///////////////////////////////////////////////////////////////////

void invertir (int nfoto, int nres);
// Invierte la imagen contenida en nfoto y la almacena en nres, que será una
// nueva ventana

void rotar_angulo (Mat imagen, Mat &imgRes, double angulo, double escala, int modo);
void rotar_angulo (int nfoto, Mat &imgRes, double angulo, double escala= 1.0, int modo= 0);
// Rota la imagen contenida en nfoto, en la cantidad grado
// y la almacena el resultado en imgRes. La imagen de salida
// siempre está centrada. modo indica: 0 = el tamaño de la imagen
// de salida es el mismo que la original; 1 = tamaño máximo (caber todo);
// 2 = tamaño mínimo (sin bordes)

void rotar_exacto (int nfoto, int nres, int grado);
// Rota la imagen contenida en nfoto, en la cantidad 90*grado
// y la almacena en nres. Se trata siempre de una rotación exacta

void ver_brillo_contraste_gama (int nfoto, double suma, double prod,
                                double gama, bool guardar= false);
// Modifica la imagen en nfoto, tomando para cada píxel A(x,y) el valor:
// A(x,y)*prod + suma. Si guardar==true se guarda la imagen, y en otro caso
// solo se visualiza el resultado, pero sin guardar

void ver_perspectiva(int nfoto1, int nfoto2, Point2f pt1[],Point2f pt2[],bool guardar = false);
//El usuario podrá seleccionar una imagen origen y una imagen
//destino. El usuario podrá seleccionar 4 puntos en la imagen origen y 4 puntos en
//la de destino. Y al pinchar aceptar, se hará la correspondiente transformación
//perspectiva de la imagen origen al destino

void ver_mat_sat_lum(int nfoto, int matiz, double sat, double lum, bool guardar = false);
//Ajuste de matriz, saturación y luminosidad

void ver_pinchar_estirar(int nfoto, int cx, int cy, double radio, double a, bool guardar=false);
//Transformaciones geométricas de pinchar/estirar una imagen.

void ver_suavizado (int nfoto, int ntipo, int tamx, int tamy,
                    bool guardar= false);
// Modifica la imagen en nfoto, aplicando un suavizado de tamaño dado. ntipo
// puede ser: 1=GAUSIANO; 2=MEDIA. Si guardar==true se guarda la imagen, y
// en otro caso solo se visualiza el resultado, pero sin guardar

void ver_bajorrelieve (int nfoto, double angulo, double grado, int ntextura, bool guardar = false);
// Aplica un efecto de bajorrelieve a la imagen, pudiendo seleccionar
// la dirección y cantidad del efecto. Se podrá seleccionar una textura de fondo, o
// bien un fondo gris.

void ver_histograma (int nfoto, int nres, int canal);
// Mostrar el histograma de una imagen, ya sea del valor de gris o de los canales por
// separado (R, G o B). Se debe usar un formato parecido al que se muestra a la derecha
// (es decir, mostrando la escala horizontal y la vertical en la imagen del histograma resultante).

void ajuste_lineal (int nfoto, double pmin, double pmax, bool guardar = false);
// Operación de ajuste o estiramiento lineal del histograma. Se debe poder indicar
// el porcentaje de píxeles que se dejan a la derecha y a la izquierda en el histograma.

void escala_color (int nfoto, int nres);
// Convertir una imagen a escala de grises o escaa de color, según el color seleccionado actualmente.

void media_ponderada (int nf1, int nf2, int nueva, double peso);
// Calcula la media ponderada entre la imagen nf1 y la nf2, según el peso dado,
// y almacena el resultado en la posición nueva. Se aplica la fórmula:
// nueva(x,y):= peso*nf1(x,y)+(1-peso)*nf2(x,y). La imagen nf2 se reescala al
// tamaño de nf1

string Lt1(string cadena);
// Convertir una cadena de UTF8 a Latin1

void copiar_a_nueva (int nfoto, int nres);
// Crea una nueva imagen con el ROI de la imagen actual. Si no hay ROI seleccionado,
// se debe copiar toda la imagen actual

void nueva_desde_portapapeles(int pl);
//Crea una nueva imagen de la que se encuentra en el portapapeles de windows.

void copiar_al_portapapeles(int nfoto);
//Copia la el ROI de la imagen actual y lo copia en el portapapeles

void deshacer_accion(int factual);

void anadir_accion_a_lista(int factual);

#endif // IMAGENES_H
