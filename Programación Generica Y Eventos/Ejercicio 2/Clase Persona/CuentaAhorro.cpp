#include "CuentaAhorro.h"

// Constructor por defecto
CuentaAhorro::CuentaAhorro() : CuentaBancaria(), tasaInteres(0.0) {}

// Constructor parametrizado
CuentaAhorro::CuentaAhorro(double saldo, const string& numeroDeCuenta, double tasaInteres)
    : CuentaBancaria(saldo, numeroDeCuenta), tasaInteres(tasaInteres) {}

// Calcular intereses
void CuentaAhorro::calcularIntereses() {
    double intereses = getSaldo() * tasaInteres;
    setSaldo(getSaldo() + intereses);
}

// Cobrar comisiones
void CuentaAhorro::cobrarComisiones(double monto) {
    setSaldo(getSaldo() - monto);
}

// Getter para la tasa de interés
double CuentaAhorro::getTasaInteres() const {
    return tasaInteres;
}

// Setter para la tasa de interés
void CuentaAhorro::setTasaInteres(double tasaInteres) {
    this->tasaInteres = tasaInteres;
}
