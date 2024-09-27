#include "login.h"
#include "formulario.h"
#include "ui_login.h"
#include <QApplication>

Login::Login(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::Login)
{
  ui->setupUi(this);

  ui->LE_Contra->setEchoMode(QLineEdit::Password);

  connect(ui->pushButton, SIGNAL(pressed()), this, SLOT(AbrirForm()), Qt::UniqueConnection);
  connect(this, SIGNAL(enterPressed()), this, SLOT(AbrirForm()), Qt::UniqueConnection);
}

void Login::AbrirForm()
{
  if(ui->LE_Usuario->text() == "admin" && ui->LE_Contra->text() == "1111"){
      formulario = new Formulario();
      formulario->show();
      this->hide();
    }else{
      ui->LE_Contra->setText("");
    }
}

Login::~Login()
{
  delete ui;
}

void Login::keyPressEvent(QKeyEvent *event)
{
      if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
          emit enterPressed();
      } else {
          QWidget::keyPressEvent(event);
      }
}
