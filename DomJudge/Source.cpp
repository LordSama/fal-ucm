// Nombre del alumno Juan Romo Iribarren
// Usuario del Juez E71

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

/*  Especificación:
*       - Precondición P: { n >= 0 ^ n <= 100000}
*       proc indicePastoso(vector<int> v) dev {int indice, bool existe}
*       - Postcondición Q: { (existe == (i : 0 <= i < v.size() - 1 : v[i] = suma)) ^ (indice = i : 0 <= i <= v.size() : v[i] = suma) }
* 
*   Invariante Inv: { (existe == (i : 0 <= i < v.size() - 1 : v[i] = suma)) ^ (indice = i : 0 <= i <= v.size() : v[i] = suma) ^ (v.size() >= 0) ^
                      (suma = sum : 0 <= i <= v.size() - 1 : v[i]) }
* 
*   Función de cota: n - i, donde n = v.size().
* 
*   Coste del algoritmo: O(n), donde n = v.size().
*/

void indicePastoso(vector<int> const& v, int& indice, bool& existe) {
    int suma = 0, i = v.size() - 1;

    while (i >= 0 && !existe) {
            if (v[i] == suma) {
                existe = true;
                indice = i;
            }
            suma += v[i];
            i--;
    }
}

void resuelveCaso() {
    int n, aux, indice;
    vector<int> v;
    bool existe = false;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        v.push_back(aux);
    }

    indicePastoso(v, indice, existe);

    if (existe) {
        cout << "Si " << indice << endl;
    }
    else {
        cout << "No" << endl;
    }
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