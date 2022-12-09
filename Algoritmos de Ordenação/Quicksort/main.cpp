// quicksort
#include <iostream>

using namespace std;

int partition (int A[], int l, int r){
    int pivo = A[r];
    int j = l;
    for (int k = l; k < r; k++){
        if (A[k] <= pivo){
            int aux = A[j];
            A[k] = A[j];
            A[j] = aux;
            j++;
        }
    }
    A[r] = A[j];
    A[j] = pivo;
    return j;
}

void quicksort(int A[], int l, int r) {
    while (l < r) {
        int j = partition(A, l, r);
        quicksort(A, l, j-1);
        l = j+1;
    }
}

int main(){
    int v[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    quicksort(v, 0, 9);
    for(int i = 0; i < 10; i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}