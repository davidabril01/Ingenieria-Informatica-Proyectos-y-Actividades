#include "admindb.h"

#include <QSqlQuery>
#include <QVariant>
#include <QDebug>

AdminDB::AdminDB(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase( "QSQLITE" );
}


bool AdminDB::conectar( QString archivoSqlite )  {
    db.setDatabaseName( archivoSqlite );

    if( db.open() )
        return true;

    return false;
}

QSqlDatabase AdminDB::getDB()  {
    return db;
}



