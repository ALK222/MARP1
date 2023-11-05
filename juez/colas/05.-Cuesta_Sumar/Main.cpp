// Alejandro Barrachina Argudo

#include <iostream>
#include <fstream>
#include "PriorityQueue.h"

using namespace std;
using lli = long long int;

lli minEsfuerzo(PriorityQueue<lli> &pq)
{
    lli esfuerzo = 0;

    lli n1;
    lli n2;

    while (pq.size() > 1)
    {
        n1 = pq.top();
        pq.pop();
        n2 = pq.top();
        pq.pop();

        n1 += n2;
        esfuerzo += n1;

        pq.push(n1);
    }

    return esfuerzo;
}

bool resuelveCaso()
{

    int numEnteros;

    std::cin >> numEnteros;

    if (numEnteros == 0)
    {
        return false;
    }

    PriorityQueue<lli> pq;

    for (int i = 0; i < numEnteros; ++i)
    {
        lli aux;
        std::cin >> aux;
        pq.push(aux);
    }

    std::cout << minEsfuerzo(pq) << "\n";

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
