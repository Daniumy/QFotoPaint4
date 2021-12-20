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

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    int nfoto;
    Ui::dmorfologia *ui;
};

#endif // DMORFOLOGIA_H
