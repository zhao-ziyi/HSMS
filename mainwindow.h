#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndexList>
#include <QCloseEvent>
#include <QStandardItem>
#include <QListWidget>
#include <QListWidgetItem>
#include <QMessageBox>

#include "datagroup.h"
#include "lib/api.h"
#include "personlist.h"
#include "ifsave.h"
#include "edit.h"
#include "find.h"
#include "about.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void ListPerson();
    QListWidgetItem *title;
    QListWidgetItem *pointing;
    ~MainWindow();
    bool finded{false};

private slots:
    void on_pushButton_clicked();

    void closeEvent (QCloseEvent *event);

    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionClose_triggered();

    void on_PersonList_itemClicked(QListWidgetItem *item);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_actionEdit_triggered();

    void on_actionDelete_triggered();


    void on_PersonList_itemDoubleClicked(QListWidgetItem *item);

    void on_Find_clicked();

    void find();

    void on_actionAbout_triggered();

    void on_actionQuit_triggered();

private:
    Ui::MainWindow *ui;
    DataGroup *dg;
    int times{1};
    Find f{};
};
#endif // MAINWINDOW_H
