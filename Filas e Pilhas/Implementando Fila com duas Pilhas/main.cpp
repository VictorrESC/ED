#include <iostream>
#include <stack>
#include <queue>
#include "Queue.h"

using namespace std;

// A primeira linha contém um único número inteiro, q, denotando o número de consultas. Cada linha i das q linhas subsequentes contém uma única consulta no padrão descrito acima no problema. Todas as três consultas começam com um número inteiro que indica o tipo da consulta, mas apenas a primeira consulta é seguida por um valor adicional x separado por espaço, indicando o valor a ser enfileirado.

// Para cada consulta do tipo 3, imprima o valor do elemento na frente da fila em uma nova linha. As consultas de tipo 1 e 2 não necessitam imprimir nada.

int main() {
    int q;
    cin >> q;

    Queue fila;

    for (int i = 0; i < q; i++) {
        int tipo;
        cin >> tipo;

        if (tipo == 1) {
            int x;
            cin >> x;
            fila.push_back(x);
        } else if (tipo == 2) {
            fila.pop_front();
        } else {
            cout << fila.front() << endl;
        }
    }

    return 0;
}