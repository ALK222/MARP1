// Alejandro Barrachina Argudo

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "IndexPQ.h"

using namespace std;

struct Mencion
{
    int menciones;
    int ultAct;

    bool operator<(Mencion const &b) const
    {
        return menciones > b.menciones || (menciones == b.menciones && ultAct > b.ultAct);
    }

    Mencion operator+=(Mencion const &m2)
    {
        menciones += m2.menciones;
        ultAct = m2.ultAct;
        return *this;
    }

    Mencion operator-=(Mencion const &m2)
    {
        menciones -= m2.menciones;
        ultAct = m2.ultAct;
        return *this;
    }
};

bool resuelveCaso()
{
    int numEventos;

    std::cin >> numEventos;
    if (!std::cin)
    {
        return false;
    }

    IndexPQ<std::string, Mencion, std::less<Mencion>> pq;

    for (int i = 0; i < numEventos; ++i)
    {
        std::string evento;

        std::cin >> evento;

        if (evento == "C")
        {
            std::string tema;
            int menciones;
            std::cin >> tema >> menciones;
            pq.update(tema, {menciones, i}, true);
        }
        else if (evento == "E")
        {
            std::string tema;
            int menciones;
            std::cin >> tema >> menciones;
            pq.update(tema, {menciones, i}, false);
        }
        else if (evento == "TC")
        {
            std::vector<IndexPQ<std::string, Mencion, less<Mencion>>::Par> aux;

            int i = 0;

            while (i < 3 && !pq.empty())
            {
                aux.push_back(pq.top());
                std::cout << i + 1 << " " << pq.top().elem << "\n";
                pq.pop();
                ++i;
            }

            for (int i = 0; i < aux.size(); ++i)
            {
                pq.push(aux[i].elem, aux[i].prioridad);
            }
        }
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
