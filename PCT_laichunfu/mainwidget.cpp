#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "exp/expdialog.h"
#include "select/selectdialog.h"
#include "manage/managedialog.h"
#include "set/setdialog.h"
#include "connect_sql.h"
#include "ecam/ezsys.h"
#include "ecam/inifile.h"
#include <QDateTime>
#include "lincom/posix_qextserialport.h"
#include "lincom/qextserialbase.h"
#include "command.h"
#include "confirmstd/confirmstd.h"
#include <QSettings>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
   // this->setWindowState(Qt::WindowFullScreen);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateDateTime()));
    timer->start(1000);
   // QDateTime dateTime = QDateTime::currentDateTime();
   // int year = dateTime.date().year();
   // if (year == 2016 || dateTime.date().month() == 10)
   // {
   //     exit(-1);
   // }
   // comm = new QextSerialPort();

    Roption.icmd=0;
    //读取系统配置参数
    readcfg(&Roption,Glut);
    //初始化摄像头
    startuvc (Roption.sexp);	//&Roption,Glut
    //printf("sexp = %d \n",Roption.sexp);

    struct PortSettings myComSettings = {BAUD19200,
                                         DATA_8,
                                         PAR_NONE,
                                         STOP_1,
                                         FLOW_OFF,
                                         500
                                        };

   // comPort = new Posix_QextSerialPort("/dev/ttyO2",myComSettings,QextSerialBase::Polling);
   // comPort->open(QIODevice::ReadWrite);
    cmdFunc.openComPort("/dev/ttyO2",myComSettings,QextSerialBase::Polling);
    cmdFunc.comPort->open(QIODevice::ReadWrite);
    comTimer = new QTimer(this);
    connect(comTimer,SIGNAL(timeout()),this,SLOT(readCommandData()));
    comTimer->start(1000);
}

MainWidget::~MainWidget()
{
    delete timer;
    delete comTimer;
    delete ui;
}
void MainWidget::updateDateTime()
{
    QDateTime dateTime = QDateTime::currentDateTime();
    ui->labelDatetime->setText(dateTime.toString("yyyy-MM-dd hh:mm:ss"));
}
//样品分析
void MainWidget::on_pushButtonExp_clicked()
{
    timer->stop();
    ExpDialog * expDlg = new ExpDialog(this);
    expDlg->show();
    timer->start();
}
//试剂管理
void MainWidget::on_pushButtonManage_clicked()
{
    timer->stop();
    ManageDialog * expDlg = new ManageDialog(this);
    expDlg->show();
    timer->start();
}
//数据查询
void MainWidget::on_pushButtonSelect_clicked()
{

    timer->stop();
    SelectDialog * selectDlg = new SelectDialog(this);
    selectDlg->show();
    timer->start();
}

//功能设置
void MainWidget::on_pushButtonSet_clicked()
{
   // timer->stop();
    SetDialog * setDlg = new SetDialog(0,this);
    setDlg->show();
   // timer->start();
}
//软件关闭
void MainWidget::on_pushButtonClose_clicked()
{
   close();
}

//软件重启
void MainWidget::on_pushButtonReboot_clicked()
{
  // close();
    db.close();
    system("reboot");
}

void MainWidget::readCommandData()
{
     QByteArray recvData = cmdFunc.comPort->readAll();

     if (recvData.size() <=0)
     {
         return;
     }
   //  qDebug() << recvData.toHex();
     unsigned char cmd;
     if (cmdFunc.analysisRecvPackage(cmd, (unsigned char *)recvData.data(), recvData.size()) < 0)
     {
         qDebug() << "analysisRecvPackage error";
         return ;
     }

     switch (cmd)
     {
         case 0x01://定标命令
             //跳转到定标界面
             cmdFunc.sendConfirmStdAck();
             openConfirmStd();

             break;
         case 0x02://质控命令
             //跳转到质控界面
             cmdFunc.sendQcAck();
             on_pushButtonExp_clicked();

             break;
         case 0x03://间距
             //跳转到间距界面
             cmdFunc.sendTcOffsetAck();
             openOffSet();
             break;
         case 0x04://下载曲线
         {
             cmdFunc.sendCurveDataAck();
             QByteArray dst = recvData.mid(3,recvData.size() -7);
             for (int i = 0; i < dst.size(); i++)
             {
                 dst[i] = dst[i] -9;
             }
             qDebug() << dst;
             QString  savePath = QDir::currentPath() + "/localreagent";
             QString dateTime = QDateTime::currentDateTime()
                                        .toString("yyyy_MM_dd_hh_mm_ss_zzz");
             QString saveFileName =savePath+ "/" + dateTime +".txt";

             QFile saveFile(saveFileName);
             if (!saveFile.open(QIODevice::WriteOnly))
             {
                return;
             }
             QTextStream out(&saveFile);
             out << dst;
             saveFile.close();

         }


             break;
         case 0x05://联机命令
             cmdFunc.sendConnectAck();
             break;
         case 0x06:

             break;
         case 0x07://下载曲线确认命令
             cmdFunc.sendCurveAck();
             break;
         default:
             break;
     }
}

void MainWidget::openConfirmStd()
{
    timer->stop();
    ConfirmStd * setDlg = new ConfirmStd(this);
    setDlg->show();
    timer->start();
}

void MainWidget::openOffSet()
{
   // timer->stop();
    //SetDialog * setDlg = new SetDialog(1,this);
    //setDlg->show();
    //timer->start();
    QSettings set("config.ini",QSettings::IniFormat);
    int Toffset = set.value("Roption/Toffset").toInt();
   // int Soffset = set.value("Roption/Soffset").toString();
   // int Cminvalue = set.value("Roption/Cminvalue").toString();
    int Twidth = set.value("Roption/Twidth").toInt();
    int Thight = set.value("Roption/Thight").toInt();
    unsigned char buf[5] = {0};
    //buf[0] = (unsigned char)Toffset &0xFF;
    buf[1] = 0;
    buf[2] = 2;
    buf[3] = (unsigned char)Twidth & 0xFF;
    buf[4] = (unsigned char)Thight & 0xFF;

    QFile file("offsetImg");
    if (!file.open(QIODevice::ReadOnly))
    {
        return;
    }
    QByteArray offsetImg = file.readAll();
    file.close();

    cmdFunc.sendTcOffsetData(Toffset,0,0,buf[3],buf[4],(unsigned char *)offsetImg.data());
}
