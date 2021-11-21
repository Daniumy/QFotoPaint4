#ifndef DPINCHAR_H
#define DPINCHAR_H

#include <QDialog>

namespace Ui {
class dpinchar;
}

class dpinchar : public QDialog
{
    Q_OBJECT

public:
    explicit dpinchar(int numfoto,QWidget *parent = nullptr);
    ~dpinchar();

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::dpinchar *ui;
};

#endif // DPINCHAR_H
