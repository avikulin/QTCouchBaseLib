#include "couchbaseadapter.h"

CouchBaseDataSource& CouchBaseAdapter::GetDataSource(QString instanceName, QString userName, QString password, QString dataBucket)
{
    static CouchBaseDataSource _datasource;

    if(!_datasource.CheckConnectionStatus()){
        CouchBaseConnectOptions opt;
        _datasource.Create(instanceName,userName,password,dataBucket, opt);
    }

    return _datasource;
}
