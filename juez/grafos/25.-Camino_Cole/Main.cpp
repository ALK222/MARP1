#include <iostream>
#include <fstream>
#include "DigrafoValorado.h"
#include "IndexPQ.h"

#define MAX_TIEMPO 1000000000

class PueblosCercanos
{
private:
    DigrafoValorado<int> const grafo;
    int const ini;
    IndexPQ<int> pq;
    std::vector<long long int> dist;
    std::vector<long long int> caminos;

    void relaja(AristaDirigida<int> a)
    {
        int v = a.desde();
        int w = a.hasta();

        if (dist[w] > dist[v] + a.valor())
        {
            dist[w] = dist[v] + a.valor();
            caminos[w] = caminos[v];
            pq.update(w, dist[w]);
        }
        else if (dist[w] == dist[v] + a.valor())
        {
            caminos[w] += caminos[v];
        }
    }
    void contarFormas()
    {
        dist[ini] = 0;
        caminos[ini] = 1;
        pq.push(ini, 0);

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
    PueblosCercanos(DigrafoValorado<int> const &g) : grafo(g), ini(0), pq(g.V()), dist(g.V(), MAX_TIEMPO), caminos(g.V(), 0)
    {
    }

    void resolver()
    {
        contarFormas();
    }

    long long int posiblesFormas()
    {
        return caminos[caminos.size() - 1];
    }
};

bool resuelveCaso()
{
    int N, C;
    std::cin >> N >> C;

    if (!std::cin)
        return false;

    DigrafoValorado<int> grafo(N);
    for (int ar = 0; ar < C; ++ar)
    {
        int v, w, c;
        std::cin >> v >> w >> c;
        grafo.ponArista({v - 1, w - 1, c});
        grafo.ponArista({w - 1, v - 1, c});
    }

    PueblosCercanos problema(grafo);
    problema.resolver();
    long long int resultado = problema.posiblesFormas();
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