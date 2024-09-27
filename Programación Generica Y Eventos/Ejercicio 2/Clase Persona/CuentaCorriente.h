#ifndef CUENTACORRIENTE_H
#define CUENTACORRIENTE_H

#include "CuentaBancaria.h"

class CuentaCorriente : public CuentaBancaria {
private:
    double comisionMantenimiento;  // Comisión de mantenimiento para la cuenta corriente

public:
    // Constructores
    CuentaCorriente();
    CuentaCorriente(double saldo, const string& numeroDeCuenta, double comisionMantenimiento);

    // Métodos para cobrar comisiones y calcular intereses (si es necesario)
    void cobrarComisiones();  // Cobra la comisión de mantenimiento

    // Getter y Setter para la comisión de mantenimiento
    double getComisionMantenimiento() const;
    void setComisionMantenimiento(double comisionMantenimiento);
};

#endif // CUENTACORRIENTE_H
