// Nombre del alumno Juan Romo Iribarren
// Usuario del Juez E71

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

/*  Especificación:
*       - Precondición P: { (temps.size() > 0 ^ temps.size() <= 10000) ^ 
                            (for all q : 0 <= q <= temps.size() : temps[q] > -50 ^ temps[q] < 60) }
*         fun temperaturasExtremas(vector<int> temps) dev {int nPicos, int nValles }
*       - Postcondición Q: { (nPicos = #p : 1 <= p <= v.size() - 1 : (temps[p] > temps[p + 1]) ^ (temps[p] > temps[p - 1])) ^
*                            (nValles = #k : 1 <= k <= v.size() - 1 : (temps[p] < temps[p + 1]) ^ (temps[p] < temps[p - 1])) }
* 
*   Invariante Inv = { (nPicos = #p : 1 <= p <= v.size() - 1 : (temps[p] > temps[p + 1]) ^ (temps[p] > temps[p - 1])) ^
*                      (nValles = #k : 1 <= k <= v.size() - 1 : (temps[p] < temps[p + 1]) ^ (temps[p] < temps[p - 1])) ^ 
*                      (i <= temps.size()) }
* 
*   Función de cota: t(i) = n - i. Siendo n = temps.size().
* 
*   Coste del algoritmo: O(n), siendo n = temps.size()
*/

void temperaturasExtremas(vector<int> const& temps, int& nPicos, int& nValles) {
    for (int i = 1; i < temps.size() - 1; i++) {
        if (temps[i] > temps[i - 1] && temps[i] > temps[i + 1]) {
            nPicos++;
        }
        else if (temps[i] < temps[i - 1] && temps[i] < temps[i + 1]) {
            nValles++;
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int nTemperaturas, aux, nPicos = 0, nValles = 0;
    vector<int> temps;

    cin >> nTemperaturas;

    for (int i = 0; i < nTemperaturas; i++) {
        cin >> aux;
        temps.push_back(aux);
    }

    temperaturasExtremas(temps, nPicos, nValles);

    cout << nPicos << " " << nValles << endl;
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