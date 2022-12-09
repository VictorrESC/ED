//Com a proximidade da Copa do Mundo, o fluxo de pessoas nas filas para compra de ingressos aumentou consideravelmente. Como as filas estão cada vez maiores, pessoas menos pacientes tendem a desistir da compra de ingressos e acabam deixando as filas, liberando assim vaga para outras pessoas. Quando uma pessoa deixa a fila, todas as pessoas que estavam atrás dela dão um passo a frente, sendo assim nunca existe um espaço vago entre duas pessoas. A fila inicialmente contém N pessoas, cada uma com um identificador diferente.

//Joãozinho sabe o estado inicial dela e os identificadores em ordem das pessoas que deixaram a fila. Sabendo que após o estado inicial nenhuma pessoa entrou mais na fila, Joãozinho deseja saber o estado final da fila.

//Entrada:
//A primeira linha da entrada contém um inteiro N, o número de pessoas na fila inicialmente. A segunda linha contém N inteiros distintos, cada um representando o identificador de uma pessoa na fila inicialmente. A terceira linha contém um inteiro M (0 ≤ M ≤ N), o número de pessoas que deixaram a fila. A quarta linha contém M inteiros distintos, cada um representando o identificador de uma pessoa que deixou a fila, na ordem em que ela deixou a fila.

//Saída:
//Seu programa deve imprimir uma única linha contendo N-M inteiros, representando o estado final da fila, na ordem em que as pessoas ficaram na fila.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int N, M;
    vector<int> fila;
    cin >> N;
    int id, i = 0;
    while (i < N){
        cin >> id;
        fila.push_back(id);
        i++;
    }
    cin >> M;
    while (M > 0){
        cin >> id;
        for (int i = 0; i < fila.size(); i++){
            if (fila[i] == id){
                fila.erase(fila.begin() + i);
            }
        }
        M--;
    }
    for (int i = 0; i < fila.size(); i++){
        cout << fila[i] << " ";
    }
    cout << endl;
}