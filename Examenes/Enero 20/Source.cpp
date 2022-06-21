#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

bool esValido(const vector<int>& escalones, int i, const vector<int>& cantidades, int k) {
    if (cantidades[i] >= escalones[k]) {
        return true;
    }
    return false;
}

void calcular(int n, int c, const vector<int>& escalones, vector<int>& cantidades, const vector<int>& precios, int ultimo, int& costeMin, int& coste, int k, vector<int>& sol, vector<int>& coloresUsados, bool& sePuede) {
    for (int i = 0; i < c; i++) {
        if (ultimo != i) {
            if (esValido(escalones, i, cantidades, k)) {
                cantidades[i] -= escalones[k];
                coste += escalones[k] * precios[i];
                coloresUsados[k] = i;
                int aux = ultimo;
                ultimo = i;
                if (k == n - 1) {
                    if (coste < costeMin) {
                        costeMin = coste;
                        sol = coloresUsados;
                        sePuede = true;
                    }
                }
                else {
                    k++;
                    calcular(n, c, escalones, cantidades, precios, ultimo, costeMin, coste, k, sol, coloresUsados, sePuede);
                }
                ultimo = aux;
                coste -= escalones[k] * precios[i];
                cantidades[i] += escalones[k];
            }
        }
    }
}

bool resuelveCaso() {
    int n;
    //Leer caso de prueba: cin>>...
    cin >> n;       // Numero de escalones.

    if (n == -1)
        return false;

    int c;
    cin >> c;       // Numero de escalones distintos.

    vector<int> escalones(n);
    for (int i = 0; i < n; i++) {
        cin >> escalones[i];        // Anchuras de cada escalon.
    }

    vector<int> cantidades(c);      // Cantidad de cada color.
    vector<int> precios(c);         // Precio de cada color.
    for (int j = 0; j < c; j++) {
        cin >> cantidades[j];
        cin >> precios[j];
    }

    int costeMin = 200000, coste = 0, k = 0;       // costeMin para el coste minimo de pintar toda la escalera. 
    vector<int> sol(n);         // Vector donde se escribirá el color utilizado en cada escalon.
    vector<int> coloresUsados(n);       // Vector para guardar los colores ya usados.
    bool sePuede = false;
    int ultimo = -1;

    //Resolver problema
    calcular(n, c, escalones, cantidades, precios, ultimo, costeMin, coste, k, sol, coloresUsados, sePuede);

    //Escribir resultado
    if (sePuede) {
        cout << costeMin << endl;
        cout << sol[0];
        for (int i = 1; i < sol.size(); i++) {
            cout << " " << sol[i];
        }
        cout << endl;
    }
    else {
        cout << "NO" << endl;
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