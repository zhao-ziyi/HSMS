#ifndef EDIT_H
#define EDIT_H

#include <QWidget>
#include <QDialog>
#include<QListWidgetItem>
#include "datagroup.h"
#include "lib/api.h"
#include<QMessageBox>
namespace Ui {
class Add;
}

class Edit : public QDialog
{
    Q_OBJECT

public:
    explicit Edit(QWidget *parent = nullptr);
    void setdg(DataGroup*,QListWidgetItem *pointing);
    ~Edit();
    bool nameedit{false},idedit{false},gradeedit{false},genderedit{false},scoreedit{false};
    DataGroup *dg;
    int gender;
    int id;
    bool ifedit{false};
public slots:

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_NameIn_textEdited();


    void on_GradeIn_valueChanged();

    void on_ScoreIn_valueChanged();

    void on_BoySelect_clicked();

    void on_GirlSelect_clicked();

private:
    Ui::Add *ui;
};

#endif // EDIT_H
