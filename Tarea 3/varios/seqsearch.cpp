#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int SeqSearch(int a[], int x, int n) {
    // Search for x in a[1:n]. a[0] is used as additional space.
    int i = n;
    a[0] = x;
    while (a[i] != x) {
        i--;
    }
    return i;
}

int main() {
    ofstream file("resultados_seqsearch.txt");
    int n, x;
    int a[100001]; // Array size is 100001 to accommodate n = 100000
    for (n = 10000; n <= 100000; n += 10000) {
        // Generate array a[1:n] with random values from 1 to n
        for (int i = 1; i <= n; i++) {
            a[i] = rand() % n + 1;
        }
        // Search for a random value x in array a
        x = rand() % n + 1;
        auto start = high_resolution_clock::now();
        SeqSearch(a, x, n);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        file << n << "\t" << duration.count() << endl;
    }
    file.close();
    return 0;
}
