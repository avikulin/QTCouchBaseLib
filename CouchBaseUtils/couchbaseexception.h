#ifndef COUCHBASEEXCEPTION_H
#define COUCHBASEEXCEPTION_H

#include "couchbaseutils_global.h"
#include <QException>
#include <QString>
#include <libcouchbase/couchbase.h>

class COUCHBASEUTILSSHARED_EXPORT CouchBaseException : public QException
{
public:
    CouchBaseException(lcb_error_t ErrCode);
    void raise() const { throw *this; }
    CouchBaseException *clone() const { return new CouchBaseException(*this); }
    const char *what() const;
private:
    lcb_error_t _err;
};
#endif // COUCHBASEEXCEPTION_H
