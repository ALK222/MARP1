// NOMBRE y APELLIDOS
// Alejandro Barrachina

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include "PriorityQueue.h"

bool resuelveCaso()
{
    int numAcciones;

    std::cin >> numAcciones;

    if (!std::cin)
    {
        return false;
    }

    std::priority_queue<int> menores;
    PriorityQueue<int> mayores;
    for (int i = 0; i < numAcciones; i++)
    {
        int acc;
        std::cin >> acc;
        if (acc == 0)
        {
            if (menores.empty())
            {
                std::cout << "ECSA ";
            }
            else
            {
                std::cout << menores.top() << " ";
                menores.pop();
                if ((long unsigned int)mayores.size() > menores.size())
                {
                    menores.push(mayores.top());
                    mayores.pop();
                }
            }
        }
        else
        {
            if (menores.empty() || menores.top() > acc)
            {
                menores.push(acc);
                if (menores.size() > (long unsigned int)mayores.size() + 1)
                {
                    mayores.push(menores.top());
                    menores.pop();
                }
            }
            else
            {
                mayores.push(acc);
                if ((long unsigned int)mayores.size() > menores.size())
                {
                    menores.push(mayores.top());
                    mayores.pop();
                }
            }
        }
    }
    std::cout << "\n";
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
