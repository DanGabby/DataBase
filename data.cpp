#include "data.h"

Data::Data(QFile *dataBase)
{
    this->Connect(dataBase);
}

void Data::Connect(QFile *dataBase)
{
    this->dataBase = dataBase;
}

void Data::Save()
{
    QString END_OF_RECORD = "~";
    QTextStream stream(this->dataBase);
    stream << this->name << endl;

    QList<Record>::iterator i;
    for(i = this->records.begin(); i != this->records.end(); ++i)
    {
        stream << i->name << endl;
        QList<Field>::iterator j;
        for(j = i->fields.begin(); j != i->fields.end(); ++j)
            stream << j->name << ':' << j->val << endl;
        stream << END_OF_RECORD << endl;
    }

}

void Data::Reset()
{
    QString END_OF_RECORD = "~";
    QTextStream stream(this->dataBase);
    // считываем имя сущности
    this->name = stream.readLine();
    // пока не закончился файл
    QString strField;
    while (!stream.atEnd())
    {
        Record newRecord;
        // считываем имя записи
        newRecord.name = stream.readLine();
        // считываем поле
        strField = stream.readLine();
        // пока не закончились поля записи
        while (strField != END_OF_RECORD)
        {
            // из строкового описания поля собираем поле, добавляем его в список полей записи
            newRecord.AddField(BuildField(strField));
            strField = stream.readLine();
        }
        records.append(newRecord);
    }
}

QList<Record> Data::GetAll()
{
    return this->records;
}

QList<Record> Data::FindByField(QString field, QString val)
{
    QList<Record> finded_records;
    QList<Record>::iterator i;
    for(i = this->records.begin(); i != this->records.end(); ++i)
    {
        QList<Field>::iterator j;
        for(j = i->fields.begin(); j < i->fields.end(); ++j)
            if(j->name == field && j->val == val)
                finded_records.append(*i);
    }
    return finded_records;
}

void Data::SetValue(Record *record, QString field, QString val)
{
    QList<Field>::iterator j;
    for(j = record->fields.begin(); j != record->fields.end(); ++j)
        if(j->name == field)
            j->val = val;
}



Field Data::BuildField(QString strField)
{
    QStringList split = strField.split(':');
    Field newField(split[0],split[1]);
    return newField;
}
