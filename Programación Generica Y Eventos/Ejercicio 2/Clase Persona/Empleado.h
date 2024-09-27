#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Persona.h"

class Empleado : public Persona {
private:
    // Atributos privados de la clase Empleado
    double Salario;       // Salario del empleado
    string Cargo;         // Cargo o puesto del empleado
    string Departamento;  // Departamento en el que trabaja el empleado

public:
    // Constructores
    Empleado();
    Empleado(string nombre, string genero, int edad, int dni, double salario, string cargo, string departamento);

    // Destructor
    ~Empleado();

    // Métodos Getters (Accesores)
    double getSalario() const;        // Retorna el salario del empleado
    string getCargo() const;          // Retorna el cargo del empleado
    string getDepartamento() const;   // Retorna el departamento del empleado

    // Métodos Setters (Mutadores)
    void setSalario(double salario);          // Establece el salario del empleado
    void setCargo(const string& cargo);       // Establece el cargo del empleado
    void setDepartamento(const string& departamento);  // Establece el departamento del empleado
};

#endif // EMPLEADO_H
