#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

// escreva uma funcao que inverta aordem das letras de cada palavra de uma sentença, preservando a ordem das palavras
// Exemplo: "O rato roeu a roupa do rei de roma" -> "O otaor ueor a apour od ier ed amor"

string reverse (string line) {
    Stack<char> *pilha = new Stack<char>();
    string result = "";
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == ' ' || line [i] == '\0') {
            while (!pilha->empty()) {
                result += pilha->top();
                pilha->pop();
            }
            result += ' ';
        } else {
            pilha->push(line[i]);
        }
    }
    while (!pilha->empty()) {
        result += pilha->top();
        pilha->pop();
    }
    return result;
}

int main () {
    string line;
    getline(cin, line);
    cout << reverse(line) << endl;
}