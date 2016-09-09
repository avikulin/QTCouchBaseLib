#ifndef COUCHBASEDOCUMENT_H
#define COUCHBASEDOCUMENT_H

#include <couchbaseadapter_global.h>
#include <QMap>
#include <QByteArray>
#include <QString>
#include <QJsonObject>
#include "../LIBS/x64/Win/Include/libcouchbase/couchbase.h"

enum COUCHBASEADAPTERSHARED_EXPORT ContentType{rawBytes, structJSON, comressedBinary, Undefined};

struct COUCHBASEADAPTERSHARED_EXPORT CouchBaseOperationResult{
    QString ResultCode;
    QString ResultDescription;
    bool isBad = false;
};

class COUCHBASEADAPTERSHARED_EXPORT CouchBaseDocument{
public:
    CouchBaseDocument(lcb_error_t error, const lcb_get_resp_t *resp);
    CouchBaseDocument(QString key, QString data, ContentType type);

//    CouchBaseDocument(CouchBaseDocument& other);
//    CouchBaseDocument(CouchBaseDocument&& temp);
    CouchBaseDocument& operator =(CouchBaseDocument& other);
//    CouchBaseDocument& operator =(CouchBaseDocument&& other);

    bool operator ==(const CouchBaseDocument& other);
    bool operator !=(CouchBaseDocument& other);


    QString GetKey ();
    lcb_error_t GetErrorCode();
    QString GetErrorDescription();
    QString asQString();
    QJsonObject asJSON();
    QByteArray asByteArray();
    bool isValid();
    CouchBaseOperationResult GetErrorInfo();
    qint32 qHash();

private:
    CouchBaseDocument();
    QByteArray _key;
    QByteArray _data;
    lcb_cas_t _cas;
    lcb_error_t _error = LCB_SUCCESS;
    ContentType _type = ContentType::Undefined;
    bool _validationStatus = false;
};

typedef QMap<QString,CouchBaseDocument> CouchBaseRecordSet;

#endif // COUCHBASEDOCUMENT_H
