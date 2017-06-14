/********************************************************************************
** Form generated from reading UI file 'selectdialog.ui'
**
** Created: Wed Dec 23 21:30:12 2015
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTDIALOG_H
#define UI_SELECTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectDialog
{
public:
    QGroupBox *groupBox;
    QLabel *labelTitle;
    QLabel *labelDateTime;
    QTableWidget *tableWidget;
    QLabel *ShowImageLabel;
    QPushButton *DeletePushButton;
    QPushButton *PrintPushButton;
    QPushButton *SelectPushButton;
    QPushButton *UpPagePushButton;
    QPushButton *DownPagePushButton;
    QPushButton *SelectReturnBtn;
    QLineEdit *PatientLineEdit;
    QLabel *label_8;
    QPushButton *SelectPushButton_2;

    void setupUi(QDialog *SelectDialog)
    {
        if (SelectDialog->objectName().isEmpty())
            SelectDialog->setObjectName(QString::fromUtf8("SelectDialog"));
        SelectDialog->resize(800, 480);
        SelectDialog->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        groupBox = new QGroupBox(SelectDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 800, 71));
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
        tableWidget = new QTableWidget(SelectDialog);
        if (tableWidget->columnCount() < 12)
            tableWidget->setColumnCount(12);
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font);
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font);
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font);
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 130, 641, 261));
        tableWidget->setRowCount(0);
        tableWidget->horizontalHeader()->setDefaultSectionSize(80);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(50);
        tableWidget->verticalHeader()->setStretchLastSection(false);
        ShowImageLabel = new QLabel(SelectDialog);
        ShowImageLabel->setObjectName(QString::fromUtf8("ShowImageLabel"));
        ShowImageLabel->setGeometry(QRect(670, 150, 91, 151));
        ShowImageLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        DeletePushButton = new QPushButton(SelectDialog);
        DeletePushButton->setObjectName(QString::fromUtf8("DeletePushButton"));
        DeletePushButton->setGeometry(QRect(40, 410, 91, 51));
        DeletePushButton->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        PrintPushButton = new QPushButton(SelectDialog);
        PrintPushButton->setObjectName(QString::fromUtf8("PrintPushButton"));
        PrintPushButton->setGeometry(QRect(190, 410, 91, 51));
        PrintPushButton->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        SelectPushButton = new QPushButton(SelectDialog);
        SelectPushButton->setObjectName(QString::fromUtf8("SelectPushButton"));
        SelectPushButton->setGeometry(QRect(290, 80, 91, 41));
        SelectPushButton->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        UpPagePushButton = new QPushButton(SelectDialog);
        UpPagePushButton->setObjectName(QString::fromUtf8("UpPagePushButton"));
        UpPagePushButton->setGeometry(QRect(330, 410, 91, 51));
        UpPagePushButton->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        DownPagePushButton = new QPushButton(SelectDialog);
        DownPagePushButton->setObjectName(QString::fromUtf8("DownPagePushButton"));
        DownPagePushButton->setGeometry(QRect(490, 410, 91, 51));
        DownPagePushButton->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        SelectReturnBtn = new QPushButton(SelectDialog);
        SelectReturnBtn->setObjectName(QString::fromUtf8("SelectReturnBtn"));
        SelectReturnBtn->setGeometry(QRect(630, 410, 91, 51));
        SelectReturnBtn->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        PatientLineEdit = new QLineEdit(SelectDialog);
        PatientLineEdit->setObjectName(QString::fromUtf8("PatientLineEdit"));
        PatientLineEdit->setGeometry(QRect(140, 80, 141, 41));
        label_8 = new QLabel(SelectDialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(63, 80, 71, 41));
        SelectPushButton_2 = new QPushButton(SelectDialog);
        SelectPushButton_2->setObjectName(QString::fromUtf8("SelectPushButton_2"));
        SelectPushButton_2->setGeometry(QRect(440, 80, 91, 41));
        SelectPushButton_2->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));

        retranslateUi(SelectDialog);

        QMetaObject::connectSlotsByName(SelectDialog);
    } // setupUi

    void retranslateUi(QDialog *SelectDialog)
    {
        SelectDialog->setWindowTitle(QApplication::translate("SelectDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        labelTitle->setText(QApplication::translate("SelectDialog", "\346\225\260\346\215\256\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        labelDateTime->setText(QApplication::translate("SelectDialog", "2015-08-09 14:41:32", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("SelectDialog", "\345\272\217\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("SelectDialog", "\351\241\271\347\233\256\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("SelectDialog", "\351\241\271\347\233\256", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("SelectDialog", "\351\200\232\351\201\223\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("SelectDialog", "\346\265\213\351\207\217\345\200\274", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("SelectDialog", "\347\273\223\346\236\234", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("SelectDialog", "\345\215\225\344\275\215", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("SelectDialog", "\345\217\202\350\200\203\350\214\203\345\233\264", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("SelectDialog", "\346\240\207\345\277\227", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("SelectDialog", "\346\202\243\350\200\205\347\274\226\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("SelectDialog", "\346\240\267\346\234\254ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("SelectDialog", "\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        ShowImageLabel->setText(QString());
        DeletePushButton->setText(QApplication::translate("SelectDialog", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        PrintPushButton->setText(QApplication::translate("SelectDialog", "\346\211\223\345\215\260", 0, QApplication::UnicodeUTF8));
        SelectPushButton->setText(QApplication::translate("SelectDialog", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        UpPagePushButton->setText(QApplication::translate("SelectDialog", "\344\270\212\351\241\265", 0, QApplication::UnicodeUTF8));
        DownPagePushButton->setText(QApplication::translate("SelectDialog", "\344\270\213\351\241\265", 0, QApplication::UnicodeUTF8));
        SelectReturnBtn->setText(QApplication::translate("SelectDialog", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("SelectDialog", "\346\202\243\350\200\205\347\274\226\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        SelectPushButton_2->setText(QApplication::translate("SelectDialog", "\345\205\250\351\203\250", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SelectDialog: public Ui_SelectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTDIALOG_H
