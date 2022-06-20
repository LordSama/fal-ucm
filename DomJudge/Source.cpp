#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

bool esValido(const vector<bool>& trabajos, const vector<bool>& funcis, int k, int i) {
    if (k > 0) {        // Si contador es mayor que 0.
        if (trabajos[k]) {  // Y trabajos en k no está asignado.
            return false;
        }
        if (funcis[i]) {    // Y funcis en i no está asignado.
            return false;
        }
    }
    return true;
}

void sumarTiempos(const vector<vector<int>>& tiempos, int n, int k, const vector<int>& acumulados, int& sumaActual, int& sumaMin, vector<bool>& trabajos, vector<bool>& funcis) {
    for (int i = 0; i < n; i++) {           // Recorremos los funcis.
        sumaActual += tiempos[i][k];        // Asignamos valor.
        if (esValido(trabajos, funcis, k, i)) {     // Comprobamos si es valido
            funcis[i] = true;       // Marcamos funcis.
            trabajos[k] = true;     // Marcamos trabajos.
            if (k == n - 1) {       // Si hemos llegado al último.
                if (sumaActual < sumaMin) {     // Y la sumaActual es menor que la mínima.
                    sumaMin = sumaActual;       // Asignamos la nueva suma.
                }
            }
            else {
                if (acumulados[k + 1] + sumaActual < sumaMin) {     // Poda. (Si la suma actual más la siguiente es menor que el minimo.
                    sumarTiempos(tiempos, n, k + 1, acumulados, sumaActual, sumaMin, trabajos, funcis);     // Entonces hacemos la vuelta atrás.
                }
            }
            funcis[i] = false;      // Desmarcamos funcis.
            trabajos[k] = false;    // Desmarcamos trabajos.
        }
        sumaActual -= tiempos[i][k];        // Desasignamos el valor.
    }
}

bool resuelveCaso() {
    int n;      // Num de funcis y de trabajos.
    cin >> n;

    if (n == 0) {
        return false;
    }

    vector<vector<int>> tiempos(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tiempos[i][j];  
        }
    }

    // Nos guardamos los valores minimos de cada trabajo:
    vector<int> minimos(n);
    for (int j = 0; j < n; j++) {
        minimos[j] = tiempos[0][j];
        for (int i = 0; i < n; i++) {
            if (minimos[j] > tiempos[i][j]) {
                minimos[j] = tiempos[i][j];
            }
        }
    }
    
    vector<int> acumulados(n);
    for (int i = n - 2; i > -1; i--) {
        acumulados[i] = acumulados[i + 1] + minimos[i];
    }

    int k = 0, sumaActual = 0, sumaMin = 1000000;
    vector<bool> trabajos(n);
    vector<bool> funcis(n);

    sumarTiempos(tiempos, n, k, acumulados, sumaActual, sumaMin, trabajos, funcis);

    cout << sumaMin << endl;
    return true;
}



int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


    while (resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
