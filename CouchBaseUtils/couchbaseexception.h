#ifndef COUCHBASEEXCEPTION_H
#define COUCHBASEEXCEPTION_H

#include <QException>
#include <QString>

class CouchBaseException : public QException
{
public:
    CouchBaseException(QString errDescription);
    void raise() const;
    QException *clone() const;
    const char *what() const;

private:
    QString _errString;

};

#endif // COUCHBASEEXCEPTION_H
