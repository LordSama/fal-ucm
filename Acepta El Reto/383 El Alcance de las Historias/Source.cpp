#include <iostream>
#include <vector>
using namespace std;

/* Especificación:
*       - Precondición P: { v.size() >= 2 ^ v.size() <= 300000 }
*         fun calcularAlcance(vector<int> secuencia) dev {int alcance}
*       - Postcondición Q: { (posMayor = i : 0 <= i < v.size : secuencia[i] > secuencia[i+1]) ^ 
                             (alcance = secuencia[i] - secuencia[i+1]) }
*   Invariante: { (posMayor = i : 0 <= i < v.size : secuencia[i] > secuencia[i+1]) ^ 
*                  (alcance = secuencia[i] - secuencia[i+1]) ^ (i <= v.size()) }
*   Función de cota: n - i (Siendo n = v.size()).
*   Coste del algoritmo: En el caso peor es O(n), siendo n = v.size().
*/

int calcularAlcance(vector<int> const& secuencia) {
    int alcance = 0, i = 0, posMayor;
    bool tieneMayor = false;

    while (i < secuencia.size() && !tieneMayor) {
        if (i != secuencia.size() - 1) {
            if (secuencia[i] > secuencia[i + 1]) {
                tieneMayor = true;
                posMayor = i;
            }
            else {
                alcance = secuencia[i] - secuencia[i + 1];
            }
        }
        i++;
    }

    
    if (tieneMayor) {
        alcance = 0;
        for (int i = posMayor + 1; i < secuencia.size(); i++) {
            if (alcance < (secuencia[posMayor] - secuencia[i])) {
                alcance = (secuencia[posMayor] - secuencia[i]);
            }
        }
    }

    return alcance;
}

void resuelveCaso() {
    int nLeidas, aux;
    vector<int> secuencia;

    cin >> nLeidas;
    for (int i = 0; i < nLeidas; i++) {
        cin >> aux;
        secuencia.push_back(aux);
    }

    if (nLeidas >= 2 && nLeidas <= 300000) {
        cout << calcularAlcance(secuencia) << endl;
    }
}

int main() {
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}
