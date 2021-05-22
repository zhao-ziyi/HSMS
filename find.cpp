#include "find.h"
#include "ui_find.h"

Find::Find(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Find)
{
    ui->setupUi(this);
    setWindowTitle(QString("Find"));
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());
    ui->label_2->setVisible(false);
    ui->FindNext->setEnabled(false);
}

Find::~Find()
{
    delete ui;
}

void Find::setlw(QListWidget * ilw,QListWidgetItem *title)
{
    lw=ilw;
    this->title=title;
}

void Find::on_Cancel_clicked()
{
    close();
}




void Find::on_FindNext_clicked()
{
    if(edited){
        edited=false;
        list=lw->findItems(ui->lineEdit->text(),Qt::MatchContains);
        if(list.length()!=0){
            if(list[0]==title)list.pop_front();
            if(list.length()!=0)
            {
                ui->label_2->setText(QString::number(list.length())+QString("results"));
                it=list.begin();
                (*(it++))->setSelected(true);
                finded=true;
                emit find();
            }
            if(it==list.end()){
                ui->FindNext->setEnabled(false);
            }

        }
        else{
            ui->label_2->setText(QString("No matching results"));
        }

        ui->label_2->setVisible(true);
    }
    else{
        if(finded)
        {
            (*(it++))->setSelected(true);
            if(it==list.end()){
                ui->FindNext->setEnabled(false);
            }
        }
        else{
            ui->label_2->setText(QString("No matching results"));
            ui->label_2->setVisible(true);
        }
    }
}


void Find::on_lineEdit_textEdited()
{
    edited=true;
    ui->FindNext->setEnabled(true);
    ui->label_2->setVisible(false);
    finded=false;
}

