#ifndef DMAT_SAT_LUM_H
#define DMAT_SAT_LUM_H

#include <QDialog>

namespace Ui {
class dmat_sat_lum;
}

class dmat_sat_lum : public QDialog
{
    Q_OBJECT

public:
    explicit dmat_sat_lum(int numfoto, QWidget *parent = nullptr);
    ~dmat_sat_lum();

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_dial_valueChanged(int value);

    void on_dmat_sat_lum_accepted();

    void on_dmat_sat_lum_rejected();

private:
    int nfoto;
    Ui::dmat_sat_lum *ui;
};

#endif // DMAT_SAT_LUM_H
