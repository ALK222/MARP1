// NOMBRE y APELLIDOS
// Alejandro Barrachina

#include <iostream>
#include <fstream>
#include <vector>
#include "mapk.h"

bool resuelveCaso()
{
    Set<int> a1;
    int numElems;

    std::cin >> numElems;

    if (numElems == 0)
    {
        return false;
    }

    for (int i = 0; i < numElems; i++)
    {
        int aux;
        std::cin >> aux;
        a1.insert({aux});
    }
    // a1.recalculaTams();

    int numConsultas;
    std::cin >> numConsultas;

    for (int i = 0; i < numConsultas; ++i)
    {
        int consulta;
        std::cin >> consulta;

        try
        {
            std::cout << a1.dokesimo(consulta) << "\n";
        }
        catch (const std::exception &e)
        {
            std::cout << "??\n";
        }
    }

    std::cout << "---\n";
    return true;
}

int main()
{
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}
