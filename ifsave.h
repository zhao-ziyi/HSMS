#ifndef IFSAVE_H
#define IFSAVE_H

#include <QDialog>
#include<QLabel>
#include<QFileDialog>
#define ACCEPT 1
#define REFUSE 2
#define CANCEL 0
namespace Ui {
class IfSave;
}

class IfSave : public QDialog
{
    Q_OBJECT

public:
    explicit IfSave(QWidget *parent = nullptr);
    ~IfSave();
    void SetFileName(QString name);
    int GetStatus();
private slots:
    void on_pushButton_clicked(bool checked);

    void on_pushButton_2_clicked(bool checked);
    void on_pushButton_3_clicked(bool checked);

private:
    Ui::IfSave *ui;
    int status{CANCEL};
};

#endif // IFSAVE_H
