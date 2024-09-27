#include <iostream>
#include <vector>

// Implementación del algoritmo de ordenamiento Shell Sort
void shellSort(std::vector<int>& arr) {
    int n = arr.size();
  
    // Comenzar con un tamaño de brecha grande y reducirlo en cada iteración
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Realizar el ordenamiento por inserción para la brecha actual
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
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
  
    shellSort(numbers);
  
    std::cout << "Vector ordenado: ";
    printVector(numbers);
  
    return 0;
}