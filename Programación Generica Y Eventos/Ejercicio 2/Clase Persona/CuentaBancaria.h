#ifndef CUENTABANCARIA_H
#define CUENTABANCARIA_H

#include <iostream>
using namespace std;

class CuentaBancaria {
private:
    // Atributos privados de la clase CuentaBancaria
    double Saldo;           // Saldo de la cuenta bancaria
    string NumeroDeCuenta;  // Número de cuenta bancaria

public:
    // Constructores
    CuentaBancaria();
    CuentaBancaria(double saldo, const string& numeroDeCuenta);

    // Destructor
    ~CuentaBancaria();

    // Métodos Getters (Accesores)
    double getSaldo() const;              // Retorna el saldo de la cuenta bancaria
    string getNumeroDeCuenta() const;     // Retorna el número de cuenta bancaria

    // Métodos Setters (Mutadores)
    void setSaldo(double saldo);               // Establece el saldo de la cuenta bancaria
    void setNumeroDeCuenta(const string& numeroDeCuenta);  // Establece el número de cuenta bancaria
};

#endif // CUENTABANCARIA_H
