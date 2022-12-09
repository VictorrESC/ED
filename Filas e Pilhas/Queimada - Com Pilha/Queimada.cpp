/*
Refaça o problema da queimada utilizando pilha no lugar da recursão.

Você pode utilizar esse algoritmo.

verifique a primeira posição e queime-o
inicie a pilha com esse elemento
enquanto a pilha não estiver vazia faça
    pegue topo da pilha

    faça uma lista com todos os vizinhos de topo que podem ser queimados
    se lista eh vazia
        desempilhe
    senão
        escolha um dos vizinhos
        queime
        empilhe
*/


// utilize pilha ao invés de recursão

#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;


void show(string *mat, int nl) {
    for(int l = 0; l < nl; l++)
        cout << mat[l] << "\n";
}

void tocar_fogo(int nl, int nc, string* mat, int l, int c){
    //TODO faca seu codigo aqui
    stack<pair<int, int>> pilha;
    pilha.push(make_pair(l, c));
    if (mat[l][c] == '#') { 
        mat[l][c] = 'o';
        while (!pilha.empty()){
            pair <int, int> topo = pilha.top();
            pilha.pop();
            vector<pair<int, int>> vizinhos = {{topo.first - 1, topo.second}, {topo.first + 1, topo.second}, {topo.first, topo.second - 1}, {topo.first, topo.second + 1}};
            for (int i = 0; i < vizinhos.size(); i++){
                if (vizinhos[i].first >= 0 && vizinhos[i].first < nl && vizinhos[i].second >= 0 && vizinhos[i].second < nc && mat[vizinhos[i].first][vizinhos[i].second] == '#'){
                    mat[vizinhos[i].first][vizinhos[i].second] = 'o';
                    pilha.push(vizinhos[i]);
                }
            }

        }
    }
}

int main(){
    int nl = 0, nc = 0, lfire = 0, cfire = 0;
    cin >> nl >> nc >> lfire >> cfire;
    string* mat = new string[nl];
    for(int l = 0; l < nl; l++){
        string line;
        cin >> line;
        mat[l] = line;
    }
    tocar_fogo(nl, nc, mat, lfire, cfire);
    show(mat, nl);
    delete[] mat;
}