
// NOMBRE Y APELLIDOS
// Alejandro Barrachina Argudo

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include "Digrafo.h"

// void bfs(Digrafo const &g, int i, std::vector<bool> &marcados, std::vector<bool> &visitados, std::vector<int> &orden, bool &imposible);
void dfs(Digrafo const &g, int i, std::vector<bool> &marcados, std::vector<bool> &visitados, std::vector<int> &orden, bool &imposible);

// void bfs(Digrafo const &g, int i, std::vector<bool> &marcados, std::vector<bool> &visitados, std::vector<int> &orden, bool &imposible)
// {
//     std::queue<int> pila;

//     pila.push(i);

//     for (int i = 0; i < g.V() && !imposible; ++i)
//     {
//         while (!pila.empty())
//         {
//             if (!visitados[i])
//             {
//                 visitados[i] = true;
//             }
//         }
//     }
// }

bool checkVisitados(Digrafo const &g, int i, std::vector<bool> &visitados)
{
    for (int w : g.ady(i))
    {
        if (visitados[w])
        {
            return true;
        }
    }

    return false;
}

void dfs(Digrafo const &g, int i, std::vector<bool> &marcados, std::vector<bool> &visitados, std::vector<int> &orden, bool &imposible)
{
    // orden.push_back(i);

    visitados[i] = true;
    marcados[i] = true;

    // imposible = checkVisitados(g, i, visitados);

    for (int w : g.ady(i))
    {
        if (visitados[w])
        {
            imposible = true;
        }

        if (!imposible && !marcados[w])
        {

            dfs(g, w, marcados, visitados, orden, imposible);
        }
    }

    // std::cout << i << "\n";
    visitados[i] = false;
    orden.push_back(i);
    //
}

bool resuelveCaso()
{

    // Leer caso de prueba: cin>>...
    int numTareas;

    std::cin >> numTareas;

    if (!std::cin)
    {
        return false;
    }

    Digrafo g(numTareas);

    int numConexiones;

    std::cin >> numConexiones;

    for (int i = 0; i < numConexiones; ++i)
    {
        int a;
        int b;
        std::cin >> a >> b;

        g.ponArista(a - 1, b - 1);
    }

    bool imposible = false;

    std::vector<bool> visitados(numTareas, false);
    std::vector<bool> marcados(numTareas, false);
    std::vector<int> orden;

    for (int i = 0; i < numTareas && !imposible; ++i)
    {
        if (!marcados[i])
        {
            dfs(g, i, marcados, visitados, orden, imposible);
        }
    }

    if (!imposible)
    {
        for (int i = orden.size() - 1; i >= 0; i--)
        {
            std::cout << orden[i] + 1 << " ";
        }
        std::cout << "\n";
    }
    else
    {
        std::cout << "Imposible\n";
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
