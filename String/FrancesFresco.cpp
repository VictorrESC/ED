#include <iostream>
#include <string>

using namespace std;

int main(){
    char letra[100];
    cin.get(letra, 100);
    
    for (int i=0; letra[i]; i++){
        if (letra[i] == ' '){
            if (letra[i-1] == letra[i+1]){
                i++;
            } else {
                cout << letra[i];
            }
        } else if (letra[i] != ' '){
            cout << letra[i];
        }
    }
    return 0;
}