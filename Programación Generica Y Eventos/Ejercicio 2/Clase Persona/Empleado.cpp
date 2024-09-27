#include "Empleado.h"

// Constructor por defecto
Empleado::Empleado(){}

// Constructor parametrizado
Empleado::Empleado(string nombre, string genero, int edad, int dni, double salario, string cargo, string departamento)
    : Persona(nombre, genero, edad, dni), Salario(salario), Cargo(cargo), Departamento(departamento) {}

// Destructor
Empleado::~Empleado() {}

// Getters
double Empleado::getSalario() const {
    return Salario;
}

string Empleado::getCargo() const {
    return Cargo;
}

string Empleado::getDepartamento() const {
    return Departamento;
}

// Setters
void Empleado::setSalario(double salario) {
    Salario = salario;
}

void Empleado::setCargo(const string& cargo) {
    Cargo = cargo;
}

void Empleado::setDepartamento(const string& departamento) {
    Departamento = departamento;
}
