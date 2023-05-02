#include <iostream>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;

const int MIN_N = 100000;
const int MAX_N = 1000000;
const int INTERVALO = 100000;

typedef double TPolinomio[MAX_N+1];

double EvaluaPolinomio(TPolinomio C, double X) {
    double S = 0.0;
    for (int i = MAX_N; i >= 0; i--) {
        S = S * X + C[i];
    }
    return S;
}

int main() {
    std::ofstream output("resultados_horner.txt");
    output << "N\tTiempo (ms)\n";

    for (int n = MIN_N; n <= MAX_N; n += INTERVALO) {
        TPolinomio C;
        for (int i = 0; i <= n; i++) {
            C[i] = 1.0;
        }

        auto start = std::chrono::high_resolution_clock::now();
        double resultado = EvaluaPolinomio(C, 2.0);
        auto end = std::chrono::high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(end - start);
        float tiempo_ms = duration.count() / 1000.0f;
        output << n << "\t" << tiempo_ms << "\n";

        std::cout << "Para N = " << n << ", el resultado es " << resultado << " y tardó " << tiempo_ms << " ms.\n";
    }

    output.close();
    return 0;
}
