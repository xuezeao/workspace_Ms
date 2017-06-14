#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QTimer>
#include "lincom/posix_qextserialport.h"
#include "lincom/qextserialbase.h"
#include "command.h"

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();
    void openConfirmStd();
    void openOffSet();
private slots:
    void updateDateTime();

    void on_pushButtonExp_clicked();

    void on_pushButtonManage_clicked();

    void on_pushButtonSelect_clicked();

    void on_pushButtonSet_clicked();

    void on_pushButtonClose_clicked();

    void on_pushButtonReboot_clicked();
    void readCommandData();

private:
    Ui::MainWidget *ui;
    QTimer *timer;
    QTimer *comTimer;
    //Command cmdFunc;
   //Posix_QextSerialPort * comm;

};

#endif // MAINWIDGET_H
