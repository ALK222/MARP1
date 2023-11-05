// Alejandro Barrachina Argudo

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "PriorityQueue.h"

using namespace std;

struct Tarea
{
    int inicio;
    int fin;
    int rep;
};

bool operator<(Tarea const &a, Tarea const &b)
{
    return a.inicio < b.inicio;
}

void resolver(int numDrones, PriorityQueue<int, greater<int>> pq15, PriorityQueue<int, greater<int>> pq9)
{
    std::vector<int> drones;

    while (!pq15.empty() && !pq9.empty())
    {
        int i = 0;
        std::vector<int> restantes9;
        std::vector<int> restantes15;

        int horas = 0;

        while (!pq15.empty() && !pq9.empty() && i < numDrones)
        {

            int p15 = pq15.top();
            pq15.pop();

            int p9 = pq9.top();
            pq9.pop();

            if (p9 < p15)
            {
                horas += p9;
                p15 -= p9;
                restantes15.push_back(p15);
            }
            else
            {
                horas += p15;
                p9 -= p15;
                if (p9 != 0)
                {
                    restantes9.push_back(p9);
                }
            }
            i++;
        }

        std::cout << horas << " ";

        for (int i = 0; i < restantes15.size(); ++i)
        {
            pq15.push(restantes15[i]);
        }

        for (int i = 0; i < restantes9.size(); ++i)
        {
            pq9.push(restantes9[i]);
        }
    }
}

bool resuelveCaso()
{
    int numDrones;

    std::cin >> numDrones;
    if (!std::cin)
    {
        return false;
    }

    int numPilas9;
    int numPilas15;

    std::cin >> numPilas9 >> numPilas15;

    int dur;

    PriorityQueue<int, greater<int>> pq9;

    for (int i = 0; i < numPilas9; ++i)
    {
        std::cin >> dur;

        pq9.push(dur);
    }

    PriorityQueue<int, greater<int>> pq15;
    for (int i = 0; i < numPilas15; ++i)
    {
        std::cin >> dur;

        pq15.push(dur);
    }

    resolver(numDrones, pq15, pq9);
    std::cout << "\n";

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
    // system("pause");
#endif
    return 0;
}
