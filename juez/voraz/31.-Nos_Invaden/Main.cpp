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
#include <algorithm>
using namespace std;

int resolver(std::vector<int> invasores, std::vector<int> defensores)
{
    int defendidas = 0;

    std::sort(invasores.begin(), invasores.end());
    std::sort(defensores.begin(), defensores.end());

    int i = 0;
    int j = 0;

    while (i < defensores.size() && j < invasores.size())
    {
        if (defensores[i] >= invasores[j])
        {
            j++;
            i++;
            defendidas++;
        }
        else
        {
            i++;
        }
    }

    return defendidas;
}

bool resuelveCaso()
{

    // Leer caso de prueba: cin>>...

    int numCiudades;

    std::cin >> numCiudades;

    if (!std::cin)
        return false;

    std::vector<int> invasores;

    for (int i = 0; i < numCiudades; ++i)
    {
        int aux;
        std::cin >> aux;
        invasores.push_back(aux);
    }

    std::vector<int> defensores;

    for (int i = 0; i < numCiudades; ++i)
    {
        int aux;
        std::cin >> aux;
        defensores.push_back(aux);
    }

    std::cout << resolver(invasores, defensores) << "\n";
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