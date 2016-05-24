#include "record.h"

void Record::AddField(Field field)
{
    this->fields.append(field);
}

