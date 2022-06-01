#include <iostream>
#include <fstream>
using namespace std;

void resuelveCaso() {
	// leer los datos de la entrada
	int n, res = 0;

	std::cin >> n;

	if (n == 0 || n == 1) {
		res = 1;
	}
	else if (n == 2) {
		res = 2;
	}
	else if (n == 3) {
		res = 6;
	}
	else if (n == 4) {
		res = 4;
	}
	else {
		res = 0;
	}

	cout << res << endl;
}

int main() {
	ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	return 0;
}
