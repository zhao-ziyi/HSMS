#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    setWindowTitle("About");
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());
    ui->label_3->setOpenExternalLinks(true);
    ui->label_3->setText("<a href=\"https://zz1.ink\">ZZ1(Zhao Ziyi)");
    ui->label_4->setOpenExternalLinks(true);
    ui->label_4->setText("<a href=\"https://blog.m1dsummer.top\">m1dsummer(Liu Hongpeng)");
}

About::~About()
{
    delete ui;
}
