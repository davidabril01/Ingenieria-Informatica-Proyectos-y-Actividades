#include <QApplication>
#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QSslConfiguration>

class BackgroundWidget : public QWidget {
public:
    BackgroundWidget(QWidget *parent = nullptr) : QWidget(parent) {
        setMinimumSize(400, 300); // Tamaño mínimo del widget
        setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding); // Widget expandible
        loadImageFromUrl("https://apod.nasa.gov/apod/image/2405/WrightDobbs_Georgia_Aurora_2.jpg");
    }

    void loadImageFromUrl(const QString &url) {
        QNetworkAccessManager *manager = new QNetworkAccessManager(this);
        connect(manager, &QNetworkAccessManager::finished, this, &BackgroundWidget::onImageDownloaded);
        manager->get(QNetworkRequest(QUrl(url)));
    }

    void onImageDownloaded(QNetworkReply *reply) {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray data = reply->readAll();
            backgroundImage.loadFromData(data);
            update(); // Actualizar widget para reflejar la nueva imagen
        }
        reply->deleteLater();
    }

protected:
    void paintEvent(QPaintEvent *event) override {
        QWidget::paintEvent(event);
        QPainter painter(this);
        painter.fillRect(rect(), Qt::white); // Rellenar el fondo con blanco
        if (!backgroundImage.isNull()) {
            // Dibujar la imagen centrada y manteniendo el aspecto
            QRect targetRect = backgroundImage.rect().translated((width() - backgroundImage.width()) / 2, (height() - backgroundImage.height()) / 2);
            painter.drawImage(targetRect, backgroundImage);
        }
    }

private:
    QImage backgroundImage;
};

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    BackgroundWidget w;
    w.show();
    return a.exec();
}
