
// NOMBRE Y APELLIDOS
// Alejandro Barrachina Argudo
// Carlos Murcia Morilla

#include <iostream>
#include "PriorityQueue.h"
#include <vector>
#include <fstream>
using namespace std;

struct Candidato
{
    int id; // orden de entrada
    int v;  // votos
    int e;  // escanios
};

bool operator<(Candidato const &a, Candidato const &b)
{
    float c1 = (float)a.v / (1 + a.e); // coeficiente de A
    float c2 = (float)b.v / (1 + b.e); // coeficiente de B

    // Comprobamos en orden el coeficiente, los votos y el orden de entrada
    if (c1 > c2)
    {
        return true;
    }
    if (c1 == c2 && a.v > b.v)
    {
        return true;
    }

    if (c1 == c2 && a.v == b.v && a.id < b.id)
    {
        return true;
    }

    return false;
}

// Coste O(n), siendo n el numero de candidaturas ya que va a ser el tama�o con el que m�s trabajemos, dado que con los esca�os solo trabajamos en un while

// En este algoritmo seguimos el siguiente procedimiento:
// 1. metemos a los candidatos en una cola de prioridad(coeficiente)
// 2. Asignamos esca�os segun prioridad
// 3. Creamos un vector ordenado por llegada de esca�os asignados
// 4. Printeamos el resultado
bool resuelveCaso()
{

    // Leer caso de prueba: cin>>...
    int numCandidaturas;
    int numEscanios;

    std::cin >> numCandidaturas >> numEscanios;

    if (numCandidaturas == 0 && numEscanios == 0)
    {
        return false;
    }

    // Resolver problema
    PriorityQueue<Candidato> pq;

    for (int i = 0; i < numCandidaturas; i++)
    {
        int votos;

        std::cin >> votos;

        pq.push({i, votos, 0}); // Metemos a cada candidatura con su orden de entrada, sus votos y 0 escanios
    }

    if (pq.empty())
    { // si la cola esta vacia, no se asignan esca�os
        std::cout << "\n";
        return true;
    }
    while (numEscanios > 0)
    {
        // Cojemos el candidato siguiente
        Candidato aux = pq.top();
        pq.pop();

        aux.e += 1;
        // le metemos en la cola otra vez con un escanio actualizado
        pq.push(aux);

        numEscanios--;
    }

    // Escribir resultado

    std::vector<int> sol(numCandidaturas); // vector de candidaturas ordenadas por llegada

    for (int i = 0; i < numCandidaturas; i++)
    {
        Candidato aux = pq.top();
        pq.pop();

        sol[aux.id] = aux.e; // metemos la candidatura en su puesto
    }

    std::cout << sol[0];
    for (int i = 1; i < sol.size(); i++)
    {
        std::cout << " " << sol[i];
    }

    std::cout << "\n";

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
