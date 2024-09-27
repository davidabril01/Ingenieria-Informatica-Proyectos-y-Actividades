#include "login.h"
#include "ui_login.h"

Login::Login(AdminDB *db, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login),
    adminDB(db)
{
    ui->setupUi(this);
}

Login::~Login() {
    delete ui;
}

void Login::on_pbIngresar_clicked() {
    QString usuario = ui->leUsuario->text();
    QString clave = ui->leClave->text();

    if (adminDB->validarUsuario(usuario, clave)) {
        emit signal_usuarioValidado(usuario);
    } else {
        ui->leClave->clear();
    }
}
