#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include "linea.h"
#include "admindb.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
  Q_OBJECT

public:
  Principal(QWidget *parent = nullptr);
  void CargarRegistro(Linea &linea);
  void paintEvent(QPaintEvent *event);
  ~Principal();

private:
  Ui::Principal *ui;
  AdminDB * adminDB;
  Linea m_linea;
};
#endif // PRINCIPAL_H
