#ifndef EJ3CLASS_H
#define EJ3CLASS_H
#include <QString>
#include <QDate>

namespace Version{
  QString getVersion() {
      QString version = "1.0.0";
      QString lastUpdate = QDate::currentDate().toString("yyyy-MM-dd");
      return QString("Versión: %1, Última actualización: %2").arg(version, lastUpdate);
  }
}

#endif // EJ3CLASS_H
