// backgroundloader.h
#ifndef BACKGROUNDLOADER_H
#define BACKGROUNDLOADER_H

#include <QObject>
#include <QImage>
#include <QNetworkReply>

class BackgroundLoader : public QObject
{
    Q_OBJECT
public:
  explicit BackgroundLoader(QObject *parent = nullptr);
  explicit BackgroundLoader(QObject *parent = nullptr, QString url1 ="");

public slots:
    void loadImageFromUrl();

signals:
    void backgroundImageLoaded(const QImage &image);

private slots:
    void onImageDownloaded(QNetworkReply *reply);

private:
    QImage backgroundImage;
    QString url;
};

#endif // BACKGROUNDLOADER_H
