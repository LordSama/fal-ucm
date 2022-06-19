#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*  Apartado 1:
*       todosPares(v,p,q) = (for all k : p <= k < q : (v[k] % 2 = 0))  
*   
*   Apartado 2: 
*       numSegs = (#longitudPar : 0 <= p <= q < v.size() : todosPares(v, p, q) ^ v.size() >= 0)
* 
*   Apartado 3: Especificación.
*       - Precondición: { v.size() >= 0 }
*           fun numSegmentos(vector<int> v) {dev int numSegs}
*       - Postcondición: { numSegs = (#longitudPar : 0 <= p <= longitudPar <= q < v.size() : todosPares(v, p, q) }
*       
*   Apartado 4: 
*        Invariante:
*           Inv = { numSegs = sum(#longitudPar : 0 <= p <= q < v.size() : todosPares(v, p, q) ^ v.size() >= 0) ^ i <= v.size() ^ longitudPar = (for all i : #z : 0 <= p <= z <= i <= q : v[i] % 2 == 0) }
*       Función de cota: t(i) = v.size() - i;
*
*   Apartado 5:
*       Coste del algoritmo: lineal O(n), siendo n = v.size().
*/

int numSegmentos(vector<int> v) {
    int i = 0, longitudPar = 0, numSegs = 0;

    while (i < v.size()) {
        if (v[i] % 2 == 0) {
            longitudPar++;
            numSegs += longitudPar;
        }
        else { 
            longitudPar = 0; 
        }
        i++;
    }
    return numSegs;
}

void resuelveCaso() {
    //resuelve aqui tu caso
       //Lee los datos
    int n, res = 0;

    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
       //Calcula el resultado
    if (n > 0) {
        res = numSegmentos(v);
    }

       //Escribe el resultado
    cout << res << endl;
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    unsigned int numCasos;
    std::cin >> numCasos;
    // Resolvemos
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
