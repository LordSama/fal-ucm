#include <iostream>
#include <fstream>
using namespace std;

/* m es el número de dígitos de n
 *          { c_0            si m=1
 *   T(m) = { T(m-1) + c_1   si m>1
 *  El coste es lineal con respecto al número de dígitos,
 *   es decir O(m).
 */

int multiplicativo(int n, int& prod) {
    int sol = 0;
    if (n < 10) {//si sólo hay un dígito
        prod = n;
        if (n == 1) //la cifra es multiplicativa
            sol = 1;
    }
    else {//caso recursivo
        int prodS; //producto de los siguientes dígitos
        sol = multiplicativo(n / 10, prodS);
        if (prodS == n % 10) //si la última cifra es multiplicativa sumamos uno más
            sol++;
        prod = prodS * n % 10; //actualizamos el producto
    }
    return sol;
}

int multiplicativo(int n) {
    int producto;
    return multiplicativo(n, producto);
}

void resuelveCaso() {
    int n;
    cin >> n;
    cout << multiplicativo(n) << endl;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("../sample2.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
