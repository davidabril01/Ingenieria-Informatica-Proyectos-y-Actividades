#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Monticulo
{
private:
    struct pais
    {
        string nombre;
        int poblacion;
        int PBI;
    };
    vector<pais> *monti;
    int cantNodos;
    int posLibre;
    // Métodos auxiliares
    // Métodos de cálculo para posición del nodo
    int Padre(int i);
    int Izquierdo(int i);
    int Derecho(int i);
    // Fin métodos cálculo posición

    // Movimiento de nodos
    void Subir(int i);
    void Bajar1(int i);
    void Bajar(int i);
    void Intercambia(int i1, int i2);

public:
    Monticulo(int tamanioInicial = 10);
    ~Monticulo();

    // Funciones de montículo
    void Insertar(string Nombre, int Poblacion, int pBI);
    void Borrar();
    bool Vacio();
    void Mostrar();
    void ExtraerMaximo();
};

// Constructor (Pasa tamaño inicial constructor)
Monticulo::Monticulo(int tamanioInicial)
{
    cantNodos = tamanioInicial;
    posLibre = 0;
    monti = new vector<pais>(tamanioInicial);
}

// Destructor
Monticulo::~Monticulo()
{
    delete monti;
}

// Grupo funciones para determinar posiciones de nodos padre e hijos
int Monticulo::Padre(int i)
{
    return (i - 1) / 2;
}

int Monticulo::Izquierdo(int i)
{
    return 2 * i + 1;
}

int Monticulo::Derecho(int i)
{
    return 2 * i + 2;
}
// Fin Grupo funciones posiciones

// Verifica si montículo está vacío
bool Monticulo::Vacio()
{
    return posLibre == 0;
}

// Inserta nodo en montículo
void Monticulo::Insertar(string Nombre, int Poblacion, int pBI)
{
    (*monti)[posLibre].nombre = Nombre;
    (*monti)[posLibre].poblacion = Poblacion;
    (*monti)[posLibre].PBI = pBI;
    posLibre+=1;
    Subir(posLibre - 1);
}

// Sube un nodo por el montículo (Aplica en Inserción de Nodos)
void Monticulo::Subir(int i)
{
    int nodoPadre;
    while (i > 0 && (*monti)[i].PBI > (*monti)[nodoPadre = Padre(i)].PBI)
    {
        Intercambia(i, nodoPadre);
        i = nodoPadre;
    }
}

// Realiza intercambio de nodos
void Monticulo::Intercambia(int i1, int i2)
{
    pais aux;
    aux = (*monti)[i1];
    (*monti)[i1] = (*monti)[i2];
    (*monti)[i2] = aux;
}

// Borra nodo de montículo

void Monticulo::Borrar()
{
    Bajar(0);
}

void Monticulo::Bajar(int i)
{
    if (Izquierdo(i) < (*monti).size() - 1)
    {
        if ((*monti)[Izquierdo(i)].PBI > (*monti)[Derecho(i)].PBI)
        {
            Intercambia(i, Izquierdo(i));
            Bajar(Izquierdo(i));
        }
        else
        {
            Intercambia(i, Derecho(i));
            Bajar(Derecho(i));
        }
    }
    else if (i < (*monti).size() - 1)
    {
        Intercambia(i, (*monti).size() - 1);
        Subir(i);
        (*monti).pop_back();
    }
    else
    {
        (*monti).pop_back();
    }
}

// Realiza la bajada de un nodo a través del la estructura.

// Recorrido del montículo (Visualiza todos los nodos)
void Monticulo::Mostrar()
{
    if (Vacio())
        cout << "Estructura vacía" << endl;
    else
    {
        for (int i = 0; i < posLibre; i++)
            cout << "pos " << i << " - Nombre : " << (*monti)[i].nombre << " - Poblacion : " << (*monti)[i].poblacion << " - PBI : " << (*monti)[i].PBI << ", ";
        cout << endl;
    }
}

// Toma el el valor máximo del montículo (Se encuentra en la raíz)
void Monticulo::ExtraerMaximo()
{
    pais retval = (*monti)[0];
    cout << "Monticulo ordenado por PBI: ";
    for (int i = 0; i < (*monti).size(); i++)
    {
        cout << (*monti)[i].nombre << " -> ";
    }
    cout << endl;
    Borrar();
    cout << "Pais: " << retval.nombre << " || Poblacion: " << retval.poblacion << " || PBI: " << retval.PBI << endl;
}