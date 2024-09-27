#ifndef LOGIN_H
#define LOGIN_H


#include "formulario.h"
#include "weather.h"
#include "backgroundloader.h"
#include <QMainWindow>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow {
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
  void loadImageFromUrl(const QString &url);
    ~Login();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private slots:
    void AbrirForm();
    void slot_publicarClima(QString);
     void onBackgroundImageLoaded(const QImage &image);

private:
    Ui::Login *ui;
    Formulario *formulario;
    Weather *clima;
    QImage backgroundImage;
    BackgroundLoader *backgroundLoader;
signals:
    void enterPressed();
};

#endif // LOGIN_H
