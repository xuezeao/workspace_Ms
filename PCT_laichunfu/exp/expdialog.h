#ifndef EXPDIALOG_H
#define EXPDIALOG_H

#include <QDialog>
#include <QTimer>
#include <QButtonGroup>
#include <QTableWidgetItem>
#include <QStringList>
#include <QMap>
#include <QList>
#include "lincom/posix_qextserialport.h"
#include "lincom/qextserialbase.h"

#define TMP_ID "样品编号:"
#define PROJECT "项目:"
#define RESULT  "结果:"
#define RANGER  "参考范围："
#define UP    "↑"
#define DOWN  "↓"
#define UP_P    "\xA1\xFC"
#define DOWN_P  "\xA1\xFD"

//#include <QThread>
namespace Ui {
class ExpDialog;
}

class ExpDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExpDialog(QWidget *parent = 0);
    ~ExpDialog();
    enum{
        AUTO_MODE = 1,
        COVER_MODE,
        MEASURE_PRINT_MODE
    };
    bool isPaperInsert();//是否有卡条插入

private slots:
    void on_selectOkBtn_clicked();
    void on_selectReturnBtn_clicked();
    void on_expReturnBtn_clicked();
    void updateDatetime();
    void testCard();
    void getCheckBoxValue(int value);
    void on_CheckPushButton_clicked();
    void on_MeasurePushButton_clicked();
    void on_PrintPushButton_clicked();
    void recordNo(QTableWidgetItem*);
    void selectRecord(QTableWidgetItem*);
    void getPaientId();
private:
    bool read_value();

private:
    Ui::ExpDialog *ui;
    QTimer *timer;
    QTimer *testTimer;
    QTimer * barcodeTimer;
    QButtonGroup * selcectGroup;
    char SelectType;
    QStringList mFileList;
    int mSelectIndex;
    int mRecordIndex;
    int mSelcetMode;
    bool mAutoTestEnable; //判断是否自动测试有效
    double mCheckValue; //校验测试标志
    QMap<int,int> mCurveTable;//测试值与结果值对应表
    QList<unsigned int> mTestValueList;
    QString mProductDate;//生产日期
    QString mValidDate; //有效日期
    QString mReagentId; //试剂ID
    QString mTc;        //T线与C线之间的距离
    QString mChannel;   //通道号
    QString mSubChannel; //子通道号
    QString mProjectName; //项目名称
    QString mConcentBit; //浓度的小数位数
    QString mUnit;      //单位
    QString mReferentRange; //参考范围
    QString mPositiveRelation; //阳性判断关系
    QString mPositiveValve; //阳性阀值
    QString mNagativeRelation; //阴性判断关系
    QString mNagativeValve;  // 阴性阀值
    QString mDetermineFd;    //定性描述符号
    int mTimeOut;
    bool mTested;
    Posix_QextSerialPort  *mBarcodePort;
    //QThread *testThread;
};

#endif // EXPDIALOG_H
