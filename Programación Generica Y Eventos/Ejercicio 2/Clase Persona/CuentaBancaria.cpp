#include "CuentaBancaria.h"

// Constructor por defecto
CuentaBancaria::CuentaBancaria() : Saldo(0.0), NumeroDeCuenta("") {}

// Constructor parametrizado
CuentaBancaria::CuentaBancaria(double saldo, const string& numeroDeCuenta)
    : Saldo(saldo), NumeroDeCuenta(numeroDeCuenta) {}

// Destructor
CuentaBancaria::~CuentaBancaria() {
    // No es necesario hacer nada en el destructor por ahora, pero debe ser definido
}

// Getters
double CuentaBancaria::getSaldo() const {
    return Saldo;
}

string CuentaBancaria::getNumeroDeCuenta() const {
    return NumeroDeCuenta;
}

// Setters
void CuentaBancaria::setSaldo(double saldo) {
    Saldo = saldo;
}

void CuentaBancaria::setNumeroDeCuenta(const string& numeroDeCuenta) {
    NumeroDeCuenta = numeroDeCuenta;
}
