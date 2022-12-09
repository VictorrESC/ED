#include <iostream>
#include <cstdlib> // pesquisar: biblioteca <random>
#include <chrono>
#include <string>
using namespace std;

// algoritmo de ordenacao bubblesort --- complexidade O(n^2)
// muito lento para arrays muito grandes
template< typename T >
void bubblesort(T A[], int l, int r) {
    bool trocou = true;
    for(int i = l; i < r && trocou; i++) {
        trocou = false;
        for(int j = r; j > i; j--) {
            if(A[j] < A[j-1]) {
                T aux = A[j];
                A[j] = A[j-1];
                A[j-1] = aux;
                trocou = true;
            }
        }
    }
}

template< typename T >
void print(T A[], int l, int r) {
    for(int i = l; i <= r; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

template< typename T >
void testa_algoritmo(T A[], int l, int r, string name, void (*func)(T[], int, int)) {
    auto start = std::chrono::steady_clock::now();
    func(A, l, r);
    auto end = std::chrono::steady_clock::now();
    auto elapsed_time = end - start;
    auto duration = 
        std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time);
    cout << name << " time: " << duration.count() << " nanoseconds" << endl;
}

int main() {
    const int n = 9000;
    int vec[n];
    for(int i = 0; i < n; i++) {
        vec[i] = 1 + rand() % 1000;
    }
    testa_algoritmo<int>(vec, 0, n-1, "bubblesort", bubblesort);

    string nomes[7] = {"luiz","ana","amanda","marta","maria","carla","claudia"};
    testa_algoritmo<string>(nomes, 0, 6, "bubblesort", bubblesort);
    print(nomes, 0, 6);   
}