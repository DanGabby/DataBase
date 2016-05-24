#ifndef DATA_H
#define DATA_H
#include "record.h"
#include <QTextStream>
#include <QFile>
class Data
{
public:
    Data(){}
    Data(QFile *dataBase);
    void Connect(QFile *dataBase);

    void Save();
    void Delete();
    void Reset();


    QList<Record> GetAll();
    QList<Record> FindByField(QString field, QString val);
    void SetValue(Record *record, QString field, QString val);

private:
    QFile *dataBase;
    QList<Record> records;
    QString name;

    Field BuildField(QString strField);
};

#endif // DATA_H
