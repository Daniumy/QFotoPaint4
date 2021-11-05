#ifndef DAJUSTE_LINEAL_H
#define DAJUSTE_LINEAL_H

#include <QDialog>

namespace Ui {
class dajuste_lineal;
}

class dajuste_lineal : public QDialog
{
    Q_OBJECT

public:
    explicit dajuste_lineal(int numfoto, QWidget *parent = nullptr);
    ~dajuste_lineal();

private slots:
    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_dajuste_lineal_accepted();

    void on_dajuste_lineal_rejected();

private:
    int nfoto;
    Ui::dajuste_lineal *ui;
};

#endif // DAJUSTE_LINEAL_H
