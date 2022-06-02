#include<iostream>
using namespace std;

int main() {
	int n, actual, anterior;
	bool creciente;

	cin >> n;
	while (n != 0) {
		anterior = 0;
		creciente = true;
		for (int i = 0; i < n; i++) {
			cin >> actual;
			if (anterior >= actual) {
				creciente = false;
			}
			anterior = actual;
		}
		if (creciente) {
			cout << "SI" << endl;
		}
		else {
			cout << "NO" << endl;
		}

		cin >> n;
	}

	return 0;
}