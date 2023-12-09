
// NOMBRE Y APELLIDOS
// Alejandro Barrachina Argudo

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Grafo.h"

class Solucion
{
private:
    std::vector<bool> visitados;
    std::vector<int> compI;
    std::vector<int> componentes;
    int conexa;

    int dfs(Grafo const &g, int v)
    {
        visitados[v] = true;
        compI[v] = conexa;

        int tam = 1;
        for (auto w : g.ady(v))
        {
            if (!visitados[w])
            {
                tam += dfs(g, w);
            }
        }
        return tam;
    }

public:
    Solucion(Grafo const &g) : visitados(g.V(), false), conexa(0), compI(g.V())
    {
        for (int i = 0; i < g.V(); ++i)
        {
            if (!visitados[i])
            {
                int sol = dfs(g, i);
                componentes.push_back(sol);
                conexa++;
            }
        }
    }
    void sol()
    {
        for (int i = 0; i < compI.size(); i++)
        {
            std::cout << componentes[compI[i]] << " ";
        }
        std::cout << "\n";
    }
};

bool resuelveCaso()
{

    // Leer caso de prueba: cin>>...
    int numUsuarios;

    std::cin >> numUsuarios;

    if (!std::cin)
    {
        return false;
    }

    Grafo g(numUsuarios);
    int numGrupos;

    std::cin >> numGrupos;

    for (int i = 0; i < numGrupos; i++)
    {
        int numUsuariosGrupo;
        std::cin >> numUsuariosGrupo;

        int user1;
        if (numUsuariosGrupo > 0)
        {
            std::cin >> user1;
        }

        for (int j = 0; j < numUsuariosGrupo - 1; j++)
        {
            int user2;
            std::cin >> user2;

            g.ponArista(user1 - 1, user2 - 1);

            user1 = user2;
        }
    }

    Solucion s(g);
    s.sol();

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
