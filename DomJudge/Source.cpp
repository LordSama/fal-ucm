// Nombre del alumno .....
// Usuario del Juez ......

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

bool esValido(vector<string> const& torre, int cont, int contVerde, int contAzul) {
    if (torre[cont] == "verde" && torre[cont - 1] == "verde") {
        return false;
    }
    else if (contVerde > contAzul) {
        return false;
    }
    else {
        return true;
    }
}

void torres(int h, vector<int>& v, vector<string>& torre, int cont, bool& valido, int& contRojo, int& contVerde, int& contAzul) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > 0) {
            switch (i) {
            case 0:
                torre[cont] = "azul";
                contAzul++;
                break;
            case 1:
                torre[cont] = "rojo";
                contRojo++;
                break;
            case 2:
                torre[cont] = "verde";
                contVerde++;
                break;
            }
            if (esValido(torre, cont, contVerde, contAzul)) {
                v[i]--;
                if (cont == h - 1) {                         //Miramos si es el ultimo
                    if (contRojo > (contAzul + contVerde)) {
                        valido = true;
                        for (int j = 0; j < torre.size(); j++) {
                            cout << torre[j] << " ";
                        }
                        cout << endl;
                    }
                }
                else {
                    torres(h, v, torre, cont + 1, valido, contRojo, contVerde, contAzul);      // Seguimos metiendo fichas
                }
                v[i]++;
            }
            switch (i) {
            case 0:
                contAzul--;
                break;
            case 1:
                contRojo--;
                break;
            case 2:
                contVerde--;
                break;
            }
        }
    }
}

bool resuelveCaso() {
    int h, a, r, v;
    cin >> h >> a >> r >> v;
    if (h == 0 && a == 0 && r == 0 && v == 0) return false;
    vector<int> colores(3);
    colores[0] = a;
    colores[1] = r;
    colores[2] = v;
    vector<string> torre(h);
    torre[0] = "rojo";
    colores[1]--;
    bool sePuede = false;
    int contA = 0, contR = 1, contV = 0;
    torres(h, colores, torre, 1, sePuede, contR, contV, contA);
    if (!sePuede) cout << "SIN SOLUCION" << endl;
    cout << endl;
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
