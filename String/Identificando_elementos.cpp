#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int verifica_flut(string txt){
    
    int flut = 0;
    int str = 0;
    int inteiro = 0;
    
    for (int i = 0; i < txt.size(); i++){
        if (txt[i] == '.' && (txt[i-1] >= '0' && txt[i-1] <= '9') && (txt[i+1] >= '0' && txt[i+1] <= '9')){
            flut = 1;
        } 
        else if (txt[i] >= 'a' && txt[i] <= 'z'){
            str = 1;
        }
        else {
            inteiro = 1;
        }
    }
    
    if (flut == 1){
        return 1;
    }
    else if (str == 1 && flut == 0){
        return 2;
    }
    else if (inteiro == 1 && flut == 0 && str == 0){
        return 3;
    }
}



int main (){
    
    stringstream ss;
    string txt;
    
    getline(cin, txt);
    
    ss << txt;
    
    while (ss >> txt){
        
        if(verifica_flut(txt) == 1){
            cout << "float ";
        }
        else if (verifica_flut(txt) == 2){
            cout <<  "str ";
        } 
        else if (verifica_flut(txt) == 3){
            cout << "int ";
        }
    }
}