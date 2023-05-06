#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int RSearch(int a[], int x, int n) {
    while (true) {
        int i = rand() % n + 1;
        if (a[i] == x) return i;
    }
}

int main() {
    srand(time(nullptr)); // Inicializa la semilla del generador de números aleatorios
    ofstream resultados("resultados_rsearch.txt"); // Archivo para guardar los resultados
    if (!resultados.is_open()) {
        cout << "Error al abrir el archivo de resultados." << endl;
        return 1;
    }
    for (int n = 10000; n <= 100000; n += 10000) {
        int* a = new int[n + 1]; // Crea el arreglo de tamaño n+1
        for (int i = 1; i <= n; i++) {
            a[i] = i; // Llena el arreglo con números del 1 al n
        }
        clock_t start_time = clock(); // Inicia el cronómetro
        int x = RSearch(a, n, n); // Busca un número aleatorio en el arreglo
        clock_t end_time = clock(); // Detiene el cronómetro
        double elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC * 1000000; // Tiempo transcurrido en microsegundos
        resultados << n << "\t" << elapsed_time << endl; // Guarda los resultados en el archivo
        delete[] a; // Libera la memoria asignada al arreglo
    }
    resultados.close(); // Cierra el archivo de resultados
    return 0;
}
