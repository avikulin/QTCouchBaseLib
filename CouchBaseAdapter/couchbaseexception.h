#ifndef COUCHBASEEXCEPTION_H
#define COUCHBASEEXCEPTION_H

#include "couchbaseadapter_global.h"
#include <QException>
#include <QString>
#include <../LIBS/x64/Win/Include/libcouchbase/couchbase.h>

struct COUCHBASEADAPTERSHARED_EXPORT ErrInfo{
    lcb_error_t ErrCode;
    QString ErrMessage;
    QString ErrComment;
};

class COUCHBASEADAPTERSHARED_EXPORT CouchBaseException : public QException
{
public:
    CouchBaseException(lcb_error_t ErrCode, const QString Comment);
    void raise() const { throw *this; }
    CouchBaseException *clone() const { return new CouchBaseException(*this); }
    const char *what() const;
    ErrInfo GetErrInfo() const;
    QString GetErrMessage() const;
private:
    lcb_error_t _errCode;
    QString _errComment;
};
#endif // COUCHBASEEXCEPTION_H
