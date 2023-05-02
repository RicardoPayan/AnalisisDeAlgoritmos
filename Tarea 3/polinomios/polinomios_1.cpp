#include <iostream>
#include <chrono>
#include <fstream>

const int MIN_N = 100000;
const int MAX_N = 1000000;
const int STEP = 100000;

typedef float TPolinomio[MAX_N+1];

float EvaluaPolinomio(TPolinomio C, float X, int N) {
    int i, j;
    float XN, S;
    S = C[0];
    for (i = 0; i <= N; i++) {
        XN = 1.0;
        for (j = 1; j <= i; j++) {
            XN = XN * X;
        }
        S = S + C[i] * XN;
    }
    return S;
}

int main() {
    int N;
    TPolinomio C;
    float X = 1.23f; // Valor arbitrario para X
    std::ofstream output("resultados.txt");
    output << "N\tTiempo (ms)\n";

    for (N = MIN_N; N <= MAX_N; N += STEP) {
        // Inicializar el polinomio C con valores arbitrarios
        for (int i = 0; i <= N; i++) {
            C[i] = i * 1.5f + 2.0f;
        }

        // Medir el tiempo de ejecución
        auto start = std::chrono::high_resolution_clock::now();
        float resultado = EvaluaPolinomio(C, X, N);
        auto end = std::chrono::high_resolution_clock::now();

        // Calcular el tiempo transcurrido y escribir el resultado en el archivo
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        float tiempo_ms = duration.count() / 1000.0f;
        output << N << "\t" << tiempo_ms << "\n";

        std::cout << "Para N = " << N << ", el resultado es " << resultado << " y tardó " << tiempo_ms << " ms.\n";
    }
    output.close();

    return 0;
}
