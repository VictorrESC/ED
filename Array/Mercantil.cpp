#include <iostream>

using namespace std;

int main (){
    int QuantProd = 0;
    cin >> QuantProd;
    int cont1 = 0, cont2 = 0;
    float ValorProd[QuantProd];
    float chute[QuantProd];
    char escolha[QuantProd];
    
    // entrada dos valores
    for (int i=0; i<QuantProd; i++){
        cin  >> ValorProd[i];
    }
    for (int i=0; i<QuantProd; i++){
        cin  >> chute[i];
    }
    for (int i=0; i<QuantProd; i++){
        cin.ignore() >> escolha[i];
    }

    // verificação  dos chutes
    for (int i=0; i<QuantProd; i++){
      if(ValorProd[i] == chute[i]){
        cont1++;
      }else if(ValorProd[i] > chute[i] && escolha[i] == 'm'){
        cont1++;
      } else if(ValorProd[i] < chute[i] && escolha[i] == 'M'){
        cont1++;
      }else {
        cont2++;
      }
    }

    // comparação das pontuações
    if (cont1 == cont2){
        cout << "empate" << endl;
    } else if (cont1 > cont2){
        cout << "primeiro" << endl;
    } else {
        cout << "segundo" << endl;
    }
}