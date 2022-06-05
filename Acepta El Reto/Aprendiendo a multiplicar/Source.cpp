#include <iostream>
#include <vector>
using namespace std;

void calcularSecuencia(vector<int> const& v, int& cantidad, int& primero, int& ultimo) {
    cantidad = v.size();
    primero = 0;
    ultimo = cantidad - 1;
}

void resuelveCaso() {
    int n, aux, cantidad = 0, primero = 0, ultimo = 0;
    vector<int> v;

    cin >> n;
    int i = 0;
    cin >> aux;
    while(i < n && aux != 0) {
        v.push_back(aux);
        i++;
        if (i < n) {
            cin >> aux;
        }
    }

    calcularSecuencia(v, cantidad, primero, ultimo);
    if (ultimo < 0) {
        cout << "SIGUE BUSCANDO" << endl;
    }
    else {
        cout << cantidad << " --> [" << primero << "," << ultimo << "]" << endl;
    }
}

int main() {
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}
