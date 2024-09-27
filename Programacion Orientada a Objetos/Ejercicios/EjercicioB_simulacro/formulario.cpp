#include "formulario.h"
#include "ui_formulario.h"
#include <iostream>
#include <QDebug>

Formulario::Formulario(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::Formulario)
{
  ui->setupUi(this);

  connect(ui->pushButton_Agregar, SIGNAL(pressed()), this, SLOT(on_pushButton_Agregar_pressed()), Qt::UniqueConnection);
  connect(ui->pushButton_VerStock, SIGNAL(pressed()), this, SLOT(on_pushButton_VerStock_pressed()), Qt::UniqueConnection);

}

void Formulario::AgregarStock(Instrumento* inst) {
    Stock.append(inst);
}

Formulario::~Formulario()
{
  for (Instrumento* inst : Stock) {
          delete inst;
      }
  delete ui;
}

void Formulario::on_pushButton_Agregar_pressed() {
    int index = ui->comboBox->currentIndex();

    QString marca = ui->LE_Marca->text();
    double precio = ui->LE_Precio->text().toDouble();
    Instrumento* nuevoInstrumento = nullptr;

    if (index == 0) {
        int cuerdas = ui->LE_CantCuer->text().toInt();
        nuevoInstrumento = new Guitarra(marca, precio, cuerdas);
    } else if (index == 1) {
        QString metal = ui->LE_Metal->text();
        nuevoInstrumento = new Viento(marca, precio, metal);
    } else if (index == 2) {
        int teclas = ui->LE_CantTecl->text().toInt();
        nuevoInstrumento = new Teclado(marca, precio, teclas);
    }

    if (nuevoInstrumento) {
        AgregarStock(nuevoInstrumento);
        qDebug() << "Instrumento agregado: ";
        nuevoInstrumento->afinar();
    }
}
void Formulario::on_pushButton_VerStock_pressed() {
    for (Instrumento* inst : Stock) {
        if (dynamic_cast<Guitarra*>(inst)) {
            Guitarra* guitarra = dynamic_cast<Guitarra*>(inst);
            qDebug() << "Guitarra - Marca:" << guitarra->getMarca()
                     << ", Precio:" << guitarra->getPrecio()
                     << ", Cuerdas:" << guitarra->getCantidadDeCuerdas();
        } else if (dynamic_cast<Viento*>(inst)) {
            Viento* viento = dynamic_cast<Viento*>(inst);
            qDebug() << "Viento - Marca:" << viento->getMarca()
                     << ", Precio:" << viento->getPrecio()
                     << ", Metal usado:" << viento->getMetalUsado();
        } else if (dynamic_cast<Teclado*>(inst)) {
            Teclado* teclado = dynamic_cast<Teclado*>(inst);
            qDebug() << "Teclado - Marca:" << teclado->getMarca()
                     << ", Precio:" << teclado->getPrecio()
                     << ", Teclas:" << teclado->getCantidadDeTeclas();
        }
    }
}
