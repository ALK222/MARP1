#include <iostream>
#include <fstream>
#include "DigrafoValorado.h"
#include "IndexPQ.h"

#define MAX_TIEMPO 1000000000

class TecladosRotos
{
private:
    DigrafoValorado<int> const grafo;
    int const ini;
    IndexPQ<int> pq;
    std::vector<long long int> dist;
    std::vector<int> const cargas;

    void relaja(AristaDirigida<int> a)
    {
        int v = a.desde();
        int w = a.hasta();

        if (dist[w] > dist[v] + a.valor() + cargas[w])
        {
            dist[w] = dist[v] + a.valor() + cargas[w];
            pq.update(w, dist[w]);
        }
    }
    void contarEnlaces()
    {
        dist[ini] = cargas[ini];
        pq.push(ini, cargas[ini]);

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
    TecladosRotos(DigrafoValorado<int> const &g, std::vector<int> const &cs) : grafo(g), ini(0), pq(g.V()), dist(g.V(), MAX_TIEMPO), cargas(cs)
    {
    }

    void resolver()
    {
        contarEnlaces();
    }

    bool posible()
    {
        return dist[dist.size() - 1] != MAX_TIEMPO;
    }

    long long int timepo()
    {
        return dist[dist.size() - 1];
    }
};

bool resuelveCaso()
{
    int N;
    std::cin >> N;

    if (N == 0)
        return false;

    std::vector<int> cargas(N);

    for (int i = 0; i < N; ++i)
    {

        int C;
        std::cin >> C;
        cargas[i] = C;
    }

    int E;
    std::cin >> E;
    DigrafoValorado<int> grafo(N);
    for (int ar = 0; ar < E; ++ar)
    {
        int v, w, c;
        std::cin >> v >> w >> c;
        grafo.ponArista({v - 1, w - 1, c});
        // grafo.ponArista({w - 1, v - 1, c});
    }

    TecladosRotos problema(grafo, cargas);
    problema.resolver();
    if (problema.posible())
    {
        long long int resultado = problema.timepo();
        std::cout << resultado << '\n';
    }
    else
    {
        std::cout << "IMPOSIBLE\n";
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