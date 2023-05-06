#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;

double Sum(int a[], int n) {
    double s = 0;
    for (int i = 0; i < n; i++) {
        s += a[i];
    }
    return s;
}

int main() {
    ofstream resultados("resultados_sum.txt");
    if (!resultados.is_open()) {
        cout << "Error al abrir archivo de resultados." << endl;
        return 1;
    }
    for (int n = 10000; n <= 100000; n += 10000) {
        int a[n];
        for (int i = 0; i < n; i++) {
            a[i] = i;
        }
        auto start = chrono::high_resolution_clock::now();
        double s = Sum(a, n);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        resultados << n << " " << duration.count() << endl;
        cout << "n = " << n << ", tiempo = " << duration.count() << " microsegundos." << endl;
    }
    resultados.close();
    return 0;
}
    