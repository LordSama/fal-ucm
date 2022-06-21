#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

/* Apartado A: 
*       Precondicion P = {v.size() > 0}
*       proc calcularTramoAscendente(vector<int> v) dev {numElems, maxAncho}
*       PostCondición Q = (#numElems = for all i : 0 <= i < v.size() : (v[i] <= v[i + 1]) ^ (#ancho : v[i] == v[i + 1]))
*       Invariante I = { (#numElems = for all i : 0 <= i < v.size() : (v[i] <= v[i + 1]) ^ (#ancho : v[i] == v[i + 1])) ^ (0 <= i < v.size() - 1) }
*       Coste de la función = O(n) lineal, siendo n = v.size().
* 
*   Apartado B:
*       Precondicion P = {v.size() > 0}
*       proc calcularTramoDescendente(vector<int> v) dev {numElems, maxAncho}
*       PostCondición Q = (#numElems = for all i : 0 <= i < v.size() : (v[i] >= v[i + 1]) ^ (#ancho : v[i] == v[i + 1]))
*       Invariante I = { (#numElems = for all i : 0 <= i < v.size() : (v[i] >= v[i + 1]) ^ (#ancho : v[i] == v[i + 1])) ^ (0 <= i < v.size() - 1) }
*       Coste de la función = O(n) lineal, siendo n = v.size().
*/

void calcularTramoAscendente(const vector<int>& v, int& maxAncho, int& numElems, int numElemsDer) {
    int i = 0, ancho = 0;
    bool ascendente = true;
    while (i < v.size() - 1 && ascendente) {
        if (v[i] < v[i + 1]) {
            numElems++;
            ancho = 1;
        }
        else if (v[i] == v[i + 1]) {
            numElems++;
            ancho++;
            if (ancho > maxAncho) {
                maxAncho = ancho;
            }
        }
        else if (v[i] > v[i + 1]) {
            ascendente = false;
        }
        i++;
    }
}

void calcularTramoDescendente(const vector<int>& v, bool& descendente, int& maxAncho, int& numElems, bool& fin) {
    int i = v.size() - 1, ancho = 1;
    while (i > 0 && descendente) {
        if (v[i] < v[i - 1]) {
            numElems++;
            ancho = 1;
        }
        else if (v[i] == v[i - 1]) {
            numElems++;
            ancho++;
            if (ancho > maxAncho) {
                maxAncho = ancho;
            }
        }
        else if (v[i] > v[i - 1]) {
            descendente = false;
        }
        i--;
        if (i == 1) {
            fin = true;
        }
    }
}

void esEscalera(const vector<int>& v, int& maxAncho, bool& correcto, int& elemsIzq, int& elemsDer) {
    // Comprobamos si la secuencia es una escalera
    bool descendente = true;
    bool fin = false;
    calcularTramoDescendente(v, descendente, maxAncho, elemsDer, fin);   // Luego si es descendente
    if (!fin) {
        calcularTramoAscendente(v, maxAncho, elemsIzq, elemsDer);      // Primero comprobamos si el tramo comienza siendo ascendente.
    }

    if (elemsDer + elemsIzq == v.size() + maxAncho) {
        correcto = true;
    }
    else if (fin) {
        correcto = true;
    }
}


bool resuelveCaso() {
    int n;
    //Leer caso de prueba: cin>>...
    cin >> n;

    if (n == -1)
        return false;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int maxAncho = 1, elemsIzq = 1, elemsDer = 1;
    bool correcto = false;
    //Resolver problema
    esEscalera(v, maxAncho, correcto, elemsIzq, elemsDer);

    //Escribir resultado
    if (correcto) {
        cout << "SI " << maxAncho << endl;
    }
    else {
        cout << "NO " << elemsIzq << " " << elemsDer << endl;
    }
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
