#include "add.h"
#include "ui_add.h"


Add::Add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add)
{
    ui->setupUi(this);
    setWindowTitle("Add new student");
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());
    setWindowModality(Qt::ApplicationModal);
}

void Add::setdg(DataGroup(*dg))
{
    this->dg=dg;
}

Add::~Add()
{
    delete ui;
}

void Add::on_pushButton_clicked()
{
    QString name=ui->NameIn->text();
    QString id=ui->IDIn->text();
    int grade=ui->GradeIn->value();
    double score=ui->ScoreIn->value();
    bool boy=ui->BoySelect->isChecked();
    bool girl=ui->GirlSelect->isChecked();
    if(name.isEmpty()||id.isEmpty()||(boy==girl)){
        QMessageBox::warning(nullptr,QString("Prompt"),QString("Please fill in the complete data"),QMessageBox::Ok);

    }
    else{
        QByteArray temp=name.toLatin1();
        int gender;
        if(boy==true)gender=MALE;else gender=FEMALE;
        if(id.toInt()==0){
            QMessageBox::warning(nullptr,QString("Prompt"),QString("Invalid ID"),QMessageBox::Ok);
            return;
        }
        Student test=getStudentById(id.toInt(),dg->a);
        if(test!=NULL){
            QMessageBox::warning(nullptr,QString("Prompt"),QString("ID already exist"),QMessageBox::Ok);
            return;
        }
        Student su=registerStudent(temp.data(),id.toInt(),gender,dg->a);
        if(su==NULL){
            QMessageBox::warning(nullptr,QString("Prompt"),QString("Name length out of limit"),QMessageBox::Ok);
            return;
        }

        setStudentGrade(su,grade);
        setStudentScore(su,score);
        ifadd=true;
        close();

    }
}


void Add::on_pushButton_2_clicked()
{
    close();
    return;
}

