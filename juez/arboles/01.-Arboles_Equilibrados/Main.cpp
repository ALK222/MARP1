// NOMBRE y APELLIDOS
// Alejandro Barrachina

#include <iostream>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

int resuelveCasoAux(const bintree<char> &a, bool &equilibrado)
{
    if (a.empty())
    {
        return 0;
    }
    else
    {

        int nivelIz = 1 + resuelveCasoAux(a.left(), equilibrado);
        int nivelDer = 1 + resuelveCasoAux(a.right(), equilibrado);

        if (abs(nivelDer - nivelIz) > 1 && equilibrado)
        {
            equilibrado = false;
        }

        return max(nivelDer, nivelIz);
    }
}

void resuelveCaso()
{
    bintree<char> a = leerArbol('.');

    bool equilibrado = true;

    resuelveCasoAux(a, equilibrado);

    if (equilibrado)
    {
        cout << "SI\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    unsigned int numCasos;
    std::cin >> numCasos;
    // Resolvemos
    for (int i = 0; i < numCasos; ++i)
    {
        resuelveCaso();
    }

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}
