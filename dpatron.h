#ifndef DPATRON_H
#define DPATRON_H

#include <QDialog>

namespace Ui {
class dpatron;
}

class dpatron : public QDialog
{
    Q_OBJECT

public:
    explicit dpatron(int numfoto,QWidget *parent = nullptr);
    ~dpatron();

private slots:
    void on_toolButton_clicked();

private:
    int nfoto;
    QWidget *padre;
    Ui::dpatron *ui;
};

#endif // DPATRON_H
