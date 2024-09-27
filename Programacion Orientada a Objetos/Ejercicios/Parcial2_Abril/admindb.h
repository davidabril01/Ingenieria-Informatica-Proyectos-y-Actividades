#ifndef ADMINDB_H
#define ADMINDB_H

#include <QObject>
#include <QSqlDatabase>
#include <QString>

class AdminDB : public QObject
{
    Q_OBJECT
public:
    explicit AdminDB(QObject *parent = nullptr);

    // Método para establecer la conexión con la base de datos
    bool conectar(QString archivoSqlite);

    // Método para obtener el objeto QSqlDatabase
    QSqlDatabase getDB();

private:
    QSqlDatabase db;

};

#endif // ADMINDB_H
