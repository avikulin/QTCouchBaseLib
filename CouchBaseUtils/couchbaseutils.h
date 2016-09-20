#ifndef COUCHBASEUTILS_H
#define COUCHBASEUTILS_H

#include <QString>
#include "couchbaseutils_global.h"

class COUCHBASEUTILSSHARED_EXPORT CouchBaseUtils
{

public:
    static char* QStringConverter(QString in_Str);
    CouchBaseUtils();
};

#endif // COUCHBASEUTILS_H
