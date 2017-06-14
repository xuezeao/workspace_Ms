#include "mainwidget.h"
#include "connect_sql.h"
#include <QApplication>
#include <QTextCodec>
#include <input/myinputpanelcontext.h>

QSqlDatabase db;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec * codec = QTextCodec::codecForName("UTF-8");
    //QTextCodec * codec = QTextCodec::codecForName("GBK");
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    MyInputPanelContext *ic = new MyInputPanelContext;
    a.setInputContext(ic);
    createConnection(db);
    MainWidget w;
    w.show();
    return a.exec();
}
