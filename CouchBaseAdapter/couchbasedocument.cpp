#include "couchbasedocument.h"

CouchBaseDocument::CouchBaseDocument(lcb_error_t error, const lcb_get_resp_t *resp, QObject *parent): QObject(parent)
{
    _error = error;

    if (error != LCB_SUCCESS){
        _validationStatus = false;
        return;
    }

    _validationStatus = true;
    _key = QByteArray((const char*)resp->v.v0.key,resp->v.v0.nkey);

    _data = QByteArray((const char*)resp->v.v0.bytes, resp->v.v0.nbytes);
    _cas = resp->v.v0.cas;

    switch(resp->v.v0.datatype){
        case LCB_VALUE_RAW:
                            _type = ContentType::rawBytes;
                            break;
        case LCB_VALUE_F_JSON:
                            _type = ContentType::structJSON;
                            break;
        case LCB_VALUE_F_SNAPPYCOMP:
                            _type = ContentType::comressedBinary;
                            break;
    }
}

CouchBaseDocument::CouchBaseDocument(QString key, QString data, ContentType type, QObject *parent)
    :QObject(parent), _key{key}, _data{data}, _type{type}
{

}

bool CouchBaseDocument::isValid()
{
    return _validationStatus;
}

CouchBaseOperationResult CouchBaseDocument::GetErrorInfo()
{
    CouchBaseOperationResult _res;
    _res.ResultCode = _error;
    _res.ResultDescription = QString.fromUtf8(lcb_strerror(NULL,_error));
    _res.isBad = (_error==LCB_SUCCESS);
    return _res;
}
