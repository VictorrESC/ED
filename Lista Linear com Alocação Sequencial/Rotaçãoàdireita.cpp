//Uma rotação desloca os elementos do vetor em uma determinada direção. Uma rotação à direita equivale a pegar o último elemento e inserí-lo na primeira posição.

//Implemente a operação de rotação. Observe que calculando as posições finais corretamente você fará uma única operação de transposição das posições do vetor.

//Entrada:
//Linha 1: tamanho do vetor T e número de elementos rotacionados
//Linha 2: elementos do vetor

//Saída:
//vetor rotacionado

#include <iostream>
#include <vector>
using namespace std;

void right_rotation(vector<int>& vet, int nrot){
    int aux;
    for (int i = 0; i < nrot; i++){
        aux = vet[vet.size()-1];
        for (int j = vet.size()-1; j > 0; j--){
            vet[j] = vet[j-1];
        }
        vet[0] = aux;
    }
}

void show(vector<int> &vet) {
    cout << "[ ";
    for(int value : vet)
        cout << value << " ";
    cout << "]\n";
}

int main(){
    int size, nrot;
    cin >> size >> nrot;
    vector<int> vet(size);
    for(int i = 0; i < size; i++)
        cin >> vet[i];
    
    right_rotation(vet, nrot);
    show(vet);
}

