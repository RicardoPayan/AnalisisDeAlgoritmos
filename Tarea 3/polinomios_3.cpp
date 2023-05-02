#include "librerias.h"

const int N = 3;

// Tipo de dato TPolinomio
typedef double TPolinomio[N+1];

// Función EvaluaPolinomio
double EvaluaPolinomio(TPolinomio C, double X) {
    double S = C[N];
    for (int i = N-1; i >= 0; i--) {
        S = S*X + C[i];
    }
    return S;
}

int main() {
    TPolinomio polinomio = {1.0, 2.0, 3.0, 4.0};
    double resultado = EvaluaPolinomio(polinomio, 2.5);
    std::cout << "El resultado de evaluar el polinomio_3 en x = 2.5 es: " << resultado << std::endl;
    return 0;
}