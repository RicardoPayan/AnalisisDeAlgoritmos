#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <fstream>

using namespace std;
using namespace std::chrono;


// Función para combinar dos subarrays de arr[].
// El primer subarray es arr[l..m]
// El segundo subarray es arr[m+1..r]
void merge(vector<int> &arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Función principal de Merge Sort
void mergeSort(vector<int> &arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
} 

// Función de Insertion Sort
void insertionSort(vector<int> &arr) {
    int n = arr.size();
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

//Funciones de utilidad -----------------------------------

std::vector<int> generar_vector_aleatorio(int n) {
    std::vector<int> v(n);
    std::random_device rd;  // Generador de semilla aleatoria
    std::mt19937 gen(rd()); // Generador de números aleatorios
    std::uniform_int_distribution<> dis(1, 200); // Distribución uniforme de 1 a 100
    for (int i = 0; i < n; i++) {
        v[i] = dis(gen);
    }
    return v;
}

void liberar_memoria(int* vector, int tamano) {
    delete[] vector;
}

//Main----------------------------------------------------

int main() {

	srand(time(NULL)); //Semilla para que cada corrida sea aleatoria
    
    vector<int> A;
    int n = rand() % 1000 + 1;
    cout << "tamaño de los arreglos: " << n;
    std::ofstream lenght("array_tamanos.txt", std::ios::app);
    lenght << n << std::endl;
    lenght.close();
    

    // Arreglo aleatorio
    for (int i = 0; i < n; i++) {
        A.push_back(rand() % 1000 + 1);
    }
    auto start = high_resolution_clock::now();
    insertionSort(A);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Arreglo aleatorio: ";
    for (auto x : A) {
        cout << x << " ";
    }
    cout << endl;
    cout << "Tiempo de ejecucion: " << duration.count() << " microsegundos" << endl;
    
    std::ofstream prom_times("insertion_prom_times.txt", std::ios::app);
    prom_times << duration.count() << std::endl;
    prom_times.close();

    // Arreglo ordenado en orden creciente
    A.clear();
    for (int i = 0; i < n; i++) {
        A.push_back(i);
    }
    start = high_resolution_clock::now();
    insertionSort(A);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    cout << "Arreglo ordenado en orden creciente: ";
    for (auto x : A) {
        cout << x << " ";
    }
    cout << endl;
    cout << "Tiempo de ejecucion: " << duration.count() << " microsegundos" << endl;
    
    std::ofstream best_times("insertion_best_times.txt", std::ios::app);
    best_times << duration.count() << std::endl;
    best_times.close();

    // Arreglo ordenado en orden decreciente
    A.clear();
    for (int i = n - 1; i >= 0; i--) {
        A.push_back(i);
    }
    start = high_resolution_clock::now();
    insertionSort(A);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    cout << "Arreglo ordenado en orden decreciente: ";
    for (auto x : A) {
        cout << x << " ";
    }
    cout << endl;
    cout << "Tiempo de ejecucion: " << duration.count() << " microsegundos" << endl;
    
    std::ofstream worst_times("insertion_worst_times.txt", std::ios::app);
    worst_times << duration.count() << std::endl;
    worst_times.close();
    
    return 0;
        
}
