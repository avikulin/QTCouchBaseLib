#ifndef COUCHBASEDATACOURCE_H
#define COUCHBASEDATACOURCE_H

#include <couchbaseadapter_global.h>
#include <QString>
#include <libcouchbase/couchbase.h>
#include <couchbasedocument.h>
#include <couchbaseexception.h>

struct COUCHBASEADAPTERSHARED_EXPORT CouchBaseConnectOptions {
    lcb_U32 operation_timeout = 0;
    lcb_U32 view_timeout = 0;
    lcb_U32 durability_timeout = 0;
    lcb_U32 durability_interval = 0;
    lcb_U32 http_timeout = 0;
    bool randomize_nodes = false;
    lcb_U32 error_thresh_count = 0;
    lcb_U32 error_thresh_delay = 0;
    lcb_U32 config_total_timeout = 0;
    lcb_U32 config_node_timeout = 0;
    QString config_cache;
    bool detailed_errcodes = true;
    lcb_U32 http_urlmode = 0;
    float retry_backoff = 0;
    lcb_U32 http_poolsize = 0;
    bool vbguess_persist = false;
};

class COUCHBASEADAPTERSHARED_EXPORT CouchBaseDataSource
{
public:
    CouchBaseDataSource();
    void Create(QStringList cpouchBaseInstances, QString userName, QString password, QString dataBucket, CouchBaseConnectOptions& options);
    CouchBaseRecordSet GetRecords(QStringList keys);
    CouchBaseDocument GetRecord(QString key);
    bool InsertOrUpdateRecord(CouchBaseDocument& doc);
    bool DeleteRecord(CouchBaseDocument& doc);
    bool CheckConnectionStatus();

private:
    CouchBaseDataSource(const CouchBaseDataSource& other);
    CouchBaseDataSource& operator = (const CouchBaseDataSource& other);

    QString GetErrorString(lcb_error_t err);
    lcb_t _couchBaseInstance = nullptr;
    int _couchBaseConfigNumber = 0;
    bool _isConnected = false;

    //---Internal CallBack functions

    void fnBootStrapCallBack (lcb_t instance, lcb_error_t err);
    void fnDestroyCallBack (const void *cookie);

//----JUST TO REMEMBER DEFINITIONS--
//    lcb_error_t lcb_connect(lcb_t 	instance);
//    lcb_error_t lcb_get_bootstrap_status(lcb_t 	instance);
//    lcb_error_t lcb_cntl(lcb_t 	instance, int mode, int cmd, void *arg);
//----Standard key-value finctions---

    lcb_error_t lcb_get3(lcb_t 	instance, const void *cookie,const lcb_CMDGET *cmd);
    lcb_error_t lcb_store3(lcb_t 	instance, const void *cookie,const lcb_CMDSTORE *cmd);
    lcb_error_t lcb_remove3(lcb_t 	instance, const void *cookie,const lcb_CMDREMOVE *cmd);
    lcb_error_t lcb_touch3(lcb_t 	instance, const void *cookie,const lcb_CMDTOUCH *cmd);
    lcb_error_t lcb_unlock3(lcb_t 	instance, const void *cookie,const lcb_CMDUNLOCK *cmd);
    lcb_error_t lcb_counter3(lcb_t 	instance, const void *cookie,const lcb_CMDCOUNTER *cmd);

    lcb_error_t lcb_get(lcb_t 	instance, const void *command_cookie, lcb_SIZE 	num,const lcb_get_cmd_t *const *commands);


    void fnGetCallBack    (lcb_t instance, const void *cookie, lcb_error_t error, const lcb_get_resp_t *resp);
    void fnUnlockCallBack (lcb_t instance, const void *cookie, lcb_error_t error, const lcb_unlock_resp_t *resp);
    void fnRemoveCallBack (lcb_t instance, const void *cookie, lcb_error_t error, const lcb_remove_resp_t *resp);
    void fnTouchCallBack  (lcb_t instance, const void *cookie, lcb_error_t error, const lcb_touch_resp_t *resp);
    void fnStoreCallBack  (lcb_t instance, const void *cookie, lcb_storage_t operation, lcb_error_t error, const lcb_store_resp_t *resp);
};

#endif // COUCHBASEDATACOURCE_H
