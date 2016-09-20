#include <QCoreApplication>
#include <iostream>
#include <QDebug>
#include <couchbaseadapter.h>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    try{
        QString instance = "avikulin";
        QString user = "beer-sample";
        QString password = "";
        QString bucket = "beer-sample";

        CouchBaseConnectOptions opt;

        qDebug()<<"CouchBase Connection Tester. v1.0";
        qDebug()<<"...";
        qDebug()<<"Initial parameters:";
        qDebug()<<"  - instances:"<<instance;
        qDebug()<<"  - user:"<<user;
        qDebug()<<"  - password:"<<password;
        qDebug()<<"  - data bucket:"<<bucket;
        qDebug()<<"";
        qDebug()<<"Trying to connect...";

        CouchBaseDataSource &dc = CouchBaseAdapter::GetDataSource(instance,user,password,bucket);
        qDebug()<<"Connection status: "<<dc.CheckConnectionStatus();

    }catch(QException &ex){
        qDebug()<<"Exception happened: "<<ex.what();
    }catch(CouchBaseException &cbEx){
        qDebug()<<"CouchBase exception happened: "<<cbEx.GetErrMessage();
    }

    return a.exec();
}
