#include "DUPServer.h"

#define PORT 5334

DUPServer::DUPServer(QObject *parent, QString theAddC)
{
    Q_UNUSED(parent);

    //for checking in terminal
    //ifconfig | grep "inet " | grep -Fv 127.0.0.1 | awk '{print $2}'

    theAdd = QHostAddress(theAddC);

    udpSocket = new QUdpSocket(this);

    udpSocket->bind(theAdd, PORT);

    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(udpSocket, SIGNAL(disconnected()), this, SLOT(disconnected()));

    if(udpSocket->isOpen()){
        qDebug() << " Server could not start";
        isLive = false;
    }else{
        qDebug() << "Server started!";
        isLive = true;
    }

}

DUPServer::~DUPServer()
{
    udpSocket->disconnect();
}

bool DUPServer::serverIsLive()
{
    return isLive;
}

QString DUPServer::getInfo()
{
    QString res = "0";
    if(isLive){
        res.clear();
        res.append(udpSocket->localAddress().toString());
        res.append(":");
        res.append(QString::number(udpSocket->localPort()));
    }
    return res;
}

void DUPServer::newConnection()
{
    // need to grab the socket

}

void DUPServer::currentFrame(QImage image)
{
    //FOR DEBUG
    //frame2Send.save("/Users/novel/newScreenSharing/2.png");
    ///
    frame2Send = image;
}

void DUPServer::readyRead()
{

    while(udpSocket->hasPendingDatagrams()){

        QByteArray data;

        data.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(data.data(), data.size());

        //decode commands
        QTextCodec *codec = QTextCodec::codecForName("KOI8-R");
        QString string = codec->toUnicode(data);

        if(string == "getScreen"){

            if(frame2Send.isNull()){
                return;
            }

            udpSocket->writeDatagram(sendImage(frame2Send), theAdd, PORT);
            udpSocket->flush();
            //qDebug() << "sent screen";

        }else if(string == "bye"){
            disconnected();
            qDebug() << "eol";

        }else{
            qDebug() << "Nothing to send";
        }


    }


}

QByteArray DUPServer::sendImage(QImage imgN)
{
    QByteArray packet;
    QDataStream out(&packet, QIODevice::WriteOnly);

    /*QBuffer buffer;
    buffer.open(QIODevice::WriteOnly);
    imgN.save(&buffer, "JPEG");*/

    //compress buffer
    QByteArray ba;
    QBuffer    buffer(&ba); // QBuffer inherits QIODevice
    buffer.open(QIODevice::WriteOnly);
    imgN.save(&buffer, "JPG");
    buffer.close();

    out << (qint32)0;
    out << ba; //imgN;
    out.device()->seek(0);
    out << (qint32)(packet.size() - sizeof(qint32));

    //compress slow
    //QByteArray ca = qCompress(packet, 5);

    return packet; //ca;
}

void DUPServer::disconnectThis(QUdpSocket *socket)
{

    //fin
    socket->flush();

    socket->waitForBytesWritten(3000);

    socket->close();

}

void DUPServer::disconnected()
{

    //fin
    udpSocket->flush();

    udpSocket->waitForBytesWritten(3000);

    udpSocket->close();

}

void DUPServer::killServer()
{
    if(udpSocket->isOpen()){

        qDebug() << "disc";

        disconnected();

        udpSocket->disconnect();

        qDebug() << "eos";
    }

}

