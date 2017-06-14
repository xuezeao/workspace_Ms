/********************************************************************************
** Form generated from reading UI file 'expdialog.ui'
**
** Created: Wed Dec 23 21:30:12 2015
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPDIALOG_H
#define UI_EXPDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QStackedWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExpDialog
{
public:
    QGroupBox *groupBox;
    QLabel *labelTitle;
    QLabel *labelDateTime;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QTableWidget *AnalysisTableWidget;
    QLabel *ShowImageLabel;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *TestValueLineEdit;
    QLineEdit *ResultLineEdit;
    QLineEdit *PatientLineEdit;
    QLabel *label_8;
    QLabel *label_9;
    QGroupBox *groupBox_2;
    QCheckBox *AutoCheckBox;
    QCheckBox *CoverCheckBox;
    QCheckBox *PrintCheckBox;
    QLabel *CurrentRegIdLabel;
    QLabel *PromptLabel;
    QPushButton *CheckPushButton;
    QPushButton *MeasurePushButton;
    QPushButton *PrintPushButton;
    QPushButton *expReturnBtn;
    QLabel *ProjectNameLabel;
    QWidget *page_2;
    QLabel *label_2;
    QTableWidget *tableWidget;
    QPushButton *selectOkBtn;
    QPushButton *selectReturnBtn;

    void setupUi(QDialog *ExpDialog)
    {
        if (ExpDialog->objectName().isEmpty())
            ExpDialog->setObjectName(QString::fromUtf8("ExpDialog"));
        ExpDialog->resize(800, 480);
        groupBox = new QGroupBox(ExpDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(-10, -10, 811, 71));
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
        stackedWidget = new QStackedWidget(ExpDialog);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 60, 801, 421));
        stackedWidget->setAutoFillBackground(false);
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        AnalysisTableWidget = new QTableWidget(page);
        if (AnalysisTableWidget->columnCount() < 6)
            AnalysisTableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        AnalysisTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        AnalysisTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        AnalysisTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        AnalysisTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        AnalysisTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        AnalysisTableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        AnalysisTableWidget->setObjectName(QString::fromUtf8("AnalysisTableWidget"));
        AnalysisTableWidget->setGeometry(QRect(210, 60, 571, 271));
        AnalysisTableWidget->setSortingEnabled(false);
        AnalysisTableWidget->setRowCount(0);
        AnalysisTableWidget->setColumnCount(6);
        AnalysisTableWidget->horizontalHeader()->setVisible(true);
        AnalysisTableWidget->horizontalHeader()->setDefaultSectionSize(73);
        AnalysisTableWidget->horizontalHeader()->setHighlightSections(false);
        AnalysisTableWidget->horizontalHeader()->setStretchLastSection(true);
        AnalysisTableWidget->verticalHeader()->setVisible(false);
        AnalysisTableWidget->verticalHeader()->setDefaultSectionSize(30);
        AnalysisTableWidget->verticalHeader()->setHighlightSections(true);
        ShowImageLabel = new QLabel(page);
        ShowImageLabel->setObjectName(QString::fromUtf8("ShowImageLabel"));
        ShowImageLabel->setGeometry(QRect(13, 50, 81, 151));
        ShowImageLabel->setStyleSheet(QString::fromUtf8("background-image: url();\n"
"background-color: rgb(255, 255, 255);"));
        label_4 = new QLabel(page);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 10, 54, 20));
        label_5 = new QLabel(page);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(100, 80, 51, 20));
        label_6 = new QLabel(page);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(100, 130, 41, 16));
        label_7 = new QLabel(page);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(100, 160, 31, 16));
        TestValueLineEdit = new QLineEdit(page);
        TestValueLineEdit->setObjectName(QString::fromUtf8("TestValueLineEdit"));
        TestValueLineEdit->setGeometry(QRect(150, 80, 41, 20));
        ResultLineEdit = new QLineEdit(page);
        ResultLineEdit->setObjectName(QString::fromUtf8("ResultLineEdit"));
        ResultLineEdit->setGeometry(QRect(150, 130, 41, 20));
        PatientLineEdit = new QLineEdit(page);
        PatientLineEdit->setObjectName(QString::fromUtf8("PatientLineEdit"));
        PatientLineEdit->setGeometry(QRect(320, 10, 141, 31));
        label_8 = new QLabel(page);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(260, 10, 54, 31));
        label_9 = new QLabel(page);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(550, 10, 71, 31));
        groupBox_2 = new QGroupBox(page);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 220, 181, 111));
        groupBox_2->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);"));
        AutoCheckBox = new QCheckBox(groupBox_2);
        AutoCheckBox->setObjectName(QString::fromUtf8("AutoCheckBox"));
        AutoCheckBox->setGeometry(QRect(18, 10, 131, 21));
        AutoCheckBox->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        CoverCheckBox = new QCheckBox(groupBox_2);
        CoverCheckBox->setObjectName(QString::fromUtf8("CoverCheckBox"));
        CoverCheckBox->setGeometry(QRect(18, 40, 131, 21));
        CoverCheckBox->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        PrintCheckBox = new QCheckBox(groupBox_2);
        PrintCheckBox->setObjectName(QString::fromUtf8("PrintCheckBox"));
        PrintCheckBox->setGeometry(QRect(18, 70, 151, 21));
        PrintCheckBox->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        CurrentRegIdLabel = new QLabel(page);
        CurrentRegIdLabel->setObjectName(QString::fromUtf8("CurrentRegIdLabel"));
        CurrentRegIdLabel->setGeometry(QRect(630, 10, 91, 31));
        PromptLabel = new QLabel(page);
        PromptLabel->setObjectName(QString::fromUtf8("PromptLabel"));
        PromptLabel->setGeometry(QRect(140, 160, 51, 21));
        CheckPushButton = new QPushButton(page);
        CheckPushButton->setObjectName(QString::fromUtf8("CheckPushButton"));
        CheckPushButton->setGeometry(QRect(70, 350, 111, 51));
        CheckPushButton->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        MeasurePushButton = new QPushButton(page);
        MeasurePushButton->setObjectName(QString::fromUtf8("MeasurePushButton"));
        MeasurePushButton->setGeometry(QRect(240, 350, 121, 51));
        MeasurePushButton->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        PrintPushButton = new QPushButton(page);
        PrintPushButton->setObjectName(QString::fromUtf8("PrintPushButton"));
        PrintPushButton->setGeometry(QRect(420, 350, 111, 51));
        PrintPushButton->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        expReturnBtn = new QPushButton(page);
        expReturnBtn->setObjectName(QString::fromUtf8("expReturnBtn"));
        expReturnBtn->setGeometry(QRect(590, 350, 121, 51));
        expReturnBtn->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        ProjectNameLabel = new QLabel(page);
        ProjectNameLabel->setObjectName(QString::fromUtf8("ProjectNameLabel"));
        ProjectNameLabel->setGeometry(QRect(120, 10, 71, 21));
        ProjectNameLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        label_2 = new QLabel(page_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 0, 121, 51));
        label_2->setStyleSheet(QString::fromUtf8("font: 75 20pt \"\345\256\213\344\275\223\";"));
        tableWidget = new QTableWidget(page_2);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QFont font;
        font.setPointSize(15);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font);
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem10);
        if (tableWidget->rowCount() < 6)
            tableWidget->setRowCount(6);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(130, 50, 541, 281));
        tableWidget->setStyleSheet(QString::fromUtf8("QHeaderView::section{background:skyblue;}"));
        tableWidget->setRowCount(6);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(100);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(40);
        tableWidget->verticalHeader()->setStretchLastSection(false);
        selectOkBtn = new QPushButton(page_2);
        selectOkBtn->setObjectName(QString::fromUtf8("selectOkBtn"));
        selectOkBtn->setGeometry(QRect(350, 360, 121, 41));
        selectOkBtn->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        selectReturnBtn = new QPushButton(page_2);
        selectReturnBtn->setObjectName(QString::fromUtf8("selectReturnBtn"));
        selectReturnBtn->setGeometry(QRect(490, 360, 121, 41));
        selectReturnBtn->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        stackedWidget->addWidget(page_2);

        retranslateUi(ExpDialog);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ExpDialog);
    } // setupUi

    void retranslateUi(QDialog *ExpDialog)
    {
        ExpDialog->setWindowTitle(QApplication::translate("ExpDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        labelTitle->setText(QApplication::translate("ExpDialog", "\350\257\225\345\211\202\351\200\211\346\213\251", 0, QApplication::UnicodeUTF8));
        labelDateTime->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = AnalysisTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ExpDialog", "\351\241\271\347\233\256", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = AnalysisTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ExpDialog", "\347\273\223\346\236\234", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = AnalysisTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ExpDialog", "\346\265\213\350\257\225\345\200\274", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = AnalysisTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ExpDialog", "\346\202\243\350\200\205\347\274\226\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = AnalysisTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("ExpDialog", "\346\240\267\346\234\254ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = AnalysisTableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("ExpDialog", "\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        ShowImageLabel->setText(QString());
        label_4->setText(QApplication::translate("ExpDialog", "\351\241\271\347\233\256\345\220\215\347\247\260\357\274\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ExpDialog", "\346\265\213\351\207\217\345\200\274\357\274\232", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ExpDialog", "\347\273\223\346\236\234\357\274\232", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ExpDialog", "\346\217\220\347\244\272\357\274\232", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("ExpDialog", "\346\202\243\350\200\205\347\274\226\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("ExpDialog", "\345\275\223\345\211\215\350\257\225\345\211\202ID\357\274\232", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QString());
        AutoCheckBox->setText(QApplication::translate("ExpDialog", "\350\207\252\345\212\250\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        CoverCheckBox->setText(QApplication::translate("ExpDialog", "\350\246\206\347\233\226\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        PrintCheckBox->setText(QApplication::translate("ExpDialog", "\346\265\213\351\207\217\345\271\266\346\211\223\345\215\260", 0, QApplication::UnicodeUTF8));
        CurrentRegIdLabel->setText(QApplication::translate("ExpDialog", "XXXXXXX", 0, QApplication::UnicodeUTF8));
        PromptLabel->setText(QString());
        CheckPushButton->setText(QApplication::translate("ExpDialog", "\346\240\241\351\252\214", 0, QApplication::UnicodeUTF8));
        MeasurePushButton->setText(QApplication::translate("ExpDialog", "\346\265\213\351\207\217", 0, QApplication::UnicodeUTF8));
        PrintPushButton->setText(QApplication::translate("ExpDialog", "\346\211\223\345\215\260", 0, QApplication::UnicodeUTF8));
        expReturnBtn->setText(QApplication::translate("ExpDialog", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        ProjectNameLabel->setText(QString());
        label_2->setText(QApplication::translate("ExpDialog", "\350\257\225\345\211\202\345\210\227\350\241\250\357\274\232", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("ExpDialog", "\345\272\217\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("ExpDialog", "\347\224\237\344\272\247\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QApplication::translate("ExpDialog", "\350\257\225\345\211\202\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QApplication::translate("ExpDialog", "\346\234\211\346\225\210\350\265\267\350\207\263", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem10->setText(QApplication::translate("ExpDialog", "\350\257\225\345\211\202ID", 0, QApplication::UnicodeUTF8));
        selectOkBtn->setText(QApplication::translate("ExpDialog", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        selectReturnBtn->setText(QApplication::translate("ExpDialog", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ExpDialog: public Ui_ExpDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPDIALOG_H
