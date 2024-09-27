#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include "CuentaBancaria.h"  // Incluir la clase CuentaBancaria

using namespace std;

class Persona {
private:
    // Atributos privados de la clase Persona
    string Nombre;            // Nombre de la persona
    string Genero;            // Género de la persona
    int Edad;                 // Edad de la persona
    int Dni;                  // DNI de la persona
    CuentaBancaria Cuenta;    // Cuenta bancaria de la persona

public:
    // Constructores
    Persona();  // Constructor por defecto
    Persona(string nombre, string genero, int edad, int dni);  // Constructor parametrizado

    // Destructor
    ~Persona();  // Destructor de la clase

    // Métodos Getters
    string getNombre() const;  // Retorna el nombre de la persona
    string getGenero() const;  // Retorna el género de la persona
    int getEdad() const;       // Retorna la edad de la persona
    int getDni() const;        // Retorna el DNI de la persona
    CuentaBancaria getCuenta() const;  // Retorna la cuenta bancaria de la persona

    // Métodos Setters
    void setNombre(const string& nombre);  // Establece el nombre de la persona
    void setGenero(const string& genero);  // Establece el género de la persona
    void setEdad(int edad);                // Establece la edad de la persona
    void setDni(int dni);                  // Establece el DNI de la persona

    // Método para asignar una cuenta bancaria a la persona
    void asignarCuenta(double saldo, const string& numeroDeCuenta);
};

#endif // PERSONA_H
