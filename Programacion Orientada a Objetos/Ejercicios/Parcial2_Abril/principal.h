#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QVector>
#include "rectangulo.h"
#include "admindb.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);

    // Método para cargar los rectángulos desde la base de datos
    void CargarRectangulos();

    // Método para dibujar los rectángulos
    void paintEvent(QPaintEvent *event);

    ~Principal();

private:
    Ui::Principal *ui;
    AdminDB *adminDB;
    QVector<Rectangulo *> Rectangulos;
};
#endif // PRINCIPAL_H
