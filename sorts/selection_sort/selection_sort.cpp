#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <fstream>

using namespace std;
using namespace std::chrono;


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
    

    // Arreglo aleatorio
    for (int i = 0; i < n; i++) {
        A.push_back(rand() % 1000 + 1);
    }
    auto start = high_resolution_clock::now();
    selectionSort(A);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Arreglo aleatorio: ";
    for (auto x : A) {
        cout << x << " ";
    }
    cout << endl;
    cout << "Tiempo de ejecucion: " << duration.count() << " microsegundos" << endl;
    
    std::ofstream prom_times("selection_prom_times.txt", std::ios::app);
    prom_times << n << "\t" << duration.count() << std::endl;
    prom_times.close();

    // Arreglo ordenado en orden creciente
    A.clear();
    for (int i = 0; i < n; i++) {
        A.push_back(i);
    }
    start = high_resolution_clock::now();
    selectionSort(A);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    cout << "Arreglo ordenado en orden creciente: ";
    for (auto x : A) {
        cout << x << " ";
    }
    cout << endl;
    cout << "Tiempo de ejecucion: " << duration.count() << " microsegundos" << endl;
    
    std::ofstream best_times("selection_best_times.txt", std::ios::app);
    best_times << n << "\t" << duration.count() << std::endl;
    best_times.close();

    // Arreglo ordenado en orden decreciente
    A.clear();
    for (int i = n - 1; i >= 0; i--) {
        A.push_back(i);
    }
    start = high_resolution_clock::now();
    selectionSort(A);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    cout << "Arreglo ordenado en orden decreciente: ";
    for (auto x : A) {
        cout << x << " ";
    }
    cout << endl;
    cout << "Tiempo de ejecucion: " << duration.count() << " microsegundos" << endl;
    
    std::ofstream worst_times("selection_worst_times.txt", std::ios::app);
    worst_times << n << "\t" << duration.count() << std::endl;
    worst_times.close();
    
    return 0;
        
}
