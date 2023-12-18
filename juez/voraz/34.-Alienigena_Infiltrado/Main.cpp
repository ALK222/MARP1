// NOMBRE Y APELLIDOS
/*
    Alejandro Barrachina Argudo
    Carlos Murcia Morilla
*/

// USUARIO DEL JUEZ: MAR108

#include <iostream>
#include <queue>
#include <vector>
#include <queue>
#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;

int resolver(std::vector<std::pair<int, int>> trabajos, int const &C, int const &F, bool &posible)
{
    int num = 0;
    int ini = C;

    int i = 0;
    while (posible && ini < F)
    {
        int aux = ini;

        while (i < trabajos.size() && trabajos[i].first <= ini)
        {
            if (trabajos[i].second > aux)
            {
                aux = trabajos[i].second;
            }
            ++i;
        }
        if (aux > ini)
        {
            num++;
            ini = aux;
        }
        else
        {
            posible = false;
        }
    }
    return num;
}

bool resuelveCaso()
{

    // Leer caso de prueba: cin>>...

    int C;
    int F;

    int numTrabajos;

    std::cin >> C >> F >> numTrabajos;

    if (C == 0 && F == 0 && numTrabajos == 0)
        return false;

    std::vector<std::pair<int, int>> trabajos;

    for (int i = 0; i < numTrabajos; ++i)
    {
        int ini;
        int fin;
        std::cin >> ini >> fin;
        trabajos.push_back({ini, fin});
    }

    std::sort(trabajos.begin(), trabajos.end());

    bool posible = true;

    int sol = resolver(trabajos, C, F, posible);

    if (posible)
    {
        std::cout << sol << "\n";
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