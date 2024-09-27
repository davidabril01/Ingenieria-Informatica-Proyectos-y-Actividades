#include "login.h"

#include <QApplication>
#include <QLoggingCategory>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

   QLoggingCategory::setFilterRules(QStringLiteral("qt.network.ssl.warning=true"));
  Login w;
  w.show();
  return a.exec();
}
