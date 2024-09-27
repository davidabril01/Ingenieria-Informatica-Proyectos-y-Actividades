#include "CuentaCorriente.h"

// Constructor por defecto
CuentaCorriente::CuentaCorriente() : CuentaBancaria(), comisionMantenimiento(0.0) {}

// Constructor parametrizado
CuentaCorriente::CuentaCorriente(double saldo, const string& numeroDeCuenta, double comisionMantenimiento)
    : CuentaBancaria(saldo, numeroDeCuenta), comisionMantenimiento(comisionMantenimiento) {}

// Cobrar comisiones
void CuentaCorriente::cobrarComisiones() {
    setSaldo(getSaldo() - comisionMantenimiento);
}

// Getter para la comisión de mantenimiento
double CuentaCorriente::getComisionMantenimiento() const {
    return comisionMantenimiento;
}

// Setter para la comisión de mantenimiento
void CuentaCorriente::setComisionMantenimiento(double comisionMantenimiento) {
    this->comisionMantenimiento = comisionMantenimiento;
}
