#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void Add(int** a, int** b, int** c, int m, int n){
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

int main() {
    ofstream outfile;
    outfile.open("resultados_add.txt");

    for (int size = 1000; size <= 10000; size += 1000) {
        int m = size;
        int n = size;

        int** a = new int*[m];
        int** b = new int*[m];
        int** c = new int*[m];
        for (int i = 0; i < m; i++) {
            a[i] = new int[n];
            b[i] = new int[n];
            c[i] = new int[n];
            for (int j = 0; j < n; j++) {
                a[i][j] = rand() % 100;
                b[i][j] = rand() % 100;
            }
        }

        auto start = high_resolution_clock::now();
        Add(a, b, c, m, n);
        auto end = high_resolution_clock::now();

        auto duration = duration_cast<milliseconds>(end - start);

        outfile << m << "x" << n << ", " << duration.count() << "ms\n";

        for (int i = 0; i < m; i++) {
            delete[] a[i];
            delete[] b[i];
            delete[] c[i];
        }
        delete[] a;
        delete[] b;
        delete[] c;
    }

    outfile.close();
    return 0;
}
