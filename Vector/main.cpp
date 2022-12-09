#include <iostream>
#include "Vector.h"
using namespace std;

void print(const Vector& list) {
	for(int i = 0; i < list.size(); i++) 
		cout << list.at(i) << " ";
	cout << endl;
}
void imprime_dados(const Vector& vec) {
	cout << vec.size() << ", " << vec.capacity() << endl;
}

int main() {
	Vector list1, list2;
	int value = 0;
	cin >> value;

	for(int i = 0; i < value; ++i) {
		list1.push_back(i);
		list2.push_back(i * 2);
	}
	print(list1);
	print(list2);
}