#ifndef DIALOGINFORMATION_H
#define DIALOGINFORMATION_H

#include <QDialog>

namespace Ui {
class dialoginformation;
}

class dialoginformation : public QDialog
{
    Q_OBJECT

public:
    explicit dialoginformation(int numfoto,QWidget *parent = nullptr);
    ~dialoginformation();

private slots:
    void on_pushButton_clicked();

private:
    int nfoto;
    Ui::dialoginformation *ui;
};

#endif // DIALOGINFORMATION_H
