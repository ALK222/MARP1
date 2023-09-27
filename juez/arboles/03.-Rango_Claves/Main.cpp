// NOMBRE y APELLIDOS
// Alejandro Barrachina

#include <iostream>
#include <fstream>
#include <vector>
#include "TreeSet_AVL.h"
using namespace std;

template <typename Clave, typename Valor, typename Comparador = std::less<Clave>>
class mapRango : public Set<Clave, Comparador>
{
public:
    mapRango(Comparador c = Comparador()) : Set<Clave, Comparador>(c){};

    void setRango(int k1, int k2)
    {
        _k1 = k1 - 1;
        _k2 = k2 + 1;
    }
    std::vector<Clave> rango() const
    {
        std::vector<Clave> rango;
        this->rango(this->raiz, rango);
        return rango;
    }

private:
    int _k1;
    int _k2;

    using TreeNode = typename Set<Clave, Comparador>::TreeNode;
    using Link = TreeNode *;
    void rango(Link a, vector<Clave> &sol) const
    {

        if (a == nullptr)
        {
            return;
        }

        if (a->iz != nullptr && this->menor(_k1, a->elem))
        {
            rango(a->iz, sol);
        }
        if (this->menor(_k1, a->elem) && this->menor(a->elem, _k2))
        {
            sol.push_back(a->elem);
        }
        if (a->dr != nullptr && this->menor(a->elem, _k2))
        {
            rango(a->dr, sol);
        }
    }
};

bool resuelveCaso()
{
    int k1;
    int k2;
    mapRango<int, std::less<int>> a1;
    vector<int> lista;
    int numElems;

    cin >> numElems;

    if (numElems == 0)
    {
        return false;
    }

    for (int i = 0; i < numElems; ++i)
    {
        int aux;
        cin >> aux;
        a1.insert(aux);
    }
    cin >> k1;
    cin >> k2;

    a1.setRango(k1, k2);

    lista = a1.rango();

    if (!lista.empty())
    {
        std::cout << lista[0];

        for (int i = 1; i < lista.size(); ++i)
        {
            std::cout << " " << lista[i];
        }
    }

    std::cout << "\n";

    return true;
}

int main()
{
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}
