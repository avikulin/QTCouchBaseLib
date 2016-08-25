#include "couchbaseclientcookie.h"
#include <couchbasedocument.h>

CouchBaseRecordSet* CouchBaseClientCookie::getFromPtr(const void *cookie)
{
    return const_cast<CouchBaseRecordSet*>(reinterpret_cast<const CouchBaseRecordSet*>(cookie));
}

CouchBaseClientCookie::CouchBaseClientCookie(const CouchBaseRecordSet documentSet, const bool operationResult)
{
    _operationResult = operationResult;
    _docs = documentSet;
}
