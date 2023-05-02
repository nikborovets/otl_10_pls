#ifndef SERVER_H
#define SERVER_H

#include<QTcpServer>
#include<QTcpSocket>
#include<generator.h>

class Server:public QTcpServer
{
    Q_OBJECT
public:
    Server();
    QTcpSocket *socket;
    GENERATOR g;
    int i;
private:
    QVector<QTcpSocket*> Sockets;
    QByteArray Data;
    void SendToClient(QString str);
    quint16 nextBlockSize;
    void gen_set(QString str);
public slots:
    void incomingConnection(qintptr socketDescriptor);
    void slotReadyRead();

};

#endif // SERVER_H
