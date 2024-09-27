#include <QApplication>
#include <QLabel>
#include <QImage>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QLabel label;

    QImage image("C:/Users/David/OneDrive - UNIVERSIDAD BLAS PASCAL/Escritorio/Proyects/Proyects/Ingenieria Informatica Proyectos y Actividades/Programacion Orientada a Objetos/Ejercicios/Ejercicio12/imagenEj12.jpg");
    if (image.isNull()) {
        return -1;
    }

    label.setPixmap(QPixmap::fromImage(image).scaled(label.size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    label.setAlignment(Qt::AlignCenter);

    label.show();

    return app.exec();
}
