#include <iostream>
#include <vector>
using namespace std;

/*	Especificación:
*		- Precondición P: { v.size() > 0 }
*		  fun contMax(vector<int> v) dev {int maximo, int cont}
*		- Postcondicion Q: { (maximo == max k : 0 <= k < v.size() : v[k]) ^ (cont == #k : 0 <= k < v.size() : v[k] == maximo) }
*/

void contMax(vector<int> const& v, int& maximo, int& cont) {
	maximo = v[0], cont = 1;
	int i = 1;
	while (i < v.size()) {
		if (v[i] > maximo) {
			maximo = v[i];
			cont = 1;
		}
		else if (v[i] == maximo) {
			cont++;
		}
		i++;
	}
}

void resuelveCaso() {
	// leer los datos de la entrada
	vector<int> v;
	int maximo = 0, cont = 0, n;

	cin >> n;
	while(n != 0) {
		v.push_back(n);
		cin >> n;
	}

	contMax(v, maximo, cont);
	// escribir sol
	cout << maximo << " " << cont << endl;

}

int main() {
	vector<int> v;
	int maximo, cont, n, aux = 0;

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	return 0;
}
