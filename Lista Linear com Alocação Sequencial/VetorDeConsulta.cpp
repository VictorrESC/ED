//Há um vetor de strings de entrada e um vetor de strings de consulta. Para cada sequência de consultas, determine quantas vezes ela ocorre na lista de sequências de entrada.

//Por exemplo, dado o vetor entrada = [‘ab’,‘ab’,‘abc’ ] e o vetor consultas = [‘ab’,‘abc’,‘bc’], encontramos duas instâncias de ‘ab’ , uma instância de ‘abc’ e zero instâncias de ‘bc’. Para cada consulta, adicionamos um elemento ao nosso vetor de retorno.

//Implemente a função matchingStrings. A função deve retornar um vetor de números inteiros representando a frequência de ocorrência de cada sequência de consultas.

//matchingStrings tem os seguintes parâmetros:

//strings – um vetor de strings para pesquisar
//consultas – um vetor de sequências de consultas

//Formato de entrada:

//Linha 1: tamanho do vetor de consultas
//Linha 2: vetor de consultas
//Linha 3: tamanho do vetor de buscas
//Linha 4: vetor de buscas

//Formato de saída:
//Retorne um vetor inteiro dos resultados de todas as consultas em ordem.

//Exemplo de entrada:
//4
//aba baba aba xzxb
//3
//aba xzxb ab

//Exemplo de saída:
//2 1 0 

//Explicação
//Há duas ocorrências de 'aba' , uma ocorrência de 'xzxb' e zero ocorrências de 'ab'. Portanto, retornamos 2 1 0 espaçados por espaço.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> matchingStrings(vector<string> strings, vector<string> consultas) {
    vector<int> retorno;
    for (int i = 0; i < consultas.size(); i++){
        int cont = 0;
        for (int j = 0; j < strings.size(); j++){
            if (consultas[i] == strings[j]){
                cont++;
            }
        }
        retorno.push_back(cont);
    }
    return retorno;
}

int main()
{
    int n;
    cin >> n;
    vector<string> strings(n);

    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }
    int q;
    cin >> q;
    vector<string> consultas(q);
    for (int i = 0; i < q; i++) {
        cin >> consultas[i];
    }
    vector<int> res = matchingStrings(strings, consultas);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i != res.size() - 1) {
            cout << " ";
        }
    }
    cout << " ";
    return 0;
}