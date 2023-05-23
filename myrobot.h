#ifndef MYROBOT_H
#define MYROBOT_H

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
#include <QTimer>
#include <QMutex>

class MyRobot : public QObject {
    Q_OBJECT
public:
    explicit MyRobot(QObject *parent = 0);
    void doConnect();
    void disConnect();
    QByteArray DataToSend;
    QByteArray DataReceived;
    QMutex Mutex;
    void changeDatatosend(__int8 bit1,__int8 bit2,__int8 bit3,__int8 bit4,__int8 bit5,__int8 bit6,__int8 bit7);


signals:
    void updateUI(const QByteArray Data);
public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();
    void MyTimerSlot();


private:
    QTcpSocket *socket;
    QTimer *TimerEnvoi;
    __int16 crc() ;
};

#endif // MYROBOT_H
