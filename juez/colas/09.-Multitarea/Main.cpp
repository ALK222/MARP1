// Alejandro Barrachina Argudo

#include <iostream>
#include <fstream>
#include <string>
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

bool resolver(PriorityQueue<Tarea> pq, int &T)
{
    bool incompatible = false;
    int ocupado = 0;

    while (!incompatible && !pq.empty() && pq.top().inicio < T)
    {
        Tarea aux = pq.top();
        pq.pop();

        if (aux.inicio < ocupado)
        {
            incompatible = true;
        }

        ocupado = aux.fin;

        if (aux.rep > 0)
        {
            pq.push({aux.inicio + aux.rep, aux.fin + aux.rep, aux.rep});
        }
    }

    return incompatible;
}

bool resuelveCaso()
{
    int N;
    int M;
    int T;

    std::cin >> N;
    if (!std::cin)
    {
        return false;
    }

    std::cin >> M >> T;

    PriorityQueue<Tarea> pq;
    int ini;
    int fin;
    int rep;

    for (int i = 0; i < N; ++i)
    {
        std::cin >> ini >> fin;
        pq.push({ini, fin, 0});
    }

    for (int j = 0; j < M; ++j)
    {
        std::cin >> ini >> fin >> rep;
        pq.push({ini, fin, rep});
    }

    if (T != 0 && resolver(pq, T))
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
    // system("pause");
#endif
    return 0;
}
