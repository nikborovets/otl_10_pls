#include "server.h"
Server::Server()
{
    if(this->listen(QHostAddress::Any, 3230))
    {
        qDebug()<<"start";
    }
    else
    {
        qDebug()<<"error";
    }
    nextBlockSize = 0;
    i = 0;
}

void Server::incomingConnection(qintptr socketDescriptor)
{
 socket = new QTcpSocket;
 socket -> setSocketDescriptor(socketDescriptor);
 connect(socket,&QTcpSocket::readyRead,this,&Server::slotReadyRead);
 connect(socket,&QTcpSocket::disconnected,socket,&QTcpSocket::deleteLater);

 Sockets.push_back(socket);

 qDebug()<< "client connected "<<socketDescriptor;
}

void Server::slotReadyRead()
{
    if ( !(g.ready()) )
    {
        socket = (QTcpSocket*)sender();
        QDataStream in(socket);
        in.setVersion(QDataStream::Qt_6_2);
        if(in.status() == QDataStream::Ok )
        {

                for(;;)
                {
                    if(nextBlockSize == 0)
                    {
                        if(socket->bytesAvailable() < nextBlockSize)
                            break;
                        in >> nextBlockSize;
                    }
                    if (socket->bytesAvailable() < nextBlockSize)
                    {
                        break;
                    }

                    QString str;
                    in >>str;




                    str = str;
                    i++;
                    nextBlockSize = 0;
                    g.fill(str);
                    break;
                }
        }
        else
        {
            qDebug()<<"DataStream error";
        }
    }
    //qDebug()<< QString::fromStdString(g.path_pattern);
    if (g.ready())
    {
        //qDebug()<< QString::fromStdString(g.path_file);
        //qDebug()<<  QString::fromStdString(g.path_pattern);
        //qDebug()<<  QString::fromStdString(g.path_result);
        g.produce();
        g.clear();
        SendToClient("complete");
    }
}

void Server::SendToClient(QString str)
{
 Data.clear();
 //qDebug()<<str<< " ";
 QDataStream out(&Data,QIODevice::WriteOnly);
 out.setVersion(QDataStream::Qt_6_2);
 out<< quint16(0)<<str;
 out.device()->seek(0);
 out<< quint16(Data.size() - sizeof(quint16));
 socket -> write(Data);
}
