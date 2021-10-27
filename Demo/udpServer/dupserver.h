#ifndef DUPServer_H
#define DUPServer_H

#include <QObject>
#include <QUdpSocket>
#include <QDebug>
#include <QBuffer>
#include <QImage>
#include <QTextCodec>

class DUPServer : public QObject
{
    Q_OBJECT

public:
    explicit DUPServer(QObject *parent = 0, QString theAddC = "128.0.0.1");
    ~DUPServer();

    bool serverIsLive();

    void killServer();

    QString getInfo();

    void currentFrame(QImage image);

private slots:
    void newConnection();

    void readyRead();

    void disconnected();

private:
    QUdpSocket *udpSocket;
    QByteArray sendImage(QImage imgN);
    bool isLive = false;
    void disconnectThis(QUdpSocket *socket);
    QImage frame2Send;
    QHostAddress theAdd;
};

#endif // DUPServer_H
