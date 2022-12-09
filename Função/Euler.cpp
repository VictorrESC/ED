#include <iostream>
#include <iomanip>

using namespace std;

double fatorial (double n){
    double fat;
    for(fat = 1; n > 1; n--){
        fat = fat * n;
    }
    return fat;
}
double euler (double n){
    double euler;
    for(euler = 1; n > 1; n--){
        euler = euler + (1/fatorial(n));
    }
    return euler;
}

int main (){
    int n;
    cin >> n;

    cout << fixed << setprecision(6) << euler (n) << endl;
}