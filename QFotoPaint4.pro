#-------------------------------------------------
#
# Project created by QtCreator 2019-10-10T21:16:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QFotoPaint4

TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
    dajuste_lineal.cpp \
    dbajorrelive.cpp \
    dcapturar_de_video.cpp \
    dcolorfalso.cpp \
    dcurva_tunal.cpp \
    dialoginformation.cpp \
    dmat_sat_lum.cpp \
    dmorfologia.cpp \
    dpatron.cpp \
    dperfilado.cpp \
    dperspectiva.cpp \
    dpinchar.cpp \
    drotaryescalar.cpp \
    mainwindow.cpp \
    imagenes.cpp \
    dialognueva.cpp \
    brillocontraste.cpp \
    suavizados.cpp \
    video.cpp \
    rotaravideo.cpp \
    mediaponderada.cpp \
    acercade.cpp \
    mediadevideo.cpp

HEADERS  += mainwindow.h \
    dajuste_lineal.h \
    dbajorrelive.h \
    dcapturar_de_video.h \
    dcolorfalso.h \
    dcurva_tunal.h \
    dialoginformation.h \
    dmat_sat_lum.h \
    dmorfologia.h \
    dpatron.h \
    dperfilado.h \
    dperspectiva.h \
    dpinchar.h \
    drotaryescalar.h \
    imagenes.h \
    dialognueva.h \
    brillocontraste.h \
    suavizados.h \
    video.h \
    rotaravideo.h \
    mediaponderada.h \
    acercade.h \
    mediadevideo.h

FORMS    += mainwindow.ui \
    dajuste_lineal.ui \
    dbajorrelive.ui \
    dcapturar_de_video.ui \
    dcolorfalso.ui \
    dcurva_tunal.ui \
    dialoginformation.ui \
    dialognueva.ui \
    brillocontraste.ui \
    dmat_sat_lum.ui \
    dmorfologia.ui \
    dpatron.ui \
    dperfilado.ui \
    dperspectiva.ui \
    dpinchar.ui \
    drotaryescalar.ui \
    suavizados.ui \
    rotaravideo.ui \
    mediaponderada.ui \
    acercade.ui \
    mediadevideo.ui

INCLUDEPATH += "C:\OpenCV\OpenCV4.1.1G\include"

LIBS += -L"C:\OpenCV\OpenCV4.1.1G\lib"\
        -llibopencv_world411

RESOURCES += recursos.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
