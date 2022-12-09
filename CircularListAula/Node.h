// Nao mexa, ja esta terminado
#ifndef NODE_H
#define NODE_H
#include <iostream>

using Item = double;

struct Node {
    Item value;
    Node* next;

    Node(const Item& val, Node *nextPtr) {
        value = val;
        next = nextPtr;
    }
    ~Node() {
        std::cout << "node " << value << " deletado" << std::endl;
    }
};

#endif