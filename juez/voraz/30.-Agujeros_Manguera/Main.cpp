// Alejandro Barrachina Argudo

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/**
 * @brief Estrategia: recorrer todos los agujeros de izquierda a derecha
 * tamapndo los agujeros no parcheados y moviendo el inicio hasta el final del parche.
 * @par Coste O(n) siendo n el número de agujeros
 *
 * @param agujeros vector con las posiciones de los agujeros
 * @param tamParche tamaño de cada parche
 * @return int mínimo número de parches a poner
 */
int minParches(std::vector<int> const &agujeros, int const &tamParche)
{
    int minParches = 1;
    int pos = agujeros[0];

    for (int i = 0; i < agujeros.size(); ++i)
    {
        if (agujeros[i] > pos + tamParche)
        {
            minParches++;
            pos = agujeros[i];
        }
    }

    return minParches;
}

bool resuelveCaso()
{
    int numAgujeros;

    std::cin >> numAgujeros;
    if (!std::cin)
    {
        return false;
    }

    int tamParche;

    std::cin >> tamParche;

    std::vector<int> agujeros;

    for (int i = 0; i < numAgujeros; ++i)
    {
        int pos;

        std::cin >> pos;

        agujeros.push_back(pos);
    }
    std::cout << minParches(agujeros, tamParche) << "\n";
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
