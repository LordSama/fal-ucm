#include <iostream>
#include <vector>
using namespace std;

/*	Especificación:
*		- Precondición P: { v.size() >= 2 ^ v.size <= 1000 ^ forall k : 0 <= k < v.size() : v[k] < 1000 } 
*		  fun calcularPicos(vector<int> v) dev {int numPicos}
*		- Postcondición Q: { (numPicos == #p : 0 <= p < v.size() : (p - 1 < p ^ p + 1 < p) ^ (p == v.size() - 1 : numPicos++ : p > primerAltura = v[0] ^ p > p - 1) ^ 
*                            (p == v[0] : numPicos++ : p > ultimaAltura = v[v.size() - 1] ^ p > p + 1) }
*   Para calcular la invariante I:
*   En el bucle se calcula el valor numPicos. Cada vuelta del bucle, variable numPicos es un contador de los picos calculados en la parte del vector ya recorrida.
*   En la vuelta i-ésima, el valor de numPicos cumple: numPicos == (#p : 0 <= o < v.size() : (p - 1 < p ^ p > p + 1)
*   Añadimos al invariante una condición sobre la variable de control del bucle: 2 <= v.size().
*	Invariante Inv: Inv : { (numPicos == (#p : 0 <= o < v.size() : (p - 1 < p ^ p > p + 1)) ^ (2 <= v.size()) }
*	Función de cota: t(i) = v.size() - i + 1.
*/

int calcularPicos(vector<int> const& v) {
    int numPicos = 0;
    int primerAltura = v[0], ultimaAltura = v[v.size() - 1];

    for (int i = 0; i < v.size(); i++) {
        if (i == 0) {
            if (v[i] > ultimaAltura && v[i] > v[i + 1]) {
                numPicos++;
            }
        }
        else if (i == v.size() - 1) {
            if (v[i] > primerAltura && v[i] > v[i - 1]) {
                numPicos++;
            }
        }
        else {
            if (v[i] > v[i - 1] && v[i] > v[i + 1]) {
                numPicos++;
            }
        }
    }

    return numPicos;
}

bool resuelveCaso() {
    vector<int> v;
    int n, aux;

    cin >> n;
    if (n == 0)
        return false;

    for (int i = 0; i < n; i++) {
        cin >> aux;
        v.push_back(aux);
    }

    cout << calcularPicos(v) << endl;

    return true;
}

int main() {
    while (resuelveCaso());

    return 0;
}
