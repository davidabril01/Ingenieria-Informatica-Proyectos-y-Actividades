#include "weather.h"
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QUrlQuery>
#include <QSslSocket>


Weather::Weather(QObject *parent) : QObject(parent), manager(new QNetworkAccessManager(this)) {
  connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(ConectarApi(QNetworkReply*)));
}

void Weather::Temperatura()
{
  QUrl url("http://api.weatherapi.com/v1/current.json?key=cdef2dc678ff423fa28134812241206&q=Cordoba&aqi=no");
  QNetworkRequest request(url);
  manager->get(request);
}

void Weather::ConectarApi(QNetworkReply *reply)
{
  if (reply->error() == QNetworkReply::NoError) {
      QByteArray response_data = reply->readAll();
      QJsonDocument json = QJsonDocument::fromJson(response_data);
      QJsonObject object = json.object();

      //Temperatura
      QJsonObject current = object["current"].toObject();
      double temp = current["temp_c"].toDouble();

      respuesta = QString::number(temp)+"°C";

      qDebug() << respuesta;
      emit signal_temperaturaLista(respuesta);

  }
  else {
      qDebug() << "Error:" << reply->errorString();
  }
  reply->deleteLater();
}
