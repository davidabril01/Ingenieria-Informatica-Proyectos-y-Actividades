#include "principal.h"
#include "ui_principal.h"
#include "admindb.h"
#include <QSqlQuery>
#include <QDebug>
#include <QPainter>

Principal::Principal(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::Principal)
{
  ui->setupUi(this);

  adminDB = new AdminDB( this );
  qDebug() << "La base se abrio bien" << adminDB->conectar( "../EjercicioA_simulacro/sqlite/db.sqlite");

  Linea linea;
  CargarRegistro(linea);
  m_linea = linea;
}

void Principal::CargarRegistro(Linea &linea)
{
    QSqlDatabase db = adminDB->getDB();
    if (db.open()) {
        QSqlQuery query = db.exec("SELECT x_inicial, y_inicial, x_final, y_final FROM lineas");

        if (query.next()) {
            int x_inicial = query.value(0).toInt();
            int y_inicial = query.value(1).toInt();
            int x_final = query.value(2).toInt();
            int y_final = query.value(3).toInt();

            linea.set_x_inicial(x_inicial);
            linea.set_y_inicial(y_inicial);
            linea.set_x_final(x_final);
            linea.set_y_final(y_final);
        } else {
            qDebug() << "No se encontraron registros en la tabla lineas.";
        }
    }
}

void Principal::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event);

    // Dibujar la línea
    QPainter painter(this);
    painter.drawLine(m_linea.get_x_inicial(), m_linea.get_y_inicial(),
                     m_linea.get_x_final(), m_linea.get_y_final());
}

Principal::~Principal()
{
  delete ui;
}
