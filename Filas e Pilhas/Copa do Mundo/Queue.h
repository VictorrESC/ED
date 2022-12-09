// A entrada é composta de quinze linhas, cada uma contendo o resultado de um jogo. A primeira linha contém o resultado do jogo de número 1, a segunda linha o resultado do jogo de número 2, e assim por diante. O resultado de um jogo é representado por dois números inteiros MM e NN separados por um espaço em branco, indicando respectivamente o número de gols da equipe representada à esquerda e à direita na tabela de jogos.

// Seu programa deve imprimir uma única linha, contendo a letra identificadora da equipe campeã.


#include <iostream>

using namespace std;

class Queue {
    private:
        int *data;
        int size;
        int max;
    public:
        Queue(int max);
        ~Queue();

        int getSize();
        void push(int val);
        void pop();
        int front();
        bool empty();
        bool full();
        void print();
};

Queue::Queue(int max) {
    this->max = max;
    data = new int[max];
    size = 0;
}

Queue::~Queue() {
    delete[] data;
}

int Queue::getSize() {
    return size;
}

void Queue::push(int val) {
    if (full()) {
        cout << "Fila cheia" << endl;
        return;
    }
    data[size] = val;
    size++;
}

void Queue::pop() {
    if (empty()) {
        cout << "Fila vazia" << endl;
        return;
    }
    for (int i = 0; i < size - 1; i++) {
        data[i] = data[i + 1];
    }
    size--;
}

int Queue::front() {
    if (empty()) {
        cout << "Fila vazia" << endl;
        return -1;
    }
    return data[0];
}

bool Queue::empty() {
    return size == 0;
}

bool Queue::full() {
    return size == max;
}

void Queue::print() {
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

