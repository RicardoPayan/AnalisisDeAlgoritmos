#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;

const int N = 1000000; // Tamaño máximo de polinomio
typedef float TPolinomio[N+1]; // Definición del tipo polinomio

float EvaluaPolinomio(TPolinomio C, float X) {
    float XN = 1.0;
    float S = C[0];
    for (int i = 0; i <= N; i++) {
        XN *= X;
        S += C[i] * XN;
    }
    return S;
}

int main() {
    ofstream archivo("resultados.txt"); // Archivo para registrar resultados
    archivo << "N\tTiempo(ms)" << endl;
    for (int n = 100000; n <= 1000000; n += 100000) {
        TPolinomio polinomio;
        for (int i = 0; i <= n; i++) {
            polinomio[i] = i; // Polinomio de prueba
        }
        auto inicio = chrono::high_resolution_clock::now(); // Inicio del temporizador
        float resultado = EvaluaPolinomio(polinomio, 2.0); // Prueba del algoritmo
        auto fin = chrono::high_resolution_clock::now(); // Fin del temporizador
        auto tiempo = chrono::duration_cast<chrono::milliseconds>(fin - inicio).count(); // Cálculo del tiempo de ejecución
        archivo << n << "\t" << tiempo << endl; // Registro de resultados en el archivo
    }
    archivo.close(); // Cierre del archivo
    return 0;
}
