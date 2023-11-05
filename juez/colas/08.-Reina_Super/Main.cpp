// Alejandro Barrachina Argudo

#include <iostream>
#include <fstream>
#include <string>
#include "PriorityQueue.h"

using namespace std;

struct Cliente
{
    int numCaja;
    int segs;
};

bool operator<(Cliente const &a, Cliente const &b)
{
    return a.segs < b.segs || (a.segs == b.segs && a.numCaja < b.numCaja);
}

bool resuelveCaso()
{

    int numCajas;
    int clientesEsperando;

    std::cin >> numCajas >> clientesEsperando;

    if (numCajas == 0 && clientesEsperando == 0)
    {
        return false;
    }

    PriorityQueue<Cliente> pq;

    Cliente c;

    int t;
    int cajaLibre = 1;
    int tiempo = 0;

    while (clientesEsperando > 0)
    {
        std::cin >> t;

        c.segs = t + tiempo;

        if (numCajas > 0)
        {
            c.numCaja = cajaLibre;
            pq.push(c);
            cajaLibre++;
            numCajas--;
        }

        if (numCajas == 0)
        {
            cajaLibre = pq.top().numCaja;
            tiempo = pq.top().segs;
            pq.pop();
            numCajas++;
        }

        clientesEsperando--;
    }

    std::cout << cajaLibre << "\n";

    return true;
}

int main()
{

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

        // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    // system("pause");
#endif
    return 0;
}
