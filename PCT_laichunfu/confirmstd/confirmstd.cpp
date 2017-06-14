#include "confirmstd.h"
#include "ui_confirmstd.h"

#include "ecam/ezsys.h"
#include "ecam/inifile.h"
#include <stdio.h>
#include <command.h>
#include <QDir>
#include <QDebug>

#define DEV_PATH "/sys/class/gpio/gpio111/value"

ConfirmStd::ConfirmStd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfirmStd)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowFlags(Qt::FramelessWindowHint);
     system("rm ./img/*.bmp");
     timer = new QTimer(this);
     connect(timer,SIGNAL(timeout()),this,SLOT(updateStd()));
     timer->start(500);
     testTimer = new QTimer(this);
     connect(testTimer,SIGNAL(timeout()),this,SLOT(testStd()));
     mTested = false;

}

ConfirmStd::~ConfirmStd()
{
    system("rm ./stdimages/*.bmp");
    delete testTimer;
    delete ui;
}
void ConfirmStd::updateStd()
{
    if (isPaperInsert())
    {
        if (!mTested)
        {
            ui->ShowImageLabel->setPixmap(QPixmap(":/images/waitTest.jpg"));
        }
    }
    else
    {
        ui->ShowImageLabel->setPixmap(QPixmap(":/images/waitCard.jpg"));
        mTested =false;
        return;
    }

}

void ConfirmStd::testStd()
{
    Roption.icmd = 's';
    if(get_frame(fd,&Roption,Glut)==0)
    {
           prccallback(Roption.pimg, 1280, 720, Roption.ovalue);//保存图像
       // testTimer->start(1000);
           printf("save snap image! tvalue=%d ovalue=%d\n",Roption.tvalue,Roption.ovalue);
           if (readDataToTable())
           {
              ui->PromptLabel->setText("测量成功");
              //向PC发送定标数据
              //cmdFunc.sendQcData(Roption.tvalue,mCheckValue,0,Roption.pimg);
              unsigned char img_buf[500*300*3];
              memset(img_buf,0,sizeof(img_buf));
              YUV2RGB0(Roption.pimg,img_buf,1280,720);
              cmdFunc.sendConfirmStd(Roption.ovalue,0,(char)0,img_buf);
           }
           else
           {
            //ui->PromptLabel->setText("测量无效");
           }
    }
    testTimer->stop();
    ui->CheckPushButton->setEnabled(true);
}

void ConfirmStd::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

//返回命令
void ConfirmStd::on_expReturnBtn_clicked()
{
    close();
}
//测量命令
void ConfirmStd::on_CheckPushButton_clicked()
{
    ui->CheckPushButton->setEnabled(false);
    ui->PromptLabel->setText("正在测量");
    testTimer->start(500);
    if (!isPaperInsert())
    {
       ui->CheckPushButton->setEnabled(true);
       mTested = false;
       return;
    }
    mTested = true;
    ui->ShowImageLabel->setPixmap(QPixmap(":/images/testing.jpg"));
}

bool ConfirmStd::isPaperInsert()
{
    QFile file(DEV_PATH);
    if (!file.open(QIODevice::ReadOnly))
    {
        system("echo 111 > /sys/class/gpio/export");
        system("echo in > /sys/class/gpio/gpio111/direction");
        return false;
    }
    QTextStream in(&file);
    QString data = in.readAll();

    file.close();
    if (data.at(0) == '1')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ConfirmStd::readDataToTable()
{
    //从img 文件中读出
    QString path = QDir::currentPath() + "/img/";
    QDir dir(path);
    QStringList listfilters;
    listfilters << "*.bmp";
    if (dir.entryList(listfilters).count() == 0)
    {
        //没有测试的数据;
        return false;
    }
    QStringList fileList =  dir.entryList(listfilters);
    for (int i = 0; i < fileList.count(); i++)
    {
        QString filename = fileList[i];
        //解析文件名
        int index1 = filename.indexOf('-',0);
        QString datetime = filename.left(index1);
        qDebug() << datetime;
        int index2 = filename.indexOf('.',index1 +1);
        QString value = filename.mid(index1+1,index2 - index1 -1);
        int count = ui->AnalysisTableWidget->rowCount();
        ui->AnalysisTableWidget->insertRow(count);
        ui->AnalysisTableWidget->setItem(count,0,new QTableWidgetItem("定标"));
        ui->AnalysisTableWidget->setItem(count,1,new QTableWidgetItem(value));
        ui->AnalysisTableWidget->setItem(count,2,new QTableWidgetItem(value));
        ui->AnalysisTableWidget->setItem(count,3,new QTableWidgetItem(QString("%1").arg(count)));
        ui->AnalysisTableWidget->setItem(count,4,new QTableWidgetItem(datetime));
        ui->TestValueLineEdit->setText(value);
        ui->ResultLineEdit->setText(value);
        //将图片显示到label中
        showImage(path + filename);
        //将图片移到定标目录下
        QString newPath = QDir::currentPath() + "/stdimages/";
        QFile::copy(path + filename,newPath + filename);
        QFile file(path + filename);
        file.remove();
    }
    return true;
}
void ConfirmStd::showImage(QString filename)
{
    QPixmap pix;
    //QPainter painter;
    pix.load(filename);
    qreal width = pix.width();
    qreal height = pix.height();
    pix = pix.scaled(width/4,height/4,Qt::KeepAspectRatio);
    QTransform transform;
    transform.rotate(90);
    ui->ShowImageLabel->setPixmap(pix.transformed(transform));
}
