#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

void Mult(int** a, int** b, int** c, int m, int n, int p){
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            c[i][j] = 0;
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    ofstream archivo("resultados_mult.txt");

    for (int size = 100; size <= 1000; size += 100) {
        int** a = new int*[size];
        int** b = new int*[size];
        int** c = new int*[size];
        for (int i = 0; i < size; i++) {
            a[i] = new int[size];
            b[i] = new int[size];
            c[i] = new int[size];
            for (int j = 0; j < size; j++) {
                a[i][j] = rand() % 10;
                b[i][j] = rand() % 10;
            }
        }

        auto start = high_resolution_clock::now();

        Mult(a, b, c, size, size, size);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);

        archivo << size << " " << duration.count() << endl;

        for (int i = 0; i < size; i++) {
            delete[] a[i];
            delete[] b[i];
            delete[] c[i];
        }
        delete[] a;
        delete[] b;
        delete[] c;
    }
    archivo.close();
    return 0;
}
