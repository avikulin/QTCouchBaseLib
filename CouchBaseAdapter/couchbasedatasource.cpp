#include "couchbasedatasource.h"

CouchBaseDataSource::CouchBaseDataSource()
{

}

bool CouchBaseDataSource::Create(QStringList cpouchBaseInstances, QString userName, QString password, QString dataBucket, CouchBaseConnectOptions options)
{
    lcb_error_t err;

    QString connStr = "couchbase://"+QString::fromStdString(cpouchBaseInstances.join(",").toStdString());

    struct lcb_create_st connectionParams;
    memset(&connectionParams, 0, sizeof(connectionParams));
    connectionParams.version = 3;
    connectionParams.v.v3.connstr = connStr.toStdString().c_str();
    connectionParams.v.v3.username = userName.toStdString().c_str();
    connectionParams.v.v3.passwd = password.toStdString().c_str();

    err = lcb_create(&_couchBaseInstance, &connectionParams);

    if (err!=LCB_SUCCESS){
        throw CouchBaseException(GetErrorString(err));
    }
    err = lcb_get_bootstrap_status(_couchBaseInstance);

    if (err!=LCB_SUCCESS){
        throw CouchBaseException(GetErrorString(err));
    }
    // lcb_error_t lcb_cntl(lcb_t 	instance, int mode, int cmd, void *arg);

    return false;
}

QString GetErrorString(lcb_error_t err)
{
    return QString("[%1] %2").arg(err).arg(QString::fromLatin1(lcb_strerror(NULL,err)));
}
