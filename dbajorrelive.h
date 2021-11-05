#ifndef DBAJORRELIVE_H
#define DBAJORRELIVE_H

#include <QDialog>

namespace Ui {
class dbajorrelive;
}

class dbajorrelive : public QDialog
{
    Q_OBJECT

public:
    explicit dbajorrelive(int numfoto, QWidget *parent = nullptr);
    ~dbajorrelive();

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_dial_valueChanged(int value);

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

private:
    int nfoto;
    int ntextura;
    Ui::dbajorrelive *ui;
};

#endif // DBAJORRELIVE_H
