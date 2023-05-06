#include <iostream>
#include <chrono>
#include <fstream>
#include <random>

using namespace std;

int BinSearch2(int a[], int n, int x) {
    int low = 1, high = n + 1;
    while (low < (high - 1)) {
        int mid = (low + high) / 2;
        if (x < a[mid]) high = mid;
        else low = mid;
    }
    if (x == a[low]) return low;
    else return 0;
}

int main() {
    ofstream archivo;
    archivo.open("resultados_binSearch2.txt");
    archivo << "n" << "\t" << "Tiempo (microsegundos)" << endl;

    const int MIN_N = 100000;
    const int MAX_N = 1000000;
    const int STEP = 100000;

    for (int n = MIN_N; n <= MAX_N; n += STEP) {
        int a[n];
        for (int i = 0; i < n; i++) {
            a[i] = i + 1;
        }
        int x = rand() % n + 1;

        auto start = chrono::high_resolution_clock::now();
        int result = BinSearch2(a, n, x);
        auto stop = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        archivo << n << "\t" << duration.count() << endl;
    }

    archivo.close();
    return 0;
}
