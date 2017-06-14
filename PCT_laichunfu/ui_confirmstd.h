/********************************************************************************
** Form generated from reading UI file 'confirmstd.ui'
**
** Created: Wed Dec 23 21:30:12 2015
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRMSTD_H
#define UI_CONFIRMSTD_H

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

class Ui_ConfirmStd
{
public:
    QGroupBox *groupBox;
    QLabel *labelTitle;
    QLabel *labelDateTime;
    QTableWidget *AnalysisTableWidget;
    QLabel *ShowImageLabel;
    QLabel *label_7;
    QLineEdit *TestValueLineEdit;
    QLineEdit *ResultLineEdit;
    QLabel *label_6;
    QLabel *PromptLabel;
    QLabel *label_5;
    QPushButton *expReturnBtn;
    QPushButton *CheckPushButton;

    void setupUi(QDialog *ConfirmStd)
    {
        if (ConfirmStd->objectName().isEmpty())
            ConfirmStd->setObjectName(QString::fromUtf8("ConfirmStd"));
        ConfirmStd->resize(800, 480);
        groupBox = new QGroupBox(ConfirmStd);
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
        AnalysisTableWidget = new QTableWidget(ConfirmStd);
        if (AnalysisTableWidget->columnCount() < 5)
            AnalysisTableWidget->setColumnCount(5);
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
        AnalysisTableWidget->setObjectName(QString::fromUtf8("AnalysisTableWidget"));
        AnalysisTableWidget->setGeometry(QRect(260, 90, 521, 271));
        AnalysisTableWidget->setSortingEnabled(false);
        AnalysisTableWidget->setRowCount(0);
        AnalysisTableWidget->setColumnCount(5);
        AnalysisTableWidget->horizontalHeader()->setVisible(true);
        AnalysisTableWidget->horizontalHeader()->setDefaultSectionSize(73);
        AnalysisTableWidget->horizontalHeader()->setHighlightSections(false);
        AnalysisTableWidget->horizontalHeader()->setStretchLastSection(true);
        AnalysisTableWidget->verticalHeader()->setVisible(false);
        AnalysisTableWidget->verticalHeader()->setDefaultSectionSize(30);
        AnalysisTableWidget->verticalHeader()->setHighlightSections(true);
        ShowImageLabel = new QLabel(ConfirmStd);
        ShowImageLabel->setObjectName(QString::fromUtf8("ShowImageLabel"));
        ShowImageLabel->setGeometry(QRect(20, 110, 101, 181));
        ShowImageLabel->setStyleSheet(QString::fromUtf8("background-image: url();\n"
"background-color: rgb(255, 255, 255);"));
        label_7 = new QLabel(ConfirmStd);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(130, 240, 31, 16));
        TestValueLineEdit = new QLineEdit(ConfirmStd);
        TestValueLineEdit->setObjectName(QString::fromUtf8("TestValueLineEdit"));
        TestValueLineEdit->setGeometry(QRect(180, 160, 41, 20));
        ResultLineEdit = new QLineEdit(ConfirmStd);
        ResultLineEdit->setObjectName(QString::fromUtf8("ResultLineEdit"));
        ResultLineEdit->setGeometry(QRect(180, 210, 41, 20));
        label_6 = new QLabel(ConfirmStd);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(130, 210, 41, 16));
        PromptLabel = new QLabel(ConfirmStd);
        PromptLabel->setObjectName(QString::fromUtf8("PromptLabel"));
        PromptLabel->setGeometry(QRect(190, 240, 51, 21));
        label_5 = new QLabel(ConfirmStd);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(130, 160, 51, 20));
        expReturnBtn = new QPushButton(ConfirmStd);
        expReturnBtn->setObjectName(QString::fromUtf8("expReturnBtn"));
        expReturnBtn->setGeometry(QRect(650, 390, 121, 51));
        expReturnBtn->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));
        CheckPushButton = new QPushButton(ConfirmStd);
        CheckPushButton->setObjectName(QString::fromUtf8("CheckPushButton"));
        CheckPushButton->setGeometry(QRect(80, 390, 111, 51));
        CheckPushButton->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\347\273\206\351\273\221\";"));

        retranslateUi(ConfirmStd);

        QMetaObject::connectSlotsByName(ConfirmStd);
    } // setupUi

    void retranslateUi(QDialog *ConfirmStd)
    {
        ConfirmStd->setWindowTitle(QApplication::translate("ConfirmStd", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        labelTitle->setText(QApplication::translate("ConfirmStd", "\345\256\232\346\240\207\347\225\214\351\235\242", 0, QApplication::UnicodeUTF8));
        labelDateTime->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = AnalysisTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ConfirmStd", "\351\241\271\347\233\256", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = AnalysisTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ConfirmStd", "\347\273\223\346\236\234", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = AnalysisTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ConfirmStd", "\346\265\213\350\257\225\345\200\274", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = AnalysisTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ConfirmStd", "\346\240\267\346\234\254ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = AnalysisTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("ConfirmStd", "\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        ShowImageLabel->setText(QString());
        label_7->setText(QApplication::translate("ConfirmStd", "\346\217\220\347\244\272\357\274\232", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ConfirmStd", "\347\273\223\346\236\234\357\274\232", 0, QApplication::UnicodeUTF8));
        PromptLabel->setText(QString());
        label_5->setText(QApplication::translate("ConfirmStd", "\346\265\213\351\207\217\345\200\274\357\274\232", 0, QApplication::UnicodeUTF8));
        expReturnBtn->setText(QApplication::translate("ConfirmStd", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        CheckPushButton->setText(QApplication::translate("ConfirmStd", "\346\265\213\351\207\217", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConfirmStd: public Ui_ConfirmStd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRMSTD_H
