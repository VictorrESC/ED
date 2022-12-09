#include <iostream>
#include <iomanip>

using namespace std;

typedef struct{
    
    int matricula;
    string nome;
    double media;


    void le_aluno(){
    
        cin >> matricula;
        cin.ignore();
        getline (cin, nome);
        cin >> media;
    }

}aluno;

int procura_aluno(aluno& x, int matricula_desejada){
    
    if(x.matricula == matricula_desejada){
        return 1;
    } 
    else {
        return 0;
    }
}

int main (){
    int numerodealunos;
    cin >> numerodealunos;
    
    aluno x[numerodealunos];
    
    for (int i = 0; i < numerodealunos; i++){
       x[i].le_aluno();
    }
    
    int matricula_desejada;
    cin >> matricula_desejada;
    bool verifica_aluno = false;
    
    for (int i = 0; i < numerodealunos; i++){
        if(procura_aluno(x[i], matricula_desejada) == true){
            cout << fixed << setprecision(1);
            cout << x[i].nome << endl;
            cout << x[i].media;
            verifica_aluno = true;
        }
    }
    if(verifica_aluno == false){
        cout << "NAO ENCONTRADA";
    }
}