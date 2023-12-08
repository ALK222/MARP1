
// NOMBRE Y APELLIDOS
// Alejandro Barrachina Argudo

#include <iostream>
#include "Grafo.h"
#include <vector>
#include <fstream>
using namespace std;

void dfs(Grafo const& G, int v, std::vector<bool> &visitados, int &numVisitados){
    numVisitados++;
    visitados[v] = true;
    for(int w : G.ady(v))
    {
        if(!visitados[w])
        {
            dfs(G, w, visitados, numVisitados);
        }
    }

}

bool resuelveCaso()
{

    // Leer caso de prueba: cin>>...
    int numVertices;

    std::cin >> numVertices;

    if (!std::cin)
    {
        return false;
    }

    int numAristas;

    std::cin >> numAristas;

    Grafo g(numVertices);

    for (int i = 0; i < numAristas; i++)
    {
        int v1;
        int v2;
        std::cin >> v1 >> v2;
        g.ponArista(v1, v2);
    }


    std::vector<bool> visitados(numVertices);
    int numVisitados = 0;

    dfs(g, 0, visitados, numVisitados);

    bool esLibre = numVisitados == numVertices && numVertices - 1 ==numAristas;

    if (esLibre)
    {
        std::cout << "SI\n";
    }
    else
    {
        std::cout << "NO\n";
    }

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
