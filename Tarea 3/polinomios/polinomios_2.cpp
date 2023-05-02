#include <iostream>
#include <chrono>
#include <fstream>

const int N_MAX = 1000000;

using namespace std;
using namespace std::chrono;

typedef float TPolinomio[N_MAX + 1];

float Potencia(float X, int j) {
    float t;
    if (j == 0) {
        return 1.0;
    }
    else if (j % 2 == 1) {
        return X * Potencia(X, j - 1);
    }
    else {
        t = Potencia(X, j / 2);
        return t * t;
    }
}

float EvaluaPolinomio(TPolinomio C, float X, int N) {
    float S = C[0];
    for (int i = 0; i <= N; ++i) {
        S += C[i] * Potencia(X, i);
    }
    return S;
}

int main() {
    std::ofstream output("resultados2.txt");
    output << "N\tTiempo (ms)\n";

    TPolinomio C;
    for (int i = 0; i <= N_MAX; ++i) {
        C[i] = i;
    }

    for (int N = 100000; N <= N_MAX; N += 100000) {
        auto start = high_resolution_clock::now();

        float resultado = EvaluaPolinomio(C, 2.5, N);

        auto stop = high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        float tiempo_ms = duration.count() / 1000.0f;
        output << N << "\t" << tiempo_ms << "\n";

        std::cout << "Para N = " << N << ", el resultado es " << resultado << " y tardó " << tiempo_ms << " ms.\n";
    }

    output.close();

    return 0;
}
