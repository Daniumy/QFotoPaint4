#include "dcapturar_de_video.h"
#include "ui_dcapturar_de_video.h"

dcapturar_de_video::dcapturar_de_video(QString nombre, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dcapturar_de_video)
{
    ui->setupUi(this);
    if (cap.open(nombre.toLatin1().data())) {
        int nframes = cap.get(CAP_PROP_FRAME_COUNT);
        ui->horizontalSlider->setMaximum(nframes - 1);
        ui->spinBox->setMaximum(nframes - 1);

        Mat frame;
        cap.read(frame);
        namedWindow("Frame del vídeo", 0);
        imshow("Frame del vídeo", frame);
    }
}

dcapturar_de_video::~dcapturar_de_video()
{
    delete ui;
}

void dcapturar_de_video::on_spinBox_valueChanged(int arg1)
{
    ui->horizontalSlider->setValue(arg1);
}

void dcapturar_de_video::on_horizontalSlider_valueChanged(int value)
{
    ui->spinBox->setValue(value);
    cap.set(CAP_PROP_POS_FRAMES, value);

    Mat frame;
    cap.read(frame);
    namedWindow("Frame del vídeo", 0);
    imshow("Frame del vídeo", frame);
}


bool dcapturar_de_video::isOpened() {
    return cap.isOpened();
}

void dcapturar_de_video::on_dcapturar_de_video_finished(int result)
{

}

void dcapturar_de_video::on_dcapturar_de_video_rejected()
{
    destroyWindow("Frame del vídeo");
}

void dcapturar_de_video::on_dcapturar_de_video_accepted()
{
    cap.set(CAP_PROP_POS_FRAMES, ui->spinBox->value());

    Mat frame;
    cap.read(frame);
    crear_nueva(primera_libre(), frame);
    destroyWindow("Frame del vídeo");
}
