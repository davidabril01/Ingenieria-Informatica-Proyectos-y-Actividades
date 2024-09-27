#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QLabel label("Hello world");
    QWidget widget;
    QPushButton button("Botón");
    QLineEdit lineEdit;

    label.setGeometry(100, 100, 200, 50);
    widget.setGeometry(350, 100, 200, 150);
    button.setGeometry(600, 100, 200, 50);
    lineEdit.setGeometry(850, 100, 200, 50);

    label.show();
    widget.show();
    button.show();
    lineEdit.show();

    return app.exec();
}
