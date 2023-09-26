// NOMBRE y APELLIDOS
// Alejandro Barrachina

#include <iostream>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

int resuelveCasoAux(const bintree<int> &a, bool &equilibrado, int _min, int _max)
{
    if (a.empty())
    {
        return 0;
    }
    else
    {

        int nivelIz = 1 + resuelveCasoAux(a.left(), equilibrado, _min, a.root());   // Si vamos por el lado menor, el número maximo es la raiz anterior
        int nivelDer = 1 + resuelveCasoAux(a.right(), equilibrado, a.root(), _max); // Si vamos por el lado mayor, el numero minimo es la raiz anterior

        if (equilibrado) // Solo resolvemos el caso si todos los casos siguientes son AVL
        {
            if (abs(nivelDer - nivelIz) > 1)
            {
                equilibrado = false;
            }
            else
            {
                equilibrado = a.root() > _min && a.root() < _max;
            }
        }

        return max(nivelDer, nivelIz);
    }
}

void resuelveCaso()
{
    bintree<int> a = leerArbol(-1);

    bool equilibrado = true;

    resuelveCasoAux(a, equilibrado, -1, 9999999999);

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
