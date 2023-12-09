
// NOMBRE Y APELLIDOS
// Alejandro Barrachina Argudo

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include "Grafo.h"

int MAX = 10000;

int adyacentes(int v, int i)
{
    switch (i)
    {
    case 0:
        return (v + 1) % MAX;
    case 1:
        return (v * 2) % MAX;
    case 2:
        return v / 3;
    }
}

int bfs(int origen, int desino);

int bfs(int origen, int destino)
{
    if (origen == destino)
    {
        return 0;
    }

    std::vector<int> distancia(MAX, __INT16_MAX__);
    distancia[origen] = 0;

    std::queue<int> q;
    q.push(origen);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for (int i = 0; i < 3; ++i)
        {
            int w = adyacentes(v, i);
            if (distancia[w] == __INT16_MAX__)
            {
                distancia[w] = distancia[v] + 1;
                if (w == destino)
                {
                    return distancia[w];
                }
                else
                {
                    q.push(w);
                }
            }
        }
    }
}

bool resuelveCaso()
{

    // Leer caso de prueba: cin>>...
    int origen;

    std::cin >> origen;

    if (!std::cin)
    {
        return false;
    }
    int destino;

    std::cin >> destino;

    int pulsaciones = bfs(origen, destino);

    std::cout << pulsaciones << "\n";

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
