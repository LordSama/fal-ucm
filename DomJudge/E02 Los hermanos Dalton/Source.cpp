// Nombre del alumno Juan Romo Iribarren
// Usuario del Juez E71

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

/*  Especificación:
*       - Precondición P: { n >= 2 ^ n > 100000 ^ for all x : 0 <= x <= n : hermanos[x] >= 1 ^ hermanos[x] <= 1000000 }
*       fun esDalton(vector<int> hermanos) dev { bool res }
*       - Postcondición Q: { res == (for all i : 0 <= i < hermanos.size() : hermanos[i] <= hermanos[i + 1]) || (for all j : 0 <= j < hermanos.size() : hermanos[j] >= hermanos[j + 1]) }
*   
*   Invariante Inv = { (res == (for all i : 0 <= i < hermanos.size() : hermanos[i] <= hermanos[i + 1]) || (for all j : 0 <= j < hermanos.size() : hermanos[j] >= hermanos[j + 1])) ^
                       (n >= 2) }
* 
*   Función de cota: t(i) = n - i, siendo n = hermanos.size()
*   
*   Coste: O(n), siendo n = hermanos.size()
*/

bool esDalton(vector<int> const& hermanos) {
    bool res = true;
    int i = 0;

    if (hermanos[i] > hermanos[i + 1]) {
        while (res && i < hermanos.size() - 1) {
            if (hermanos[i] <= hermanos[i + 1]) {
                res = false;
            }
            i++;
        }
    }
    else if (hermanos[i] < hermanos[i + 1]) {
        while (res && i < hermanos.size() - 1) {
            if (hermanos[i] >= hermanos[i + 1]) {
                res = false;
            }
            i++;
        }
    }
    else {
        res = false;
    }

    return res; 
}

bool resuelveCaso() {
    int n, aux;
    vector<int> hermanos;

    cin >> n;
    if (n == 0)
        return false;

    for (int i = 0; i < n; i++) {
        cin >> aux;
        hermanos.push_back(aux);
    }

    if (esDalton(hermanos)) {
        cout << "DALTON" << endl;
    } 
    else {
        cout << "DESCONOCIDOS" << endl;
    }

    // escribir sol

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
