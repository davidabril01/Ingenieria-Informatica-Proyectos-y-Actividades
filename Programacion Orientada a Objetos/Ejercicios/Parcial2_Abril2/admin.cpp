#include "admin.h"

Admin::Admin() {
    adminDB = new AdminDB();
    login = new Login(adminDB);
    ventana = new Ventana();

    QObject::connect(login, &Login::signal_usuarioValidado, this, &Admin::onUsuarioValidado);

    login->show();
}

Admin::~Admin() {
    delete login;
    delete ventana;
    delete adminDB;
}

void Admin::onUsuarioValidado(const QString &usuario) {
    login->hide();
    ventana->show();
}
