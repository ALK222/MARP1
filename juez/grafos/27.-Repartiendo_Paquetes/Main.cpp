#include <iostream>
#include <fstream>
#include "DigrafoValorado.h"
#include "IndexPQ.h"

#define MAX_TIEMPO 1000000000

class Amazont
{
private:
    DigrafoValorado<int> const grafo;
    int const ini;
    IndexPQ<int> pq;
    std::vector<long long int> dist;
    int min;

    void relaja(AristaDirigida<int> a)
    {
        int v = a.desde();
        int w = a.hasta();

        if (dist[w] > dist[v] + a.valor())
        {
            dist[w] = dist[v] + a.valor();
            pq.update(w, dist[w]);
        }
    }
    void rutas(DigrafoValorado<int> g)
    {
        dist[ini] = 0;
        pq.push(ini, 0);

        while (!pq.empty())
        {
            int v = pq.top().elem;
            pq.pop();
            for (AristaDirigida<int> a : g.ady(v))
            {
                relaja(a);
            }
        }
    }

public:
    Amazont(DigrafoValorado<int> const &g, int i) : grafo(g), ini(i), pq(g.V()), dist(g.V(), MAX_TIEMPO), min(0)
    {
    }

    void resolver(std::vector<int> dest)
    {
        rutas(grafo.inverso());
        std::vector<int> vuelta;

        for (int i = 0; i < dist.size(); ++i)
        {
            vuelta.push_back(dist[i]);
            dist[i] = MAX_TIEMPO;
        }

        rutas(grafo);

        for (int i : dest)
        {
            if (dist[i] == MAX_TIEMPO || vuelta[i] == MAX_TIEMPO)
            {
                min = MAX_TIEMPO;
                return;
            }
            min += dist[i] + vuelta[i];
        }
    }

    bool posible()
    {
        return min != MAX_TIEMPO;
    }

    long long int tiempo()
    {
        return min;
    }
};

bool resuelveCaso()
{
    int N;
    std::cin >> N;

    if (!std::cin)
        return false;

    int E;
    std::cin >> E;
    DigrafoValorado<int> grafo(N);
    for (int ar = 0; ar < E; ++ar)
    {
        int v, w, c;
        std::cin >> v >> w >> c;
        grafo.ponArista({v - 1, w - 1, c});
    }

    int ini;
    std::cin >> ini;
    ini--;

    int paquetes;
    std::cin >> paquetes;
    std::vector<int> destinatarios(paquetes);
    for (int i = 0; i < paquetes; i++)
    {
        int destinatario;
        std::cin >> destinatario;
        destinatarios[i] = destinatario - 1;
    }

    Amazont problema(grafo, ini);
    problema.resolver(destinatarios);
    if (problema.posible())
    {
        std::cout << problema.tiempo() << "\n";
    }
    else
    {
        std::cout << "Imposible\n";
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