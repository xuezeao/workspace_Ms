#ifndef CONFIRMSTD_H
#define CONFIRMSTD_H

#include <QDialog>
#include <QTimer>

namespace Ui {
    class ConfirmStd;
}

class ConfirmStd : public QDialog {
    Q_OBJECT
public:
    ConfirmStd(QWidget *parent = 0);
    ~ConfirmStd();
    bool readDataToTable();
    void showImage(QString filename);
    bool isPaperInsert();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ConfirmStd *ui;
    QTimer *timer;
    QTimer *testTimer;
    bool mTested;

private slots:
    void on_CheckPushButton_clicked();
    void on_expReturnBtn_clicked();
    void testStd();
    void updateStd();
};

#endif // CONFIRMSTD_H
