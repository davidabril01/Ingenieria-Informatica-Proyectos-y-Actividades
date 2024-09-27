// backgroundloader.cpp
#include "backgroundloader.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>

BackgroundLoader::BackgroundLoader(QObject *parent) : QObject(parent)
{

}

BackgroundLoader::BackgroundLoader(QObject *parent, QString url1) : QObject(parent), url(url1){
  loadImageFromUrl();
}

void BackgroundLoader::loadImageFromUrl() {
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onImageDownloaded(QNetworkReply*)));
    manager->get(QNetworkRequest(QUrl(url)));
}

void BackgroundLoader::onImageDownloaded(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray data = reply->readAll();
        backgroundImage.loadFromData(data);
        emit backgroundImageLoaded(backgroundImage);
    }
    reply->deleteLater();
}
