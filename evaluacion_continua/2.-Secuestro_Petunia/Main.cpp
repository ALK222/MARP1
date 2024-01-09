#include <iostream>
#include <fstream>
#include <queue>
#include "DigrafoValorado.h"
#include "IndexPQ.h"

#define MAX_TIEMPO 100000000

class PueblosCercanos
{
private:
    DigrafoValorado<int> const grafo;
    int const maxD;
    int pueblos;
    IndexPQ<int> pq;
    std::vector<bool> visitados;
    std::vector<int> dist;

    void relaja(AristaDirigida<int> const &a)
    {
        int v = a.desde();
        int w = a.hasta();

        if (dist[w] > dist[v] + a.valor())
        {
            dist[w] = dist[v] + a.valor();
            if (dist[w] <= maxD && !visitados[w])
            {
                visitados[w] = true;
                pueblos++;
            }
            pq.update(w, dist[w]);
        }
    }

    void contarPueblos()
    {
        while (!pq.empty())
        {
            int v = pq.top().elem;
            pq.pop();
            for (AristaDirigida<int> a : grafo.ady(v))
            {
                relaja(a);
            }
        }
    }

public:
    PueblosCercanos(DigrafoValorado<int> const &g, int const maxDistancia) : grafo(g), maxD(maxDistancia), pq(g.V()), visitados(g.V(), false), dist(g.V(), MAX_TIEMPO)
    {
    }

    void pushPQ(std::vector<int> borriquines)
    {
        for (int i : borriquines)
        {
            dist[i] = 0;
            visitados[i] = true;
            pq.push(i, 0);
        }
        pueblos = borriquines.size();
    }

    void resolver()
    {
        contarPueblos();
    }

    int posiblesPueblos()
    {
        return pueblos;
    }
};

bool resuelveCaso()
{
    int D, P, C;
    std::cin >> D >> P >> C;

    if (!std::cin)
        return false;

    DigrafoValorado<int> grafo(P);
    for (int ar = 0; ar < C; ++ar)
    {
        int v, w, c;
        std::cin >> v >> w >> c;
        grafo.ponArista({v - 1, w - 1, c});
        grafo.ponArista({w - 1, v - 1, c});
    }

    int B;
    std::cin >> B;
    std::vector<int> borriquines(B);
    for (int &x : borriquines)
    {
        std::cin >> x;
        --x;
    }

    PueblosCercanos problema(grafo, D);
    problema.pushPQ(borriquines);
    problema.resolver();
    int resultado = problema.posiblesPueblos();
    std::cout << resultado << '\n';
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