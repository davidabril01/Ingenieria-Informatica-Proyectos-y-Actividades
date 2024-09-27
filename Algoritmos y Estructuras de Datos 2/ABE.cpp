#include <iostream>
#include <vector>

using namespace std;

// Estructura de datos para representar un grafo
struct Grafo {
  int V; // Número de vértices
  vector<vector<int>> aristas; // Matriz de adyacencia
  vector<int> grados; // Vector de grados de los vértices
};

bool contains(vector<int>& v, int x) {
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == x) {
      return true;
    }
  }

  return false;
}

// Estructura de datos para representar un ciclo hamiltoniano
struct CicloHamiltoniano {
  vector<int> vertices; // Vértices del ciclo
  int peso; // Peso del ciclo
};

// Función para calcular el ciclo hamiltoniano con menos peso
CicloHamiltoniano encontrarCicloHamiltonianoMinimo(Grafo grafo) {
  // Variables locales
  CicloHamiltoniano cicloMinino;
  int pesoMinino = INT_MAX;

  // Iteramos sobre todos los vértices del grafo
  for (int v = 0; v < grafo.V; v++) {
    // Inicializamos el ciclo con el vértice v
    cicloMinino.vertices.push_back(v);

    // Recorremos los vértices adyacentes a v
    for (int u : grafo.aristas[v]) {
      // Si el vértice u no está en el ciclo, lo añadimos
      if (!contains(cicloMinino.vertices, u)) {
        cicloMinino.vertices.push_back(u);

        // Actualizamos el peso del ciclo
        int pesoActual = 0;
        for (int i = 0; i < cicloMinino.vertices.size() - 1; i++) {
          pesoActual += grafo.aristas[cicloMinino.vertices[i]][cicloMinino.vertices[i + 1]];
        }

        if (pesoActual < pesoMinino) {
          pesoMinino = pesoActual;
          cicloMinino.peso = pesoMinino;
        }

        // Eliminamos el vértice u del ciclo
        cicloMinino.vertices.pop_back();
      }
    }

    // Eliminamos el vértice v del ciclo
    cicloMinino.vertices.pop_back();
  }

  return cicloMinino;
}

// Función para comprobar si un elemento está presente en un vector


// Función principal
int main() {
  // Declaramos un grafo con 5 vértices
  Grafo grafo = {5, {{0, 1, 10}, {0, 2, 5}, {1, 2, 15}, {1, 3, 20}, {2, 3, 12}}, {0, 1, 2, 3}};

  // Encontramos el ciclo hamiltoniano con menos peso
  CicloHamiltoniano cicloMinino = encontrarCicloHamiltonianoMinimo(grafo);

  // Imprimimos el ciclo hamiltoniano
  cout << "El ciclo hamiltoniano con menos peso es: ";
  for (int v : cicloMinino.vertices) {
    cout << v << " ";
  }
  cout << endl;

  return 0;
}
