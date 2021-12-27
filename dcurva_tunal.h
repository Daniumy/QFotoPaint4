#ifndef DCURVA_TUNAL_H
#define DCURVA_TUNAL_H

#include <QDialog>

namespace Ui {
class dcurva_tunal;
}

class dcurva_tunal : public QDialog
{
    Q_OBJECT

public:
    explicit dcurva_tunal(int numfoto,QWidget *parent = nullptr);
    ~dcurva_tunal();

private slots:
    void on_dcurva_tunal_accepted();

    void on_dcurva_tunal_rejected();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::dcurva_tunal *ui;
};

#endif // DCURVA_TUNAL_H
