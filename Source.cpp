#include <iostream>
using namespace std;

bool casoDePrueba() {
	int huevos, tam, tiempo = 1;
	cin >> huevos;
	cin >> tam;
	if (huevos == 0) {
		return false;
	}

	while (huevos > tam) {
		huevos = huevos - tam;
		tiempo = tiempo + 1;
	}

	cout << tiempo * 10 << "\n";
}

int main() {

	while (casoDePrueba()) {

	}

	return 0;
}