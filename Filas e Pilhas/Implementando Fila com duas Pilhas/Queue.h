#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Queue {
    private:
        stack<int> deposito;
        stack<int> prateleira;
    public:
        Queue() = default;

        void push_back(int x);
        void pop_front();
        int front();
};

#endif