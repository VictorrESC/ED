//Hanoi com 4 pinos recursivo

#include <iostream>
using namespace std;

void hanoi(int n, int origem, int destino, int aux1, int aux2)
{
    if (n == 1)
    {
        cout << "Mova o disco " << n << " do pino " << origem << " para o pino " << destino << endl;
    }
    else
    {
        hanoi(n - 1, origem, aux1, aux2, destino);
        cout << "Mova o disco " << n << " do pino " << origem << " para o pino " << destino << endl;
        hanoi(n - 1, aux1, destino, origem, aux2);
    }
}

int main()
{
    int n;
    cin >> n;
    hanoi(n, 1, 4, 2, 3);
    return 0;
}