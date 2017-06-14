#include "managedialog.h"
#include "ui_managedialog.h"
#include <QDateTime>
#include <QDir>
#include <QDebug>
#include <QMessageBox>

ManageDialog::ManageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageDialog)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowFlags(Qt::FramelessWindowHint);
   // this->setWindowState(Qt::WindowFullScreen);
    this->move((parent->width() - this->width())/2,
               (parent->height() - this->height())/2);
    mSelectIndex = -1;
    mUsbDirExsited = 0;
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateDatetime()));
    timer->start(1000);
    ui->tableWidget->horizontalHeader()->setClickable(false); //设置表头不可点击
    ui->tableWidget->setStyleSheet("selection-background-color:lightblue;"); //设置选中背景色
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//设置行选择
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(ui->tableWidget,SIGNAL(itemClicked(QTableWidgetItem*)),this,SLOT(recordNo(QTableWidgetItem*)));
    model = new QFileSystemModel(this);
    QString uPath = "/media/sda1/reagent";
    model->setRootPath("/");
    ui->listView->setModel(model);
    //ui->listView->setRootIndex(model->index("D:/git/laichunfu/laichunfu/reagent"));
    ui->listView->setRootIndex(model->index(uPath));
    ui->listView->setViewMode(QListView::IconMode);
   // connect(ui->listView,SIGNAL(clicked(QModelIndex)),this,SLOT(selectFile(QModelIndex)));
    while (ui->tableWidget->rowCount()) {
        ui->tableWidget->removeRow(0);
    }
    //connect(ui->listView,SIGNAL())
    //读取目录下的文件
    QFileInfo fi(uPath);
    if (fi.exists())
    {
        mUsbDirExsited =1;
    }
    else
    {
        mUsbDirExsited = 0;
    }

    QDir dir(uPath);
    QStringList listfilters;
    listfilters << "*.txt";
   // dir.setNameFilters(listfilters);
    if (dir.entryList(listfilters).count() == 0)
    {
        ui->ImportPushButton->setEnabled(false);
        //提示请插入u盘
        //QMessageBox::information(this,"试剂管理"，"请插入U盘")；
       //return;
    }
    else
    {
        ui->ImportPushButton->setEnabled(true);
    }
    //将试剂ID号放入表格中
    //QDir loaclDir("D:/git/laichunfu/laichunfu/localreagent");
    QDir loaclDir(QDir::currentPath() +"/localreagent");
    if (loaclDir.entryList(listfilters).count() == 0)
    {
        ui->DeletePushButton->setEnabled(false);
        //提示请插入u盘
        return;
    }
    else
    {
        ui->DeletePushButton->setEnabled(true);
        //读出目录下所有文件到tablewidget
        QStringList fileList = loaclDir.entryList(listfilters);
       // QString path("D:/git/laichunfu/laichunfu/localreagent");
        QString path = QDir::currentPath() +"/localreagent";
        qDebug() << path;
        for (int i = 0; i < fileList.count(); i++)
        {
            QString filePath =  path +"/"+fileList[i];
            QFile file(filePath);
            if (file.open(QIODevice::ReadOnly))
            {
                QTextStream in(&file);
                QString data = in.readAll();

                QStringList dataList = data.split(',');
                //qDebug() << data;
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
                QMap<QString,QString> curveTable;
                for (int j = stPos +1,k =eePos+1;j < eePos; j++,k++)
                {
                    curveTable.insert(dataList[j],dataList[k]);
                }
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

ManageDialog::~ManageDialog()
{
    delete timer;
    delete model;
    delete ui;
}
void ManageDialog::updateDatetime()
{
    QDateTime datetime= QDateTime::currentDateTime();
    ui->labelDateTime->setText(datetime.toString("yyyy-MM-dd hh:mm:ss"));


    QString uPath = "/media/sda1/reagent";
    QFileInfo fi(uPath);
    if (!fi.exists())
    {
        mUsbDirExsited = 0;
        return;
    }
    else {
        if (mUsbDirExsited == 0)
        {
            //QFileSystemModel *model = new QFileSystemModel(this);
            model->setRootPath("/");
            ui->listView->setModel(model);
            //ui->listView->setRootIndex(model->index("D:/git/laichunfu/laichunfu/reagent"));
            ui->listView->setRootIndex(model->index(uPath));
            ui->listView->setViewMode(QListView::IconMode);
            mUsbDirExsited =1;
        }
    }
}

void ManageDialog::on_manageReturnBtn_clicked()
{
    close();
}

//删除按钮
void ManageDialog::on_DeletePushButton_clicked()
{
    QString  path = QDir::currentPath() + "/localreagent";
    QDir loaclDir(path);

    QStringList listfilters;
    listfilters << "*.txt";
    if (loaclDir.entryList(listfilters).count() == 0)
    {
        ui->DeletePushButton->setEnabled(false);
        return;
    }

    QStringList fileList = loaclDir.entryList(listfilters);
     if (mSelectIndex < 0)
     {
         //请选择要删除的文件
     }
     else if (mSelectIndex >= 0 && mSelectIndex < fileList.count())
     {
         QString fileName = path + "/" + fileList[mSelectIndex];
         //system(QString("rm %1").arg(fileName));
         remove(fileName.toAscii().data());
         ui->tableWidget->removeRow(mSelectIndex);
         mSelectIndex = -1;
     }
     else
     {
         ui->tableWidget->removeRow(mSelectIndex);
          mSelectIndex = -1;
     }
}

//导入按钮
void ManageDialog::on_ImportPushButton_clicked()
{
    //读取目录下的文件
   // QString  readPath("D:/git/laichunfu/laichunfu/reagent");
   // QString  savePath("D:/git/laichunfu/laichunfu/localreagent");
   // QDir dir(readPath);
    QString  readPath = "/media/sda1/reagent";
    QString  savePath = QDir::currentPath() + "/localreagent";
    QDir dir(readPath);

    QStringList listfilters;
    listfilters << "*.txt";
   // dir.setNameFilters(listfilters);
    if (dir.entryList(listfilters).count() == 0)
    {
        ui->ImportPushButton->setEnabled(false);
        //提示请插入u盘
    }
    else
    {
        QStringList fileList = dir.entryList(listfilters);
       // ui->ImportPushButton->setEnabled(true);
        for (int i =0; i < fileList.count(); i++)
        {
            QString fileName = readPath + "/" + fileList[0];
            QFile file(fileName);
            if (!file.open(QIODevice::ReadOnly))
            {
                continue;
            }
            QTextStream in(&file);
            QString dateTime = QDateTime::currentDateTime()
                                       .toString("yyyy_MM_dd_hh_mm_ss_zzz");
            QString saveFileName =savePath+ "/" + dateTime +".txt";

            QFile saveFile(saveFileName);
            if (!saveFile.open(QIODevice::WriteOnly))
            {
               file.close();
               continue;
            }
            QTextStream out(&saveFile);
            QString data = in.readAll();
            out << data;
            saveFile.close();

            file.close();
             //添加文件成功,在tablewidget中显示出来
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
            QString productDate = dataList[ddPos +2];//生成日期
            QString validDate = dataList[ddPos +3]; //有效期至
            QString reagent =  dataList[ddPos +4]; //试剂ID
           // QString tc = dataList[ddPos + 6]; //T线与C线之间的距离
           // ui->tableWidget->insertRow(i);
            int count = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(count);
            ui->tableWidget->setItem(count,0,new QTableWidgetItem(QString("%1").arg(count+1)));
            ui->tableWidget->setItem(count,1,new QTableWidgetItem("PCT"));
            ui->tableWidget->setItem(count,2,new QTableWidgetItem(productDate));
            ui->tableWidget->setItem(count,3,new QTableWidgetItem(validDate));
            ui->tableWidget->setItem(count,4,new QTableWidgetItem(reagent));
            ui->DeletePushButton->setEnabled(true);//让删除键有效
        }
    }
}

void ManageDialog::recordNo(QTableWidgetItem *item)
{
    mSelectIndex = item->row();
    qDebug() << mSelectIndex;
}
