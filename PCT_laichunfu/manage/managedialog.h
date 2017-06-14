#ifndef MANAGEDIALOG_H
#define MANAGEDIALOG_H

#include <QDialog>
#include <QTimer>
#include <QTableWidgetItem>
#include <QModelIndex>
#include <QFileSystemModel>

namespace Ui {
class ManageDialog;
}

class ManageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ManageDialog(QWidget *parent = 0);
    ~ManageDialog();

private slots:
    void on_manageReturnBtn_clicked();
    void updateDatetime();

    void on_DeletePushButton_clicked();

    void on_ImportPushButton_clicked();
    void recordNo(QTableWidgetItem*);
    //void selectFile(QModelIndex);

private:
    Ui::ManageDialog *ui;
     QTimer *timer;
     int mSelectIndex;
     int mFileSelect;
     char mUsbDirExsited;
     QFileSystemModel *model;
};

#endif // MANAGEDIALOG_H
