#include <iostream>
#include <vector>
using namespace std;

/*  Especificación:
*       - Precondición P: { v.size() > 0 && v.size() <= 100000 && suma == sum(v[k]) : 0 <= k <= v.size() : suma <= 1000000000 }
*         fun montarBocadillo(vector<int> v) dev { string posible, int posicion }
*       - PostCondición Q: { suma == k : 0 <= k < v.size() :  sum(p, q) : k < p < q < v.size() : q - p }
*   Invariante: Inv = { (suma == v[i] : 0 <= i < v.size() :  sum(p, q) : v[i] < p < q < v.size() : q - p) ^ (v.size() > 0 && v.size() <= 100000) }
*   Función de cota: t(i) = v.size() - i + 1.
*/

void montarBocadillo(vector<int> const& v, string& posible, int& posicion) {
    int i = v.size() - 1;
    int suma = 0;

    while (i != 0 && posible != "SI") {
        suma = suma + v[i];
        if (suma == v[i - 1]) {
            posible = "SI";
            posicion = i;
        }
        else {
            posible = "NO";
        }
        i--;
    }
}

bool resuelveCaso() {
    // leer los datos de la entrada
    vector<int> v;
    int n, aux, posicion;
    string posible;

    cin >> n;
    if (n == 0)
        return false;

    for (int i = 0; i < n; i++) {
        cin >> aux;
        v.push_back(aux);
    }

    montarBocadillo(v, posible, posicion);

    if (posible == "SI") {
        cout << posible << " " << posicion << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return true;

}

int main() {
    while (resuelveCaso());

    return 0;
}
