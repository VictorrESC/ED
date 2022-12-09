#include <iostream>
#include <vector>
#include "List.h"

using namespace std;

int main(){

    vector<int> vec {1, 2, 3, 4, 5};

    for (auto it = vec.begin(); it != vec.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    List<float> lista;

    for (int i = 0; i <= 10; i++){
        lista.push_back(i);
    }

    for (int i = 0; i < lista.size(); i++){
        cout << lista[i] << " ";
    }

    cout << endl;

    for (auto it = lista.begin(); it != lista.end(); ++it){
        cout << *it << " ";
    }
}