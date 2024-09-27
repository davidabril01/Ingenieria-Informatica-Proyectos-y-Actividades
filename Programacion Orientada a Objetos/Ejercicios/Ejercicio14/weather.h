#ifndef WEATHER_H
#define WEATHER_H

#include <QObject>
#include <QNetworkAccessManager>

class Weather : public QObject
{
  Q_OBJECT

public:
  explicit Weather(QObject *parent = nullptr);
  void Temperatura();

private:
    QNetworkAccessManager *manager;
    QString respuesta="Not Set";
signals:
    void signal_temperaturaLista(QString);
private slots:
    void ConectarApi(QNetworkReply *reply);
};

#endif // WEATHER_H
