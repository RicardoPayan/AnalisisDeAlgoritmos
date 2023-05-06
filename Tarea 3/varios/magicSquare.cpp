#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;

void Magic(int n){
    if ((n % 2) == 0) {
        cout << "n is even" << endl;
        return;
    }
    else
    {
        int square[n][n];
        for (int i=0; i<n; i++) //Initialize square to zero
            for (int j=0; j<n; j++) square[i][j]=0;
        square[0][(n-1)/2]=1; // Middle of first row
        // (i,j) is current position
        int i=0, j=(n-1)/2;
        for (int key=2; key<=n*n; key++){
            int k = i-1, l = j-1;
            if(i >= 1) k = i-1; else k = n-1;
            if(j >= 1) l = j-1; else l = n-1;
            if(square[k][l]>=1) i=(i+1) % n;
            else i = k, j = l;
            square[i][j] = key;
        }
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++) cout << square[i][j] << " ";
            cout << endl;
        }
    }
}

int main() {
    ofstream resultados("resultados_magic.txt");
    for (int n=101; n<=1001; n+=101){
        auto start = chrono::high_resolution_clock::now();
        Magic(n);
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
        resultados << n << " " << duration.count() << endl;
    }
    resultados.close();
    return 0;
}
