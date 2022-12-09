#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main (){

    stringstream ss;
    string txt;
    string linha;
    string tira_espaco;
    char escolha;

    getline (cin, linha);
    cin >> escolha;
    ss << linha;

    if (escolha == 'm'){
        while (ss >> txt){
            for (int i = 0; i < txt.size(); i++){
                if (txt[i] >= 'A' && txt[i] <= 'Z'){
                    txt[i] += 32;
                }
            }
        tira_espaco += txt + " ";
        }
    }
    else if (escolha == 'M'){
        while (ss >> txt){
            for (int i = 0; i < txt.size(); i++){
                if (txt[i] >= 'a' && txt[i] <= 'z'){
                    txt[i] -= 32;
                }
            }
        tira_espaco += txt + " ";
        }
    }
    else if (escolha == 'i'){
        while (ss >> txt){
            for (int i = 0; i < txt.size(); i++){
                if (txt[i] >= 'a' && txt[i] <= 'z'){
                    txt[i] -= 32;
                }
                else if (txt[i] >= 'A' && txt[i] <= 'Z'){
                    txt[i] += 32;
                }
            }
        tira_espaco += txt + " ";
        }
    }
    else if (escolha == 'p'){
        while (ss >> txt){
            if (txt.size() > 1){
                if (txt[0] >= 'a' && txt[0] <= 'z'){
                    txt[0] -= 32;
                }
            }
            if(txt.size() == 1){
                if (txt[0] >= 'A' && txt[0] <= 'Z'){
                    txt[0] += 32;
                }
            }
        tira_espaco += txt + " ";
        }
    }
    for (int i = 0; i < tira_espaco.size() - 1; i++){
        cout << tira_espaco[i];
    }
}