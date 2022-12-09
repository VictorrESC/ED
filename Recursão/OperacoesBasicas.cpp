#include <iostream>
#include <sstream>
#include <vector>

using namespace std;


int sum(vector<int> a,int n){
    if(n==1){
        return a[n-1];
    }else{
        return a[n-1] + sum(a,n-1);
    }
}
int mult(vector<int> a,int n){   
    if(n==1){
        return a[n-1];
    }else{
        return a[n-1] * mult(a,n-1);
    }
}
void inversao(vector<int> v, int c,int d){
    if(c < d){
    int aux=v[c];
    v[c]=v[d-1];
    v[d-1]=aux;
    inversao(v,c+1,d-1);
    }
}
void imprime(vector<int> a, int n){
    if(n==1){
        cout << a[n-1] << " ";
    }else{
        imprime(a,n-1);
        cout << a[n-1] << " ";
    }

}
void imprimecontra(vector<int> a, int n){
    if(n==1){
        cout << a[n-1] << " ";
    }else{
        cout << a[n-1] << " ";
        imprimecontra(a,n-1);
    }

}

int vetmenor(vector<int> a, int n){
   if (n == 1){
      return a[n-1];
    }else{
      int menor = vetmenor(a,n-1);
      if(menor < a[n-1] ){
         return menor;
         }
      else{
         return a[n-1];
      }
    }
}


int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> vet;
    int value;
    while(ss >> value)
        vet.push_back(value);

    
    cout << "vet : [ ";
    imprime(vet, vet.size());
    cout << "]";
    cout << endl;

    
    cout << "rvet: [ ";
    imprimecontra(vet,vet.size());
    cout << "]";
    cout << endl;
    
    
    cout <<"sum : " <<sum(vet,vet.size())<< endl;
    
    cout <<"mult: "<< mult(vet,vet.size()) << endl;
    
    cout <<"min : " << vetmenor(vet,vet.size()) << endl;
    
    cout << "inv : [ ";
    imprimecontra(vet,vet.size());
    cout << "]";
    cout << endl;
}