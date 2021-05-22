#ifndef PERSONLISTBODY_H
#define PERSONLISTBODY_H

#include <QWidget>
#include <QLabel>
#include <QList>
#include "datagroup.h"
#include <lib/api.h>
#include <QStandardItem>

class PersonListBody : public QWidget
{
    Q_OBJECT
public:
    PersonListBody(DataGroup *dg);
    StudentItem *s;
    QList<QStandardItem*> l;
signals:

};

#endif // PERSONLISTBODY_H
