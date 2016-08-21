#include "couchbaseerror.h"

CouchBaseError::CouchBaseError(QString ErrCode, QString ErrDescription)
    :QException(), _errorCode{ErrCode}, _errorDescription{ErrDescription}
{

}

void CouchBaseError::raise() const
{
    throw *this;
}

QException *CouchBaseError::clone() const
{
    return new CouchBaseError(*this);
}

const char *CouchBaseError::what() const
{
    return QString("[%1] Description: %2").arg(_errorCode).arg(_errorDescription).toStdString().c_str();
}
