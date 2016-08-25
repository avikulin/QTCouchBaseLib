#ifndef COUCHBASECLIENTCOOKIE_H
#define COUCHBASECLIENTCOOKIE_H
#include <QtCore>
#include <QMap>
#include <couchbasedocument.h>

class CouchBaseClientCookie
{
    public:
        static CouchBaseRecordSet *getFromPtr(const void* cookie);
        explicit CouchBaseClientCookie(const bool operationResult);
        explicit CouchBaseClientCookie(const CouchBaseRecordSet documentSet, const bool operationResult);
        bool GetResult();
        CouchBaseRecordSet GetData();
    private:
        CouchBaseRecordSet _docs;
        bool _operationResult;
};

#endif // COUCHBASECLIENTCOOKIE_H
