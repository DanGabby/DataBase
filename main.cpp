#include <QFile>
#include "data.h"
int main()
{
    QFile dataFile("data.txt");
    dataFile.open(QIODevice::ReadOnly);
    Data data;
    data.Connect(&dataFile);
    data.Reset();
    QList<Record> records = data.FindByField("student1","name");
    dataFile.close();
    return 0;
}
