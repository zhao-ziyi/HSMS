#ifndef FIND_H
#define FIND_H

#include <QDialog>
#include <QListWidget>
#include <QList>
#include <QListWidgetItem>

namespace Ui {
class Find;
}

class Find : public QDialog
{
    Q_OBJECT

public:
    explicit Find(QWidget *parent = nullptr);
    ~Find();
    void setlw(QListWidget *,QListWidgetItem*);
    bool finded{false};
    QList<QListWidgetItem*> list;
    bool edited{false};
    QList<QListWidgetItem*>::Iterator it;

private slots:
    void on_Cancel_clicked();



    void on_FindNext_clicked();

    void on_lineEdit_textEdited();

private:
    Ui::Find *ui;
    QListWidget *lw;
    QListWidgetItem *title;
signals:
    void find();
};

#endif // FIND_H
