
// NOMBRE Y APELLIDOS
// Alejandro Barrachina Argudo

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include "Grafo.h"

void bfs(Grafo const &g, int v, int TTL, int &totalNodos, std::vector<bool> &visitados);

void bfs(Grafo const &g, int v, int TTL, int &totalNodos, std::vector<bool> &visitados)
{
    std::queue<int> q;
    std::vector<int> dist(g.V(), 0);

    dist[v] = 0;
    visitados[v] = true;

    q.push(v);

    while (!q.empty())
    {
        int nodo = q.front();
        q.pop();

        for (int w : g.ady(nodo))
        {
            if (!visitados[w] && dist[nodo] < TTL)
            {
                dist[w] = dist[nodo] + 1;
                visitados[w] = true;
                totalNodos++;
                q.push(w);
            }
        }
    }
}

bool resuelveCaso()
{

    // Leer caso de prueba: cin>>...
    int numNodos;

    std::cin >> numNodos;

    if (!std::cin)
    {
        return false;
    }

    Grafo g(numNodos);
    int numConexiones;

    std::cin >> numConexiones;

    for (int i = 0; i < numConexiones; i++)
    {
        int a;
        int b;

        std::cin >> a >> b;

        if (a == 0 || b == 0)
        {
            continue;
        }
        g.ponArista(a - 1, b - 1);
    }

    int numConsultas;

    std::cin >> numConsultas;

    for (int i = 0; i < numConsultas; ++i)
    {
        int nodoInicio;
        int TTL;

        std::cin >> nodoInicio >> TTL;

        int totalNodos = 0;

        std::vector<bool> visitados(numNodos, false);

        bfs(g, nodoInicio - 1, TTL, totalNodos, visitados);

        std::cout << numNodos - totalNodos - 1 << "\n";
    }

    std::cout << "---\n";

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
    system("pause");
#endif
    return 0;
}
