#include "librerias.h"

//Complejidad computacional: O(n^2)
const int N = 3; // Definimos N como 3
using TPolinomio = std::array<double, N + 1>;


double EvaluaPolinomio(const TPolinomio& C, double X) {
    double S = C[0];
    for (int i = 1; i <= N; ++i) {
        double XN = 1.0;
        for (int j = 1; j <= i; ++j) {
            XN = XN * X;
        }
        S = S + C[i] * XN;
    }
    return S;
}


int main() {
    // Creamos un polinomio de ejemplo
    TPolinomio p {{1, 2, 3, 4}};

    // Evaluamos el polinomio en x = 2.5
    double resultado = EvaluaPolinomio(p, 2.5);

    // Mostramos el resultado
    std::cout << "El resultado de evaluar el polinomio en x = 2.5 es: " << resultado << std::endl;

    return 0;
}
