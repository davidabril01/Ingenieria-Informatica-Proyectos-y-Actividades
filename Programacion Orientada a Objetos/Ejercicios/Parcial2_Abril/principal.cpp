#include "principal.h"
#include "ui_principal.h"
#include <QSqlQuery>
#include <QDebug>
#include <QPainter>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);

    // Establecer el tamaño de la ventana principal
    resize(300, 300);

    // Crear una instancia de AdminDB para administrar la base de datos
    adminDB = new AdminDB(this);

    // Conectar a la base de datos y cargar los rectángulos
    qDebug() << "La base se abrió correctamente" << adminDB->conectar("../Parcial2_Abril/sqlite/rectangles.sqlite");
    CargarRectangulos();
}

void Principal::CargarRectangulos()
{
    // Obtener la base de datos
    QSqlDatabase db = adminDB->getDB();

    // Verificar que la base de datos se abrió correctamente
    if (db.open()) {
        // Ejecutar la consulta para obtener los rectángulos
        QSqlQuery query = db.exec("SELECT x, y, ancho, alto FROM rectangulos");

        // Recorrer los resultados de la consulta
        while (query.next()) {
            // Leer las coordenadas y dimensiones del rectángulo desde la consulta
            int x = query.value(0).toInt();
            int y = query.value(1).toInt();
            int ancho = query.value(2).toInt();
            int alto = query.value(3).toInt();

            // Crear un nuevo rectángulo y agregarlo al vector de rectángulos
            Rectangulo *nuevoRectangulo = new Rectangulo(x, y, ancho, alto);
            Rectangulos.append(nuevoRectangulo);
        }

        // Verificar si no se encontraron registros en la tabla de rectángulos
        if (Rectangulos.isEmpty()) {
            qDebug() << "No se encontraron registros en la tabla rectangulos.";
        }
    }
}

void Principal::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event);

    QPainter painter(this);

    // Iterar sobre todos los rectángulos en el QVector
    for (Rectangulo *rectangulo : Rectangulos) {
        // Obtener las coordenadas y dimensiones del rectángulo
        int x = rectangulo->getX();
        int y = rectangulo->getY();
        int ancho = rectangulo->getAncho();
        int alto = rectangulo->getAlto();

        // Dibujar el rectángulo
        painter.drawRect(x, y, ancho, alto);
    }
}

Principal::~Principal()
{
    // Liberar la memoria de la interfaz de usuario
    delete ui;
}

