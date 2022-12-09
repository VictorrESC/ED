#include <iostream>
#include <sstream>
#include "Queue.h"
using namespace std;

// funcao que recebe tres filas e transfira alternadamente os elementos.
// a funcao deve unir as duas filas em uma terceira.
// as duas primeiras filas devem ser vazias ao final da execucao e a terceira com todos os valores originalmente presentes nas duas primeiras.

template < typename T>
void Queue<T>::combina_filas(Queue& f_res, Queue& f1, Queue& f2) {

    while (!f1.empty()&& !f2.empty()) {
        f_res.push(f1.front());
        f_res.push(f2.front());
        f1.pop();
        f2.pop();
    }
    while (!f1.empty()) {
        f_res.push(f1.front());
        f1.pop();
    }

    while (!f2.empty()) {
        f_res.push(f2.front());
        f2.pop();
    }
}

int main() {
    Queue<int> fila1; // cria fila vazia
    Queue<int> fila2; // cria fila vazia
    Queue<int> fila_res; // cria fila vazia

    for(int i = 1; i <= 7; i++){
        fila1.push(i);  // enfileira
    }
    for(int j = 12; j <= 15; j++){
        fila2.push(j);  // enfileira
    }

    fila_res.combina_filas(fila_res, fila1, fila2);

    while (!fila_res.empty()) {
        cout << fila_res.front() << " ";
        fila_res.pop();
    }
    cout << endl;
}