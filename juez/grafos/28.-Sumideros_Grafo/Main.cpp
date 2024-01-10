#include <iostream>
#include <fstream>
#include <queue>
#include "Digrafo.h"

#define MAX_TIEMPO 1000000000

bool esSumidero(Digrafo const &g, int v)
{
    int entrada = 0;
    for (int i = 0; i < g.V(); ++i)
    {
        if (g.hayArista(i, v))
        {
            entrada++;
        }
    }
    return entrada == g.V() - 1;
}

int buscaSumidero(Digrafo g)
{
    std::vector<bool> visitados(g.V(), false);
    int sumidero = -1;

    std::queue<int> q;

    q.push(0);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        if (visitados[v])
        {
            continue;
        }

        visitados[v] = true;

        if (g.ady(v).size() == 0)
        {
            if (esSumidero(g, v))
            {
                return v;
            }
        }

        for (int w : g.ady(v))
        {
            if (!visitados[w])
            {
                q.push(w);
            }
        }
    }
    return sumidero;
}

bool resuelveCaso()
{
    int N;
    std::cin >> N;

    if (!std::cin)
        return false;

    int E;
    std::cin >> E;
    Digrafo grafo(N);
    for (int ar = 0; ar < E; ++ar)
    {
        int v, w;
        std::cin >> v >> w;
        grafo.ponArista(v, w);
    }

    int sol = buscaSumidero(grafo);

    if (sol != -1)
    {
        std::cout << "SI " << sol << "\n";
    }
    else
    {
        std::cout << "NO\n";
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