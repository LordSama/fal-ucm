#include <iostream>
#include <vector>
using namespace std;

/*  Especificación:
*       - Precondición P:
*         fun
*       - Postcondición Q:
*   Invariante:
*   Función de cota:
*   Coste del algoritmo:
*/

int calcularNumPersonas(vector<int>& v, int a) {
    int nPersonas = 0;
    for (int i = v.size() - 1; i >= 0; i--) {
        while (abs(v[i] - v[v.size() - 1]) >= a) {
            v.pop_back();
        }
        if ((v.size() - i) > nPersonas) {
            nPersonas = v.size() - i;
        }
    }

    return nPersonas;
}

bool resuelveCaso() {
    int nacimientos, a;

    cin >> nacimientos;
    cin >> a;

    if (nacimientos == 0 && a == 0) {
        return false;
    }

    vector<int> anyos;
    int aux;

    for (int i = 0; i < nacimientos; i++) {
        cin >> aux;
        anyos.push_back(aux);
    }

    cout << calcularNumPersonas(anyos, a) << endl;

    return true;
}

int main() {
    while (resuelveCaso());

    return 0;
}
