#include <iostream>
#include <chrono>
#include <fstream>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

void Transpose(int **a, int n){
    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            int t = a[i][j]; a[i][j] = a[j][i]; a[j][i] = t;
        }
    }
}

int main() {
    ofstream outfile;
    outfile.open("resultados_transpose.txt");

    // Iterar sobre diferentes tamaños de matrices n
    for (int n = 1000; n <= 10000; n += 1000){
        // Crear matriz cuadrada de tamaño n
        int **a = new int*[n];
        for (int i = 0; i < n; i++){
            a[i] = new int[n];
            for (int j = 0; j < n; j++){
                a[i][j] = rand() % 100;
            }
        }

        // Medir el tiempo de ejecución de la transposición
        auto start = high_resolution_clock::now();
        Transpose(a, n);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);

        // Guardar resultados en el archivo de texto
        outfile << n << "\t" << duration.count() << endl;

        // Liberar memoria de la matriz a
        for (int i = 0; i < n; i++){
            delete[] a[i];
        }
        delete[] a;
    }

    // Cerrar el archivo de texto
    outfile.close();
    
    return 0;
}
