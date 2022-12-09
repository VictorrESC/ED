#include <iostream>

using namespace std;

int main (){
    int matriz[3][3];
    int cont = 0;
    
    // entrada da matriz
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cin >> matriz[i][j];
        }
    }

    // verifica  se está em ordem
    for (int i=0; i<3; i++){
        for (int j=1; j<3; j++){
            if(matriz[j][i] < matriz[j-1][i]){
                cont++;
            }
        }
    }
    cout << cont << endl;
}