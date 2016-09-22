#include "qstringconverter.h"

QStringConverter::QStringConverter(QString data)
{
    rawData = data.toUtf8();
}

QStringConverter::QStringConverter(char *data, size_t size)
{
    rawData = QByteArray(data, size);
}

QStringConverter::QStringConverter(std::string data)
{
    rawData = QByteArray::fromStdString(data);
}

QStringConverter::QStringConverter(QJsonObject data)
{
    QJsonDocument doc(data);
    rawData = doc.toJson();
}

QString QStringConverter::toQString()
{
    return QString::fromStdString(rawData.toStdString());
}

char *QStringConverter::to_cstr()
{
    return rawData.data();
}

std::string QStringConverter::toStdString()
{
    return rawData.toStdString();
}

QJsonObject QStringConverter::toJSON()
{
    return QJsonDocument::fromJson(rawData).object();
}

size_t QStringConverter::Lenght()
{
    return rawData.size();
}
