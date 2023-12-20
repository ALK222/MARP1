/*
USUARIO JUEZ: MAR108

    Alejandro Barrachina Argudo
    Carlos Murcia Morilla

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Explica la estrategia voraz
/*
La estrategia voraz consiste en ordenar el vector de pesos de mayor a menor.
Al hacer esta estrategia comprobamos si el de menor pero puede ir acompañado de otra persona de mayor o igual peso,
dejando a las personas de mayor peso solos en caso de no tener alguien para complementar el peso restante

Correccion:

    | 2 | 2 | 2 | 2 | 2 | Optima
    | 2 | 2 | 2 | 1 | 2 | Voraz

    Esto representa el numero de personas en cada telesilla según la estrategia optima y la estrategia voraz.
    El caso optimo es imposible por la estrategia voraz debido a que cualquier persona que pueda ir acompañada
    vaya sola, y que comprobamos a las personas de menor peso primero.

    | 2 | 2 | 2 | 2 | 1 | Optima
    | 2 | 2 | 2 | 1 | 2 | Voraz

    Este caso representa un orden distinto de asignacion de sillas pero podemos comprobar que el numero de viajes
    seria el mismo por lo que la solucion voraz seria equivalente

*/

int telesilla(int pesoMaximo, vector<int> &pesos)
{
    int numeroViajes = 0;

    // Implementa la estrategia voraz
    // Coste del algoritmo O(n) siendo n el número de personas que quieren montar en el telesilla

    /* Ordenamos de mayor a menor */
    std::sort(pesos.begin(), pesos.end(), greater<int>()); // O(nlog(n))

    /* Indice de mayor peso actual */
    int i = 0;
    /* Indice de menor peso actual */
    int j = pesos.size() - 1;

    while (i <= j) // mientras no hayamos recorrido todo el vector
    {
        if (i == j) // caso impar o de una sola persona restante
        {
            numeroViajes++;
            i++;
        }
        else
        {
            if (pesos[i] + pesos[j] <= pesoMaximo) // comparamos si podemos unir a dos personas en el mismo asiento
            {
                numeroViajes++;
                i++; // persona de mayor peso sentada
                j--; // persona de menor peso sentada
            }
            else
            { // la persona de mayor peso no puede compartir asiento
                numeroViajes++;
                i++;
            }
        }
    }

    return numeroViajes;
}

/*
Demostracion de correccion de la estrategia voraz
*/

bool resuelveCaso()
{
    int a, b, j;
    cin >> a >> b;
    if (!cin)
        return false;

    vector<int> v(b);
    for (int i = 0; i < b; i++)
    {
        cin >> j;
        v[i] = j;
    }
    int sol = telesilla(a, v);
    cout << sol << '\n';
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