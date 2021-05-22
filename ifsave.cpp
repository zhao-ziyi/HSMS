#include "ifsave.h"
#include "ui_ifsave.h"

IfSave::IfSave(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IfSave)
{
    ui->setupUi(this);
    setWindowTitle("Prompt");
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());
}

IfSave::~IfSave()
{
    delete ui;
}

void IfSave::SetFileName(QString name)
{
    name.push_back("\" to file?");
    name.push_front("Whether to save \"");
    ui->label_2->setText(name);
}

int IfSave::GetStatus()
{
    return status;
}



void IfSave::on_pushButton_clicked(bool checked)
{
    status=ACCEPT;
    close();
}


void IfSave::on_pushButton_2_clicked(bool checked)
{
    status=REFUSE;
    close();
}


void IfSave::on_pushButton_3_clicked(bool checked)
{
    close();
}

