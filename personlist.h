#ifndef PERSONLIST_H
#define PERSONLIST_H
#include "lib/api.h"
#include "personlistbody.h"
#include "datagroup.h"
#include <QMainWindow>
#include<QStandardItem>
#include<QStandardItemModel>
#include<QList>
#include<QListWidgetItem>

class PersonList
{
public:
    PersonList(DataGroup *s):sa(s){};
    QStandardItemModel *SwitchToItemModel();
private:
    QStandardItemModel *ItemModel;
    DataGroup *sa;
};

#endif // PERSONLIST_H
