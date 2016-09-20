#include "couchbasedatasource.h"

CouchBaseDataSource::CouchBaseDataSource()
{
    _isConnected = false;
}

void CouchBaseDataSource::Create(QString cpouchBaseInstance, QString userName, QString password, QString dataBucket, CouchBaseConnectOptions &options)
{
    lcb_error_t err;
    _isConnected = false;

    QString connStr = "couchbase://"+cpouchBaseInstance+"/"+dataBucket;

    struct lcb_create_st connectionParams;
    memset(&connectionParams, 0, sizeof(connectionParams));
//    connectionParams.version = 3;
//    connectionParams.v.v3.connstr = connStr.toStdString().c_str();
//    connectionParams.v.v3.username = userName.toStdString().c_str();
//    connectionParams.v.v3.passwd = password.toStdString().c_str();

    connectionParams.version = 3;
    connectionParams.v.v3.connstr = "couchbase://avikulin/beer-sample";
    connectionParams.v.v3.username = "beer-sample";
    connectionParams.v.v3.passwd = "";

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
