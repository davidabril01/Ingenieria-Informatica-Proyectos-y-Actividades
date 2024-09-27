#include <iostream>
#include "Empleado.h"
#include "CuentaAhorro.h"
#include "CuentaCorriente.h"

using namespace std;

int main() {
    // Crear un objeto de la clase Empleado
    Empleado empleado("Juan Pérez", "Masculino", 30, 12345678, 50000, "Ingeniero", "Desarrollo");

    // Asignar una cuenta de ahorro al empleado
    CuentaAhorro cuentaAhorro(2000.0, "001-234-567", 0.05);  // Saldo inicial de 2000.0 y tasa de interés del 5%
    empleado.asignarCuenta(cuentaAhorro.getSaldo(), cuentaAhorro.getNumeroDeCuenta());

    // Mostrar los detalles de la cuenta de ahorro antes de calcular intereses
    cout << "Empleado: " << empleado.getNombre() << endl;
    cout << "Cuenta Ahorro - Saldo inicial: " << empleado.getCuenta().getSaldo() << endl;
    cout << "Número de Cuenta: " << empleado.getCuenta().getNumeroDeCuenta() << endl;

    // Calcular intereses y mostrar el saldo actualizado
    cuentaAhorro.calcularIntereses();
    cout << "Cuenta Ahorro - Saldo después de calcular intereses: " << cuentaAhorro.getSaldo() << endl;

    // Crear una cuenta corriente y asignársela al empleado
    CuentaCorriente cuentaCorriente(1500.0, "987-654-321", 20.0);  // Saldo inicial de 1500.0 y comisión de 20.0
    empleado.asignarCuenta(cuentaCorriente.getSaldo(), cuentaCorriente.getNumeroDeCuenta());

    // Mostrar los detalles de la cuenta corriente antes de cobrar comisiones
    cout << "Cuenta Corriente - Saldo inicial: " << empleado.getCuenta().getSaldo() << endl;
    cout << "Número de Cuenta: " << empleado.getCuenta().getNumeroDeCuenta() << endl;

    // Cobrar comisión y mostrar el saldo actualizado
    cuentaCorriente.cobrarComisiones();
    cout << "Cuenta Corriente - Saldo después de cobrar comisiones: " << cuentaCorriente.getSaldo() << endl;
    int a;
    cin >> a;
    return 0;
}
