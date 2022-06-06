#include <iostream>
#include <vector>
using namespace std;

/*  Especificación:
*       - Precondición P: { v.size() > 0 ^ v.size <= 100000 }
*         fun calcularFranja(vector<int> v, int pesoNieve) dev {int cont}
*       - Postcondición Q: { (cont == max p, q: 0 <= p <= q < v.size() ^ for all k : p <= k <= q : v[k] = numEnPie < 5 :q - p) ^
*                             (numEnPie = #i : 0 <= i < v.size()) : v[i] >= pesoNieve) }
*   Invariante Inv: Para demostrar la corrección del bucle hacemos uso del predicado Invanriante. En el bucle se calculan los valores cont y numEnPie,
*                   además se va modificando la variable de control i.
*                    Por tanto Inv = { (cont == max p, q: 0 <= p <= q < v.size() ^ for all k : p <= k <= q : v[k] = numEnPie < 5 :q - p) ^
*                                      (numEnPie = #i : 0 <= i < v.size()) : v[i] >= pesoNieve) ^ (i <= v.size()) }
*   Función de cota: t(i) = v.size() - i
*   Coste del algoritmo: En el caso peor es O(n), siendo n = v.size(), es decir, el tamaño del vector..
*/

int calcularFranja(vector<int> const& v, int pesoNieve) {
    int cont = 0, numEnPie = 0, i = 0;

    while (i < v.size() && numEnPie < 5) {
        cont++;
        if (v[i] >= pesoNieve) {
            numEnPie++;
        }
        i++;
    }

    return cont;
}

void resuelveCaso() {
    int pesoNieve, nPalmeras, aux;
    vector<int> v;

    cin >> pesoNieve;
    cin >> nPalmeras;
    for (int i = 0; i < nPalmeras; i++) {
        cin >> aux;
        v.push_back(aux);
    }

    int l = calcularFranja(v, pesoNieve);
    cout << l << endl;
}

int main() {
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}