#ifndef DROTARYESCALAR_H
#define DROTARYESCALAR_H

#include <QDialog>

namespace Ui {
class drotaryescalar;
}

class drotaryescalar : public QDialog
{
    Q_OBJECT

public:
    explicit drotaryescalar(QWidget *parent = nullptr);
    ~drotaryescalar();

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_horizontalSlider_2_valueChanged(int value);

private:
    int nfoto;
    Ui::drotaryescalar *ui;
};

#endif // DROTARYESCALAR_H
