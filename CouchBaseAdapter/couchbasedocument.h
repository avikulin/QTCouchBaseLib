#ifndef COUCHBASEDOCUMENT_H
#define COUCHBASEDOCUMENT_H

#include <QObject>
#include <QByteArray>
#include <QString>
#include <QJsonObject>
#include "libcouchbase/couchbase.h"

enum ContentType{rawBytes, structJSON, comressedBinary, Undefined};

struct CouchBaseOperationResult{
    QString ResultCode;
    QString ResultDescription;
    bool isBad = false;
};

class CouchBaseDocument: public QObject
{
    Q_OBJECT

public:
    CouchBaseDocument(lcb_error_t error, const lcb_get_resp_t *resp, QObject *parent = 0);
    CouchBaseDocument(QString key, QString data, ContentType type, QObject *parent = 0);

    CouchBaseDocument(CouchBaseDocument& other);
    CouchBaseDocument(CouchBaseDocument&& other);
    CouchBaseDocument& operator =(CouchBaseDocument& other);
    CouchBaseDocument& operator =(CouchBaseDocument&& other);

    bool operator ==(CouchBaseDocument& firstOperand, CouchBaseDocument& secondOperand);
    bool operator !=(CouchBaseDocument& firstOperand, CouchBaseDocument& secondOperand);


    QString GetKey ();
    lcb_error_t GetErrorCode();
    QString GetErrorDescription();
    QString asQString();
    QJsonObject asJSON();
    QByteArray asByteArray();
    bool isValid();
    CouchBaseOperationResult GetErrorInfo();

private:

    QByteArray _key;
    QByteArray _data;
    lcb_cas_t _cas;
    lcb_error_t _error;
    ContentType _type = ContentType::Undefined;
    bool _validationStatus = false;
};

typedef QHash<QString,CouchBaseDocument> CouchBaseRecordSet;

#endif // COUCHBASEDOCUMENT_H
