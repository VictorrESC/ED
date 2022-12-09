#include <iostream>
#include <stack>
#include <queue>
#include "Queue.h"

using namespace std;

void Queue::push_back(int x) {
    deposito.push(x);
}

void Queue::pop_front() {
    if (prateleira.empty()){
        while (!deposito.empty()){
            prateleira.push(deposito.top());
            deposito.pop();
        }
    }

    prateleira.pop();
}

int Queue::front() {
    if (prateleira.empty()){
        while (!deposito.empty()){
            prateleira.push(deposito.top());
            deposito.pop();
        }
    }

    return prateleira.top();
}
