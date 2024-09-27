#include <iostream>
#include <vector>
using namespace std;

// Función auxiliar para intercambiar dos elementos en un vector
void swap(vector<int>& arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Función para seleccionar el pivote y particionar el vector en dos subvectores
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Seleccionamos el último elemento como pivote
    int i = (low - 1); // Índice del elemento más pequeño
  
    for (int j = low; j <= high - 1; j++) {
        // Si el elemento actual es más pequeño o igual que el pivote
        if (arr[j] <= pivot) {
            i++;
            swap(arr, i, j); // Intercambiar arr[i] y arr[j]
        }
    }
    swap(arr, i + 1, high); // Intercambiar arr[i+1] y el pivote
    return (i + 1); // Retorna el índice del pivote
}

// Implementación recursiva del algoritmo de ordenamiento Quick Sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Obtenemos el índice del pivote después de particionar el vector
        int pivotIndex = partition(arr, low, high);
  
        // Ordenamos los elementos antes y después del pivote
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Función auxiliar para imprimir el vector
void printVector(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> numbers = {9, 5, 1, 8, 3, 4, 2, 7, 6};
  
    cout << "Vector original: ";
    printVector(numbers);
  
    quickSort(numbers, 0, numbers.size() - 1);
  
    cout << "Vector ordenado: ";
    printVector(numbers);
  
    return 0;
}