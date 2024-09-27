#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QUrl>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
  Q_OBJECT

public:
  Login(QWidget *parent = nullptr);
  ~Login();

private:
  Ui::Login *ui;

signals:
    void enterPressed();

protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void AbrirForm();
};
#endif // LOGIN_H
