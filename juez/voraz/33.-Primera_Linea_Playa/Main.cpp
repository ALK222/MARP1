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

struct Edificio
{
    int ini;
    int fin;
};

bool operator>(Edificio const &p1, Edificio const &p2)
{
    return p1.fin > p2.fin || (p1.fin == p2.fin && p1.ini > p2.ini);
}

int resolver(std::priority_queue<Edificio, std::vector<Edificio>, std::greater<Edificio>> peliculas)
{
    int vistas = 1;

    int tunel = peliculas.top().fin;

    while (!peliculas.empty())
    {
        if (peliculas.top().ini >= tunel)
        {
            vistas++;
            tunel = peliculas.top().fin;
        }
        peliculas.pop();
    }
    return vistas;
}

bool resuelveCaso()
{

    // Leer caso de prueba: cin>>...

    int numEdificios;

    std::cin >> numEdificios;

    if (numEdificios == 0)
        return false;

    std::priority_queue<Edificio, std::vector<Edificio>, std::greater<Edificio>> peliculas;

    for (int i = 0; i < numEdificios; ++i)
    {
        int ini;
        int fin;
        std::cin >> ini >> fin;
        peliculas.push({ini, fin});
    }

    std::cout << resolver(peliculas) << "\n";

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