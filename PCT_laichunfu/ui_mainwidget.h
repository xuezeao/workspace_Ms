/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created: Wed Dec 23 21:30:12 2015
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QGroupBox *groupBox;
    QLabel *labelType;
    QLabel *labelDatetime;
    QPushButton *pushButtonClose;
    QPushButton *pushButtonReboot;
    QLabel *label;
    QPushButton *pushButtonManage;
    QPushButton *pushButtonExp;
    QPushButton *pushButtonSet;
    QPushButton *pushButtonSelect;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(800, 480);
        MainWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        groupBox = new QGroupBox(MainWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(-9, -9, 821, 71));
        groupBox->setMinimumSize(QSize(821, 71));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 85, 255);"));
        labelType = new QLabel(groupBox);
        labelType->setObjectName(QString::fromUtf8("labelType"));
        labelType->setGeometry(QRect(60, 20, 211, 41));
        labelType->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 75 38pt \"\351\273\221\344\275\223\";"));
        labelDatetime = new QLabel(groupBox);
        labelDatetime->setObjectName(QString::fromUtf8("labelDatetime"));
        labelDatetime->setGeometry(QRect(490, 30, 311, 31));
        labelDatetime->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 22pt \"\351\273\221\344\275\223\";"));
        pushButtonClose = new QPushButton(MainWidget);
        pushButtonClose->setObjectName(QString::fromUtf8("pushButtonClose"));
        pushButtonClose->setGeometry(QRect(100, 380, 74, 32));
        pushButtonClose->setMinimumSize(QSize(74, 32));
        pushButtonClose->setStyleSheet(QString::fromUtf8("border:0px;\n"
"background-image: url(:/images/close.jpg);"));
        pushButtonReboot = new QPushButton(MainWidget);
        pushButtonReboot->setObjectName(QString::fromUtf8("pushButtonReboot"));
        pushButtonReboot->setGeometry(QRect(230, 380, 74, 32));
        pushButtonReboot->setMinimumSize(QSize(74, 32));
        pushButtonReboot->setStyleSheet(QString::fromUtf8("border:0px;\n"
"background-image: url(:/images/reboot.jpg);"));
        label = new QLabel(MainWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(290, 80, 205, 73));
        label->setMinimumSize(QSize(205, 73));
        label->setStyleSheet(QString::fromUtf8("background-image: url(:/images/ags_logo.png);"));
        pushButtonManage = new QPushButton(MainWidget);
        pushButtonManage->setObjectName(QString::fromUtf8("pushButtonManage"));
        pushButtonManage->setGeometry(QRect(260, 200, 94, 110));
        pushButtonManage->setMinimumSize(QSize(94, 110));
        pushButtonManage->setStyleSheet(QString::fromUtf8("border: 0px;\n"
"background-image: url(:/images/manage.jpg);"));
        pushButtonExp = new QPushButton(MainWidget);
        pushButtonExp->setObjectName(QString::fromUtf8("pushButtonExp"));
        pushButtonExp->setGeometry(QRect(90, 200, 90, 110));
        pushButtonExp->setMinimumSize(QSize(90, 110));
        pushButtonExp->setStyleSheet(QString::fromUtf8("background-image: url(:/images/exp.jpg);\n"
"border: 0px;"));
        pushButtonSet = new QPushButton(MainWidget);
        pushButtonSet->setObjectName(QString::fromUtf8("pushButtonSet"));
        pushButtonSet->setGeometry(QRect(620, 200, 94, 110));
        pushButtonSet->setMinimumSize(QSize(94, 110));
        pushButtonSet->setStyleSheet(QString::fromUtf8("background-image: url(:/images/funcset.jpg);\n"
"border: 0px;"));
        pushButtonSelect = new QPushButton(MainWidget);
        pushButtonSelect->setObjectName(QString::fromUtf8("pushButtonSelect"));
        pushButtonSelect->setGeometry(QRect(450, 200, 94, 110));
        pushButtonSelect->setMinimumSize(QSize(94, 110));
        pushButtonSelect->setStyleSheet(QString::fromUtf8("background-image: url(:/images/dataselect.jpg);\n"
"border: 0px;"));

        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "MainWidget", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        labelType->setText(QApplication::translate("MainWidget", "AG1000", 0, QApplication::UnicodeUTF8));
        labelDatetime->setText(QString());
        pushButtonClose->setText(QString());
        pushButtonReboot->setText(QString());
        label->setText(QString());
        pushButtonManage->setText(QString());
        pushButtonExp->setText(QString());
        pushButtonSet->setText(QString());
        pushButtonSelect->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
