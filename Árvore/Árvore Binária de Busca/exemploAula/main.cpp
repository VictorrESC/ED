#include <iostream>
#include <string>
#include <sstream>
#include "bst.h"
using namespace std;

int main() {
    BST t;
    string skeys;
    int k;
    
    cout << "Digite as chaves separadas por espacos: ";
    getline(cin, skeys);
    stringstream ss { skeys };
    
    while(ss >> k) t.add(k); // adiciona as chaves na arvore

    cout << "Menor chave: " << t.minimum() << endl;

    t.inorder(); // ordem simétrica

    cout << endl;

    cout << "contains 16? " << boolalpha << t.contains(16) << endl;

    cout << endl;
    return 0;
}
