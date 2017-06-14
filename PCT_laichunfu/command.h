#ifndef COMMAND_H
#define COMMAND_H

#include <QObject>
#include "lincom/posix_qextserialport.h"
#include "lincom/qextserialbase.h"


class Command : public QObject
{
Q_OBJECT
public:
    explicit Command(QObject *parent = 0);
    ~Command();
    int sendConfirmStdAck();//定标应答命令
    int sendConfirmStd(int tValue, float oValue,char offet,unsigned char *imagePix);//定标数据命令
    int sendQcAck();//质控应答命令
    int sendQcData(int tValue, float oValue,char offet,unsigned char *imagePix);//质控数据
    int sendTcOffsetAck();//间距
  // int sendTcOffsetData();//间距数据
    int sendTcOffsetData(unsigned short offset,unsigned char cWidth,unsigned char cLength,
                   unsigned char tWidth,unsigned char tLength,unsigned char *imagePix);
    int sendCurveAck();
    int sendCurveDataAck();//曲线导入命令应答
    int sendConnectAck();//联机命令应答

   // int openCommandserial();//打开串口
   // int closeCommandSerial();//关闭串口
    unsigned int sumCheck(unsigned char * buf,int len);
    int groupSendPackage(unsigned char cmd,unsigned char * dst, unsigned char *srcData, int srcLen);
    int analysisRecvPackage(unsigned char &cmd, unsigned char *recv,int recvLen);
    int openComPort(const QString & name, const PortSettings& settings, QextSerialBase::QueryMode mode = QextSerialBase::Polling);
    int closeComPort();
signals:

public slots:

private:

public:
    Posix_QextSerialPort *comPort;

};

extern Command cmdFunc;
#endif // COMMAND_H
