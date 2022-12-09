#include <iostream>

using namespace std;

typedef struct {
    
    string nome;
    int matricula;
    string disciplina;
    double nota;
} aluno;

aluno leAluno(){
    aluno aluno;
   

    getline(cin, aluno.nome);
    cin >> aluno.matricula;
    cin.ignore();
    getline(cin, aluno.disciplina);
    cin >> aluno.nota;

    return aluno;
}

void imprimeAluno(aluno aluno){
    if (aluno.nota >= 7){
        cout << aluno.nome << " aprovado(a) em " << aluno.disciplina;
    }
    else {
        cout << aluno.nome << " reprovado(a) em " << aluno.disciplina;
    }
}

int main (){
    
    aluno x = leAluno();
    
    imprimeAluno(x);
    
    return 0;
}