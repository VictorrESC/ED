// verifique se os elementos de um vetor estão em ordem crescente. Usando for.

#include <iostream>
using namespace std;

bool crescente(int v[], int tam)
{
    if(tam == 1){ // C1
        return true;
    }
    else{
        for (int i = 0; i < tam; i++) // C2 * (n+1)
        {
            if (v[i] > v[i + 1]) //C3 * n
            {
                return false;
            }
        }
        return true; // C4
    }
}

// Melhor caso: O(1).

// Pior caso:

// T(n) = C1 + C2 * (n+1) + C3 * n + C4
// T(n) = C1 + C2 + C4 + C2n + C3n
// C1 + C2 + C4 = A
// T(n) = A + C2n + C3n
// T(n) = A + n(C2 + C3)
// C2 + C3 = B
// T(n) = A + nB
// A + nB <= A.n + B.n
// A + nB <= n(A + B)
// A + B = C
// A + nB <= nC
// A + nB = O(n)


int main()
{
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << crescente(v, 9) << endl;
    return 0;
}