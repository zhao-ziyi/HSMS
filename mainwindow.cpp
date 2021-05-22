#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString temp="untitled";
    temp.push_back(QChar(times+'0'));
    this->dg=new DataGroup(temp);
    times++;
    setWindowTitle(*dg->GetTitle());
    ListPerson();
    QWidget::connect(&f,SIGNAL(find()),this,SLOT(find()));
}

void MainWindow::ListPerson()
{
    ui->PersonList->clear();
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->actionEdit->setEnabled(false);
    ui->actionDelete->setEnabled(false);
    title=new QListWidgetItem(QString("Name\t")+QString("ID\t")+QString("Grade\t")+QString("Gender\t")+QString("Score\t"),ui->PersonList);

    ui->PersonList->addItem(title);
    QString gender;
    for(StudentItem it=this->dg->a->head;it!=NULL;it=it->next){
        if(it->item->gender==FEMALE){
            gender="Girl";
        }
        else gender="Boy";
        QListWidgetItem *temp=new QListWidgetItem(QString(it->item->name)+QString("\t")
                                                  +QString::number(it->item->id)+QString("\t")
                                                  +QString::number(it->item->grade)+QString("\t")
                                                  +gender+QString('\t')
                                                  +QString::number(it->item->score)+QString("\t"));
        ui->PersonList->addItem(temp);
    }
    ui->TotalLabel->setText(QString("Total: ")+QString::number(dg->a->length));
    if(dg->ifchanged){
        setWindowTitle(*dg->GetTitle()+QString('*'));
    }
    else setWindowTitle(*dg->GetTitle());
}

MainWindow::~MainWindow()
{
    delete ui;
    delete dg;
}

void MainWindow::closeEvent (QCloseEvent *event){
    f.close();
    if(dg->ifchanged){
        IfSave i;
        i.SetFileName(*dg->GetTitle());
        i.exec();
        int status=i.GetStatus();
        if(status==0){
            event->ignore();
        }
        else if(status==1){
            if(dg->WriteToExistFile()){
                event->accept();
            }
            else event->ignore();
        }
    }
    else{
        event->accept();
    }

}

void MainWindow::on_pushButton_clicked()
{
        if(dg->AddData())
        {
            dg->ifchanged=true;
            ListPerson();
        }
}


void MainWindow::on_actionNew_triggered()
{
    if(close()){
        delete dg;
        QString temp="untitled";
        temp.push_back(QChar(times+'0'));
        this->dg=new DataGroup(temp);
        times++;
        this->show();
        setWindowTitle(*dg->GetTitle());
        ListPerson();
    }
}


void MainWindow::on_actionOpen_triggered()
{
    DataGroup *ndg=new DataGroup();
    if(ndg->OpenFile()){
        if(close()){
            delete dg;
            this->dg=ndg;
            this->show();
            ListPerson();
            setWindowTitle(*dg->GetTitle());
        }
    }
    else delete ndg;
}


void MainWindow::on_actionSave_triggered()
{
    if(dg->ifchanged){
        dg->WriteToExistFile();
        dg->ifchanged=false;
    }
}


void MainWindow::on_actionSave_as_triggered()
{
    dg->WriteToFile();
}


void MainWindow::on_actionClose_triggered()
{
    close();
}

void MainWindow::on_PersonList_itemClicked(QListWidgetItem *item)
{
    if(item!=title){
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        ui->actionEdit->setEnabled(true);
        ui->actionDelete->setEnabled(true);
        pointing=item;
    }
    else {
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        ui->actionEdit->setEnabled(false);
        ui->actionDelete->setEnabled(false);
    }
}




void MainWindow::on_pushButton_2_clicked()
{
    Edit e;
    e.setdg(dg,pointing);
    if(e.exec()){
        dg->ifchanged=true;
        ListPerson();

    }
}


void MainWindow::on_pushButton_3_clicked()
{
    if(QMessageBox::warning(nullptr,QString("Prompt"),QString("Really want to delete?"),QMessageBox::Ok,QMessageBox::Cancel)==QMessageBox::Ok)
    {
        QString temp=pointing->text();
        QStringList listtemp=temp.split('\t');
        temp=listtemp[1];
        Student su=getStudentById(temp.toInt(),dg->a);
        deleteStudent(su,dg->a);
        ListPerson();
        dg->ifchanged=true;
    }
}


void MainWindow::on_actionEdit_triggered()
{
    on_pushButton_2_clicked();
}


void MainWindow::on_actionDelete_triggered()
{
    on_pushButton_3_clicked();
}




void MainWindow::on_PersonList_itemDoubleClicked(QListWidgetItem *item)
{
    if(item!=title)
    {
        on_pushButton_2_clicked();
    }
}


void MainWindow::on_Find_clicked()
{
    f.show();
    f.raise();
    f.activateWindow();
    f.setlw(ui->PersonList,title);

}

void MainWindow::find()
{
    QList<QListWidgetItem*> l=ui->PersonList->selectedItems();
    pointing=l[0];
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->actionEdit->setEnabled(true);
    ui->actionDelete->setEnabled(true);
}


void MainWindow::on_actionAbout_triggered()
{
    About a;
    a.exec();
}


void MainWindow::on_actionQuit_triggered()
{
    close();
}

