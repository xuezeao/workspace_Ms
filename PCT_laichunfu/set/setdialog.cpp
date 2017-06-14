#include "setdialog.h"
#include "ui_setdialog.h"
#include <QDateTime>
#include <QSettings>
#include <QDebug>
#include <QDir>
#include "ecam/ezsys.h"
#include "command.h"

#define DEV_PATH "/sys/class/gpio/gpio111/value"

SetDialog::SetDialog(int WindIndex,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetDialog)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowFlags(Qt::FramelessWindowHint);
  //  this->setWindowState(Qt::WindowFullScreen);
    this->move((parent->width() - this->width())/2,
               (parent->height() - this->height())/2);
    ui->sysImageLabel->setPixmap(QPixmap(":/images/waitCard.jpg"));
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateDatetime()));
    timer->start(1000);
    testTimer = new QTimer(this);
    connect(testTimer,SIGNAL(timeout()),this,SLOT(testSysCheck()));
    mTestFlag = false;
    if (WindIndex == 1)
    {
        isTestOffset = true;
    }
    else
    {
        isTestOffset = false;
    }
    ui->stackedWidget->setCurrentIndex(WindIndex);
    mSelectIndex = 0;
    ui->sysCheckTableWidget->horizontalHeader()->setClickable(false); //设置表头不可点击
    ui->sysCheckTableWidget->setStyleSheet("selection-background-color:lightblue;"); //设置选中背景色
    ui->sysCheckTableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}"); //设置表头背景色
    ui->sysCheckTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    connect(ui->sysCheckTableWidget,SIGNAL(itemClicked(QTableWidgetItem*)),this,SLOT(recordNo(QTableWidgetItem*)));

    //设置日期
    ui->comboBoxYear->clear();
    for (int i = 1970; i <= 2100; i++)
    {
         ui->comboBoxYear->addItem(QString("%1").arg(i));
    }
    int index  = ui->comboBoxMonth->currentIndex();
    setDays(index);
    connect(ui->comboBoxMonth,SIGNAL(currentIndexChanged(int)),this,SLOT(setDays(int)));
    QDateTime dateTime = QDateTime::currentDateTime();
    QString str = dateTime.toString("yyyyMMddhhmmss");

    ui->comboBoxYear->setCurrentIndex(str.mid(0,4).toInt() - 1970);
    ui->comboBoxMonth->setCurrentIndex(str.mid(4,2).toInt() - 1);
    ui->comboBoxDay->setCurrentIndex(str.mid(6,2).toInt() - 1);
    ui->comboBoxHour->setCurrentIndex(str.mid(8,2).toInt());
    ui->comboBoxMin->setCurrentIndex(str.mid(10,2).toInt());
    ui->comboBoxSec->setCurrentIndex(str.mid(12,2).toInt());

    QSettings set("setconfig.ini",QSettings::IniFormat);//
    QString localIp = set.value("ip/localip").toString();
    QString mask = set.value("mask/submask").toString();
    QStringList list = localIp.split('.');
    ui->IPEdit_1->setText(list[0]);
    ui->IPEdit_2->setText(list[1]);
    ui->IPEdit_3->setText(list[2]);
    ui->IPEdit_4->setText(list[3]);
    list.clear();
    list = mask.split('.');
    ui->MaskEdit_1->setText(list[0]);
    ui->MaskEdit_2->setText(list[1]);
    ui->MaskEdit_3->setText(list[2]);
    ui->MaskEdit_4->setText(list[3]);
}

SetDialog::~SetDialog()
{   delete timer;
    delete testTimer;
    delete ui;
}

void SetDialog::testSysCheck()
{
    Roption.icmd = 's';
    if(get_frame(fd,&Roption,Glut)==0)
    {
           prccallback(Roption.pimg, 1280, 720, Roption.ovalue);//保存图像
           printf("save snap image! tvalue=%d ovalue=%d\n",Roption.tvalue,Roption.ovalue);
           if (read_value())
           {
              ui->sysResultLabel->setText("测量成功");
           }
           else
           {
            //ui->PromptLabel->setText("测量无效");
           }
    }
    else
    {
        //ui->PromptLabel->setText("测量无效");
    }
     ui->sysCheckTestBtn->setEnabled(true);
     testTimer->stop();
}

void SetDialog::showImage(int rowIndex)
{
    QString newPath = QDir::currentPath() + "/SysCheckImages/";
    QString imageName = newPath;
    imageName.append(ui->sysCheckTableWidget->item(rowIndex,3)->text());
    imageName.append("-");
    imageName.append(ui->sysCheckTableWidget->item(rowIndex,1)->text());
    imageName.append(".bmp");
    qDebug() << imageName;
    QPixmap pix;
    pix.load(imageName);
    qreal width = pix.width();
    qreal height = pix.height();
    pix = pix.scaled(width/3,height/3,Qt::KeepAspectRatio);
    QTransform transform;
    transform.rotate(90);
    ui->sysImageLabel->setPixmap(pix.transformed(transform));
}

void SetDialog::deleteImage(int rowIndex)
{
    QString newPath = QDir::currentPath() + "/SysCheckImages/";
    QString imageName = newPath;
    imageName.append(ui->sysCheckTableWidget->item(rowIndex,3)->text());
    imageName.append("-");
    imageName.append(ui->sysCheckTableWidget->item(rowIndex,1)->text());
    imageName.append(".bmp");
   // QFile file(imageName);
    QFile::remove(imageName);
}

//选择的行
void SetDialog::recordNo(QTableWidgetItem *item)
{
    mSelectIndex = item->row();
    qDebug() << mSelectIndex;
    showImage(mSelectIndex);

}

void SetDialog::updateDatetime()
{
    QDateTime datetime= QDateTime::currentDateTime();
    ui->labelDateTime->setText(datetime.toString("yyyy-MM-dd hh:mm:ss"));
    if (isPaperInsert())
    {
        if (!mTestFlag)
        {
            ui->sysImageLabel->setPixmap(QPixmap(":/images/waitTest.jpg"));
        }

    }
    else
    {
        ui->sysImageLabel->setPixmap(QPixmap(":/images/waitCard.jpg"));
        mTestFlag = false;
    }
}

void SetDialog::setDays(int index)
{
    int days = 0;
    if (index == 1)//如果是二月
    {
        QString year = ui->comboBoxYear->currentText();
        int iYear = year.toInt();
        if ((iYear % 4 == 0 && iYear %100 != 0) || iYear % 400 == 0)
        {
            //是闰年
            days = 29;
        }
        else
        {
            //不是闰年
            days = 28;
        }
    }
    else if (index == 3 || index == 5 || index == 8 || index == 10)//4,6,9,11月
    {
        days = 30;
    }
    else //1,3,5,7,8,10,12
    {
       days = 31;
    }
    ui->comboBoxDay->clear();
    for (int i = 1; i <= days; i++)
    {
        ui->comboBoxDay->addItem(QString("%1").arg(i));
    }
}

//CMOS校准
void SetDialog::on_cmosCheckBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->labelTitle->setText("CMOS校准");
}

//用户校准
void SetDialog::on_userCheckBtn_clicked()
{
  ui->stackedWidget->setCurrentIndex(2);
  QSettings set("config.ini",QSettings::IniFormat);
  QString Toffset = set.value("Roption/Toffset").toString();
 // QString Soffset = set.value("Roption/Soffset").toString();
 // QString Cminvalue = set.value("Roption/Cminvalue").toString();
  QString Twidth = set.value("Roption/Twidth").toString();
//  QString Thight = set.value("Roption/Thight").toString();
  ui->CT_DistLineEdit->setText(Toffset);
  ui->TWidthLineEdit->setText(Twidth);
  ui->labelTitle->setText("用户校准");
}

//程序升级
void SetDialog::on_programUpdateBtn_clicked()
{

}

//设置时钟与IP确认
//void SetDialog::on_DatetimeIPConfirmBtn_clicked()
//{
//
//}

//设置时钟和Ip返回
void SetDialog::on_DateTimeIPRetBtn_clicked()
{
    close();
}

//版本返回
void SetDialog::on_VersionRetBtn_clicked()
{
    close();
}

//用户校准返回
void SetDialog::on_UserCheckRetBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->labelTitle->setText("功能设置");
}

//校验与升级返回按钮
void SetDialog::on_checkOrUpdateBtn_clicked()
{
    close();
}

//系统校准返回
void SetDialog::on_sysCheckRetBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->labelTitle->setText("功能设置");
}

//判断是否有卡插入
bool SetDialog::isPaperInsert()
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
//系统校准按钮
void SetDialog::on_sysCheckBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

    ui->labelTitle->setText("系统校准");
}

//CMOS设置返回
void SetDialog::on_cmosReturnBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->labelTitle->setText("功能设置");
}

//系统校准删除按钮
void SetDialog::on_sysCheckDelBtn_clicked()
{
    if (mSelectIndex >= ui->sysCheckTableWidget->rowCount())
    {
        return;
    }
   deleteImage(mSelectIndex);
   ui->sysCheckTableWidget->removeRow(mSelectIndex);
}

//读取测量值
bool SetDialog::read_value()
{
    //测试值
    QString path = QDir::currentPath() + "/img/";
    QDir dir(path);
    QStringList listfilters;
    listfilters << "*.bmp";

    if (dir.entryList(listfilters).count() == 0)
    {
        //没有测试的数据;
        return false;
    }
    else
    {
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
           qDebug() << value;
           ui->sysCheckTableWidget->insertRow(0);
           ui->sysTestLineEdit->setText(QString(value));
           //序号
           int count = ui->sysCheckTableWidget->rowCount() + 1;
           ui->sysCheckTableWidget->setItem(0,0,new QTableWidgetItem(QString("%1").arg(count)));
           ui->sysCheckTableWidget->setItem(0,1,new QTableWidgetItem(value));
           ui->sysCheckTableWidget->setItem(0,2,new QTableWidgetItem(ui->sysOdLineEdit->text()));
           ui->sysCheckTableWidget->setItem(0,3,new QTableWidgetItem(datetime));
           //提示测试成功
           ui->sysResultLabel->setText("测试成功");
           //显示图片

           QString newPath = QDir::currentPath() + "/SysCheckImages/";
           QFile::copy(path + filename,newPath + filename);
           QFile file(path + filename);
           file.remove();
           showImage(0);
           break;
       }
   }
    return true;
}

//系统校准测量按钮
void SetDialog::on_sysCheckTestBtn_clicked()
{
    if (ui->sysOdLineEdit->text() == "")
    {
        //提示输入OD值
        return;
    }
    if (!isPaperInsert())
    {
        ui->sysImageLabel->setPixmap(QPixmap(":/images/waitCard.jpg"));
        mTestFlag = false;
        return;
    }
    ui->sysCheckTestBtn->setEnabled(false);
    testTimer->start(1000);
    ui->sysImageLabel->setPixmap(QPixmap(":/images/testing.jpg"));
    mTestFlag = true;

  /*  Roption.icmd = 's';
    if(get_frame(fd,&Roption,Glut)==0)
    {
           prccallback(Roption.pimg, 1280, 720, Roption.ovalue);//保存图像
           printf("save snap image! tvalue=%d ovalue=%d\n",Roption.tvalue,Roption.ovalue);
           if (read_value())
           {
              ui->sysResultLabel->setText("测量成功");
           }
           else
           {
            //ui->PromptLabel->setText("测量无效");
           }
    }
    else
    {
        //ui->PromptLabel->setText("测量无效");
    }*/
}

//系统校准保存按钮
void SetDialog::on_sysCheckSaveBtn_clicked()
{
    CRVALUE crvalu[100];
    memset(crvalu,0,sizeof(crvalu));
    if (ui->sysCheckTableWidget->rowCount() == 0)//如果没有记录，则返回
    {
        return;
    }
    int i = 0;
    for(i = 0; i < ui->sysCheckTableWidget->rowCount(); i++)
    {
        crvalu[i].ivalue = ui->sysCheckTableWidget->item(i,1)->text().toInt();
        crvalu[i].ovalue = ui->sysCheckTableWidget->item(i,2)->text().toInt();
    }
    CRlut(Glut,crvalu,i);
}

//间距校准
void SetDialog::on_cmosTCBtn_clicked()
{
    Roption.icmd = 't';
    if(get_frame(fd,&Roption,Glut)==0)
    {
        //显示参数
        QSettings set("config.ini",QSettings::IniFormat);
        QString Toffset = set.value("Roption/Toffset").toString();
        QString Soffset = set.value("Roption/Soffset").toString();
        QString Cminvalue = set.value("Roption/Cminvalue").toString();
        QString Twidth = set.value("Roption/Twidth").toString();
        QString Thight = set.value("Roption/Thight").toString();
        ui->cmosLineEdit_1->setText(Toffset);
        ui->cmosLineEdit_2->setText(Soffset);
        ui->cmosLineEdit_3->setText(Cminvalue);
        ui->cmosLineEdit_4->setText(Twidth);
        ui->cmosLineEdit_5->setText(Thight);
        unsigned char img_buf[500*300*3];
        memset(img_buf,0,sizeof(img_buf));
        YUV2RGB0(Roption.pimg,img_buf,1280,720);
        QFile file("offsetImg");
        if (file.open(QIODevice::WriteOnly))
        {
           QByteArray offsetImg = QByteArray::fromRawData((char *)img_buf,sizeof(img_buf));
           file.seek(SEEK_SET);
           file.write(offsetImg);
           file.close();
        }
    }
}

//底色校准
void SetDialog::on_cmosCameraBtn_clicked()
{
    Roption.icmd = 'l';
    if(get_frame(fd,&Roption,Glut)==0)
    {
        //显示底色
        QSettings set("config.ini",QSettings::IniFormat);
        QString RZout = set.value("RZValue/RZout").toString();
        QString exp = set.value("CamSet/exp").toString();
        ui->cmosLineEdit_6->setText(RZout);
        ui->cmosLineEdit_7->setText(exp);
    }
}

//设置IP
void SetDialog::on_IPConfirmBtn_clicked()
{
    QSettings set("setconfig.ini",QSettings::IniFormat);
    if (ui->IPEdit_1->text() == "" ||
        ui->IPEdit_2->text() == "" ||
        ui->IPEdit_3->text() == "" ||
        ui->IPEdit_4->text() == "" )
    {
        return;
    }

    if (ui->MaskEdit_1->text() == "" ||
        ui->MaskEdit_2->text() == "" ||
        ui->MaskEdit_3->text() == "" ||
        ui->MaskEdit_4->text() == "" )
    {
        return;
    }
    QString localIp = ui->IPEdit_1->text() +"."+
                      ui->IPEdit_2->text() +"."+
                      ui->IPEdit_3->text() +"."+
                      ui->IPEdit_4->text();
    QString mask = ui->MaskEdit_1->text() +"."+
                   ui->MaskEdit_2->text() +"."+
                   ui->MaskEdit_3->text() +"."+
                   ui->MaskEdit_4->text();
    set.setValue("ip/localip",localIp);
    set.setValue("mask/submask",mask);
    QString cmd = QString("ifconfig eth0 %1").arg(localIp);
    qDebug() << cmd;
    system(cmd.toAscii().data());
}

//设置日期
void SetDialog::on_DatetimeConfirmBtn_clicked()
{
    QString dateTime = "";
    dateTime.append(ui->comboBoxYear->currentText());
    dateTime.append("-");
    dateTime.append(ui->comboBoxMonth->currentText());
    dateTime.append("-");
    dateTime.append(ui->comboBoxDay->currentText());
    dateTime.append(" ");
    dateTime.append(ui->comboBoxHour->currentText());
    dateTime.append(":");
    dateTime.append(ui->comboBoxMin->currentText());
    dateTime.append(":");
    dateTime.append(ui->comboBoxSec->currentText());
    QString cmd = QString("date -s \"%1\"").arg(dateTime);
    qDebug() << cmd;
    system(cmd.toAscii().data());
    system("hwclock -w");
}

//设置CT间距和T线宽度
void SetDialog::on_UserCheckConfirmBtn_clicked()
{

    QSettings set("config.ini",QSettings::IniFormat);

    if (ui->CT_DistLineEdit->text() != "")
    {
        set.setValue("Roption/Toffset",ui->CT_DistLineEdit->text());
    }

    if (ui->TWidthLineEdit->text() != "")
    {
        set.setValue("Roption/Twidth",ui->TWidthLineEdit->text());
    }

}
