#include "couchbasedatasource.h"

CouchBaseDataSource::CouchBaseDataSource()
{
    _isConnected = false;
}

void CouchBaseDataSource::Create(QStringList cpouchBaseInstances, QString userName, QString password, QString dataBucket, CouchBaseConnectOptions &options)
{
    lcb_error_t err;
    _isConnected = false;

    QStringConverter connStr(QString("couchbase://%1/%2").arg(cpouchBaseInstances.join(",")).arg(dataBucket));
    QStringConverter userLogin(userName);
    QStringConverter userPassword(password);

    struct lcb_create_st connectionParams;
    memset(&connectionParams, 0, sizeof(connectionParams));

    connectionParams.version = 3;
    connectionParams.v.v3.connstr = connStr.to_cstr();
    connectionParams.v.v3.username = userLogin.to_cstr();
    connectionParams.v.v3.passwd = userPassword.to_cstr();

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
     if (err!=LCB_SUCCESS){
         throw CouchBaseException(err, "Can't set extended error info");
     }

     _isConnected = true;
}

bool CouchBaseDataSource::CheckConnectionStatus()
{
    return _isConnected;
}
