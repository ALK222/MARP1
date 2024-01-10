#include <iostream>
#include <fstream>
#include "PriorityQueue.h"
#include "GrafoValorado.h"
#include "ConjuntosDisjuntos.h"

#define MAX_TIEMPO 1000000000

int minAutonomia(GrafoValorado<int> const &g)
{
    int coste = 0;
    int maximo = 0;
    PriorityQueue<Arista<int>> pq(g.aristas());
    ConjuntosDisjuntos c(g.V());

    while (!pq.empty())
    {
        Arista<int> a = pq.top();
        pq.pop();
        int v = a.uno();
        int w = a.otro(v);
        if (!c.unidos(v, w))
        {
            c.unir(v, w);
            coste += a.valor();

            maximo = std::max(a.valor(), maximo);
        }
    }
    return c.num_cjtos() < 2 ? maximo : -1;
}

bool resuelveCaso()
{
    int N;
    std::cin >> N;

    if (!std::cin)
        return false;

    int M;
    std::cin >> M;
    GrafoValorado<int> grafo(N);
    for (int ar = 0; ar < M; ++ar)
    {
        int v, w, c;
        std::cin >> v >> w >> c;
        grafo.ponArista({v - 1, w - 1, c});
    }

    int sol = minAutonomia(grafo);

    if (sol == -1)
    {
        std::cout << "Imposible\n";
    }
    else
    {
        std::cout << sol << "\n";
    }

    return true;
}
int main()
{
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

        // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}