#include <iostream>

using namespace std;

int main (){
    int n;
    int ordenador;
    cin >> n;
    int vetor [n];
    
    for (int i = 0; i < n; i++){
        cin >> vetor[i];
    }
    for (int i = 1; i < n; i++){
    if (vetor[i] >= vetor[i-1]){
        ordenador++;
        } 
    }
    if (ordenador == n){
        cout << "ok" << endl;
    } else {
        cout << "precisa de ajuste" << endl;
        }
}