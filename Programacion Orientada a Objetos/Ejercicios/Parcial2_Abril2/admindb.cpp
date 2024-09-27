#include "admindb.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

AdminDB::AdminDB() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../Parcial2_Abril2/sqlite/base_poo.sqlite");

    if (!db.open()) {
        qDebug() << "Error: No se pudo conectar a la base de datos.";
    }
}

AdminDB::~AdminDB() {
    if (db.isOpen()) {
        db.close();
    }
}

bool AdminDB::validarUsuario(const QString &usuario, const QString &clave) {
    QSqlQuery query;
    query.prepare("SELECT * FROM usuarios WHERE usuario = :usuario AND clave = :clave");
    query.bindValue(":usuario", usuario);
    query.bindValue(":clave", clave);

    if (query.exec() && query.next()) {
        return true;
    } else {
        qDebug() << "Usuario o clave incorrectos:" << query.lastError();
        return false;
    }
}


