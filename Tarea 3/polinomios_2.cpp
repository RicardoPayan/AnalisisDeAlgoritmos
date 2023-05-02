#include "librerias.h"

//Complejidad computacional: O(n log n)
#include <iostream>

const int N = 3;

// Prototipo de la función Potencia
double Potencia(double X, int j);

// Tipo de dato TPolinomio
typedef double TPolinomio[N+1];

// Función EvaluaPolinomio
double EvaluaPolinomio(TPolinomio C, double X) {
    double S = C[0];
    for (int i = 1; i <= N; i++) {
        S += C[i] * Potencia(X, i);
    }
    return S;
}

// Función Potencia
double Potencia(double X, int j) {
    if (j == 0) {
        return 1.0;
    } else if (j % 2 == 1) {
        return X * Potencia(X, j-1);
    } else {
        double t = Potencia(X, j/2);
        return t * t;
    }
}

int main() {
    TPolinomio polinomio = {1.0, 2.0, 3.0, 4.0};
    double resultado = EvaluaPolinomio(polinomio, 2.5);
    std::cout << "El resultado de evaluar el polinomio_2 en x = 2.5 es: " << resultado << std::endl;
    return 0;
}
