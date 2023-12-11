
// NOMBRE Y APELLIDOS
// Alejandro Barrachina Argudo

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include "Digrafo.h"

int bfs(Digrafo const &g, int const &carasDado);

int bfs(Digrafo const &g, int const &carasDado)
{

    std::queue<int> cola;

    std::vector<int> distancias(g.V());

    distancias[0] = 0;
    cola.push(0);

    while (!cola.empty())
    {
        int pos = cola.front();
        cola.pop();

        for (int i = 1; i <= carasDado && pos + i < g.V(); ++i)
        {
            int acc = pos + i;

            if (g.ady(acc).size() == 1)
            {
                acc = g.ady(acc).front();
            }
            if (distancias[acc] == 0)
            {
                distancias[acc] = distancias[pos] + 1;
                if (acc == g.V() - 1)
                {
                    return distancias[acc];
                }
                cola.push(acc);
            }
        }
    }
}

bool resuelveCaso()
{

    // Leer caso de prueba: cin>>...
    int N;

    std::cin >> N;

    Digrafo g(N * N);

    int carasDado;

    std::cin >> carasDado;

    int numSerpientes;
    int numEscaleras;

    std::cin >> numSerpientes >> numEscaleras;

    if (N == 0 && carasDado == 0 && numSerpientes == 0 && numEscaleras == 0)
    {
        return false;
    }

    // std::cout << g.V() << "\n";

    for (int i = 0; i < numSerpientes + numEscaleras; ++i)
    {
        int a;
        int b;
        std::cin >> a >> b;

        // std::cout << a << " " << b << "\n";

        g.ponArista(a - 1, b - 1);
    }

    std::cout << bfs(g, carasDado) << "\n";

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
