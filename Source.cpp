#include <iostream>
using namespace std;

int main() {
	long long int numCasos, valor, min, contadorMin, max, contadorMax;
	
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		cin >> valor;
		min = valor;
		max = valor;
		contadorMin = 0;
		contadorMax = 0;
		while (valor != 0) {
			if (valor < min) {
				min = valor;
				contadorMin = 1;
			}
			else if (valor == min) {
				contadorMin++;
			}
			if (valor > max) {
				max = valor;
				contadorMax = 1;
			}
			else if (valor == max) {
				contadorMax++;
			}
			cin >> valor;
		}
		cout << min << " " << contadorMin << " " << max << " " << contadorMax << endl;
	}

	return 0;
}