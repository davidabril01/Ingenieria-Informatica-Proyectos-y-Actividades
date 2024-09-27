#ifndef CUENTAAGORRO_H
#define CUENTAAGORRO_H

#include "CuentaBancaria.h"

class CuentaAhorro : public CuentaBancaria {
private:
    double tasaInteres;  // Tasa de interés para la cuenta de ahorro

public:
    // Constructores
    CuentaAhorro();
    CuentaAhorro(double saldo, const string& numeroDeCuenta, double tasaInteres);

    // Métodos para calcular intereses y cobrar comisiones
    void calcularIntereses();  // Calcula los intereses basados en la tasa de interés
    void cobrarComisiones(double monto);  // Cobra una comisión de la cuenta

    // Getter y Setter para la tasa de interés
    double getTasaInteres() const;
    void setTasaInteres(double tasaInteres);
};

#endif // CUENTAAGORRO_H
