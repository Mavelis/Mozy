#include "mytcpserver.h"
#include "Pars.h"
#include <QDebug>
#include <QCoreApplication>

QList<QTcpSocket*> clients;

MyTcpServer::~MyTcpServer()
{
//    int i = 0;
//    while(i < mTcpSocket.length())
//        mTcpSocket[i]->close();
    mTcpServer->close();
    server_status=0;
}

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    } else {
        server_status=1;
        qDebug() << "server is started";
    }
}

void MyTcpServer::slotNewConnection(){

    if(server_status==1){
        QTcpSocket* cTcpSocket;
        cTcpSocket = mTcpServer->nextPendingConnection();
        cTcpSocket->write("Привет!!! Введите запрос!\r\n");
        connect(cTcpSocket, &QTcpSocket::readyRead, this,&MyTcpServer::slotServerRead);
        connect(cTcpSocket,&QTcpSocket::disconnected, this,&MyTcpServer::slotClientDisconnected);
        mTcpSocket.push_back(cTcpSocket);
    }

}

void MyTcpServer::slotServerRead(){
    QTcpSocket* cTcpSocket = (QTcpSocket*)sender();
        QString request;
        while(cTcpSocket->bytesAvailable()>0) {
            request.append(cTcpSocket->readAll());
        }
        QByteArray response = parse(request)+ "\r\n";
        cTcpSocket->write(response);

}

void MyTcpServer::slotClientDisconnected(){
    QTcpSocket* cTcpSocket = (QTcpSocket*)sender();
    cTcpSocket->close();
}
