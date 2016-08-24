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

    ContentType _type = ContentType::Undefined;
    lcb_cas_t _cas;
    lcb_error_t _error;
    bool _validationStatus = false;
};

#endif // COUCHBASEDOCUMENT_H
