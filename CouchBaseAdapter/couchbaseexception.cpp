#include "couchbaseexception.h"



CouchBaseException::CouchBaseException(lcb_error_t ErrCode, const QString Comment)
    :_errCode(ErrCode), _errComment(Comment)
{

}

const char *CouchBaseException::what() const
{
    return lcb_strerror(NULL,_errCode);
}

ErrInfo CouchBaseException::GetErrInfo() const
{
    ErrInfo res;
    res.ErrCode = _errCode;
    res.ErrMessage = lcb_strerror(NULL,_errCode);
    res.ErrComment = _errComment;

    return (res);
}

QString CouchBaseException::GetErrMessage() const
{
    return (QString("[%1] %2. Comments: %3.").arg(_errCode).
            arg(QString::fromLatin1(lcb_strerror(NULL,_errCode))).arg(_errComment));
}
