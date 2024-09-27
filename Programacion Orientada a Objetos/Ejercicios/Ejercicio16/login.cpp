#include "login.h"
#include "ui_login.h"
#include <QEventLoop>

Login::Login(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::Login)
{
  ui->setupUi(this);

  ui->LE_Contra->setEchoMode(QLineEdit::Password);

  connect(ui->PB_Iniciar, SIGNAL(pressed()), this, SLOT(AbrirForm()), Qt::UniqueConnection);
  connect(this, SIGNAL(enterPressed()), this,  SLOT(AbrirForm()), Qt::UniqueConnection);
}

void Login::keyPressEvent(QKeyEvent *event)
{
      if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
          emit enterPressed();
      } else {
          QWidget::keyPressEvent(event);
      }
}

void Login::AbrirForm()
{
    QNetworkAccessManager manager;
    QUrl url("http://127.0.0.1:8000/validar_usuario/");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // Crear el objeto JSON con los datos del usuario y la contraseña
    QJsonObject jsonObject;
    jsonObject["usuario"] = ui->LE_Usuario->text();
    jsonObject["clave"] = ui->LE_Contra->text();
    QJsonDocument doc(jsonObject);
    QByteArray postData = doc.toJson();

    // Realizar la solicitud POST
    QNetworkReply* reply = manager.post(request, postData);

    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, [&]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray response = reply->readAll();
            QString respuesta = QString::fromUtf8(response);

            // Verificar la respuesta del servidor
            if (respuesta != "\"denegado\"") {
                qDebug() << "Inicio de sesión correcto para usuario:" << respuesta;
            } else {
                qDebug() << "Usuario o contraseña incorrectos";
            }
        } else {
            qDebug() << "Error:" << reply->errorString();
        }

        reply->deleteLater();
        loop.quit();
    });

    loop.exec();
}


Login::~Login()
{
  delete ui;
}
