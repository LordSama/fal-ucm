#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	int n, max, aux;
	vector<int> v(100000);

	cin >> n;

	while (n != 0) {
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		max = 0;
		int contador = 0;
		for (int i = v.size() - 1; i >= 0; i--) {
			if (max < v[i]) {
				max = v[i];
				contador++;
			}
		}
		cout << contador << endl;

		cin >> n;
	}

	return 0;
}
