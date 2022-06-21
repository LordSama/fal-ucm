#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int resolver(const vector<int>& v, int ini, int fin) {
    if (ini == fin) {
        return v[ini];
    }
    else {
        int m = (ini + fin - 1) / 2;

        if (v[m] < v[ini]) {
            return resolver(v, ini, m);
        }
        else if (v[m] > v[fin]) {
            return resolver(v, m, fin);
        }
        else {
            return v[m];
        }
    }
}

bool resuelveCaso() {
    int n;
    //Leer caso de prueba: cin>>...
    cin >> n;

    if (n == -1)
        return false;

    int m;
    cin >> m;

    vector<int>v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int ini = 0, fin = v.size() - 1;
    //Resolver problema
    //Escribir resultado
    cout << resolver(v, ini, fin);
    
    return true;
}


int main() {

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}
