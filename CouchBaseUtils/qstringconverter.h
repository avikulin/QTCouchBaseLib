#ifndef QSTRINGCONVERTER_H
#define QSTRINGCONVERTER_H
#include <couchbaseutils_global.h>

#include <QString>
#include <QByteArray>
#include <QJsonObject>
#include <QJsonDocument>

class COUCHBASEUTILSSHARED_EXPORT QStringConverter
{
public:
    QStringConverter(QString data);
    QStringConverter(char* data, size_t size);
    QStringConverter(std::string data);
    QStringConverter(QJsonObject data);

    QString toQString();
    char* to_cstr();
    std::string toStdString();
    QJsonObject toJSON();
    size_t Lenght();

private:
    QByteArray rawData;
};

#endif // QSTRINGCONVERTER_H
