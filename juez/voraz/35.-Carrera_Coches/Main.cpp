#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define MAX_TIEMPO 1000000000

int combinacionPilas(std::vector<int> &pilas, int const &voltaje)
{
    int maxCoches = 0;
    std::sort(pilas.begin(), pilas.end(), std::greater<int>());

    int i = 0;
    int j = pilas.size() - 1;

    while (i < j)
    {
        if (pilas[i] + pilas[j] >= voltaje)
        {
            maxCoches++;
            i++;
        }
        j--;
    }

    return maxCoches;
}

void resuelveCaso()
{
    int numPilas;
    int minVoltaje;
    std::cin >> numPilas >> minVoltaje;

    std::vector<int> pilas;

    for (int i = 0; i < numPilas; ++i)
    {
        int pila;
        std::cin >> pila;
        pilas.push_back(pila);
    }

    int maxCoches = combinacionPilas(pilas, minVoltaje);

    std::cout << maxCoches << "\n";
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