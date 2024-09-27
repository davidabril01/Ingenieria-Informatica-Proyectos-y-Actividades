#include "graphAnaliser.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>
using namespace std;

graphAnaliser::graphAnaliser(const vector<vector<int>>& graph_) : graph(graph_) {
    V = graph_.size();
    parentVertex.resize(V, -1);
    distance.resize(V, numeric_limits<int>::max());
    buildEdges();
}

void graphAnaliser::printMatrix()
{
    cout << "MATRIZ DE ADYACENCIA" << endl;
    for (const vector<int>& innerVector : graph)
    {
        cout << "|";
        bool firstElement = 1;
        for (int element : innerVector)
        {
            if (!firstElement)
            {
                cout << "  ";
            }
            cout << element;
            firstElement = 0;
        }
        cout << "|" << endl;
    }
}

void graphAnaliser::matrixToList()
{
    cout << "LISTA DE ADYACENCIA" << endl;
    int i = 0;
    for (const vector<int>& e : graph)
    {
        i++;
        cout << i << "| ";
        bool firstElement = false;
        int a = 0;
        for (int x : e)
        {
            a++;

            if (x >= 1)
            {
                if (!firstElement)
                {
                    cout << " -> ";
                }
                cout << a << "[" << x << "]";
                firstElement = false;
            }
        }
        cout << endl;
    }
}

void graphAnaliser::printCycle(const vector<int>& cycle) {
    cycles.push_back(cycle);
}

void graphAnaliser::findCycle(vector<int>& path, int currentVertex, int startVertex) {
    path.push_back(currentVertex);

    if (currentVertex == startVertex && path.size() > 1) {
        printCycle(path);
    }
    else {
        for (int neighbor = 0; neighbor < graph.size(); ++neighbor) {
            if (graph[currentVertex][neighbor] == 1 && (neighbor == startVertex || find(path.begin(), path.end(), neighbor) == path.end())) {
                findCycle(path, neighbor, startVertex);
            }
        }
    }
    path.pop_back();
}

void graphAnaliser::findCycles() {
    vector<int> path;
    for (int i = 0; i < graph.size(); ++i) {
        findCycle(path, i, i);
    }
}

void graphAnaliser::findCycleLength(int length) {
    int cant = 0;
    for (int i = 0; i < cycles.size(); i++) {
        if (cycles[i].size()-1 == length) cant+=1;
    }
    if (cant > 0)
    {
        cout << "El grafo tiene " << cant << " ciclo/s de longitud " << length << "." << endl;
    }
    else if (cant == 0)
    {
        cout << "El grafo no tiene ciclos de longitud " << length << "." << endl;
    }
}

int graphAnaliser::countingSimplePaths(int inicio, int destino)
{
    int numCaminos = 0;
    vector<bool> visitado(graph.size(), false);

    CountingRecursivePaths(inicio - 1, destino - 1, visitado, numCaminos);

    return numCaminos;
}

void graphAnaliser::CountingRecursivePaths(int actual, int destino, vector<bool>& visitado, int& numCaminos)
{
    if (actual == destino)
    {
        numCaminos++;
        return;
    }

    visitado[actual] = true;

    for (int i = 0; i < graph.size(); ++i)
    {
        if (graph[actual][i] && !visitado[i])
        {
            CountingRecursivePaths(i, destino, visitado, numCaminos);
        }
    }

    visitado[actual] = false;
}

void graphAnaliser::removeDuplicateCycles() {
    for (int i = 0; i < cycles.size(); i++) {
        for (int w = i; w < cycles.size(); w++) {
            if (cycles[i].size() == cycles[w].size()) {
                int cantDeIguales = 0;
                for (int h = 0; h < cycles[i].size() - 1; h++) {
                    for (int a = 0; a < cycles[i].size() - 1; a++) {
                        if (cycles[i][h] == cycles[w][a]) cantDeIguales += 1;
                    }
                    if (cantDeIguales == (cycles[w].size() - 1)) {
                        if (w >= 0 && w < cycles.size()) {
                            vector<vector<int>>::iterator it = cycles.begin() + w;
                            cycles.erase(it);
                        }
                    }
                }
            }
        }
    }
}

void graphAnaliser::printCycles() {
    for (int i = 0; i < cycles.size(); i++) {
        if (cycles[i].size() > 3) {
            for (int w = 0; w < cycles[i].size(); w++) {
                cout << cycles[i][w] + 1 << " ";
            }
            cout << endl;
        }
    }
}

void graphAnaliser::primMST() {
    /*V es el tamaño de la matriz, osea la cantidad de vertices
    graph es la matriz de adyacencia*/
    int parent[V];
    int clave[V];
    bool MSTset[V];

    for (int i = 0; i < V; i++) {
        clave[i] = INT_MAX;
        MSTset[i] = false;
    }

    clave[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = findMinimalVertex(clave, MSTset);
        MSTset[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !MSTset[v] && graph[u][v] < clave[v]) {
                parent[v] = u;
                clave[v] = graph[u][v];
            }
        }
    }

    // Imprimir el MST
    cout << "Aristas del MST (PRIM):\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i]+1 << " - " << i+1 << " Peso: " << graph[i][parent[i]] << "\n";
    }
}

int graphAnaliser::findMinimalVertex(int clave[], bool MSTset[]) {
    int minimo = INT_MAX, minimo_index;

    for (int v = 0; v < V; v++) {
        if (!MSTset[v] && clave[v] < minimo) {
            minimo = clave[v];
            minimo_index = v;
        }
    }

    return minimo_index;
}

void graphAnaliser::findMinimumSpanningTreeKruskal() {
    // Ordenar las aristas en orden creciente de peso
    sort(edges.begin(), edges.end());

    // Arreglo para representar los conjuntos disjuntos (inicialmente, cada nodo es un conjunto)
    vector<int> parent(V);

    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    // Vector para almacenar el resultado del MST
    vector<pair<int, pair<int, int>>> resultMST;

    for (pair<int, pair<int, int>> edge : edges) {
        int weight = edge.first;
        int src = edge.second.first;
        int dest = edge.second.second;

        // Buscar los padres de los conjuntos de los nodos src y dest
        int x = findFather(parent, src);
        int y = findFather(parent, dest);

        // Si incluir esta arista no forma un ciclo en el MST, agrégala al resultado
        if (x != y) {
            resultMST.push_back(edge);
            // Unir los conjuntos de src y dest
            unionSets(parent, x, y);
        }
    }

    // Imprimir el MST
    cout << "Aristas del MST (Kruskal):\n";
    for (pair<int, pair<int, int>> edge : resultMST) {
        int weight = edge.first;
        int src = edge.second.first;
        int dest = edge.second.second;
        cout << src+1 << " - " << dest+1 << " Peso: " << weight << endl;
    }
}

int graphAnaliser::findFather(vector<int>& parent, int node) {
    if (parent[node] != node) {
        parent[node] = findFather(parent, parent[node]);
    }
    return parent[node];
}

void graphAnaliser::unionSets(vector<int>& parent, int x, int y) {
    int rootX = findFather(parent, x);
    int rootY = findFather(parent, y);
    parent[rootX] = rootY;
}

void graphAnaliser::buildEdges() {
    edges.clear();
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j] != 0) {
                edges.push_back(make_pair(graph[i][j], make_pair(i, j)));
            }
        }
    }
}



int graphAnaliser::minDistance(const vector<int>& distancias, const vector<bool>& visitados) {
    int minDistancia = INT_MAX;
    int minVertice = -1;

    for (int i = 0; i < distancias.size(); ++i) {
        if (!visitados[i] && distancias[i] < minDistancia) {
            minDistancia = distancias[i];
            minVertice = i;
        }
    }

    return minVertice;
}

void graphAnaliser::imprimirCaminoDijkstra(const vector<int>& padres, int vertice) {
    if (vertice == -1) return;
    imprimirCaminoDijkstra(padres, padres[vertice]);
    cout << vertice+1 << " ";
}

void graphAnaliser::dijkstra(int origen, int destino) {
    origen -=1;
    destino -=1;
    int numVertices = V;

    vector<int> distancias(numVertices, INT_MAX);
    vector<bool> visitados(numVertices, false);
    vector<int> padres(numVertices, -1);

    distancias[origen] = 0;

    for (int i = 0; i < numVertices - 1; ++i) {
        int minVertice = minDistance(distancias, visitados);

        if (minVertice == destino) break;

        visitados[minVertice] = true;

        for (int j = 0; j < numVertices; ++j) {
            if (!visitados[j] && graph[minVertice][j] && distancias[minVertice] != INT_MAX
                && distancias[minVertice] + graph[minVertice][j] < distancias[j]) {
                distancias[j] = distancias[minVertice] + graph[minVertice][j];
                padres[j] = minVertice;
            }
        }
    }

    cout << "Camino más corto desde el vértice " << origen+1 << " al vértice " << destino+1 << ":\n";
    cout << "Distancia = " << distancias[destino] << " Camino = ";
    imprimirCaminoDijkstra(padres, destino);
    cout << endl;
}