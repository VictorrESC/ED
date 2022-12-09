#include <iostream>
#include <iomanip>

using namespace std;

typedef struct {
    
    string nome;
    int matricula;
    string disciplina;
    double nota;
} aluno;

aluno leAluno(){
    aluno aluno;
   

    cin >> aluno.nome;
    cin >> aluno.matricula;
    cin.ignore();
    cin >> aluno.disciplina;
    cin >> aluno.nota;

    return aluno;
}

void comparaAluno(aluno aluno1, aluno aluno2){
    
    cout << fixed << setprecision(1);
    
    if (aluno1.nota > aluno2.nota){
        cout << aluno1.nome << " , " << aluno1.nota;
    }
    else if (aluno2.nota > aluno1.nota){
        cout << aluno2.nome << " , " << aluno2.nota;
    } else {
        cout << aluno1.nome << " e " << aluno2.nome << " , " << aluno1.nota;
    }
}

int main (){
    
    aluno x = leAluno();
    aluno y = leAluno();
    
    comparaAluno(x,y);
    
    return 0;
}