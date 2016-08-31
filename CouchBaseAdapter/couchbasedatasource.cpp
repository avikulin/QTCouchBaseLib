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
        throw CouchBaseException(err,"Can't ctreate the CouchBase instance");
    }

    err = lcb_connect(_couchBaseInstance);
    if (err != LCB_SUCCESS) {
        throw CouchBaseException(err, "Can't connect to the CouchBase instance");
    }

    lcb_wait(_couchBaseInstance);

    err = lcb_get_bootstrap_status(_couchBaseInstance);

    if (err!=LCB_SUCCESS){
        throw CouchBaseException(err, "Can't bootstrap the CouchBase instance");
    }

     err = lcb_cntl(_couchBaseInstance, LCB_CNTL_SET, LCB_CNTL_DETAILED_ERRCODES, &_couchBaseConfigNumber);

    return false;
}
