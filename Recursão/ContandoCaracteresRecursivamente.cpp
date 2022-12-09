#include <iostream>
#include <string>

using namespace std;

// Retorna o números de ocorrências do caractere 'c' na string 'str' (com 'n' caracteres).
// Algoritmo deve ser recursivo e sem comandos de repetição.
int contaCaracteres(string str, int n, char c)
{
    if (n == 1){
        if (str[n-1] == c){
            return 1;
        }else {
            return 0;
        }
    }
    else {
        if (str[n-1] == c){
            return 1+contaCaracteres(str, n-1, c);
        }
        else {
            return contaCaracteres(str, n-1, c);
        }
    }
}

int main() 
{
   string str;
   getline (cin, str);
   char c;
   cin >> c;
   
   int n = str.size();
   
   cout << contaCaracteres(str, n, c);
}