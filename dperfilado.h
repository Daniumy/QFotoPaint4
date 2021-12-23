#ifndef DPERFILADO_H
#define DPERFILADO_H

#include <QDialog>

namespace Ui {
class dperfilado;
}

class dperfilado : public QDialog
{
    Q_OBJECT

public:
    explicit dperfilado(QWidget *parent = nullptr);
    ~dperfilado();

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::dperfilado *ui;
};

#endif // DPERFILADO_H
