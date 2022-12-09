#include <iostream>

using namespace std;

int main (){
    int matriz[3][3];
    int linhas = 0, colunas = 0, dp = 0, ds = 0;
    
    // entrada da matriz
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cin >> matriz[i][j];
        }
    }
    // soma da diagonal principal
    for (int i=0; i<3; i++){
        dp += matriz[i][i];
    }
    // soma da diagonal secundaria
    for (int i=0; i<3; i++){
        ds += matriz[i][3-i-1];
    }
    // soma das linhas
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            linhas += matriz[0][0] + matriz[1][0] + matriz [2][0];
        }
    }
    // soma das colunas
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            colunas += matriz[0][0] + matriz[0][1] + matriz [0][2];
        }
    }
    if (linhas && colunas && dp == ds){
        cout << "sim" << endl;
    } else {
        cout << "nao" << endl;
    }
}
