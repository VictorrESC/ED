#include <iostream>

using  namespace std;


int main (){
    string texto;
    getline(cin, texto);

    for (int i=0; texto[i];i++){
        if (texto[i] == ' ' || texto[i] == '\t'){
            while (texto[i] == ' ' || texto[i] == '\t'){
                i++;
            }
            cout << ' ';
            i--;
        }
        else {
            cout << texto[i];
        }
    }
}