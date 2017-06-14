#ifndef SELECTDIALOG_H
#define SELECTDIALOG_H

#include <QDialog>
#include <QTimer>
#include <QTableWidgetItem>

namespace Ui {
class SelectDialog;
}

class SelectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SelectDialog(QWidget *parent = 0);
    ~SelectDialog();

private slots:
    void on_SelectPushButton_2_clicked();
    void on_SelectReturnBtn_clicked();
    void updateDatetime();
    void on_DeletePushButton_clicked();

    void on_PrintPushButton_clicked();

    void on_SelectPushButton_clicked();

    void on_UpPagePushButton_clicked();

    void on_DownPagePushButton_clicked();
    void showImage(QTableWidgetItem *);

private:
    Ui::SelectDialog *ui;
    QTimer *timer;
    int mTotalPage;
    int mPage;
    int mSelectIndex;
    bool mSelectFlag;
};

#endif // SELECTDIALOG_H
