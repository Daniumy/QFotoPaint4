#ifndef BRILLOCONTRASTE_H
#define BRILLOCONTRASTE_H

#include <QDialog>

namespace Ui {
    class brillocontraste;
}

class brillocontraste : public QDialog {
    Q_OBJECT
public:
    brillocontraste(QWidget *parent = nullptr);
    ~brillocontraste();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::brillocontraste *ui;
    int nfoto;
    double suma;
    double multiplica;
    void actualiza_suma_multiplica();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void on_horizontalSlider_2_valueChanged(int value);
    void on_horizontalSlider_valueChanged(int value);
    void on_spinBox_2_valueChanged(int );
    void on_spinBox_valueChanged(int );
    void on_checkBox_stateChanged(int arg1);
};

#endif // BRILLOCONTRASTE_H
