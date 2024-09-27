#include "Persona.h"

// Constructor por defecto
Persona::Persona() : Cuenta() {}

// Constructor parametrizado
Persona::Persona(string nombre, string genero, int edad, int dni)
    : Nombre(nombre), Genero(genero), Edad(edad), Dni(dni), Cuenta() {}

// Destructor
Persona::~Persona() {}

// Getters
string Persona::getNombre() const {
    return Nombre;
}

string Persona::getGenero() const {
    return Genero;
}

int Persona::getEdad() const {
    return Edad;
}

int Persona::getDni() const {
    return Dni;
}

CuentaBancaria Persona::getCuenta() const {
    return Cuenta;
}

// Setters
void Persona::setNombre(const string& nombre) {
    Nombre = nombre;
}

void Persona::setGenero(const string& genero) {
    Genero = genero;
}

void Persona::setEdad(int edad) {
    Edad = edad;
}

void Persona::setDni(int dni) {
    Dni = dni;
}

// Método para asignar una cuenta bancaria
void Persona::asignarCuenta(double saldo, const string& numeroDeCuenta) {
    Cuenta.setSaldo(saldo);
    Cuenta.setNumeroDeCuenta(numeroDeCuenta);
}
