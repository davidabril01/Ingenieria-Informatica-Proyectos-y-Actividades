#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "admindb.h"

namespace Ui {
class Login;
}

class Login : public QMainWindow {
    Q_OBJECT

public:
    Login(AdminDB *db, QWidget *parent = nullptr);
    ~Login();

signals:
    void signal_usuarioValidado(QString usuario);

private slots:
    void on_pbIngresar_clicked();

private:
    Ui::Login *ui;
    AdminDB *adminDB;
};

#endif // LOGIN_H
