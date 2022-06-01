#include <iostream>
#include <vector>
using namespace std;

bool resuelveCaso() {
	long long int nPaises, suma = 0, total = 0; 
	vector<int> v(100000);

	cin >> nPaises;
	if (nPaises == 0) {
		return false;
	}

	cin >> v[0];
	suma = suma + v[0];
	for (int i = 1; i < nPaises; i++) {
		cin >> v[i];
		total = total + v[i] * suma;
		suma = suma + v[i]; 
	}

	cout << total << endl;

}

int main() {

	while (resuelveCaso()) {}

	return 0;
}