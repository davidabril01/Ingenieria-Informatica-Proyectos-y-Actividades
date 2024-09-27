#include "admindb.h"

#include <QSqlQuery>
#include <QVariant>
#include <QDebug>

AdminDB::AdminDB(QObject *parent) : QObject(parent)
{
    // Configuración de la base de datos SQLite
    db = QSqlDatabase::addDatabase("QSQLITE");
}

bool AdminDB::conectar(QString archivoSqlite)
{
    // Establecer el nombre del archivo de la base de datos
    db.setDatabaseName(archivoSqlite);

    // Intentar abrir la base de datos
    if (db.open())
        return true;

    return false;
}

QSqlDatabase AdminDB::getDB()
{
    return db;
}
