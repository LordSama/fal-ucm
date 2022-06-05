#include <iostream>
#include <string>
#include <vector>
using namespace std;

void resuelveCaso() {
    string cadena;
    vector<char> apellidoAct, apellidoAnt;
    int pos;
    bool sonHermanos = false;
    long long int participantes = 0, total = 0, p = 1;

    apellidoAnt.clear();

    do {
        getline(cin, cadena);
        if (cadena != "====") {
            participantes++;
            pos = cadena.find_first_of(',');

            for (int i = 0; i < pos; i++) {
                apellidoAct.push_back(tolower(cadena[i]));
            }

            if (apellidoAct == apellidoAnt) {
                p++;
                sonHermanos = true;
            }
            else if (sonHermanos) {
                total = total + p;
                p = 1;
                sonHermanos = false;
            }
            apellidoAnt = apellidoAct;
            apellidoAct.clear();
            cadena.clear();
        }
    } while (cadena != "====");

    if (sonHermanos) {
        total = total + p;
    }

    cout << participantes << " " << total << endl;
}

int main() {
    int numCasos;

    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}
