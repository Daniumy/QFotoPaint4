#ifndef DPERSPECTIVA_H
#define DPERSPECTIVA_H
#include "imagenes.h"
#include <QDialog>

namespace Ui {
class dperspectiva;
}

class dperspectiva : public QDialog
{
    Q_OBJECT

public:
    explicit dperspectiva(QWidget *parent = nullptr);
    ~dperspectiva();

private slots:
    void on_listWidget_currentRowChanged(int currentRow);

    void on_listWidget_2_currentRowChanged(int currentRow);

    void on_dperspectiva_rejected();

    void on_dperspectiva_accepted();

private:
    Ui::dperspectiva *ui;
    int corresp[MAX_VENTANAS];
};

#endif // DPERSPECTIVA_H
