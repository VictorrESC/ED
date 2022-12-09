// A entrada é composta de quinze linhas, cada uma contendo o resultado de um jogo. A primeira linha contém o resultado do jogo de número 1, a segunda linha o resultado do jogo de número 2, e assim por diante. O resultado de um jogo é representado por dois números inteiros MM e NN separados por um espaço em branco, indicando respectivamente o número de gols da equipe representada à esquerda e à direita na tabela de jogos.

// Seu programa deve imprimir uma única linha, contendo a letra identificadora da equipe campeã.

/*Coloque as 16 letras em uma fila
Pegue as duas primeiras
que no caso seriam A e B
leia os gols
decida quem você coloca de novo na fila
Continue até que só existe um elemento na fila
*/

#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
    Queue *q = new Queue(16);
    for (int i = 0; i < 16; i++) {
        q->push(i + 65);
    }
    while (q->getSize() > 1) {
        int a = q->front();
        q->pop();
        int b = q->front();
        q->pop();
        int ga, gb;
        cin >> ga >> gb;
        if (ga > gb) {
            q->push(a);
        } else {
            q->push(b);
        }
    }
    cout << (char)q->front() << endl;
    delete q;
    return 0;
}