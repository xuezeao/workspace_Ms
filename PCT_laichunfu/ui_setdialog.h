/********************************************************************************
** Form generated from reading UI file 'setdialog.ui'
**
** Created: Wed Dec 23 21:30:12 2015
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETDIALOG_H
#define UI_SETDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QStackedWidget>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetDialog
{
public:
    QGroupBox *groupBox;
    QLabel *labelTitle;
    QLabel *labelDateTime;
    QStackedWidget *stackedWidget;
    QWidget *checkPage;
    QTabWidget *tabWidget;
    QWidget *tab;
    QComboBox *comboBoxYear;
    QComboBox *comboBoxMonth;
    QComboBox *comboBoxDay;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_9;
    QComboBox *comboBoxSec;
    QComboBox *comboBoxMin;
    QLabel *label_10;
    QLabel *label_11;
    QComboBox *comboBoxHour;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *IPEdit_1;
    QLabel *label_14;
    QLineEdit *IPEdit_2;
    QLineEdit *IPEdit_3;
    QLabel *label_15;
    QLineEdit *IPEdit_4;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLineEdit *MaskEdit_1;
    QLabel *label_19;
    QLineEdit *MaskEdit_4;
    QLineEdit *MaskEdit_3;
    QLabel *label_20;
    QLineEdit *MaskEdit_2;
    QPushButton *DatetimeConfirmBtn;
    QPushButton *DateTimeIPRetBtn;
    QPushButton *IPConfirmBtn;
    QWidget *tab_2;
    QPushButton *cmosCheckBtn;
    QPushButton *userCheckBtn;
    QPushButton *programUpdateBtn;
    QPushButton *checkOrUpdateBtn;
    QPushButton *sysCheckBtn;
    QWidget *tab_3;
    QLabel *label_21;
    QLabel *label_22;
    QPushButton *VersionRetBtn;
    QWidget *cmosPage;
    QPushButton *cmosReturnBtn;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *cmosLineEdit_1;
    QLineEdit *cmosLineEdit_2;
    QLineEdit *cmosLineEdit_3;
    QLineEdit *cmosLineEdit_4;
    QPushButton *cmosTCBtn;
    QPushButton *cmosCameraBtn;
    QLabel *label_23;
    QLabel *label_26;
    QLabel *label_28;
    QLabel *label_29;
    QLineEdit *cmosLineEdit_5;
    QLineEdit *cmosLineEdit_6;
    QLineEdit *cmosLineEdit_7;
    QLineEdit *cmosLineEdit_8;
    QWidget *userCheckPage;
    QPushButton *UserCheckRetBtn;
    QLineEdit *CT_DistLineEdit;
    QLabel *label_30;
    QLabel *label_31;
    QLineEdit *TWidthLineEdit;
    QPushButton *UserCheckConfirmBtn;
    QWidget *sysCheckPage;
    QLabel *sysImageLabel;
    QLabel *label_24;
    QLineEdit *sysTestLineEdit;
    QLabel *label_25;
    QLabel *sysResultLabel;
    QLabel *label_27;
    QLineEdit *sysOdLineEdit;
    QTableWidget *sysCheckTableWidget;
    QPushButton *sysCheckDelBtn;
    QPushButton *sysCheckTestBtn;
    QPushButton *sysCheckSaveBtn;
    QPushButton *sysCheckRetBtn;

    void setupUi(QDialog *SetDialog)
    {
        if (SetDialog->objectName().isEmpty())
            SetDialog->setObjectName(QString::fromUtf8("SetDialog"));
        SetDialog->resize(800, 480);
        SetDialog->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        groupBox = new QGroupBox(SetDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 811, 71));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 85, 255);"));
        labelTitle = new QLabel(groupBox);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        labelTitle->setGeometry(QRect(50, 20, 201, 41));
        labelTitle->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 75 32pt \"\351\273\221\344\275\223\";"));
        labelDateTime = new QLabel(groupBox);
        labelDateTime->setObjectName(QString::fromUtf8("labelDateTime"));
        labelDateTime->setGeometry(QRect(520, 20, 271, 41));
        labelDateTime->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font:  20pt \"\351\273\221\344\275\223\";"));
        stackedWidget = new QStackedWidget(SetDialog);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 70, 801, 421));
        checkPage = new QWidget();
        checkPage->setObjectName(QString::fromUtf8("checkPage"));
        tabWidget = new QTabWidget(checkPage);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(-10, 0, 811, 411));
        tabWidget->setStyleSheet(QString::fromUtf8("font: 75 20pt \"\351\273\221\344\275\223\";"));
        tabWidget->setIconSize(QSize(20, 18));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        comboBoxYear = new QComboBox(tab);
        comboBoxYear->setObjectName(QString::fromUtf8("comboBoxYear"));
        comboBoxYear->setGeometry(QRect(110, 120, 91, 41));
        comboBoxYear->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        comboBoxMonth = new QComboBox(tab);
        comboBoxMonth->setObjectName(QString::fromUtf8("comboBoxMonth"));
        comboBoxMonth->setGeometry(QRect(270, 120, 101, 41));
        comboBoxMonth->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        comboBoxDay = new QComboBox(tab);
        comboBoxDay->setObjectName(QString::fromUtf8("comboBoxDay"));
        comboBoxDay->setGeometry(QRect(450, 120, 81, 41));
        comboBoxDay->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(220, 110, 31, 51));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(390, 110, 31, 51));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(560, 110, 31, 51));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 110, 81, 61));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(220, 180, 31, 51));
        comboBoxSec = new QComboBox(tab);
        comboBoxSec->setObjectName(QString::fromUtf8("comboBoxSec"));
        comboBoxSec->setGeometry(QRect(450, 190, 81, 41));
        comboBoxSec->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        comboBoxMin = new QComboBox(tab);
        comboBoxMin->setObjectName(QString::fromUtf8("comboBoxMin"));
        comboBoxMin->setGeometry(QRect(270, 190, 101, 41));
        comboBoxMin->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        label_10 = new QLabel(tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(390, 180, 31, 51));
        label_11 = new QLabel(tab);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 180, 81, 61));
        comboBoxHour = new QComboBox(tab);
        comboBoxHour->setObjectName(QString::fromUtf8("comboBoxHour"));
        comboBoxHour->setGeometry(QRect(110, 190, 91, 41));
        comboBoxHour->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        label_12 = new QLabel(tab);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(560, 180, 31, 51));
        label_13 = new QLabel(tab);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(20, 0, 111, 61));
        IPEdit_1 = new QLineEdit(tab);
        IPEdit_1->setObjectName(QString::fromUtf8("IPEdit_1"));
        IPEdit_1->setGeometry(QRect(130, 10, 51, 41));
        label_14 = new QLabel(tab);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(190, 10, 16, 51));
        IPEdit_2 = new QLineEdit(tab);
        IPEdit_2->setObjectName(QString::fromUtf8("IPEdit_2"));
        IPEdit_2->setGeometry(QRect(210, 10, 51, 41));
        IPEdit_3 = new QLineEdit(tab);
        IPEdit_3->setObjectName(QString::fromUtf8("IPEdit_3"));
        IPEdit_3->setGeometry(QRect(290, 10, 51, 41));
        label_15 = new QLabel(tab);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(350, 10, 16, 51));
        IPEdit_4 = new QLineEdit(tab);
        IPEdit_4->setObjectName(QString::fromUtf8("IPEdit_4"));
        IPEdit_4->setGeometry(QRect(370, 10, 51, 41));
        label_16 = new QLabel(tab);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(270, 10, 16, 51));
        label_17 = new QLabel(tab);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(20, 50, 101, 61));
        label_18 = new QLabel(tab);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(270, 60, 16, 51));
        MaskEdit_1 = new QLineEdit(tab);
        MaskEdit_1->setObjectName(QString::fromUtf8("MaskEdit_1"));
        MaskEdit_1->setGeometry(QRect(130, 60, 51, 41));
        label_19 = new QLabel(tab);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(190, 60, 16, 51));
        MaskEdit_4 = new QLineEdit(tab);
        MaskEdit_4->setObjectName(QString::fromUtf8("MaskEdit_4"));
        MaskEdit_4->setGeometry(QRect(370, 60, 51, 41));
        MaskEdit_3 = new QLineEdit(tab);
        MaskEdit_3->setObjectName(QString::fromUtf8("MaskEdit_3"));
        MaskEdit_3->setGeometry(QRect(290, 60, 51, 41));
        label_20 = new QLabel(tab);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(350, 60, 16, 51));
        MaskEdit_2 = new QLineEdit(tab);
        MaskEdit_2->setObjectName(QString::fromUtf8("MaskEdit_2"));
        MaskEdit_2->setGeometry(QRect(210, 60, 51, 41));
        DatetimeConfirmBtn = new QPushButton(tab);
        DatetimeConfirmBtn->setObjectName(QString::fromUtf8("DatetimeConfirmBtn"));
        DatetimeConfirmBtn->setGeometry(QRect(610, 180, 111, 41));
        DateTimeIPRetBtn = new QPushButton(tab);
        DateTimeIPRetBtn->setObjectName(QString::fromUtf8("DateTimeIPRetBtn"));
        DateTimeIPRetBtn->setGeometry(QRect(610, 280, 111, 41));
        IPConfirmBtn = new QPushButton(tab);
        IPConfirmBtn->setObjectName(QString::fromUtf8("IPConfirmBtn"));
        IPConfirmBtn->setGeometry(QRect(610, 60, 111, 41));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        cmosCheckBtn = new QPushButton(tab_2);
        cmosCheckBtn->setObjectName(QString::fromUtf8("cmosCheckBtn"));
        cmosCheckBtn->setGeometry(QRect(50, 70, 112, 137));
        cmosCheckBtn->setStyleSheet(QString::fromUtf8("background-image: url(:/images/cmos.jpg);\n"
"border:0px;"));
        userCheckBtn = new QPushButton(tab_2);
        userCheckBtn->setObjectName(QString::fromUtf8("userCheckBtn"));
        userCheckBtn->setGeometry(QRect(200, 70, 112, 137));
        userCheckBtn->setStyleSheet(QString::fromUtf8("background-image: url(:/images/check.jpg);\n"
"border:0px;"));
        programUpdateBtn = new QPushButton(tab_2);
        programUpdateBtn->setObjectName(QString::fromUtf8("programUpdateBtn"));
        programUpdateBtn->setGeometry(QRect(500, 70, 112, 137));
        programUpdateBtn->setStyleSheet(QString::fromUtf8("background-image: url(:/images/update.jpg);\n"
"border:0px;"));
        checkOrUpdateBtn = new QPushButton(tab_2);
        checkOrUpdateBtn->setObjectName(QString::fromUtf8("checkOrUpdateBtn"));
        checkOrUpdateBtn->setGeometry(QRect(580, 260, 121, 51));
        sysCheckBtn = new QPushButton(tab_2);
        sysCheckBtn->setObjectName(QString::fromUtf8("sysCheckBtn"));
        sysCheckBtn->setGeometry(QRect(350, 60, 112, 150));
        sysCheckBtn->setStyleSheet(QString::fromUtf8("background-image: url(:/images/systemcheck.jpg);\n"
"border:0px;"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        label_21 = new QLabel(tab_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(30, 60, 391, 41));
        label_22 = new QLabel(tab_3);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(30, 130, 711, 51));
        VersionRetBtn = new QPushButton(tab_3);
        VersionRetBtn->setObjectName(QString::fromUtf8("VersionRetBtn"));
        VersionRetBtn->setGeometry(QRect(510, 250, 131, 51));
        tabWidget->addTab(tab_3, QString());
        stackedWidget->addWidget(checkPage);
        cmosPage = new QWidget();
        cmosPage->setObjectName(QString::fromUtf8("cmosPage"));
        cmosReturnBtn = new QPushButton(cmosPage);
        cmosReturnBtn->setObjectName(QString::fromUtf8("cmosReturnBtn"));
        cmosReturnBtn->setGeometry(QRect(520, 260, 101, 51));
        cmosReturnBtn->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        label_5 = new QLabel(cmosPage);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 10, 181, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        label_6 = new QLabel(cmosPage);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 60, 161, 31));
        label_6->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        label_7 = new QLabel(cmosPage);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 110, 181, 31));
        label_7->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        label_8 = new QLabel(cmosPage);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 160, 181, 31));
        label_8->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        cmosLineEdit_1 = new QLineEdit(cmosPage);
        cmosLineEdit_1->setObjectName(QString::fromUtf8("cmosLineEdit_1"));
        cmosLineEdit_1->setGeometry(QRect(200, 10, 151, 31));
        cmosLineEdit_2 = new QLineEdit(cmosPage);
        cmosLineEdit_2->setObjectName(QString::fromUtf8("cmosLineEdit_2"));
        cmosLineEdit_2->setGeometry(QRect(200, 60, 151, 31));
        cmosLineEdit_3 = new QLineEdit(cmosPage);
        cmosLineEdit_3->setObjectName(QString::fromUtf8("cmosLineEdit_3"));
        cmosLineEdit_3->setGeometry(QRect(200, 110, 151, 31));
        cmosLineEdit_4 = new QLineEdit(cmosPage);
        cmosLineEdit_4->setObjectName(QString::fromUtf8("cmosLineEdit_4"));
        cmosLineEdit_4->setGeometry(QRect(200, 160, 151, 31));
        cmosTCBtn = new QPushButton(cmosPage);
        cmosTCBtn->setObjectName(QString::fromUtf8("cmosTCBtn"));
        cmosTCBtn->setGeometry(QRect(200, 260, 101, 51));
        cmosTCBtn->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        cmosCameraBtn = new QPushButton(cmosPage);
        cmosCameraBtn->setObjectName(QString::fromUtf8("cmosCameraBtn"));
        cmosCameraBtn->setGeometry(QRect(350, 260, 101, 51));
        cmosCameraBtn->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        label_23 = new QLabel(cmosPage);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(390, 10, 141, 31));
        label_23->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        label_26 = new QLabel(cmosPage);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(390, 60, 141, 31));
        label_26->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        label_28 = new QLabel(cmosPage);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(390, 110, 121, 31));
        label_28->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        label_29 = new QLabel(cmosPage);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(390, 160, 121, 31));
        label_29->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        cmosLineEdit_5 = new QLineEdit(cmosPage);
        cmosLineEdit_5->setObjectName(QString::fromUtf8("cmosLineEdit_5"));
        cmosLineEdit_5->setGeometry(QRect(540, 10, 151, 31));
        cmosLineEdit_6 = new QLineEdit(cmosPage);
        cmosLineEdit_6->setObjectName(QString::fromUtf8("cmosLineEdit_6"));
        cmosLineEdit_6->setGeometry(QRect(540, 60, 151, 31));
        cmosLineEdit_7 = new QLineEdit(cmosPage);
        cmosLineEdit_7->setObjectName(QString::fromUtf8("cmosLineEdit_7"));
        cmosLineEdit_7->setGeometry(QRect(540, 110, 151, 31));
        cmosLineEdit_8 = new QLineEdit(cmosPage);
        cmosLineEdit_8->setObjectName(QString::fromUtf8("cmosLineEdit_8"));
        cmosLineEdit_8->setGeometry(QRect(540, 160, 151, 31));
        stackedWidget->addWidget(cmosPage);
        userCheckPage = new QWidget();
        userCheckPage->setObjectName(QString::fromUtf8("userCheckPage"));
        UserCheckRetBtn = new QPushButton(userCheckPage);
        UserCheckRetBtn->setObjectName(QString::fromUtf8("UserCheckRetBtn"));
        UserCheckRetBtn->setGeometry(QRect(510, 280, 101, 51));
        UserCheckRetBtn->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        CT_DistLineEdit = new QLineEdit(userCheckPage);
        CT_DistLineEdit->setObjectName(QString::fromUtf8("CT_DistLineEdit"));
        CT_DistLineEdit->setGeometry(QRect(200, 20, 151, 31));
        label_30 = new QLabel(userCheckPage);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(20, 20, 181, 31));
        label_30->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        label_31 = new QLabel(userCheckPage);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(20, 80, 171, 31));
        label_31->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        TWidthLineEdit = new QLineEdit(userCheckPage);
        TWidthLineEdit->setObjectName(QString::fromUtf8("TWidthLineEdit"));
        TWidthLineEdit->setGeometry(QRect(200, 80, 151, 31));
        UserCheckConfirmBtn = new QPushButton(userCheckPage);
        UserCheckConfirmBtn->setObjectName(QString::fromUtf8("UserCheckConfirmBtn"));
        UserCheckConfirmBtn->setGeometry(QRect(300, 280, 101, 51));
        UserCheckConfirmBtn->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        stackedWidget->addWidget(userCheckPage);
        sysCheckPage = new QWidget();
        sysCheckPage->setObjectName(QString::fromUtf8("sysCheckPage"));
        sysImageLabel = new QLabel(sysCheckPage);
        sysImageLabel->setObjectName(QString::fromUtf8("sysImageLabel"));
        sysImageLabel->setGeometry(QRect(10, 10, 101, 171));
        sysImageLabel->setStyleSheet(QString::fromUtf8(""));
        label_24 = new QLabel(sysCheckPage);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(160, 40, 61, 31));
        label_24->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        sysTestLineEdit = new QLineEdit(sysCheckPage);
        sysTestLineEdit->setObjectName(QString::fromUtf8("sysTestLineEdit"));
        sysTestLineEdit->setGeometry(QRect(240, 40, 71, 27));
        label_25 = new QLabel(sysCheckPage);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(160, 90, 41, 21));
        label_25->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        sysResultLabel = new QLabel(sysCheckPage);
        sysResultLabel->setObjectName(QString::fromUtf8("sysResultLabel"));
        sysResultLabel->setGeometry(QRect(230, 90, 91, 21));
        sysResultLabel->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        label_27 = new QLabel(sysCheckPage);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(150, 130, 81, 31));
        label_27->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        sysOdLineEdit = new QLineEdit(sysCheckPage);
        sysOdLineEdit->setObjectName(QString::fromUtf8("sysOdLineEdit"));
        sysOdLineEdit->setGeometry(QRect(240, 130, 71, 27));
        sysCheckTableWidget = new QTableWidget(sysCheckPage);
        if (sysCheckTableWidget->columnCount() < 4)
            sysCheckTableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        sysCheckTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        sysCheckTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        sysCheckTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        sysCheckTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        sysCheckTableWidget->setObjectName(QString::fromUtf8("sysCheckTableWidget"));
        sysCheckTableWidget->setGeometry(QRect(340, 20, 411, 281));
        sysCheckTableWidget->horizontalHeader()->setStretchLastSection(true);
        sysCheckDelBtn = new QPushButton(sysCheckPage);
        sysCheckDelBtn->setObjectName(QString::fromUtf8("sysCheckDelBtn"));
        sysCheckDelBtn->setGeometry(QRect(70, 330, 93, 51));
        sysCheckDelBtn->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        sysCheckTestBtn = new QPushButton(sysCheckPage);
        sysCheckTestBtn->setObjectName(QString::fromUtf8("sysCheckTestBtn"));
        sysCheckTestBtn->setGeometry(QRect(250, 330, 93, 51));
        sysCheckTestBtn->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        sysCheckSaveBtn = new QPushButton(sysCheckPage);
        sysCheckSaveBtn->setObjectName(QString::fromUtf8("sysCheckSaveBtn"));
        sysCheckSaveBtn->setGeometry(QRect(440, 330, 93, 51));
        sysCheckSaveBtn->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        sysCheckRetBtn = new QPushButton(sysCheckPage);
        sysCheckRetBtn->setObjectName(QString::fromUtf8("sysCheckRetBtn"));
        sysCheckRetBtn->setGeometry(QRect(630, 330, 93, 51));
        sysCheckRetBtn->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        stackedWidget->addWidget(sysCheckPage);

        retranslateUi(SetDialog);

        stackedWidget->setCurrentIndex(2);
        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(SetDialog);
    } // setupUi

    void retranslateUi(QDialog *SetDialog)
    {
        SetDialog->setWindowTitle(QApplication::translate("SetDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        labelTitle->setText(QApplication::translate("SetDialog", "\345\212\237\350\203\275\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        labelDateTime->setText(QApplication::translate("SetDialog", "2015-08-09 14:41:32", 0, QApplication::UnicodeUTF8));
        comboBoxYear->clear();
        comboBoxYear->insertItems(0, QStringList()
         << QApplication::translate("SetDialog", "2014", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "2015", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "2016", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "2017", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "2018", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "2019", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "2020", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "2021", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "2022", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "2023", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "2024", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "2025", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "2026", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "2027", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "2028", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "2029", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "2030", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "2031", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "2032", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "2033", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "2034", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "2035", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "2036", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "2037", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "2038", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "2039", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "2040", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "2041", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "2042", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "2043", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "2044", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "2045", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "2046", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "2047", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "2048", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "2049", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "2050", 0, QApplication::UnicodeUTF8)
        );
        comboBoxMonth->clear();
        comboBoxMonth->insertItems(0, QStringList()
         << QApplication::translate("SetDialog", "01", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "02", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "03", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "04", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "05", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "06", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "07", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "08", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "09", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "11", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "12", 0, QApplication::UnicodeUTF8)
        );
        comboBoxDay->clear();
        comboBoxDay->insertItems(0, QStringList()
         << QApplication::translate("SetDialog", "01", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "02", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "03", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "04", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "05", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "06", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "07", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "08", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "09", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "11", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "12", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "14", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "15", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "16", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "17", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "18", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "19", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "21", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "22", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "23", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "24", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "25", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "26", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "27", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "28", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "29", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "30", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "31", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("SetDialog", "\345\271\264", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SetDialog", "\346\234\210", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SetDialog", "\346\227\245", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SetDialog", "\346\227\245\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("SetDialog", "\346\227\266", 0, QApplication::UnicodeUTF8));
        comboBoxSec->clear();
        comboBoxSec->insertItems(0, QStringList()
         << QApplication::translate("SetDialog", "00", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "01", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "02", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "03", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "04", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "05", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "06", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "07", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "08", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "09", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "11", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "12", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "14", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "15", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "16", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "17", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "18", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "19", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "21", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "22", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "23", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "24", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "25", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "26", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "27", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "28", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "29", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "30", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "31", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "32", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "33", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "34", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "35", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "36", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "37", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "38", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "39", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "40", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "41", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "42", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "43", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "44", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "45", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "46", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "47", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "48", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "49", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "50", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "51", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "52", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "53", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "54", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "55", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "56", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "57", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "58", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "59", 0, QApplication::UnicodeUTF8)
        );
        comboBoxMin->clear();
        comboBoxMin->insertItems(0, QStringList()
         << QApplication::translate("SetDialog", "00", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "01", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "02", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "03", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "04", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "05", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "06", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "07", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "08", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "09", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "11", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "12", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "13", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "14", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "15", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "16", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "17", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "18", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "19", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "21", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "22", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "23", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "24", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "25", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "26", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "27", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "28", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "29", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "30", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "31", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "32", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "33", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "34", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "35", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "36", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "37", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "38", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "39", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "40", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "41", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "42", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "43", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "44", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "45", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "46", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "47", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "48", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "49", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "50", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "51", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "52", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "53", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "54", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "55", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "56", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "57", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "58", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "59", 0, QApplication::UnicodeUTF8)
        );
        label_10->setText(QApplication::translate("SetDialog", "\345\210\206", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("SetDialog", "\346\227\266\351\227\264\357\274\232", 0, QApplication::UnicodeUTF8));
        comboBoxHour->clear();
        comboBoxHour->insertItems(0, QStringList()
         << QApplication::translate("SetDialog", "00", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "01", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "02", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "03", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "04", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "05", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "06", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "07", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "08", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "09", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "11", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "12", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "13", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "14", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "15", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "16", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "17", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "18", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "19", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "21", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "22", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SetDialog", "23", 0, QApplication::UnicodeUTF8)
        );
        label_12->setText(QApplication::translate("SetDialog", "\347\247\222", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("SetDialog", "\346\234\254\346\234\272IP\345\234\260\345\235\200\357\274\232", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("SetDialog", ".", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("SetDialog", ".", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("SetDialog", ".", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("SetDialog", "\345\255\220\347\275\221\346\216\251\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("SetDialog", ".", 0, QApplication::UnicodeUTF8));
        MaskEdit_1->setText(QString());
        label_19->setText(QApplication::translate("SetDialog", ".", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("SetDialog", ".", 0, QApplication::UnicodeUTF8));
        DatetimeConfirmBtn->setText(QApplication::translate("SetDialog", "\350\256\276\347\275\256\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        DateTimeIPRetBtn->setText(QApplication::translate("SetDialog", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        IPConfirmBtn->setText(QApplication::translate("SetDialog", "\350\256\276\347\275\256\347\275\221\347\273\234", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("SetDialog", "\346\227\266\351\222\237\345\217\212IP", 0, QApplication::UnicodeUTF8));
        cmosCheckBtn->setText(QString());
        userCheckBtn->setText(QString());
        programUpdateBtn->setText(QString());
        checkOrUpdateBtn->setText(QApplication::translate("SetDialog", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        sysCheckBtn->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("SetDialog", "\346\240\241\351\252\214\344\270\216\345\215\207\347\272\247", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("SetDialog", "\350\275\257\344\273\266\347\211\210\346\234\254\357\274\232VER1.00", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("SetDialog", "\350\275\257\344\273\266\346\211\200\346\234\2112011-2015\346\235\255\345\267\236\345\256\211\346\235\260\346\200\235\347\224\237\347\211\251\347\247\221\346\212\200\346\234\211\351\231\220\345\205\254\345\217\270", 0, QApplication::UnicodeUTF8));
        VersionRetBtn->setText(QApplication::translate("SetDialog", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("SetDialog", "\345\205\263\344\272\216", 0, QApplication::UnicodeUTF8));
        cmosReturnBtn->setText(QApplication::translate("SetDialog", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("SetDialog", "C\347\272\277\345\222\214T\347\272\277\347\232\204\351\227\264\350\267\235\357\274\232", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("SetDialog", "T\347\272\277\345\217\202\350\200\203\351\227\264\350\267\235\357\274\232", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("SetDialog", "C\347\216\260\346\234\200\345\260\217\346\234\211\346\225\210\345\200\274\357\274\232", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("SetDialog", "T\347\272\277\346\265\213\351\207\217\345\256\275\345\272\246\357\274\232", 0, QApplication::UnicodeUTF8));
        cmosTCBtn->setText(QApplication::translate("SetDialog", "\351\227\264\350\267\235\346\240\241\345\207\206", 0, QApplication::UnicodeUTF8));
        cmosCameraBtn->setText(QApplication::translate("SetDialog", "\345\272\225\350\211\262\346\240\241\345\207\206", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("SetDialog", "T\347\272\277\346\265\213\351\207\217\351\253\230\345\272\246\357\274\232", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("SetDialog", "\345\272\225\350\211\262\345\201\217\347\247\273\351\207\217\357\274\232", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("SetDialog", "\346\233\235\345\205\211\345\200\274\357\274\232", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("SetDialog", "\345\205\266\344\273\226\345\217\202\346\225\260\357\274\232", 0, QApplication::UnicodeUTF8));
        UserCheckRetBtn->setText(QApplication::translate("SetDialog", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("SetDialog", "C\347\272\277\345\222\214T\347\272\277\347\232\204\351\227\264\350\267\235\357\274\232", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("SetDialog", "T\347\272\277\347\232\204\345\256\275\345\272\246\357\274\232", 0, QApplication::UnicodeUTF8));
        UserCheckConfirmBtn->setText(QApplication::translate("SetDialog", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        sysImageLabel->setText(QString());
        label_24->setText(QApplication::translate("SetDialog", "\346\265\213\351\207\217\345\200\274:", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("SetDialog", "\346\217\220\347\244\272:", 0, QApplication::UnicodeUTF8));
        sysResultLabel->setText(QApplication::translate("SetDialog", "\346\227\240\346\225\210", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("SetDialog", "\350\276\223\345\205\245OD\345\200\274:", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = sysCheckTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("SetDialog", "\345\272\217\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = sysCheckTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("SetDialog", "\346\265\213\351\207\217\345\200\274", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = sysCheckTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("SetDialog", "OD\345\200\274", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = sysCheckTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("SetDialog", "\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        sysCheckDelBtn->setText(QApplication::translate("SetDialog", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        sysCheckTestBtn->setText(QApplication::translate("SetDialog", "\346\265\213\351\207\217", 0, QApplication::UnicodeUTF8));
        sysCheckSaveBtn->setText(QApplication::translate("SetDialog", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        sysCheckRetBtn->setText(QApplication::translate("SetDialog", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SetDialog: public Ui_SetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETDIALOG_H
