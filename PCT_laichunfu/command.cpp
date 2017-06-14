#include "command.h"
#include <QDebug>

Command cmdFunc;

Command::Command(QObject *parent) :
    QObject(parent)
{

   // comPort->open()
    comPort = NULL;
}
Command::~Command()
{
     if(comPort != NULL)
     {
         comPort->close();
     }
     delete comPort;

}
int Command::openComPort(const QString &name, const PortSettings &settings, QextSerialBase::QueryMode mode)
{
     comPort = new Posix_QextSerialPort(name,settings,mode);
     return 0;
     //comPort->open()
}
int Command::closeComPort()
{
    if(comPort != NULL)
    {
        comPort->close();
        comPort = NULL;
    }

}

unsigned int Command::sumCheck(unsigned char *buf, int len)
{
    unsigned int checkValue  =0;
    for (int i = 0; i < len; i ++)
    {
        checkValue += buf[i];
    }
    return checkValue;
}

int Command::groupSendPackage(unsigned char cmd,unsigned char * dst, unsigned char *srcData, int srcLen)
{
        int count = 0;
        dst[count++] = 0xEA;
        dst[count++] = 0xEA;
        dst[count++] = cmd;
        if (srcData != NULL)
        {
           memcpy(dst + count,srcData,srcLen);
           count += srcLen;
        }
        unsigned int check = sumCheck(dst+2,count -2);
        check &= 0xFF;
        dst[count++] = (unsigned char )(check >> 4);
        dst[count++] = (unsigned char )check&0x0F;
        dst[count++] = 0xED;
        dst[count++] = 0xEE;
        return count;
}

int Command::analysisRecvPackage(unsigned char &cmd,unsigned char * recv,int recvLen)
{
     unsigned char header1 = recv[0];
     unsigned char header2 = recv[1];
     cmd  =  recv[2];
     unsigned char tail1 = recv[recvLen -2];
     unsigned char tail2 = recv[recvLen -1];
   //  unsigned int recvCheck = recv[recvLen -3]+recv[recvLen -4]*256;
    unsigned int recvCheck  = (recv[recvLen -3] &0x0f)|((recv[recvLen -4]&0x0f) << 4);
     if (header1 != 0xEA|| header2 != 0xEA)
     {
         qDebug() << "-1";
         return -1;
     }

     if (tail1 != 0xED || tail2 != 0xEE)
     {
          qDebug() << "-2";
         return -2;
     }
     unsigned int check = sumCheck(recv+2,recvLen - 6);
     check &= 0xff;
     if (check != recvCheck)
     {
         qDebug() << "-3 "<< "check:" << check << "recvCheck" <<recvCheck;
         return -3;
     }

     return 0;
}

int Command::sendConfirmStdAck()
{
    if (comPort == NULL)
    {
        return -1;
    }

    unsigned char sendBuf[20] = {0};
    int sendLen = groupSendPackage(0x11,sendBuf,NULL,0);
    QByteArray data = QByteArray::fromRawData((char *)sendBuf,sendLen);
    comPort->write(data);
   // qDebug() << data.toHex();

    return 0;
}

int Command::sendConfirmStd(int tValue, float oValue,char offet,unsigned char *imagePix)
{
    unsigned char sendBuf[1024];
    unsigned char data[1024];
    if (comPort == NULL)
    {
        return -1;
    }
    memset(sendBuf,0,sizeof(sendBuf));
    memset(data,0,sizeof(data));
    int count = 0;
    tValue *= 1000;
    data[count++] = (tValue >> 24)&0xFF;
    data[count++] = (tValue >> 16)&0xFF;
    data[count++] = (tValue >> 8)&0xFF;
    data[count++] = tValue & 0xFF;
    data[count++] = '|';
    int result = (int)(oValue * 1000);
    data[count++] = (result >> 24)&0xFF;
    data[count++] = (result >> 16)&0xFF;
    data[count++] = (result >> 8)&0xFF;
    data[count++] = result & 0xFF;
    data[count++] = '|';
    data[count++] = offet;
    data[count++] = '|';
    data[count++] = 0x01;
    data[count++] = '|';
    int imageOffset = (500*150 +30)*3;
    for (int i = 0;i < 1200; i+= 3)
    {
        data[count++] = *(imagePix + imageOffset + i++);
        data[count++] = *(imagePix + imageOffset + i++);
        data[count++] = *(imagePix + imageOffset + i++);

    }
    int sendLen = groupSendPackage(0x12,sendBuf,data,count);
    QByteArray sendData = QByteArray::fromRawData((char *)sendBuf,sendLen);
    comPort->write(sendData);
   // qDebug() << sendData.toHex();
    return 0;
}

int Command::sendQcAck()
{
    if (comPort == NULL)
    {
        return -1;
    }

    unsigned char sendBuf[20] = {0};
    int sendLen = groupSendPackage(0x21,sendBuf,NULL,0);
    QByteArray data = QByteArray::fromRawData((char *)sendBuf,sendLen);
    comPort->write(data);
   // qDebug() << data.toHex();

    return 0;
}
int Command::sendTcOffsetAck()
{
    if (comPort == NULL)
    {
        return -1;
    }

    unsigned char sendBuf[20] = {0};
    int sendLen = groupSendPackage(0x31,sendBuf,NULL,0);
    QByteArray data = QByteArray::fromRawData((char *)sendBuf,sendLen);
    comPort->write(data);
   // qDebug() << data.toHex();
    return 0;
}

int Command::sendCurveDataAck()
{
    if (comPort == NULL)
    {
        return -1;
    }

    unsigned char sendBuf[20] = {0};
    int sendLen = groupSendPackage(0x41,sendBuf,NULL,0);
    QByteArray data = QByteArray::fromRawData((char *)sendBuf,sendLen);
    comPort->write(data);
   // qDebug() << data.toHex();
    return 0;
}

int Command::sendCurveAck()
{
    if (comPort == NULL)
    {
        return -1;
    }

    unsigned char sendBuf[20] = {0};
    int sendLen = groupSendPackage(0x71,sendBuf,NULL,0);
    QByteArray data = QByteArray::fromRawData((char *)sendBuf,sendLen);
    comPort->write(data);
   // qDebug() << data.toHex();
    return 0;
}

int Command::sendConnectAck()
{
    if (comPort == NULL)
    {
        return -1;
    }

    unsigned char sendBuf[20] = {0};
    int sendLen = groupSendPackage(0x51,sendBuf,NULL,0);
    QByteArray data = QByteArray::fromRawData((char *)sendBuf,sendLen);
    comPort->write(data);
   // qDebug() << data.toHex();
    return 0;
}

int Command::sendQcData(int tValue, float oValue,char offet,unsigned char *imagePix)
{
    unsigned char sendBuf[1024];
    unsigned char data[1024];
    if (comPort == NULL)
    {
        return -1;
    }
    memset(sendBuf,0,sizeof(sendBuf));
    memset(data,0,sizeof(data));
    int count = 0;
    tValue *= 1000;
    data[count++] = (tValue >> 24)&0xFF;
    data[count++] = (tValue >> 16)&0xFF;
    data[count++] = (tValue >> 8)&0xFF;
    data[count++] = tValue & 0xFF;
    data[count++] = '|';
    int result = (int)(oValue * 1000);
    data[count++] = (result >> 24)&0xFF;
    data[count++] = (result >> 16)&0xFF;
    data[count++] = (result >> 8)&0xFF;
    data[count++] = result & 0xFF;
    data[count++] = '|';
    data[count++] = offet;
    data[count++] = '|';
    data[count++] = 0x01;
    data[count++] = '|';
    int imageOffset = (500*150 +30)*3;
    for (int i = 0;i < 1200; i+= 3)
    {
        data[count++] = *(imagePix + imageOffset +i++);
        data[count++] = *(imagePix + imageOffset +i++);
        data[count++] = *(imagePix + imageOffset +i++);
    }
    int sendLen = groupSendPackage(0x22,sendBuf,data,count);
    QByteArray sendData = QByteArray::fromRawData((char *)sendBuf,sendLen);
    comPort->write(sendData);
   // qDebug() << sendData.toHex();
    return 0;
}

int Command::sendTcOffsetData(unsigned short offset,unsigned char cWidth,unsigned char cLength,
                            unsigned char tWidth,unsigned char tLength,unsigned char *imagePix)
{
    unsigned char sendBuf[1024];
    unsigned char data[1024];
    if (comPort == NULL)
    {
        return -1;
    }
    memset(sendBuf,0,sizeof(sendBuf));
    memset(data,0,sizeof(data));
    int count = 0;
    data[count++] = offset /256;
    data[count++] = offset %256;
    data[count++] = '|';
    data[count++] = cWidth;
    data[count++] = '|';
    data[count++] = cLength;
    data[count++] = '|';
    data[count++] = tWidth;
    data[count++] = '|';
    data[count++] = tLength;
    data[count++] = '|';
    int imageOffset = (500*150 +30)*3;
    for (int i = 0;i < 1200; i+= 3)
    {
        data[count++] = *(imagePix + imageOffset +i++);
        data[count++] = *(imagePix + imageOffset +i++);
        data[count++] = *(imagePix + imageOffset +i++);
    }
    int sendLen = groupSendPackage(0x32,sendBuf,data,count);
    QByteArray sendData = QByteArray::fromRawData((char *)sendBuf,sendLen);
    comPort->write(sendData);
   // qDebug() << sendData.toHex();
    return 0;
}
