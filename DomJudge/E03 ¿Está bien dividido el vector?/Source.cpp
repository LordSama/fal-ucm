// Nombre del alumno Juan Romo Iribarren
// Usuario del Juez E71

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

/*  Especificación:
*       - Precondición P: { n > 0 }
*       fun bienDividido(vector<int> v, int p) dev {bool res}
*       - Postcondición Q: { (max = (max i : 0 <= i <= p : v[i])) ^ (res == (for all j : p + 1 <= j < v.size() : max < v[j])) }
* 
*   Invariante Inv = { (max = (max i : 0 <= i <= p : v[i])) ^ (res == (for all j : p + 1 <= j < v.size() : max < v[j])) ^ (i <= p) ^ (j < v.size()) }
* 
*   Función de cota: n - j, siendo n = v.size().
* 
*   Coste del algoritmo: El coste es lineal O(n), siendo n = v.size().
*/

bool bienDividido(vector<int> const& v, int p) {
    bool res = true;
    int i = 1, max = v[0];

    while (i <= p) {
        if (v[i] > max) {
            max = v[i];
        }  
        i++;
    }

    int j = p + 1;
    while (j < v.size() && res) {
        if (max >= v[j]) {
            res = false;
        }
        j++;
    }

    return res;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int n, p, aux;
    vector<int> v;

    cin >> n;
    cin >> p;

    for (int i = 0; i < n; i++) {
        cin >> aux;
        v.push_back(aux);
    }

    if (bienDividido(v, p)) {
        cout << "SI" << endl;
    }
    else {
        cout << "NO" << endl;
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
