#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;

int BinSrch(int a[], int i, int n, int x) {
    if (n == 1) {
        if (x == a[i]) {
            return i;
        } else {
            return -1;
        }
    } else {
        int mid = (i + n) / 2;
        if (x == a[mid]) {
            return mid;
        } else if (x < a[mid]) {
            return BinSrch(a, i, mid, x);
        } else {
            return BinSrch(a, mid + 1, n - mid, x);
        }
    }
}


int main() {
    ofstream output("resultados_binsrch.txt");

    for(int n = 1000000; n <= 10000000; n += 1000000) {
        // Crear un array ordenado con n elementos
        int* a = new int[n];
        for(int i = 0; i < n; i++) {
            a[i] = i+1;
        }

        // Realizar la búsqueda para un elemento que no existe
        auto start = chrono::high_resolution_clock::now();
        BinSrch(a, 0, n, -1);
        auto end = chrono::high_resolution_clock::now();

        // Calcular el tiempo de ejecución y guardar en el archivo de resultados
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
        output << n << " " << duration << endl;

        // Liberar la memoria del array
        delete[] a;
    }

    output.close();
    return 0;
}
