//NOMBRE y APELLIDOS: Juan Romo Iribarren.

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool esValida(const vector<int>& supermercado, const vector<bool>& productos, int pos, int i) {
    if (productos[pos]) {
        return false;
    }
    else if (supermercado[i] >= 3) {
        return false;
    }
    else {
        return true;
    }
}

void comprar(const vector<vector<int>>& valores, int m, int n, int cont, int& total, int& precioActual, vector<int>& supermercado, vector<bool>& productos, const vector<int>& acumulados, bool& correcto) {
    for (int i = 0; i < m; i++) {
        if (esValida(supermercado, productos, cont, i)) {
            precioActual += valores[i][cont];       // Sumamos el valor del precio del producto en posición cont y en el supermercado i a la suma total. 
            productos[cont] = true;                 // Marcamos que ya tenemos el producto en posición cont seleccionado.
            supermercado[i]++;                      // Aumentamos el numero de productos que hemos cogido del supermercado en la posición i.
            if (cont == n - 1) {       // Si hemos llegado al final del vector.
                if (precioActual < total) {
                    total = precioActual;
                    correcto = true;
                }
            }
            else {  // Si el precio que se lleva hasta entonces más lo posible más pequeño a partir de ahí es menor que lo guardado en total entonces se llama recursivamente, si no, se mantiene dicho total y no se hace la recursión.
                if (acumulados[cont + 1] + precioActual < total) {
                    comprar(valores, m, n, cont + 1, total, precioActual, supermercado, productos, acumulados, correcto);
                }
            }
            precioActual -= valores[i][cont];
            productos[cont] = false;
            supermercado[i]--;
        }
    }
}

void resuelveCaso() {
    //resuelve aqui tu caso
       //Lee los datos
    int m, n;

    cin >> m >> n;    

    vector<vector<int>> valores(m, vector<int>(n));
    vector<int> minValores(n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> valores[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        minValores[i] = valores[0][i];
        for (int j = 0; j < m; j++) {      // Obtenemos los mínimos de cada producto.
            if (minValores[i] > valores[j][i]) {        // Obtenemos los mínimos de cada producto.
                minValores[i] = valores[j][i];
            }
        }
    }

    vector<int> sumasMinimos(n);
    sumasMinimos = minValores;
    for (int i = n - 2; i > -1; i--) {
        sumasMinimos[i] = sumasMinimos[i + 1] + minValores[i];
    }

    int total = 1000000, precioActual = 0, cont = 0;
    bool correcto = false;
    vector<int> supermercado(m);    // Para saber los productos que se han cogido de cada supermercado (En super 0 (supermercado[0]) x productos, en super 1 y productos, etc).
    vector<bool> productos(n);      // Para saber si ese producto ya ha sido cogido.

       //Calcula el resultado
    comprar(valores, m, n, cont, total, precioActual, supermercado, productos, sumasMinimos, correcto);
       //Escribe el resultado
    if (!correcto) {
        cout << "Sin solucion factible" << endl;
    }
    else {
        cout << total << endl;
    }
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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