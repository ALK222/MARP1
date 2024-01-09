#include <iostream>
#include <fstream>
#include <queue>
#include "DigrafoValorado.h"
#include "IndexPQ.h"

#define MAX_TIEMPO 100000000

class Intersecciones
{
private:
    int ini;
    int fin;
    std::vector<int> dist;
    std::vector<int> caminos;
    std::vector<int> aristas;
    IndexPQ<int> pq;

    void relajar(AristaDirigida<int> a)
    {
        int v = a.desde();
        int w = a.hasta();
        if (dist[w] > dist[v] + a.valor() || (dist[w] == dist[v] + a.valor() && aristas[w] > aristas[v] + 1))
        {
            dist[w] = dist[v] + a.valor();
            aristas[w] = aristas[v] + 1;
            pq.update(w, dist[w]);
        }
    }
    void bfs(DigrafoValorado<int> const &g)
    {
        std::vector<bool> visitados(g.V(), false);
        std::queue<int> cola;
        cola.push(ini);
        visitados[ini] = true;

        while (!cola.empty())
        {
            int v = cola.front();
            cola.pop();
            for (auto w : g.ady(v))
            {
                if (!visitados[w.hasta()])
                {
                    visitados[w.hasta()] = true;
                    caminos[w.hasta()] = caminos[v] + 1;
                    cola.push(w.hasta());
                }
            }
        }
    }

    void dijkstra(DigrafoValorado<int> const &g)
    {
        dist[ini] = 0;
        pq.push(ini, 0);
        while (!pq.empty())
        {
            int v = pq.top().elem;
            pq.pop();
            for (AristaDirigida<int> a : g.ady(v))
            {
                relajar(a);
            }
        }
    }

public:
    Intersecciones(DigrafoValorado<int> const &g, int i, int f) : ini(i), fin(f), dist(g.V(), MAX_TIEMPO),
                                                                  caminos(g.V(), 0), aristas(g.V(), 0), pq(g.V())
    {
        dijkstra(g);
        bfs(g);
    }

    bool hayCamino() const
    {
        return dist[fin] != MAX_TIEMPO;
    }
    int distancia() const
    {
        return dist[fin];
    }

    bool esPosible()
    {
        return aristas[fin] == caminos[fin];
    }
};

bool resuelveCaso()
{
    int intersecciones;
    std::cin >> intersecciones;

    if (!std::cin)
    {
        return false;
    }

    int calles;
    std::cin >> calles;

    DigrafoValorado<int> g(intersecciones);

    for (int i = 0; i < calles; ++i)
    {
        int i1;
        int i2;
        int tiempo;

        std::cin >> i1 >> i2 >> tiempo;

        AristaDirigida<int> aux(i1 - 1, i2 - 1, tiempo);
        AristaDirigida<int> aux2(i2 - 1, i1 - 1, tiempo);
        g.ponArista(aux);
        g.ponArista(aux2);
    }

    int consultas;
    std::cin >> consultas;

    for (int i = 0; i < consultas; ++i)
    {
        int ini;
        int fin;
        std::cin >> ini >> fin;

        Intersecciones sol(g, ini - 1, fin - 1);

        if (sol.hayCamino())
        {
            std::cout << sol.distancia();
            sol.esPosible() ? std::cout << " SI\n" : std::cout << " NO\n";
        }
        else
        {
            std::cout << "SIN CAMINO\n";
        }
    }

    std::cout << "---\n";
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