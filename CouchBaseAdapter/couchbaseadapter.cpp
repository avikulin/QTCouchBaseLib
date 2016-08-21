#include "couchbaseadapter.h"

lcb_t CouchBaseAdapter::instance;

bool CouchBaseAdapter::Create(QString instanceName, QString userName, QString password, QString dataBucket)
{
    struct lcb_create_st options;
    memset(&options, 0, sizeof(options));

    options.version = 3;
    options.v.v3.connstr = QString("couchbase://{%1}").arg(instanceName).toStdString().c_str();
    options.v.v3.passwd = password.toStdString().c_str();;
    options.v.v3.username = userName.toStdString().c_str();;

    lcb_error_t err = lcb_create(&instance, &options);
    if (err != LCB_SUCCESS) {
       qDebug()<<"Failed to create instance: %s\n"<<lcb_strerror(NULL, err);
       return false;
    } else return true;
}

lcb_t CouchBaseAdapter::GetDataSource()
{
    return instance;
}
