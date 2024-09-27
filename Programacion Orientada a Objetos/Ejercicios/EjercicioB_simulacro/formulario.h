#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QMainWindow>
#include <QVector>
#include "instrumento.h"
#include "guitarra.h"
#include "viento.h"
#include "teclado.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Formulario; }
QT_END_NAMESPACE

class Formulario : public QMainWindow
{
  Q_OBJECT

public:
  Formulario(QWidget *parent = nullptr);
  void AgregarStock(Instrumento* inst);
  ~Formulario();

private:
  Ui::Formulario *ui;
  QVector< Instrumento * > Stock;

private slots:
    void on_pushButton_Agregar_pressed();
    void on_pushButton_VerStock_pressed();
};
#endif // FORMULARIO_H
