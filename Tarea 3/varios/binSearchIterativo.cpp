#include <iostream>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;

int BinSearch(int a[], int n, int x) {
    int low = 1, high = n;
    while(low <= high) {
        int mid = (low + high) / 2;
        if (x < a[mid]) high = mid - 1;
        else if (x > a[mid]) low = mid + 1;
        else return mid;
    }
    return 0;
}

int main() {
    ofstream file("resultados_binsearch.txt");
    for (int n = 100000; n <= 1000000; n += 100000) {
        int arr[n];
        for (int i = 1; i <= n; i++) {
            arr[i] = i; // Llenamos el arreglo con números del 1 al n
        }
        int x = n/2; // Buscamos el elemento en la mitad del arreglo
        auto start = high_resolution_clock::now(); // Iniciamos la medición de tiempo
        int res = BinSearch(arr, n, x);
        auto stop = high_resolution_clock::now(); // Terminamos la medición de tiempo
        auto duration = duration_cast<microseconds>(stop - start); // Obtenemos la duración en microsegundos
        file << n << " " << duration.count() << endl; // Escribimos los resultados en el archivo
    }
    file.close();
    return 0;
}
