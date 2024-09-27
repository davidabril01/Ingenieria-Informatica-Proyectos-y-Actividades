#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int> max_heap; // Crear un montículo máximo

    // Insertar elementos en el montículo máximo
    max_heap.push(20);
    max_heap.push(18);
    max_heap.push(9);
    max_heap.push(8);
    max_heap.push(10);
    max_heap.push(12);
    max_heap.push(11);

    cout << "Elementos en el montículo máximo:" << endl;

    while (!max_heap.empty()) {
        cout << max_heap.top() << " "; // Acceder al elemento de mayor prioridad
        max_heap.pop(); // Eliminar el elemento de mayor prioridad
    }
    cout << endl;

    return 0;
}