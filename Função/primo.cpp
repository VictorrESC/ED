#include <iostream>

using namespace std;

int primo (int x){
    int primo;
    
    for (int i = 2; i < x; i++){
        if( x%i == 0){
            return 0;
        }
    }
    return 1;
}

int main (){
    int a, b;
    cin >> a;
    cin >> b;
    
    for (a; a <= b; a++){
        if (primo(a) == 1){
            cout << a << endl;
        }
    }
}