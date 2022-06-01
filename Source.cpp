#include <iostream>
using namespace std;

int main() {
	int n;
	string aux, nombre;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> aux >> nombre;
		cout << "Hola, " << nombre << "." << endl;
	}

	return 0;
}