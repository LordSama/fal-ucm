#include <iostream>
using namespace std;

bool resuelveCaso() {
	int n, max, aux;

	cin >> n;
	if (!std::cin || n < 1)
		return false;

	max = n;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		if (max < aux && aux < 1000000000) {
			max = aux;
		}
	}

	cout << max << endl;
}

int main() {
	while(resuelveCaso()) 

	return 0;
}