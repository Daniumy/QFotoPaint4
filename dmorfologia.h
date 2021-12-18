#ifndef DMORFOLOGIA_H
#define DMORFOLOGIA_H

#include <QDialog>

namespace Ui {
class dmorfologia;
}

class dmorfologia : public QDialog
{
    Q_OBJECT

public:
    explicit dmorfologia(int numfoto, QWidget *parent = nullptr);
    ~dmorfologia();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();
private:
    int nfoto;
    Ui::dmorfologia *ui;
};

#endif // DMORFOLOGIA_H