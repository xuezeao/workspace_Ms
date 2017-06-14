#include "expdialog.h"
#include "ui_expdialog.h"
#include "connect_sql.h"
#include <QDateTime>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QPixmap>
#include "ecam/ezsys.h"
#include "command.h"
#include "lincom/posix_qextserialport.h"
#include "lincom/qextserialbase.h"


#define DEV_PATH "/sys/class/gpio/gpio111/value"

ExpDialog::ExpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExpDialog)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowFlags(Qt::FramelessWindowHint);
   // this->setWindowState(Qt::WindowFullScreen);
    mTimeOut = 0;
    mSelectIndex = -1;
    mRecordIndex = -1;
    mSelcetMode = 0;
    mTested = false;
    mAutoTestEnable = true;
    struct PortSettings myComSettings = {BAUD19200,
                                         DATA_8,
                                         PAR_NONE,
                                         STOP_1,
                                         FLOW_OFF,
                                         500
                                        };
    mBarcodePort = new Posix_QextSerialPort("/dev/ttyO1",myComSettings,QextSerialBase::Polling);
    mBarcodePort->open(QIODevice::ReadWrite);

    barcodeTimer = new QTimer(this);
    connect(barcodeTimer,SIGNAL(timeout()),this,SLOT(getPaientId()));
    barcodeTimer->start(1500);

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateDatetime()));
    timer->start(1000);
    testTimer = new QTimer(this);
    connect(testTimer,SIGNAL(timeout()),this,SLOT(testCard()));
    ui->labelTitle->setText("试剂选择");
    ui->stackedWidget->setCurrentIndex(1);
   // this->move((parentWidget()->width() - this->width())/2,
   //            (parentWidget()->height() - this->height())/2);
    this->move((parent->width() - this->width())/2,
               (parent->height() - this->height())/2);
    ui->ShowImageLabel->setPixmap(QPixmap(":/images/waitCard.jpg"));
//    ui->tableWidget->setFrameShape(QFrame::Box); //设置无边框
    ui->tableWidget->horizontalHeader()->setClickable(false); //设置表头不可点击
    ui->tableWidget->horizontalHeader()->setVisible(true);
    ui->tableWidget->setStyleSheet("selection-background-color:lightblue;"); //设置选中背景色
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}"); //设置表头背景色
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    connect(ui->tableWidget,SIGNAL(itemClicked(QTableWidgetItem*)),this,SLOT(recordNo(QTableWidgetItem*)));

    ui->AnalysisTableWidget->horizontalHeader()->setVisible(true);
    ui->AnalysisTableWidget->horizontalHeader()->setClickable(false); //设置表头不可点击
    ui->AnalysisTableWidget->setStyleSheet("selection-background-color:lightblue;"); //设置选中背景色
    ui->AnalysisTableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->AnalysisTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    connect(ui->AnalysisTableWidget,SIGNAL(itemClicked(QTableWidgetItem*)),this,SLOT(selectRecord(QTableWidgetItem*)));
//单选改成复选
//   selcectGroup = new QButtonGroup(this);
//   selcectGroup->addButton(ui->checkBox,AUTO_MODE);
//   selcectGroup->addButton(ui->checkBox_2,COVER_MODE);
//   selcectGroup->addButton(ui->checkBox_3,MEASURE_PRINT_MODE);
//   connect(selcectGroup,SIGNAL(buttonClicked(int)),this,SLOT(getCheckBoxValue(int)));
   system("rm ./img/*.bmp");
   //将试剂ID号放入表格中
  // QString path("D:/git/laichunfu/laichunfu/localreagent");
   QString path(QDir::currentPath() +"/localreagent");
   QStringList listfilters;
   listfilters << "*.txt";
   QDir loaclDir(path);
   if (loaclDir.entryList(listfilters).count() == 0)
   {
       //提示没有试剂文件
       ui->selectOkBtn->setEnabled(false);
   }
   else
   {
       //读出目录下所有文件到tablewidget
       mFileList = loaclDir.entryList(listfilters);
       for (int i = 0; i < mFileList.count(); i++)
       {
           QString filePath =  path +"/"+mFileList[i];
           QFile file(filePath);
           if (file.open(QIODevice::ReadOnly))
           {
               QTextStream in(&file);
               QString data = in.readAll();

               QStringList dataList = data.split(',');
               int stPos,eePos,ddPos;
               for (int j =0; j < dataList.count() ; j++)
               {
                   if (dataList[j] == "ST")
                   {
                       stPos = j;
                   }
                   else if (dataList[j] == "EE")
                   {
                       eePos = j;
                   }
                   else if(dataList[j] == "DD")
                   {
                       ddPos = j;
                   }
               }
//               QMap<QString,QString> curveTable;
//               for (int j = stPos +1,k =eePos+1;j < eePos; j++,k++)
//               {
//                   curveTable.insert(dataList[j],dataList[k]);
//               }
               QString productDate = dataList[ddPos +2];//生成日期
               QString validDate = dataList[ddPos +3]; //有效期至
               QString reagent =  dataList[ddPos +4]; //试剂ID
               QString tc = dataList[ddPos + 6]; //T线与C线之间的距离
               ui->tableWidget->insertRow(i);
               ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString("%1").arg(i+1)));
               ui->tableWidget->setItem(i,1,new QTableWidgetItem("PCT"));
               ui->tableWidget->setItem(i,2,new QTableWidgetItem(productDate));
               ui->tableWidget->setItem(i,3,new QTableWidgetItem(validDate));
               ui->tableWidget->setItem(i,4,new QTableWidgetItem(reagent));
           }
       }
   }


}
ExpDialog::~ExpDialog()
{
    delete timer;
    delete testTimer;
    delete barcodeTimer;
   // delete selcectGroup;
    mBarcodePort->close();
    delete mBarcodePort;
    delete ui;
}

void ExpDialog::getPaientId()
{
    qDebug() << "mBarcodePort exec";
    QByteArray recvData = mBarcodePort->readAll();

    if (recvData.size() <=0)
    {
        return;
    }
    QString str = "";
    str.append(recvData);
    ui->PatientLineEdit->setText(str);
}

bool ExpDialog::isPaperInsert()
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
  //  qDebug() << data;
    file.close();
    if (data.at(0) == '1')
    {
       // qDebug() << "data falied";
        return true;
    }
    else
    {
        //qDebug() << "data success";
        mAutoTestEnable = true;
        return false;
    }
}

//更新时间和自动模式
void ExpDialog::updateDatetime()
{
    if (mTimeOut > 0)
    {
        mTimeOut--;
    }
   // QDateTime datetime= QDateTime::currentDateTime();
   // ui->labelDateTime->setText(datetime.toString("yyyy-MM-dd hh:mm:ss"));
  //  if (mSelcetMode == AUTO_MODE && isPaperInsert())//自动模式设置 //检测光耦标志

    if (isPaperInsert())
    {
        if (mTested == false)
        {
            ui->ShowImageLabel->setPixmap(QPixmap(":/images/waitTest.jpg"));
            mTested = true;
        }
    }
    else
    {   if (mTested == true)
        {
            ui->ShowImageLabel->setPixmap(QPixmap(":/images/waitCard.jpg"));
            mTested =false;
        }
        return;
    }

    if (ui->AutoCheckBox->isChecked() && isPaperInsert())//自动模式设置 //检测光耦标志
    {  // ui->ShowImageLabel->setPixmap(QPixmap(":/images/waitTest.jpg"));
        if (mAutoTestEnable)
        {
            mAutoTestEnable = false;
            on_MeasurePushButton_clicked();
        }
    }
}
//测试定时
void ExpDialog::testCard()
{
    testTimer->stop();
    timer->stop();
    Roption.icmd = 's';
    if(get_frame(fd,&Roption,Glut)==0)
    {
           prccallback(Roption.pimg, 1280, 720, Roption.ovalue);//保存图像
          // printf("save snap image! tvalue=%d ovalue=%d\n",Roption.tvalue,Roption.ovalue);
           if (read_value())
           {
              ui->PromptLabel->setText("测量成功");
           }
           else
           {
            //ui->PromptLabel->setText("测量无效");
           }
    }
    timer->start(1000);
    ui->MeasurePushButton->setEnabled(true);

}
//获取模式值
void ExpDialog::getCheckBoxValue(int value)
{
  // qDebug() << value;
    mSelcetMode = value;
}

//选择试剂
void ExpDialog::on_selectOkBtn_clicked()
{
    if (mSelectIndex < 0)
    {
        //提示请选择一个试剂
        return;
    }
    //打开试剂文件
   // QString path("D:/git/laichunfu/laichunfu/localreagent/");
    QString path = QDir::currentPath() + "/localreagent/";
    QString fileName = path + mFileList[mSelectIndex];
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        QString data = in.readAll();

        QStringList dataList = data.split(',');
        int stPos,eePos,ddPos;
        for (int j =0; j < dataList.count() ; j++)
        {
            if (dataList[j] == "ST")
            {
                stPos = j;
            }
            else if (dataList[j] == "EE")
            {
                eePos = j;
            }
            else if(dataList[j] == "DD")
            {
                ddPos = j;
            }
        }
       // QMap<QString,QString> curveTable;
        mTestValueList.clear();
        mCurveTable.insert(0,0);
        mTestValueList.append(0);
        for (int j = stPos +1,k =eePos+1;j < eePos; j++,k++)
        {
            mCurveTable.insert(dataList[k].toInt(),dataList[j].toInt());
            mTestValueList.append(dataList[k].toInt());
           //mCurveTable.find()
        }
        mProductDate = dataList[ddPos +2];//生成日期
        mValidDate = dataList[ddPos +3]; //有效期至
        mReagentId =  dataList[ddPos +4]; //试剂ID
        mTc = dataList[ddPos + 6]; //T线与C线之间的距离
        mChannel = dataList[ddPos + 8];   //通道号
        mSubChannel = dataList[ddPos + 9]; //子通道号

        if (dataList[ddPos + 10] == "CN")
        {
              mProjectName = dataList[ddPos + 11];
              mConcentBit = dataList[ddPos + 12]; //浓度的小数位数
              mUnit = dataList[ddPos + 14];      //单位
              mReferentRange = dataList[ddPos + 15]; //参考范围
              mPositiveRelation = dataList[ddPos + 17]; //阳性判断关系
              mPositiveValve = dataList[ddPos + 18]; //阳性阀值
              mNagativeRelation = dataList[ddPos + 19]; //阴性判断关系
              mNagativeValve = dataList[ddPos + 20];  // 阴性阀值
              mDetermineFd = dataList[ddPos + 21];    //定性描述符号
        }
        else
        {

            mConcentBit = dataList[ddPos + 10]; //浓度的小数位数
            mUnit = dataList[ddPos + 12];      //单位
            mReferentRange = dataList[ddPos + 13]; //参考范围
            mPositiveRelation = dataList[ddPos + 15]; //阳性判断关系
            mPositiveValve = dataList[ddPos + 16]; //阳性阀值
            mNagativeRelation = dataList[ddPos + 17]; //阴性判断关系
            mNagativeValve = dataList[ddPos + 18];  // 阴性阀值
            mDetermineFd = dataList[ddPos + 19];    //定性描述符号
        }
    }
    else
    {
        //提示打开试剂文件异常
        return;
    }

    ui->labelTitle->setText(QString(tr("样品分析")));
    ui->CurrentRegIdLabel->setText(mReagentId);
    ui->stackedWidget->setCurrentIndex(0);
}

//选择试剂返回
void ExpDialog::on_selectReturnBtn_clicked()
{
    close();
}

//样品分析返回
void ExpDialog::on_expReturnBtn_clicked()
{
    close();
}

//校验
void ExpDialog::on_CheckPushButton_clicked()
{
     ui->PromptLabel->setText("正在测量");
     update();
     timer->stop();
     Roption.icmd = 's';
     if(get_frame(fd,&Roption,Glut)==0)
     {
            prccallback(Roption.pimg, 1280, 720, Roption.ovalue);//保存图像
            if (read_value())
            {
               ui->PromptLabel->setText("测量成功");
               //向PC发送质控数据
               unsigned char img_buf[500*300*3];
               memset(img_buf,0,sizeof(img_buf));
               YUV2RGB0(Roption.pimg,img_buf,1280,720);
               cmdFunc.sendQcData(Roption.ovalue,mCheckValue,(char)0,img_buf);
            }
            else
            {
             //ui->PromptLabel->setText("测量无效");
            }
     }
     timer->start(1000);
     ui->MeasurePushButton->setEnabled(true);
}

bool ExpDialog::read_value()
{
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
           //计算result
           unsigned int upValue = 0;
           unsigned int downValue = 0;
           unsigned int iValue = value.toInt();
           double iResult = 0;
           int j = 0;
           for (j = 0; j < mTestValueList.count(); j++)
           {
               if (iValue <= (mTestValueList[j]/1000))
               {
                   upValue =  mTestValueList[j];
                   if (j == 0)//如果为第一个
                   {
                       iResult = mCurveTable.value(upValue)/1000;
                       break;
                   }
                   else
                   {
                     downValue =  mTestValueList[j-1];
                     break;
                   }
               }
           }
           if (j == mTestValueList.count())//如果找不到
           {
                iResult = mCurveTable.value(mTestValueList[j-1])/1000;
           }
           else if (j < mTestValueList.count())
           {
               iResult = mCurveTable.value(downValue)*1.0/1000 +
                 (iValue*1.0 - downValue/1000)* ( mCurveTable.value(upValue) - mCurveTable.value(downValue) )*1.0/
                                                                    (upValue - downValue);
           }
           else
           {
                iResult = 0;
           }
           mCheckValue = iResult;
           QString result = "";
           if (mConcentBit.toInt() == 1)
           {
              result.sprintf("%.01f",iResult);
           }
           else if (mConcentBit.toInt() == 2)
           {
             result.sprintf("%.02f",iResult);
           }
           else
           {
             result.sprintf("%.03f",iResult);
           }
           ui->TestValueLineEdit->setText(value);
           ui->ResultLineEdit->setText(result);
           //将记录保存到数据库
           QSqlQuery query;
           int count = 0;
           if (!query.exec("select id,testvalue,datetime from result"))
           {
               //数据库命令执行异常
               return false;
           }

           if (query.last())
           {
              count = query.value(0).toInt();
              //if (mSelcetMode == COVER_MODE)//如果选择为覆盖模式
              if (ui->CoverCheckBox->isChecked())//如果选择为覆盖模式
              {
                  //先删除图片
                  QString deleteFileDir = QDir::currentPath() + "/finishimages/";
                  QString fName = query.value(2).toString() + "-"
                                  + query.value(1).toString() + ".bmp";
                  QFile Deletefile(deleteFileDir + fName);
                  Deletefile.remove();

                  //然后再删除记录
                  if (query.exec(QString("delete from result where id = '%1'").arg(count)))
                  {
                      count -= 1;
                  }
              }
           }
           else
           {
               count = 0;
               //数据库出错
               qDebug() << "查询数据库错误1";
              // return;
           }
           //存储数据
           QString flag = "↓";
           QStringList referentList = mReferentRange.split('-');
           if (iResult >= referentList[0].toDouble() && iResult <= referentList[1].toDouble())
           {
               flag = "↓";
           }
           else
           {
               flag = "↑";
           }

          if (query.exec(QString("insert into result (id,projectname,project,channel,testvalue,"
                      "result,unit,referentrange,flag,patientid,expid,datetime) "
                      "values('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','%11','%12')")
                      .arg(count +1)
                      .arg("")
                      .arg("PCT")
                      .arg(mChannel)
                      .arg(value)
                      .arg(result)
                      .arg(mUnit)
                      .arg(mReferentRange)
                      .arg(flag)
                      .arg(ui->PatientLineEdit->text())
                      .arg(count +1)
                      .arg(datetime)))
          {
               //数据库执行成功
          }
          else
          {
            //数据库出错
            qDebug() << "查询数据库错误2";
            return false;
          }

          //if (mSelcetMode == COVER_MODE && ui->AnalysisTableWidget->rowCount() != 0)
          if (ui->CoverCheckBox->isChecked() && ui->AnalysisTableWidget->rowCount() != 0)
          {
            //如果选择覆盖模式并且表格存在记录
          }
          else
          {
             ui->AnalysisTableWidget->insertRow(0);//在第一行插入
          }
          // ui->AnalysisTableWidget->setItem(i,0,new QTableWidgetItem(QString("%1").arg(i)));
           ui->AnalysisTableWidget->setItem(0,0,new QTableWidgetItem("PCT"));
           //结果值需要进行计算
           ui->AnalysisTableWidget->setItem(0,1,new QTableWidgetItem(QString("%1").arg(result)));
           ui->AnalysisTableWidget->setItem(0,2,new QTableWidgetItem(QString("%1").arg(value)));
           ui->AnalysisTableWidget->setItem(0,3,new QTableWidgetItem(ui->PatientLineEdit->text()));
           //样本ID需要去数据库中的序号
           ui->AnalysisTableWidget->setItem(0,4,new QTableWidgetItem(QString("%1").arg(count + 1)));
           ui->AnalysisTableWidget->setItem(0,5,new QTableWidgetItem(datetime));
           mRecordIndex = 0;
           //显示测试图片
           QPixmap pix;
           //QPainter painter;
           pix.load(path + filename);
           qreal width = pix.width();
           qreal height = pix.height();
           pix = pix.scaled(width/4,height/4,Qt::KeepAspectRatio);
           QTransform transform;
           transform.rotate(90);
           ui->ShowImageLabel->setPixmap(pix.transformed(transform));
          // ui->TestValueLineEdit->setText(value);
          // ui->ResultLineEdit->setText(value);
           //将文件保存到其他位置
          // QString newPath("D:/git/laichunfu/laichunfu/finishimages/");
           QString newPath = QDir::currentPath() + "/finishimages/";
           QFile::copy(path + filename,newPath + filename);
           QFile file(path + filename);
           file.remove();
       }
   }
   if (ui->PrintCheckBox->isChecked())
   {
       on_PrintPushButton_clicked();
   }
   return true;
}

//测量
void ExpDialog::on_MeasurePushButton_clicked()
{
    if (isPaperInsert())
    {
        if (mTested == false)
        {
            ui->ShowImageLabel->setPixmap(QPixmap(":/images/waitTest.jpg"));
            mTested = true;
        }
    }
    else
    {
        if (mTested == true)
        {
            ui->ShowImageLabel->setPixmap(QPixmap(":/images/waitCard.jpg"));
            mTested = false;
        }
        return;
    }
   mTested =true;
   ui->MeasurePushButton->setEnabled(false);
   ui->PromptLabel->setText("正在测量");
   testTimer->start(1000);
   ui->ShowImageLabel->setPixmap(QPixmap(":/images/testing.jpg"));


}

//打印
void ExpDialog::on_PrintPushButton_clicked()
{
     //打印
    //先找出
    qDebug() << mRecordIndex;
    if (mRecordIndex < 0)
    {
        return;
    }
   QString expid =  ui->AnalysisTableWidget->item(mRecordIndex,4)->text();
    QSqlQuery query;
    QString sql = QString("select id,projectname,project,channel,testvalue,"
                          "result,unit,referentrange,flag,patientid,datetime "
                          "from result where expid = '%1'").arg(expid);
    if (!query.exec(sql))
    {
        return;
    }
    if (!query.next())
    {
        return;
    }
    QDateTime dateTime = QDateTime::fromString(query.value(10).toString(),"yyyyMMddhhmmss");
//    QString print = "ID:"+ query.value(0).toString() + "\n"+
//                    "PROJECTNAME:" + query.value(1).toString() + "\n"+
//                    "PROJECT:" + query.value(2).toString() + "\n"+
//                    "CHANNEL:"+ query.value(3).toString() + "\n"+
//                    "VALUE:" + query.value(4).toString() + "\n"+
//                    "RESULT:" + query.value(5).toString() + "\n"+
//                    "UNIT:" + query.value(6).toString() + "\n"+
//                    "参数范围：" + query.value(7).toString() + "\n"+
//                    "标志：" + query.value(8).toString() + "\n"+
//                    "PATIENTID：" + query.value(9).toString() + "\n"+
//                    "datetime:" + query.value(10).toString() + "\n"+
//                    "样本ID" + expid + "\n";
    QByteArray print = TMP_ID + query.value(0).toByteArray() + "\n"+
                    PROJECT + query.value(2).toByteArray() + "\n"+
                    RESULT + query.value(5).toByteArray() + query.value(6).toByteArray()+ " " ;
    if (query.value(8).toByteArray() == "↑")
    {
        print.append(UP_P);
        print.append("\n");
    }
    else
    {
        // print += DOWN_P + "\n";
         print.append(DOWN_P);
         print.append("\n");
    }
    print += RANGER + query.value(7).toByteArray() + query.value(6).toByteArray()+"\n"+
              (dateTime.toString("yyyy-MM-dd hh:mm:ss")).toLocal8Bit() + "\n";

    //查询数据库
    cmdFunc.comPort->write(print);
}

//选择的行
void ExpDialog::recordNo(QTableWidgetItem *item)
{
    mSelectIndex = item->row();
    qDebug() << mSelectIndex;
}

void ExpDialog::selectRecord(QTableWidgetItem * item)
{
   // QString newPath("D:/git/laichunfu/laichunfu/finishimages/");
    QString newPath = QDir::currentPath() + "/finishimages/";
    QString imageName = newPath;
    mRecordIndex = item->row();
    imageName.append(ui->AnalysisTableWidget->item(item->row(),5)->text());
    imageName.append("-");
    imageName.append(ui->AnalysisTableWidget->item(item->row(),2)->text());
    imageName.append(".bmp");
    qDebug() << imageName;
    QPixmap pix;
    pix.load(imageName);
    qreal width = pix.width();
    qreal height = pix.height();
    pix = pix.scaled(width/4,height/4,Qt::KeepAspectRatio);
    QTransform transform;
    transform.rotate(90);
    ui->ShowImageLabel->setPixmap(pix.transformed(transform));
    ui->TestValueLineEdit->setText(ui->AnalysisTableWidget->item(item->row(),2)->text());
    ui->ResultLineEdit->setText(ui->AnalysisTableWidget->item(item->row(),1)->text());
}
