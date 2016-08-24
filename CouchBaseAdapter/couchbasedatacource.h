#ifndef COUCHBASEDATACOURCE_H
#define COUCHBASEDATACOURCE_H

#include "libcouchbase/couchbase.h"
#include <QString>

class CouchBaseDataCource
{
public:
    CouchBaseDataCource();
    bool Create(QString instance, QString userName, QString password, QString dataBucket);
    bool CheckConnectionStatus();

private:
    lcb_t _couchBaseInstance;
    bool isConnected = false;

    //---Internal CallBack functions

    void fnBootStrapCallBack (lcb_t instance, lcb_error_t err);
    void fnDestroyCallBack (const void *cookie);

    void fnGetCallBack    (lcb_t instance, const void *cookie, lcb_error_t error, const lcb_get_resp_t *resp);
    void fnUnlockCallBack (lcb_t instance, const void *cookie, lcb_error_t error, const lcb_unlock_resp_t *resp);
    void fnRemoveCallBack (lcb_t instance, const void *cookie, lcb_error_t error, const lcb_remove_resp_t *resp);
    void fnTouchCallBack  (lcb_t instance, const void *cookie, lcb_error_t error, const lcb_touch_resp_t *resp);
    void fnStoreCallBack  (lcb_t instance, const void *cookie, lcb_storage_t operation, lcb_error_t error, const lcb_store_resp_t *resp);
    void fnBootStrapCallBack(lcb_t instance, lcb_error_t err);

};

#endif // COUCHBASEDATACOURCE_H
