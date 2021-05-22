#include "edit.h"
#include"ui_add.h"

Edit::Edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add)
{
    ui->setupUi(this);
    setWindowTitle("Edit student");
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());
    ui->pushButton->setEnabled(false);
    ui->IDIn->setEnabled(false);
}

void Edit::setdg(DataGroup *dgin,QListWidgetItem *pointing)
{
    dg=dgin;
    QStringList temp=pointing->text().split('\t');
    ui->NameIn->setText(temp[0]);
    ui->IDIn->setText(temp[1]);
    ui->GradeIn->setValue(temp[2].toInt());
    ui->ScoreIn->setValue(temp[4].toDouble());
    if(temp[3]=="Boy"){
        ui->BoySelect->click();
        gender=MALE;
    }
    else
    {
        ui->GirlSelect->click();
        gender=FEMALE;
    }
    id=temp[1].toInt();
}

Edit::~Edit()
{
    delete ui;
}

void Edit::on_pushButton_clicked()
{
    Student su=getStudentById(id,dg->a);
    if(nameedit){
        QByteArray temp=ui->NameIn->text().toLatin1();
        if(setStudentName(su,temp.data())==FAIL){
            QMessageBox::warning(nullptr,QString("Prompt"),QString("Name length out of limit"),QMessageBox::Ok);
            return;
        }
    }
    if(gradeedit){
        setStudentGrade(su,ui->GradeIn->value());
    }
    if(scoreedit){
        setStudentScore(su,ui->ScoreIn->value());
    }
    if(genderedit){
        if(ui->BoySelect->isChecked()){
            setStudentGender(su,MALE);
        }
        else setStudentGender(su,FEMALE);
    }
    close();
    accept();
    return;
}

void Edit::on_pushButton_2_clicked()
{
    close();
    return;
}

void Edit::on_NameIn_textEdited()
{
    nameedit=true;
    ui->pushButton->setEnabled(true);
}

void Edit::on_GradeIn_valueChanged()
{
    gradeedit=true;
    ui->pushButton->setEnabled(true);
}

void Edit::on_ScoreIn_valueChanged()
{
    scoreedit=true;
    ui->pushButton->setEnabled(true);
}

void Edit::on_GirlSelect_clicked()
{
    if(gender==MALE){
        genderedit=true;
        ui->pushButton->setEnabled(true);
    }
}

void Edit::on_BoySelect_clicked()
{
    if(gender==FEMALE)
    {
        genderedit=true;
        ui->pushButton->setEnabled(true);
    }
}
