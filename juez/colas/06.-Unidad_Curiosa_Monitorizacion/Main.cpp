// Alejandro Barrachina Argudo

#include <iostream>
#include <fstream>
#include "PriorityQueue.h"

using namespace std;

struct Usuario
{
    int id;
    int intervalo;
    int sig;
};

bool operator<(Usuario const &a, Usuario const &b)
{
    return a.sig < b.sig || (a.sig == b.sig && a.id < b.id);
}

bool resuelveCaso()
{

    int numUsuarios;

    std::cin >> numUsuarios;

    if (numUsuarios == 0)
    {
        return false;
    }

    PriorityQueue<Usuario> pq;

    for (int i = 0; i < numUsuarios; ++i)
    {
        int idCur, interCur;

        std::cin >> idCur >> interCur;

        pq.push({idCur, interCur, interCur});
    }

    int K;

    std::cin >> K;

    while (K > 0)
    {
        Usuario u = pq.top();
        pq.pop();

        std::cout << u.id << "\n";

        u.sig += u.intervalo;

        pq.push(u);
        K--;
    }

    std::cout << "---\n";
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
