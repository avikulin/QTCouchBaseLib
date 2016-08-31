#ifndef COUCHBASEADAPTER_H
#define COUCHBASEADAPTER_H

#include "couchbaseadapter_global.h"
#include "libcouchbase/couchbase.h"
#include <QString>
#include <QDebug>
//#include <stdio.h>

class COUCHBASEADAPTERSHARED_EXPORT CouchBaseAdapter
{
private:
    static lcb_t instance;

public:

    static bool Create(QString instanceName, QString userName, QString password, QString dataBucket);
    static lcb_t GetDataSource();
};

#endif // COUCHBASEADAPTER_H
