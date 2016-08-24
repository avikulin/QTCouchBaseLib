#include "couchbaseclientcookie.h"
#include <couchbasedocument.h>

CouchBaseClientCookie::CouchBaseClientCookie(QObject *parent) : QObject(parent)
{
    Q_OBJECT

    public:
        CouchBaseClientCookie(const void* cookie);
        bool GetResult();
        CouchBaseRecordSet GetData();
    private:
        CouchBaseClientCookie();
        CouchBaseRecordSet _docs;
        bool operationResult = false;
}
