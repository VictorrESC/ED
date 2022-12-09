/*Entrada
Linha 1: número de linhas e das colunas da matriz
Linhas subsequentes: matriz composta por 4 caracteres
# representa uma parede
representa um corredor por onde se pode andar
I representa o início
F representa o fim
Saída
Imprima a matriz utilizando o char . para mostrar o caminho entre início e fim
*/

/*
Para resolver, você deve utilizar uma pilha no lugar da recursão.
marque e empilhe a posição inicio
inicie a pilha com esse elemento
enquanto a pilha não estiver vazia faça
    pegue topo da fila
    se ele for o destino
        retorne

    faça uma lista com todos os vizinhos de topo que ainda não foram percorridos
    se lista eh vazia
        desempilhe
    senão
        escolha um dos vizinhos
        marque
        empilhe
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Pos{
    int l;
    int c;
};

//retorna um vetor com todos os vizinhos da posição p
vector<Pos> get_vizinhos(Pos p){
    return {{p.l, p.c - 1}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l + 1, p.c}};
}

int main(){
    int nl = 0, nc = 0;
    cin >> nl >> nc;
    vector<string> mat(nl, ""); //começa com nl strings ""
    getchar();//remove \n after nc
    Pos inicio, fim;

    //carregando matriz
    for(int i = 0; i < nl; i++)
        getline(cin, mat[i]);

    //procurando inicio e fim e colocando ' ' nas posições iniciais
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            if(mat[l][c] == 'I'){
                mat[l][c] = ' ';
                inicio = Pos {l, c};
            }
            if(mat[l][c] == 'F'){
                mat[l][c] = ' ';
                fim = Pos {l, c};
            }
        }
    }       

    // marcar e empilhar a posição inicio
    mat[inicio.l][inicio.c] = '.';
    stack<Pos> pilha;   
    pilha.push(inicio);

    // enquanto a pilha não estiver vazia faça
    while(!pilha.empty()){
        // quebra de linha para melhor visualização
        Pos topo = pilha.top();
        // se ele for o destino
        if(topo.l == fim.l && topo.c == fim.c){
            // retorne
            return 0;
        }
        // faça uma lista com todos os vizinhos de topo que ainda não foram percorridos
        vector<Pos> vizinhos = get_vizinhos(topo);
        vector<Pos> vizinhos_validos;
        for(Pos p : vizinhos){
            if(p.l >= 0 && p.l < nl && p.c >= 0 && p.c < nc && mat[p.l][p.c] == ' '){
                vizinhos_validos.push_back(p);
            }
        }
        // se lista eh vazia
        if(!vizinhos_validos.empty()){
            // desempilhe
            pilha.pop();
        } else { // senão
            //     escolha um dos vizinhos
            Pos p = pilha.top();
            //     marque
            mat[p.l][p.c] = '.';
            //     empilhe
            pilha.push(p);
        }
    }

    //imprimindo matriz
    for(int i = 0; i < nl; i++){
        cout << mat[i] << endl;
    }

    
    for(string line : mat){
        cout << line << endl
             << nl << nc << "\n"
             << inicio.l << inicio.c << endl
             << fim.l << fim.c << endl;
    }
}