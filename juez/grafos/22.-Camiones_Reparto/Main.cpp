// NOMBRE Y APELLIDOS
/*
    Alejandro Barrachina Argudo
    Carlos Murcia Morilla
*/

// USUARIO DEL JUEZ: MAR108

#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include "GrafoValorado.h"
using namespace std;

struct tiempoPueblo
{
    int pueblo;
    int tiempo;
};

bool operator<(tiempoPueblo const &uno, tiempoPueblo const &otro)
{
    return uno.tiempo < otro.tiempo;
}

/*
EXPLICACION

Realizamos un recorrido en dijasktra iniciando desde cada pueblo que tiene un borriquin. Comprobamos el tiempo de desplazamiento hasta un pueblo adyacente siempre y cuando no lo hayamos visitado ya.
Si el tiempo de transito es menor que tiempoMax, comprobamos los pueblos adyacentes a este.


*/
void resolver(GrafoValorado<int> const &g, int &pueblosPosibles, int const &tiempoMax, std::vector<int> borriquines)
{
    priority_queue<tiempoPueblo> cola;
    std::vector<int> ultimo(g.V());
    std::vector<int> distancia(g.V(), 999);
    for (int ini : borriquines)
    {
        cola.push({ini - 1, 0});
        pueblosPosibles++;
    }

    while (!cola.empty() && cola.top().tiempo < tiempoMax)
    {

        tiempoPueblo acc = cola.top();
        cola.pop();
        for (Arista<int> w : g.ady(acc.pueblo))
        {
            if (w.valor() + acc.tiempo <= tiempoMax)
            {
                pueblosPosibles++;
                distancia[w.otro(acc.pueblo)] = std::min(distancia[w.otro(acc.pueblo)], w.valor() + acc.tiempo);
                cola.push({w.otro(acc.pueblo), acc.tiempo + w.valor()});
            }
        }
    }
}

bool resuelveCaso()
{

    // Leer caso de prueba: cin>>...

    int tiempoMax;

    std::cin >> tiempoMax;

    if (!std::cin)
        return false;

    int numVertices;
    int numAristas;

    std::cin >> numVertices >> numAristas;

    GrafoValorado<int> g(numVertices);

    for (int i = 0; i < numAristas; ++i)
    {
        int v1;
        int v2;
        int valor;

        std::cin >> v1 >> v2 >> valor;

        g.ponArista({v1 - 1, v2 - 1, valor});
    }

    // Resolver problema
    int pueblosPosibles = 0;

    int borriquin;

    std::cin >> borriquin;

    // Reutilizamos el vector para no visitar pueblos que hemos visitado desde otro borriquin
    std::vector<bool> visitados(g.V(), false);

    std::vector<int> distancia(g.V(), 9999);
    std::vector<int> borriquines;

    for (int i = 0; i < borriquin; ++i)
    {
        // pueblosPosibles++;
        int ini;
        std::cin >> ini;
        borriquines.push_back(ini);
    }

    resolver(g, pueblosPosibles, tiempoMax, borriquines);

    // Escribir resultado

    std::cout << pueblosPosibles << "\n";
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