#ifndef COUCHBASEADAPTER_H
#define COUCHBASEADAPTER_H

#include "couchbaseadapter_global.h"
#include <QString>
#include <couchbasedatasource.h>

class COUCHBASEADAPTERSHARED_EXPORT CouchBaseAdapter
{
private:

    CouchBaseAdapter();
    CouchBaseAdapter(CouchBaseAdapter &other);
    CouchBaseAdapter& operator= (CouchBaseAdapter &other);
    ~CouchBaseAdapter();

public:

    static CouchBaseDataSource& GetDataSource(QString instanceName, QString userName, QString password, QString dataBucket);
};

#endif // COUCHBASEADAPTER_H
