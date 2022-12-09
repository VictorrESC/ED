#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace ufc{
// Compara dois valores e retorna o maior entre eles.
    template <typename T>
    T max(T x, T y){
        if (x >= y){
            return x;
        }
        else{
            return y;
        }
    }

    template <typename N>
    void print (vector<N> v){
        for (int i = 0; i < v.size(); i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
}

int main(){
    cout << ufc::max(34, 67) << endl;
    cout << ufc::max(54.5, 67.8) << endl;
    cout << ufc::max("Victor", "Larissa") << endl;

    vector<int> v = {1, 2, 3, 4, 5, 69, 96};
    ufc::print(v);
}