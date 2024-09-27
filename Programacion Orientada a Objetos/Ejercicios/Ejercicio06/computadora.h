#ifndef COMPUTADORA_H
#define COMPUTADORA_H
#include <QString>
using namespace std;


class Computadora
{
public:
  Computadora(QString procesador, QString marca, int gbRam);

  int getRam() const{
    return GbRam;
  }

  QString getProcesador() const{
    return Procesador;
  }

  QString getMarca() const{
    return Marca;
  }

  friend ostream& operator<<(ostream &os, const Computadora &computadora);
private:
  QString Procesador, Marca;
  int GbRam;
};

#endif // COMPUTADORA_H
