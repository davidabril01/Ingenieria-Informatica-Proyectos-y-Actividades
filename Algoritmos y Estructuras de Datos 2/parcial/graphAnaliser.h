#ifndef GRAPHANALISER_H
#define GRAPHANALISER_H
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class graphAnaliser {
private:
    const int INFINITY = 1000000;
    int V;
    vector<pair<int, pair<int, int>>> edges;
    const vector<vector<int>> graph;
    vector<vector<int>> cycles;
    vector<int> parentVertex;
    vector<int> distance;
    void printCycle(const vector<int>& cycle);
    void findCycle(vector<int>& path, int currentVertex, int startVertex);
    void CountingRecursivePaths(int actual, int destino, vector<bool>& visitado, int& numCaminos);
    int findMinimalVertex(int clave[], bool MSTset[]);
    int findFather(vector<int>& parent, int node);
    void unionSets(vector<int>& parent, int x, int y);
    void buildEdges();
    int minDistance(const vector<int>& distancias, const vector<bool>& visitados);
    void imprimirCaminoDijkstra(const vector<int>& padres, int vertice);

public:
    graphAnaliser(const vector<vector<int>>& graph_);
    void printMatrix();
    void matrixToList();
    void findCycles();
    void findCycleLength(int length);
    int countingSimplePaths(int inicio, int destino);
    void removeDuplicateCycles();
    void printCycles();
    void primMST();
    void findMinimumSpanningTreeKruskal();
    void dijkstra(int origen, int destino);
};
#endif
