#include <iostream>
#include <vector>

// Función auxiliar para intercambiar dos elementos en un vector
void swap(std::vector<int>& arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Función que realiza el ajuste descendente del elemento en la posición 'index' en un subárbol de 'n' elementos
void heapify(std::vector<int>& arr, int n, int index) {
    int largest = index; // Inicializamos el elemento más grande como la raíz
    int left = 2 * index + 1; // Índice del hijo izquierdo
    int right = 2 * index + 2; // Índice del hijo derecho
  
    // Si el hijo izquierdo es más grande que la raíz
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
  
    // Si el hijo derecho es más grande que el elemento más grande hasta ahora
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
  
    // Si el elemento más grande no es la raíz
    if (largest != index) {
        swap(arr, index, largest); // Intercambiamos el elemento más grande con la raíz
  
        // Ajustamos el subárbol afectado recursivamente
        heapify(arr, n, largest);
    }
}

// Implementación del algoritmo de ordenamiento Heap Sort
void heapSort(std::vector<int>& arr) {
    int n = arr.size();
  
    // Construimos el heap máximo
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
  
    // Extraemos los elementos del heap uno por uno
    for (int i = n - 1; i >= 0; i--) {
        swap(arr, 0, i); // Movemos el elemento actual a la raíz
  
        // Llamamos a heapify en el subárbol reducido
        heapify(arr, i, 0);
    }
}

// Función auxiliar para imprimir el vector
void printVector(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> numbers = {9, 5, 1, 8, 3, 4, 2, 7, 6};
  
    std::cout << "Vector original: ";
    printVector(numbers);
  
    heapSort(numbers);
  
    std::cout << "Vector ordenado: ";
    printVector(numbers);
  
    return 0;
}