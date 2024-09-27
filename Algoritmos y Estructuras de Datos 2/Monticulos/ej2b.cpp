#include <iostream>
#include <queue>

using namespace std;

struct pais {
    string nombre;
    int poblacion;
    int PBI;

    // Sobrecarga del operador de comparación
    bool operator<(const pais& otro) const {
        // En este caso, comparamos por PBI en orden decreciente
        return PBI < otro.PBI;
    }
};

int main() {
    priority_queue<pais> max_heap; // Crear un montículo máximo

    pais Arg;
    Arg.nombre = "Argentina";
    Arg.PBI = 487;
    Arg.poblacion = 46044703;
    pais Jap;
    Jap.nombre = "Japon";
    Jap.PBI = 4940;
    Jap.poblacion = 125000000;
    pais Hol;
    Hol.nombre = "Holanda";
    Hol.PBI = 1013;
    Hol.poblacion = 17530000;
    pais Usa;
    Usa.nombre = "USA";
    Usa.PBI = 1600;
    Usa.poblacion = 331900000;

    // Insertar elementos en el montículo máximo
    max_heap.push(Arg);
    max_heap.push(Jap);
    max_heap.push(Hol);
    max_heap.push(Usa);

    cout << "Elementos en el montículo máximo:" << endl;

    while (!max_heap.empty()) {
        pais prev;
        prev = max_heap.top();
        cout << prev.nombre << " - " << prev.PBI << " - " << prev.poblacion << " | "; // Acceder al elemento de mayor prioridad
        max_heap.pop(); // Eliminar el elemento de mayor prioridad
    }
    cout << endl;

    return 0;
}
