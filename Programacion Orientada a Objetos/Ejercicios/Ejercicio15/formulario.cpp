#include "formulario.h"
#include "ui_formulario.h"

#include <QMessageBox>

Formulario::Formulario(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Formulario)
{
  ui->setupUi(this);
  captchaNumber = qrand() % 10000 + 1;
  ui->L_Captcha->setText(QString::number(captchaNumber));

  connect(ui->PB_Enviar, SIGNAL(pressed()), this, SLOT(EnviarForm()), Qt::UniqueConnection);
}

Formulario::~Formulario()
{
  delete ui;
}

void Formulario::EnviarForm()
{
  if (ui->LE_Legajo->text().isEmpty() || ui->LE_Nombre->text().isEmpty() || ui->LE_Apellido->text().isEmpty()) {
      QMessageBox::critical(this, "Error", "Por favor, complete todos los campos.");
      return;
    }else if (ui->LE_Captcha->text().toInt() != captchaNumber) {
      QMessageBox::critical(this, "Error", "El captcha ingresado es incorrecto. Por favor, inténtelo de nuevo.");
    }else{
      this->close();
    }
}
