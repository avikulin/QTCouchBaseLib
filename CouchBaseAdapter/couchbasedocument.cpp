#include "couchbasedocument.h"

CouchBaseDocument::CouchBaseDocument(lcb_error_t error, const lcb_get_resp_t *resp)
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

CouchBaseDocument::CouchBaseDocument(QString key, QString data, ContentType type)
    :_key(key.toLatin1()), _data(data.toLatin1()), _type(type)
{
    _error = LCB_SUCCESS;
    _cas = 0;
    _validationStatus = false;
}

//CouchBaseDocument::CouchBaseDocument(CouchBaseDocument &other)
//    :_key(other._key), _data(other._data), _cas(other._cas),
//      _error(other._error), _type(other._type), _validationStatus(other._validationStatus)
//{
//}

//CouchBaseDocument::CouchBaseDocument(CouchBaseDocument &&temp)
//    :_cas(temp._cas),_error(temp._error),_type(temp._type),_validationStatus(temp._validationStatus)
//{
//    _key = std::move(temp._key);
//    _data = std::move(temp._data);
//}

CouchBaseDocument& CouchBaseDocument::operator =(CouchBaseDocument &other)
{
    _key = other._key;
    _data = other._data;
    _cas = other._cas;
    _error = other._error;
    _type = other._type;
    _validationStatus = other._validationStatus;
    return *this;
}

//CouchBaseDocument& CouchBaseDocument::operator =(CouchBaseDocument &&temp)
//{
//    _key = std::move(temp._key);
//    _data = std::move(temp._data);
//    _cas = temp._cas;
//    _error = temp._error;
//    _type = temp._type;
//    _validationStatus = temp._validationStatus;
//    return *this;
//}

bool CouchBaseDocument::operator ==(const CouchBaseDocument &other)
{
    return  (_key==other._key)&&
            (_data == other._data)&&
            (_cas == other._cas) &&
            (_type == other._type)&&
            (_validationStatus == other._validationStatus);
}

bool CouchBaseDocument::operator !=(CouchBaseDocument &other)
{
    return  (_key!=other._key)||
            (_data != other._data)||
            (_cas != other._cas) ||
            (_type != other._type)||
            (_validationStatus != other._validationStatus);
}

bool CouchBaseDocument::isValid()
{
    return _validationStatus;
}

CouchBaseOperationResult CouchBaseDocument::GetErrorInfo()
{
    CouchBaseOperationResult _res;
    _res.ResultCode = _error;
    _res.ResultDescription = QString::fromUtf8(lcb_strerror(NULL,_error));
    _res.isBad = (_error==LCB_SUCCESS);
    return _res;
}
