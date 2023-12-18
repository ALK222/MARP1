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
#include <algorithm>
using namespace std;

struct Pelicula
{
    int ini;
    int fin;
};

bool operator>(Pelicula const &p1, Pelicula const &p2)
{
    return p1.fin > p2.fin || (p1.fin == p2.fin && p1.ini > p2.ini);
}

Pelicula leer()
{
    int hora;
    int min;
    int dur;
    char aux;
    std::cin >> hora >> aux >> min >> dur;

    return {(hora * 60) + min, (hora * 60) + min + dur + 10};
}

int resolver(std::priority_queue<Pelicula, std::vector<Pelicula>, std::greater<Pelicula>> peliculas)
{
    int vistas = 1;

    int tiempo = peliculas.top().fin;

    while (!peliculas.empty())
    {
        if (peliculas.top().ini >= tiempo)
        {
            vistas++;
            tiempo = peliculas.top().fin;
        }
        peliculas.pop();
    }
    return vistas;
}

bool resuelveCaso()
{

    // Leer caso de prueba: cin>>...

    int numPeliculas;

    std::cin >> numPeliculas;

    if (numPeliculas == 0)
        return false;

    std::priority_queue<Pelicula, std::vector<Pelicula>, std::greater<Pelicula>> peliculas;

    for (int i = 0; i < numPeliculas; ++i)
    {
        Pelicula aux;
        aux = leer();
        peliculas.push(aux);
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