#include "couchbaseexception.h"

CouchBaseException::CouchBaseException(QString errDescription)
{
    _errString = errDescription;
}

void CouchBaseException::raise() const
{
    throw *this;
}

QException *CouchBaseException::clone() const
{
    return new CouchBaseException(*this);
}


const char *CouchBaseException::what() const
{
    return _errString.toStdString().c_str();
}
