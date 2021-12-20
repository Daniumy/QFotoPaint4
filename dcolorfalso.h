#ifndef DCOLORFALSO_H
#define DCOLORFALSO_H

#include <QDialog>

namespace Ui {
class dcolorfalso;
}

class dcolorfalso : public QDialog
{
    Q_OBJECT

public:
    explicit dcolorfalso(QWidget *parent = nullptr);
    ~dcolorfalso();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    int ultimo_usado = 0;
    int nfoto;
    Ui::dcolorfalso *ui;
};

#endif // DCOLORFALSO_H
