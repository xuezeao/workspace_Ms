#include "selectdialog.h"
#include "ui_selectdialog.h"
#include "connect_sql.h"
#include "command.h"
#include "exp/expdialog.h"

#include <QDateTime>
#include <QFile>
#include <QDir>

SelectDialog::SelectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectDialog)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowFlags(Qt::FramelessWindowHint);
  //  this->setWindowState(Qt::WindowFullScreen);
    this->move((parent->width() - this->width())/2,
               (parent->height() - this->height())/2);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateDatetime()));
    timer->start(1000);
    ui->tableWidget->horizontalHeader()->setClickable(false); //设置表头不可点击
    ui->tableWidget->setStyleSheet("selection-background-color:lightblue;"); //设置选中背景色
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    //设置表头背景色
    mSelectIndex = -1;
    mSelectFlag = false;
    connect(ui->tableWidget,SIGNAL(itemClicked(QTableWidgetItem*)),this,SLOT(showImage(QTableWidgetItem*)));
    QSqlQuery query;
    QString cmd = "";
    if (!mSelectFlag)
    {
        cmd = QString("select COUNT(*) from result");
    }
    else 
    {
        cmd = QString("select COUNT(*) from result where patientid = '%1'")
                     .arg(ui->PatientLineEdit->text());
    }
    if (!query.exec(cmd))
    {
        return;
    }
    else
    {
        if (query.next())
        {
            if (query.value(0).toInt() == 0)
            {
                mTotalPage = 0;
                mPage = 0;
            }
            else
            {
             mTotalPage = (query.value(0).toInt() +5)/5;
            }

        }else
        {
            mTotalPage = 0;
            mPage = 0;
        }
    }
    if (mTotalPage == 0)
    {
        return;
    }

    mPage = 1;
    if (!mSelectFlag)
    {
        cmd = QString("select * from result limit 0,5");
    }
    else
    {
        cmd = QString("select * from result where patientid = '%1' limit 0,5")
                     .arg(ui->PatientLineEdit->text());
    }
    if (!query.exec(cmd))
    {
        return;
    }
    int i =0;
    while (query.next())
    {
        ui->tableWidget->insertRow(i);
        for(int j =0; j < 12; j++)
        {
            ui->tableWidget->setItem(i,j,new QTableWidgetItem(query.value(j).toString()));
        }
        i++;
    }
    //ui->tableWidget->selectRow(0);
    showImage(ui->tableWidget->item(0,0));
}

SelectDialog::~SelectDialog()
{
    delete timer;
    delete ui;
}

void SelectDialog::updateDatetime()
{
    QDateTime datetime= QDateTime::currentDateTime();
    ui->labelDateTime->setText(datetime.toString("yyyy-MM-dd hh:mm:ss"));
}

void SelectDialog::on_SelectReturnBtn_clicked()
{
    close();
}

//删除
void SelectDialog::on_DeletePushButton_clicked()
{
    if (mSelectIndex < 0)
    {
        //提示选择记录
        return;
    }
    if (ui->tableWidget->rowCount() <= 0)
    {
        //如果已经没有记录，则返回
        return;
    }
    //QString newPath("D:/git/laichunfu/laichunfu/finishimages/");
    QString newPath = QDir::currentPath() + "/finishimages/";
    QString imageName = newPath;
    imageName.append(ui->tableWidget->item(mSelectIndex,11)->text());
    imageName.append("-");
    imageName.append(ui->tableWidget->item(mSelectIndex,4)->text());
    imageName.append(".bmp");
    QSqlQuery query;
   if (!query.exec(QString("delete from result where id = '%1'")
                      .arg(ui->tableWidget->item(mSelectIndex,0)->text())))
   {
        return;
   }
   ui->tableWidget->removeRow(mSelectIndex);
    mSelectIndex = -1;
    qDebug() << imageName;
    QFile file(imageName);
    file.remove();
    QString cmd = "";
    if (!mSelectFlag)
    {
        cmd =QString("select * from result limit %1,5").arg((mPage -1)*5);
    }
    else
    {
        cmd = QString("select * from result where patientid = '%1' limit %2,5")
                      .arg(ui->PatientLineEdit->text()
                      .arg((mPage -1)*5));

    }

    if (!query.exec(cmd))
    {
        return;
    }
    while (ui->tableWidget->rowCount())
    {
        ui->tableWidget->removeRow(0);
    }

    int i =0;
    while (query.next())
    {
        ui->tableWidget->insertRow(i);
        for(int j =0; j < 12; j++)
        {
            ui->tableWidget->setItem(i,j,new QTableWidgetItem(query.value(j).toString()));
        }
        i++;
    }
    //ui->tableWidget->selectRow(0);
   // showImage(ui->tableWidget->item(0,0));
}

//打印
void SelectDialog::on_PrintPushButton_clicked()
{
    if (mSelectIndex < 0)
    {
        return;
    }
   QString expid =  ui->tableWidget->item(mSelectIndex,10)->text();
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

    QByteArray print = TMP_ID + query.value(0).toByteArray() + "\n"+
                    PROJECT + query.value(2).toByteArray() + "\n"+
                    RESULT + query.value(5).toByteArray() + query.value(6).toByteArray() + " ";
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

//查询
void SelectDialog::on_SelectPushButton_clicked()
{
    mSelectFlag = true;
    QSqlQuery query;
    QString cmd = "";
    if (!mSelectFlag)
    {
        cmd = QString("select COUNT(*) from result");
    }
    else
    {
        cmd = QString("select COUNT(*) from result where patientid = '%1'")
                     .arg(ui->PatientLineEdit->text());
    }
    if (!query.exec(cmd))
    {
        return;
    }
    else
    {
        if (query.next())
        {
            if (query.value(0).toInt() == 0)
            {
                mTotalPage = 0;
                mPage = 0;
            }
            else
            {
             mTotalPage = (query.value(0).toInt() +5)/5;
            }

        }else
        {
            mTotalPage = 0;
            mPage = 0;
        }
    }
    if (mTotalPage == 0)
    {
        return;
    }

    mPage = 1;
    if (!mSelectFlag)
    {
        cmd = QString("select * from result limit 0,5");
    }
    else
    {
        cmd = QString("select * from result where patientid = '%1' limit 0,5")
                     .arg(ui->PatientLineEdit->text());
    }
    if (!query.exec(cmd))
    {
        return;
    }
    while (ui->tableWidget->rowCount())
    {
        ui->tableWidget->removeRow(0);
    }

    int i =0;
    while (query.next())
    {
        ui->tableWidget->insertRow(i);
        for(int j =0; j < 12; j++)
        {
            ui->tableWidget->setItem(i,j,new QTableWidgetItem(query.value(j).toString()));
        }
        i++;
    }
    //ui->tableWidget->selectRow(0);
    showImage(ui->tableWidget->item(0,0));
}
//上一页
void SelectDialog::on_UpPagePushButton_clicked()
{
    mPage--;
    if (mPage <= 0)
    {
        mPage = 1;
        return;
    }

    QSqlQuery query;
    QString cmd = "";
    if (!mSelectFlag)
    {
        cmd =QString("select * from result limit %1,5").arg((mPage -1)*5);
    }
    else
    {
        cmd = QString("select * from result where patientid = '%1' limit %2,5")
                      .arg(ui->PatientLineEdit->text()
                      .arg((mPage -1)*5));

    }
    if (!query.exec(cmd))
    {
        return;
    }
    while (ui->tableWidget->rowCount())
    {
        ui->tableWidget->removeRow(0);
    }

    int i =0;
    while (query.next())
    {
        ui->tableWidget->insertRow(i);
        for(int j =0; j < 12; j++)
        {
            ui->tableWidget->setItem(i,j,new QTableWidgetItem(query.value(j).toString()));
        }
        i++;
    }
    //ui->tableWidget->selectRow(0);
    showImage(ui->tableWidget->item(0,0));
}
//下一页
void SelectDialog::on_DownPagePushButton_clicked()
{
    mPage++;
    if (mPage > mTotalPage)
    {
        mPage  = mTotalPage;
        return;
    }

    QSqlQuery query;
    QString cmd = "";
    if (!mSelectFlag)
    {
        cmd =QString("select * from result limit %1,5").arg((mPage -1)*5);
    }
    else
    {
        cmd = QString("select * from result where patientid = '%1' limit %2,5")
                      .arg(ui->PatientLineEdit->text()
                      .arg((mPage -1)*5));

    }
    if (!query.exec(cmd))
    {
        return;
    }
    while (ui->tableWidget->rowCount())
    {
        ui->tableWidget->removeRow(0);
    }

    int i =0;
    while (query.next())
    {
        ui->tableWidget->insertRow(i);
        for(int j =0; j < 12; j++)
        {
            ui->tableWidget->setItem(i,j,new QTableWidgetItem(query.value(j).toString()));
        }
        i++;
    }
    //ui->tableWidget->selectRow(0);
    showImage(ui->tableWidget->item(0,0));
}
void SelectDialog::showImage(QTableWidgetItem *item)
{
    if (!item)//item为空
    {
        mSelectIndex = -1;
        return;
    }
    mSelectIndex = item->row();
    if (mSelectIndex <0)
    {
        return;
    }
  //  QString newPath("D:/git/laichunfu/laichunfu/finishimages/");
    QString newPath = QDir::currentPath() + "/finishimages/";
    QString imageName = newPath;
    imageName.append(ui->tableWidget->item(item->row(),11)->text());
    imageName.append("-");
    imageName.append(ui->tableWidget->item(item->row(),4)->text());
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
   // ui->TestValueLineEdit->setText(ui->AnalysisTableWidget->item(item->row(),2)->text());
   // ui->ResultLineEdit->setText(ui->AnalysisTableWidget->item(item->row(),1)->text());
}

//显示全部记录
void SelectDialog::on_SelectPushButton_2_clicked()
{
    mSelectFlag = false;
    QSqlQuery query;
    QString cmd = "";
    if (!mSelectFlag)
    {
        cmd = QString("select COUNT(*) from result");
    }
    else
    {
        cmd = QString("select COUNT(*) from result where patientid = '%1'")
                     .arg(ui->PatientLineEdit->text());
    }
    if (!query.exec(cmd))
    {
        return;
    }
    else
    {
        if (query.next())
        {
            if (query.value(0).toInt() == 0)
            {
                mTotalPage = 0;
                mPage = 0;
            }
            else
            {
             mTotalPage = (query.value(0).toInt() +5)/5;
            }

        }else
        {
            mTotalPage = 0;
            mPage = 0;
        }
    }
    if (mTotalPage == 0)
    {
        return;
    }

    mPage = 1;
    if (!mSelectFlag)
    {
        cmd = QString("select * from result limit 0,5");
    }
    else
    {
        cmd = QString("select * from result where patientid = '%1' limit 0,5")
                     .arg(ui->PatientLineEdit->text());
    }
    if (!query.exec(cmd))
    {
        return;
    }
    while (ui->tableWidget->rowCount())
    {
        ui->tableWidget->removeRow(0);
    }

    int i =0;
    while (query.next())
    {
        ui->tableWidget->insertRow(i);
        for(int j =0; j < 12; j++)
        {
            ui->tableWidget->setItem(i,j,new QTableWidgetItem(query.value(j).toString()));
        }
        i++;
    }
    //ui->tableWidget->selectRow(0);
    showImage(ui->tableWidget->item(0,0));
}
