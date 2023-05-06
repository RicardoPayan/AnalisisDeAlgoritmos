#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

double RSum(int* a, int n) {
    if (n <= 0) {
        return 0.0;
    } else {
        return RSum(a, n-1) + a[n-1];
    }
}

int main() {
    ofstream myfile;
    myfile.open("resultados_Rsum.txt");

    for (int n = 10000; n <= 100000; n += 10000) {
        int* a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = i;
        }

        auto start = high_resolution_clock::now();
        double result = RSum(a, n);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        myfile << n << " " << duration.count() << endl;

        delete[] a;
    }

    myfile.close();

    return 0;
}
