#include <iostream>
using namespace std;
/***************************************************************/
class persona
{
private:
    double DNI;
    string Nombre;
    string Mail;
public:
persona(){}
persona(double dni, string nombre, string mail){DNI=dni; Nombre=nombre; Mail=mail;}
    void setDni(double dni){DNI=dni;}
    double getDni(){return DNI;}
    void setNom(string nom){Nombre=nom;}
    string getNom(){return Nombre;}
    void setmail(string mail){Mail=mail;}
    string getmail(){return Mail;}
~persona(){}
};
/***************************************************************/
class administrativo : public persona
{
private:
    cuenta C;
    string Puesto;
public:
    administrativo(){}
    administrativo(string puesto, double dni, string nombre, string mail){Puesto=puesto; persona::persona(dni, nombre, mail);}
    void setPuesto(string puesto){Puesto=puesto;}
    string getPuesto(){return Puesto;}
    ~administrativo(){}
};
/***************************************************************/
class profesional : public persona
{
private:
    cuenta C;
    string Titulo;
    string Actividad;
    int TDeServ;
public:
    profesional(){}
    profesional(string titulo, string actividad , double dni, string nombre, string mail){Titulo=titulo; persona::persona(dni, nombre, mail);}
    void setTitulo(string titulo){Titulo=titulo;}
    string getTitulo(){return Titulo;}
    void setActividad(string actividad){Actividad=actividad;}
    string getActividad(){return Actividad;}
    void setTDeServ(int tDeServ){TDeServ=tDeServ;}
    int getTDeServ(){return TDeServ;}
    int tarjeta();
    ~profesional(){}
};
/***************************************************************/
class cuenta
{
private:
    bool altabaja;
    double saldo;
    double sueldo;  
public:
    cuenta(){}
    void CrearCuenta();
    void IngresoEgreso();
    ~cuenta(){}
};
/***************************************************************/
class SistMainBanco
{
private:
    administrativo A[100];
    profesional P[100];
    int  ultimoA=0,ultimoP=0;
public:
    int busquedaDNI(int dni);
    SistMainBanco(){}
    void AltaBaja();
    void Menu();
};