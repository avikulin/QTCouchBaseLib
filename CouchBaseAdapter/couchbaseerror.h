#ifndef COUCHBASEERROR_H
#define COUCHBASEERROR_H

#include <QObject>
#include <QException>

class CouchBaseError : public QException
{

private:
    CouchBaseError();
    QString _errorCode;
    QString _errorDescription;

   //Native methods
public:
    explicit CouchBaseError(QString ErrCode, QString ErrDescription);
    QString GetErrCode() const;
    QString GetErrDescription() const;

    // QException interface
public:
    void raise() const;
    QException *clone() const;

    // exception interface
public:
    const char *what() const;
};

#endif // COUCHBASEERROR_H
