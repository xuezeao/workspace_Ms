#ifndef SETDIALOG_H
#define SETDIALOG_H

#include <QDialog>
#include <QTimer>
#include <QTableWidgetItem>

namespace Ui {
class SetDialog;
}

class SetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SetDialog(int WindIndex,QWidget *parent = 0);
    ~SetDialog();
    bool read_value();
    void showImage(int rowIndex);
    void deleteImage(int rowIndex);
    bool isPaperInsert();

private slots:
    void on_UserCheckConfirmBtn_clicked();
    void on_DatetimeConfirmBtn_clicked();
    void on_IPConfirmBtn_clicked();
    void on_cmosCameraBtn_clicked();
    void on_cmosTCBtn_clicked();
    void on_sysCheckSaveBtn_clicked();
    void on_sysCheckTestBtn_clicked();
    void on_sysCheckDelBtn_clicked();
    void on_cmosReturnBtn_clicked();
    void on_sysCheckBtn_clicked();
    void on_sysCheckRetBtn_clicked();
    void on_cmosCheckBtn_clicked();

    void on_userCheckBtn_clicked();

    void on_programUpdateBtn_clicked();

   // void on_DatetimeIPConfirmBtn_clicked();

    void on_DateTimeIPRetBtn_clicked();

    void on_VersionRetBtn_clicked();

    void on_UserCheckRetBtn_clicked();
    void updateDatetime();
    void testSysCheck();
    void setDays(int);

    void on_checkOrUpdateBtn_clicked();
    void recordNo(QTableWidgetItem*);

private:
    Ui::SetDialog *ui;
    QTimer * timer;
    QTimer * testTimer;
     int mSelectIndex;//选择序号
     bool isTestOffset;
     bool mTestFlag;
};

#endif // SETDIALOG_H
