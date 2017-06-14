#ifndef CONNECT_SQL_H
#define CONNECT_SQL_H

//#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

extern QSqlDatabase db;

static bool createConnection(QSqlDatabase & db)
{

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("pct.db");
    if (!db.open())
    {
        qDebug() << "open Database error";
        return false;
    }
    qDebug() << "open Database success";
    return true;
}



#endif // CONNECT_SQL_H
