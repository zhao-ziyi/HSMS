#ifndef DATAGROUP_H
#define DATAGROUP_H
#include <QVector>
#include <QLabel>
#include <QString>
#include <QDialog>
#include <QFileDialog>
#include <QSysInfo>
#include "lib/api.h"
class DataGroup
{
public:
    DataGroup();
    DataGroup(QString &title);
    bool AddData();
    QString * GetTitle();
    ~DataGroup();
    bool ifchanged{false};
    bool WriteToFile();
    int IfWrite(DataGroup &dg);
    bool OpenFile();
    bool WriteToExistFile();
    StudentArray a;
private:
    QString title;

    QString filepath;
};

#endif // DATAGROUP_H
