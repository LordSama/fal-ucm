#include <iostream>
using namespace std;

void resuelveCaso() {
	int n, contador = 0, aux;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> aux;
		if (aux % 2 == 0) {
			contador++;
		}
	}
	cout << contador << endl;
}

int main() {
	int numCasos;

	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}

	return 0;
}