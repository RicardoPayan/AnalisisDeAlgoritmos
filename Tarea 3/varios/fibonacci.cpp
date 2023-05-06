#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;

int fibonacci(int n) {
    if(n<=1) {
        return n;
    } else {
        int fnm2 = 0;
        int fnm1 = 1;
        int fn;
        for(int i=2; i<=n; i++) {
            fn = fnm1 + fnm2;
            fnm2 = fnm1;
            fnm1 = fn;
        }
        return fn;
    }
}

int main() {
    ofstream resultados("resultados_fibonacci.txt");
    int tamano_min = 10000;
    int tamano_max = 100000;
    int intervalo = 10000;

    for(int n = tamano_min; n <= tamano_max; n += intervalo) {
        auto start_time = chrono::high_resolution_clock::now();
        fibonacci(n);
        auto end_time = chrono::high_resolution_clock::now();
        auto tiempo_microsegundos = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

        resultados << n << "\t" << tiempo_microsegundos << endl;
    }

    resultados.close();
    return 0;
}
