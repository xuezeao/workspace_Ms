/********************************************************************************
** Form generated from reading UI file 'managedialog.ui'
**
** Created: Wed Dec 23 21:30:12 2015
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEDIALOG_H
#define UI_MANAGEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_ManageDialog
{
public:
    QGroupBox *groupBox;
    QLabel *labelTitle;
    QLabel *labelDateTime;
    QTableWidget *tableWidget;
    QListView *listView;
    QPushButton *DeletePushButton;
    QPushButton *ImportPushButton;
    QPushButton *manageReturnBtn;

    void setupUi(QDialog *ManageDialog)
    {
        if (ManageDialog->objectName().isEmpty())
            ManageDialog->setObjectName(QString::fromUtf8("ManageDialog"));
        ManageDialog->resize(800, 480);
        groupBox = new QGroupBox(ManageDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(-10, 0, 811, 71));
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
        tableWidget = new QTableWidget(ManageDialog);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QFont font;
        font.setPointSize(12);
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
        if (tableWidget->rowCount() < 5)
            tableWidget->setRowCount(5);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(20, 90, 501, 291));
        tableWidget->setRowCount(5);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(50);
        tableWidget->verticalHeader()->setStretchLastSection(false);
        listView = new QListView(ManageDialog);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(540, 90, 211, 291));
        DeletePushButton = new QPushButton(ManageDialog);
        DeletePushButton->setObjectName(QString::fromUtf8("DeletePushButton"));
        DeletePushButton->setGeometry(QRect(120, 420, 111, 51));
        DeletePushButton->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        ImportPushButton = new QPushButton(ManageDialog);
        ImportPushButton->setObjectName(QString::fromUtf8("ImportPushButton"));
        ImportPushButton->setGeometry(QRect(320, 420, 111, 51));
        ImportPushButton->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        manageReturnBtn = new QPushButton(ManageDialog);
        manageReturnBtn->setObjectName(QString::fromUtf8("manageReturnBtn"));
        manageReturnBtn->setGeometry(QRect(530, 420, 111, 51));
        manageReturnBtn->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));

        retranslateUi(ManageDialog);

        QMetaObject::connectSlotsByName(ManageDialog);
    } // setupUi

    void retranslateUi(QDialog *ManageDialog)
    {
        ManageDialog->setWindowTitle(QApplication::translate("ManageDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        labelTitle->setText(QApplication::translate("ManageDialog", "\350\257\225\345\211\202\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        labelDateTime->setText(QApplication::translate("ManageDialog", "2015-08-09 14:41:32", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ManageDialog", "\345\272\217\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ManageDialog", "\350\257\225\345\211\202\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ManageDialog", "\347\224\237\344\272\247\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ManageDialog", "\346\234\211\346\225\210\346\234\237\350\207\263", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("ManageDialog", "\350\257\225\345\211\202ID", 0, QApplication::UnicodeUTF8));
        DeletePushButton->setText(QApplication::translate("ManageDialog", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        ImportPushButton->setText(QApplication::translate("ManageDialog", "\345\257\274\345\205\245", 0, QApplication::UnicodeUTF8));
        manageReturnBtn->setText(QApplication::translate("ManageDialog", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ManageDialog: public Ui_ManageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEDIALOG_H
