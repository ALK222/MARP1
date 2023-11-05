// Alejandro Barrachina Argudo

#include <iostream>
#include <fstream>
#include <string>
#include "PriorityQueue.h"

using namespace std;

struct Paciente
{
    std::string nombre;
    int prioridad;
    int entrada;
};

bool operator<(Paciente const &a, Paciente const &b)
{
    return a.prioridad > b.prioridad || (a.prioridad == b.prioridad && a.entrada < b.entrada);
}

bool resuelveCaso()
{

    int numEventos;

    std::cin >> numEventos;

    if (numEventos == 0)
    {
        return false;
    }

    PriorityQueue<Paciente> pq;

    for (int i = 0; i < numEventos; ++i)
    {
        char evento;

        std::cin >> evento;

        if (evento == 'I')
        {
            std::string nombreAcc;
            int prioridad;

            std::cin >> nombreAcc >> prioridad;

            pq.push({nombreAcc, prioridad, i});
        }
        else if (evento == 'A')
        {
            Paciente p = pq.top();
            pq.pop();

            std::cout << p.nombre << "\n";
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
