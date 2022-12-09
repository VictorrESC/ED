#include <iostream>

using namespace std;

char paraMinusculo (char c){
    if (c >= 'A' && c <= 'Z'){
        return c + 32;
    }
}

char paraMaiusculo (char c){ 
    if (c >= 'a' && c <= 'z'){
        return c - 32;
    }
}

int main (){
    int n;
    string linha;

    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++){
        getline(cin, linha);
        if(islower(linha[0])){
            for (int j=0;linha[j];j++){
                if(linha[j-1] != ' '){
                    if (islower(linha[j-1])){
                        linha[j] = paraMaiusculo(linha[j]);
                    } 
                    else {
                        linha[j] = paraMinusculo(linha[j]);
                    }
                } else{
                    if(islower(linha[j-2])){
                        linha[j] = paraMaiusculo(linha[j]);
                    }
                    else {
                        linha[j] = paraMinusculo(linha[j]);
                    }
                }
            }
        }
    cout << linha << endl;
    }
}