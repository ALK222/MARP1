// NOMBRE y APELLIDOS
// Alejandro Barrachina

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include "GrafoValorado.h"

class Archipielagos
{
private:
    int minimo;
    std::vector<bool> visitados;
    std::queue<Arista<int>> cola;
    std::priority_queue<Arista<int>, std::vector<Arista<int>>, std::greater<Arista<int>>> pq;

    void visit(GrafoValorado<int> const &g, int v)
    {
        visitados[v] = true;
        for (Arista<int> i : g.ady(v))
        {
            if (!visitados[i.otro(v)])
            {
                pq.push(i);
            }
        }
    }

public:
    Archipielagos(GrafoValorado<int> const &g) : minimo(-1), visitados(g.V(), false)
    {
        visit(g, 0);
        while (!pq.empty())
        {
            Arista<int> aux = pq.top();
            pq.pop();
            int v = aux.uno();
            int w = aux.otro(v);
            if (!visitados[v] || !visitados[w])
            {
                cola.push(aux);
                if (!visitados[v])
                {
                    visit(g, v);
                }
                if (!visitados[w])
                {
                    visit(g, w);
                }
            }
        }

        if (conexo(g))
        {
            int coste = 0;
            while (!cola.empty())
            {
                Arista<int> aux = cola.front();
                cola.pop();
                coste += aux.valor();
            }
            minimo = coste;
        }
    }

    bool conexo(GrafoValorado<int> const &g)
    {
        return cola.size() == (long unsigned int)g.V() - 1;
    }

    int getMinimo()
    {
        return minimo;
    }
};

bool resuelveCaso()
{
    int numIslas;

    std::cin >> numIslas;

    if (!std::cin)
    {
        return false;
    }

    int numPuentes;

    std::cin >> numPuentes;

    GrafoValorado<int> g(numIslas);

    for (int i = 0; i < numPuentes; ++i)
    {
        int origen;
        int destino;
        int coste;
        std::cin >> origen >> destino >> coste;

        Arista<int> aux(origen - 1, destino - 1, coste);
        g.ponArista(aux);
    }

    Archipielagos a(g);

    if (a.getMinimo() != -1)
    {
        std::cout << a.getMinimo() << "\n";
    }
    else
    {
        std::cout << "No hay puentes suficientes\n";
    }

    return true;
}

int main()
{
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}
