#include <QCoreApplication>
#include <QDebug>
#include "ej3class.h"

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  qDebug() << Version::getVersion();

  return a.exec();
}
