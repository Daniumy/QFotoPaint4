#ifndef SUAVIZADOS_H
#define SUAVIZADOS_H

#include <QDialog>

namespace Ui {
    class suavizados;
}

class suavizados : public QDialog {
    Q_OBJECT
public:
    suavizados(int tipo, QWidget *parent = nullptr);
    ~suavizados();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::suavizados *ui;
    int nfoto;
    int num_tipo;            // Tipo de suavizado que se aplica: 1=GAUSIANO, 2=MEDIA

private slots:
    void on_buttonBox_rejected();
    void on_buttonBox_accepted();
    void on_horizontalSlider_2_valueChanged(int value);
    void on_horizontalSlider_valueChanged(int value);
    void on_spinBox_2_valueChanged(int );
    void on_spinBox_valueChanged(int );
    void on_checkBox_stateChanged(int arg1);
};

#endif // SUAVIZADOS_H
