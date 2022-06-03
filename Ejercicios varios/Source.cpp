#include <iostream>
#include <vector>
using namespace std;

/*  Especificación:
*       - Precondición P: { v.size() >= 0 }
*         fun segmentoMaximo (vector<int> v) dev { int np, int nv, int fg }     
*                Siendo np el número máximo de partidos ganados, nv el número de segmentos de longitud np y fg el número de partidos
*                desde que terminó la última racha.
*       - Postcondición Q: { (np == max : p, q : 0 <= p <= q < v.size() ^ secPositiva(v, p, q) : q - p) ^ 
*                            (nv = #p : 0 <= j < v.size() - np + 1 : secPositiva(v, p, p + np)) ^
*                            (all j : 0 <= j < v.size() - np ^ secPositiva(v, j, j + np) : j <= v.size() - fg - np) ^
*                            (secPositiva(v, v.size() - fg - np, v.size() - fg)) }
*                               Siendo secPositiva(v, p, q) === all k : p <= k < q : v[k] > 0. Es decir que todos los elementos
*                               de ese segmento son positivos.
*   Invariante: Conjunción de las siguientes propiedades:
*               - longMax == max p, q : 0 <= p <= q <= i ^ secPositiva(v, p, q) : q - p.
*               - numVeces == #p : 0 <= p < i - longMax + 1 : secPositiva(v, p, p + longMax)
*               - Para ultMax -->  (forall j : 0 <= j <= i - longMax ^ secPositiva(v, j, j + longMax) : j <= ultMax + 1 - longMax) ^ 
*                                   secPositiva(v, ultMax + 1 - longMax, ultMax + 1)).
*               - longAct == max k : 0 <= k < v.size() : secPositiva(v, i - k, i) : k
*               - i <= v.size()   --> Sobre la variable de control.
*   Función cota: t(i) = v.size() - i + 1.
*/

struct tSol {
    int maxGanados;
    int repeticiones;
    int racha;
};

tSol resolver(vector<int> const& v) {
    int ultimoMax = -1, longMax = 0, numVeces = 0, longAct = 0, i = 0;

    while (i < v.size()) {
        if (v[i] > 0) {                 // El elemento continúa la racha, pues se ha ganado ese partido.
            longAct++;
            if (longMax < longAct) {    // Mejora la racha anterior, pues ya llevamos mas partidos ganados.
                longMax = longAct;
                ultimoMax = i;          // Guardamos la posición del último partido ganado en la racha.
                numVeces = 1;           // Como es la primera vez que aparece esta racha se reinicia el numVeces a 1.
            }
            else if (longMax == longAct) {      // Iguala la racha anterior, pues ambas tienen el mismo número de partidos ganados.
                numVeces++;                     // Se aumenta el contador de apariciones de esa racha.
                ultimoMax = i;                  // Guardamos la posición donde acaba la racha.
            }
        }
        else {              // Se rompe la racha, pues se ha perdido el partido (v[i] <= 0).
            longAct = 0;    // La racha actual se reinicia a 0.
        }
        i++;
    }
    return { longMax, numVeces, (int)v.size() - ultimoMax - 1 };
}

bool resuelveCaso() {
    // leer los datos de la entrada
    int n, aux;
    vector<int> v;
    tSol sol;

    cin >> n;
    if (!std::cin)
        return false;

    for (int i = 0; i < n; i++) {
        cin >> aux;
        v.push_back(aux);
    }

    sol = resolver(v);

    // escribir sol
    cout << sol.maxGanados << " " << sol.repeticiones << " " << sol.racha << endl;

    return true;

}

int main() {
    while (resuelveCaso());

    return 0;
}