#ifndef RECORD_H
#define RECORD_H
#include "field.h"
#include <QList>
class Record
{
public:
    Record(){}
    void AddField(Field field);
//private:
    QList<Field> fields;
    QString name;
};

#endif // RECORD_H
