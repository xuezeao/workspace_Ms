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

#define TMP_ID "��Ʒ���:"
#define PROJECT "��Ŀ:"
#define RESULT  "���:"
#define RANGER  "�ο���Χ��"
#define UP    "��"
#define DOWN  "��"
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
    bool isPaperInsert();//�Ƿ��п�������

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
    bool mAutoTestEnable; //�ж��Ƿ��Զ�������Ч
    double mCheckValue; //У����Ա�־
    QMap<int,int> mCurveTable;//����ֵ����ֵ��Ӧ��
    QList<unsigned int> mTestValueList;
    QString mProductDate;//��������
    QString mValidDate; //��Ч����
    QString mReagentId; //�Լ�ID
    QString mTc;        //T����C��֮��ľ���
    QString mChannel;   //ͨ����
    QString mSubChannel; //��ͨ����
    QString mProjectName; //��Ŀ����
    QString mConcentBit; //Ũ�ȵ�С��λ��
    QString mUnit;      //��λ
    QString mReferentRange; //�ο���Χ
    QString mPositiveRelation; //�����жϹ�ϵ
    QString mPositiveValve; //���Է�ֵ
    QString mNagativeRelation; //�����жϹ�ϵ
    QString mNagativeValve;  // ���Է�ֵ
    QString mDetermineFd;    //������������
    int mTimeOut;
    bool mTested;
    Posix_QextSerialPort  *mBarcodePort;
    //QThread *testThread;
};

#endif // EXPDIALOG_H
