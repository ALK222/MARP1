
// NOMBRE Y APELLIDOS
// Alejandro Barrachina Argudo

#include <iostream>
#include "Grafo.h"
#include <vector>
#include <fstream>
using namespace std;

int dfs(Grafo const& G, int v, std::vector<bool> &visitados);

int maxNumAmigos(Grafo const& G, std::vector<bool> &visitados)
{
    int maxAmigos = 0;
    for(int v = 0; v < G.V(); ++v)
    {
        if(!visitados[v])
        {
            int tam = dfs(G, v, visitados);
            maxAmigos = std::max(maxAmigos, tam);
        }
    }

    return maxAmigos;
}

int dfs(Grafo const& G, int v, std::vector<bool> &visitados){
    visitados[v] = true;
    int tam = 1;
    for(int w : G.ady(v))
    {
        if(!visitados[w])
        {
            tam +=dfs(G, w, visitados);
        }
    }
    return tam;
}

void resuelveCaso()
{

    // Leer caso de prueba: cin>>...
    int numVertices;

    std::cin >> numVertices;

    int numAristas;

    std::cin >> numAristas;

    Grafo g(numVertices);

    for (int i = 0; i < numAristas; i++)
    {
        int v1;
        int v2;
        std::cin >> v1 >> v2;
        g.ponArista(v1 - 1, v2 - 1);
    }


    std::vector<bool> visitados(numVertices);

    std::cout << maxNumAmigos(g, visitados) << "\n";
}

int main()
{

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for(int i = 0; i < numCasos; ++i)
    {
        resuelveCaso();
    }

        // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}
