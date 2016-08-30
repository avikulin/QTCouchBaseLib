#include "couchbaseexception.h"



CouchBaseException::CouchBaseException(lcb_error_t ErrCode)
{
   _err = ErrCode;
}

const char *CouchBaseException::what() const
{
    return lcb_strerror(NULL,_err);
}
