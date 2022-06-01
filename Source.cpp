#include <iostream>
using namespace std;

void resuelveCaso() {
	int numVecinos, cont = 0, butaca;
	bool par = false, correcto = true;;

	cin >> numVecinos;
	for (int i = 0; i < numVecinos; i++) {
		cin >> butaca;
		if (butaca % 2 == 0 && !par) {
			cont++;
		}
		if (butaca % 2 == 0 && par) {
			correcto = false;
		}
		if (butaca % 2 != 0 && !par) {
			par = true;
		}
	}
	if (correcto) {
		cout << "SI " << cont << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

int main() {
	int numCasos;

	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}

	return 0;
}