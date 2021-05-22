#include "datagroup.h"
#include "add.h"
#include "ifsave.h"
#include "mainwindow.h"

DataGroup::DataGroup()
{
    a=newStudentArray();
}
DataGroup::DataGroup(QString &title){
    this->title=title;
    a=newStudentArray();
}
bool DataGroup::AddData(){
    Add a;
    a.setdg(this);
    a.show();
    a.exec();
    return a.ifadd;
}

QString *DataGroup::GetTitle()
{
    return &(this->title);
}

DataGroup::~DataGroup()
{
    destroyStudentArray(a);
}

bool DataGroup::WriteToFile()
{
    QString temp;
    if(QSysInfo::kernelType()=="darwin"){
        temp="../../../";
    }
    else temp="./";
    temp.push_back(this->title);
    QString fileName = QFileDialog::getSaveFileName(nullptr,"Save File", temp, "Data Files (*.dat)");
    if(fileName.isEmpty()){
        return false;
    }
    QByteArray temp2=fileName.toLatin1();
    saveStudentsToFile(temp2.data(),a);
    this->ifchanged=false;
    return true;
}

int DataGroup::IfWrite(DataGroup &dg)
{
    IfSave i;
    i.SetFileName(*dg.GetTitle());
    i.show();
    i.exec();
    return i.GetStatus();
}

bool DataGroup::OpenFile()
{
    QString temp;
    if(QSysInfo::kernelType()=="darwin"){
        temp="../../../";
    }
    else temp="./";
    QString fileName = QFileDialog::getOpenFileName(nullptr,"Open File", temp, "Data Files (*.dat)");
    if(fileName.isEmpty()){
        return false;
    }
    this->filepath=fileName;
    QByteArray temp2=fileName.toLatin1();
    a=loadStudentsFromFile(temp2.data());
    QStringList sl=fileName.split('/');
    auto it=sl.rbegin();
    sl=it->split('.');
    auto it2=sl.begin();
    this->title=*it2;
    return true;
}

bool DataGroup::WriteToExistFile()
{
    if(filepath.isEmpty()){
        if(WriteToFile()){
            return true;
        }
        else return false;
    }
    else{
        QByteArray temp2=filepath.toLatin1();
        saveStudentsToFile(temp2.data(),this->a);
        this->ifchanged=false;
        return true;
    }
}



