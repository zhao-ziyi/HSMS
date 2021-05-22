#ifndef ADD_H
#define ADD_H

#include <QDialog>
#include "lib/api.h"
#include "datagroup.h"
#include<QMessageBox>

namespace Ui {
class Add;
}

class Add : public QDialog
{
    Q_OBJECT

public:
    explicit Add(QWidget *parent = nullptr);
    void setdg(DataGroup*dg);
    bool ifadd{false};
    ~Add();
    DataGroup *dg;
private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


private:
    Ui::Add *ui;
};

#endif // ADD_H
