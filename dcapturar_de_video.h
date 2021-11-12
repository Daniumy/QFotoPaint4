#ifndef DCAPTURAR_DE_VIDEO_H
#define DCAPTURAR_DE_VIDEO_H

#include <QDialog>
#include "imagenes.h"

namespace Ui {
class dcapturar_de_video;
}

class dcapturar_de_video : public QDialog
{
    Q_OBJECT

public:
    explicit dcapturar_de_video(QString nombre, QWidget *parent = nullptr);
    ~dcapturar_de_video();
    bool isOpened();

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_spinBox_valueChanged(int arg1);

    void on_dcapturar_de_video_finished(int result);

    void on_dcapturar_de_video_rejected();

    void on_dcapturar_de_video_accepted();

private:
    VideoCapture cap;
    Ui::dcapturar_de_video *ui;
};

#endif // DCAPTURAR_DE_VIDEO_H
