// Nombre del alumno Juan Romo Iribarren
// Usuario del Juez E71

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

/*  Especificación:
*       - Precondición P: { true }
*       fun
*       - Postcondición Q : { −1 ≤ p < v.size() ∧ numUnos(v, p + 1) = numCeros(v, p + 1) ∧ ∀k : p < k < v.size() : numUnos(v, k + 1) 6= numCeros(v, k + 1) }
*                           donde numUnos(v, j) = #i : 0 ≤ i < j : v[i] = 1 y numCeros(v, j) = #i : 0 ≤ i < j : v[i] = 0.
*   Invariante Inv = { (numCeros = (#i : 0 <= i < v.size() : v[i] = 0)) ^ (numUnos = (#i : 0 <= i < v.size() : v[i] = 1)) ^ (pos : 0 <= pos < v.size() : numUnos = numCeros) ^ (i < v.size) }
* 
*   Función de cota: n - i, donde n = v.size().
* 
*   Coste del algoritmo: Es lineal O(n), donde n = v.size().
*/

int ultimaPosicionEquilibrio(vector<int> const& v) {
    int pos = -1, numUnos = 0, numCeros = 0, i = 0;

    while (i < v.size()) {
        if (v[i] == 0) {
            numCeros++;
        }
        else if (v[i] == 1) {
            numUnos++;
        }
        if (numCeros == numUnos) {
            pos = i;
        }
        i++;
    }

    return pos;
}

void resuelveCaso() {
    int n, aux;
    vector<int> v;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> aux;
        v.push_back(aux);
    }

    cout << ultimaPosicionEquilibrio(v) << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
