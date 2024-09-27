#include "login.h"

#include <QPainter>
#include <QWidget>
#include <ui_login.h>



Login::Login(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::Login),
      backgroundLoader(new BackgroundLoader(this, "https://1.bp.blogspot.com/-zKX8CREi3QY/T2OMZgW3s6I/AAAAAAAAWzg/5sFH754c6sw/s1600/Los-mas-Hermosos-Paisajes-Naturales_04.jpg"))
{
    ui->setupUi(this);


    clima = new Weather();
    clima->Temperatura();
    ui->LE_Contra->setEchoMode(QLineEdit::Password);

    connect(ui->PB_Login, SIGNAL(pressed()), this, SLOT(AbrirForm()), Qt::UniqueConnection);
    connect(this, SIGNAL(enterPressed()), this, SLOT(AbrirForm()), Qt::UniqueConnection);
    connect(this->clima, SIGNAL(signal_temperaturaLista(QString)), this, SLOT(slot_publicarClima(QString)));
    connect(backgroundLoader, SIGNAL(backgroundImageLoaded(QImage)), this, SLOT(onBackgroundImageLoaded(QImage)));
}

void Login::onBackgroundImageLoaded(const QImage &image) {
    backgroundImage = image;
    update();
}

void Login::AbrirForm() {
  if (ui->LE_Usuario->text() == "admin" && ui->LE_Contra->text() == "1111") {
      formulario = new Formulario();
      formulario->show();
      this->hide();
    } else {
      ui->LE_Contra->setText("");
    }
}

void Login::slot_publicarClima(QString clima) {
  this->ui->L_Temp->setText(clima);
}

Login::~Login() {
    delete ui;
}

void Login::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
        emit enterPressed();
    } else {
        QWidget::keyPressEvent(event);
    }
}

void Login::paintEvent(QPaintEvent *event) {
  QWidget::paintEvent(event);
  QPainter painter(this);
  painter.fillRect(rect(), Qt::white);
  if (!backgroundImage.isNull()) {
      QRect targetRect = backgroundImage.rect().translated((width() - backgroundImage.width()) / 2, (height() - backgroundImage.height()) / 2);
      painter.drawImage(targetRect, backgroundImage);
    }
}

