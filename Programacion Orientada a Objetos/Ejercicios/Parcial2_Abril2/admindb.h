#ifndef ADMINDB_H
#define ADMINDB_H

#include <QObject>
#include <QSqlDatabase>
#include <QString>

class AdminDB : public QObject {
    Q_OBJECT

public:
    AdminDB();
    ~AdminDB();
    bool validarUsuario(const QString &usuario, const QString &clave);

private:
    QSqlDatabase db;
};

#endif // ADMINDB_H
