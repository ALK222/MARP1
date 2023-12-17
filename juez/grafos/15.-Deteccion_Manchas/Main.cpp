
// NOMBRE Y APELLIDOS
// Alejandro Barrachina Argudo

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using linea = std::vector<std::string>;

class Mapa{

    private:
    int f, c;
    std::vector<std::vector<bool>> visitados;
    int numManchas;
    int maxTam;

    bool esPixel(int i, int j) const {
        return 0 <= i && i < f && 0 <= j && j < c;
    }

    const std::vector<std::pair<int,int>> dirs = { {1,0}, {0,1},{-1,0},{0,-1}};

    int dfs(const linea& l, int i, int j)
    {
        visitados[i][j] = true;
        int tam = 1;
        for(std::pair<int,int> d : dirs)
        {
            int newI = i + d.first;
            int newJ = j + d.second;
            if(esPixel(newI,newJ) && l[newI][newJ] == '#' && !visitados[newI][newJ])
            {
                tam += dfs(l, newI, newJ);
            }
        }
        return tam;
    }

    public:
    Mapa(linea const& l) : f(l.size()), c(l[0].size()), visitados(f, std::vector<bool>(c, false)), numManchas(0), maxTam(0)
    {
        for(int i = 0; i < f; ++i)
        {
            for(int j = 0; j < c; ++j)
            {
                if(!visitados[i][j] && l[i][j] == '#')
                {
                    numManchas++;
                    int newMax = dfs(l, i, j);
                    maxTam = std::max(maxTam, newMax);
                }
            }
        }
    }

    int getNumManchas()
    {
        return numManchas;
    }

    int getMaxTam(){
        return maxTam;
    }
};

bool resuelveCaso()
{

    // Leer caso de prueba: cin>>...
    int numVertices;

    std::cin >> numVertices;

    if (!std::cin)
    {
        return false;
    }

    int numAristas;

    std::cin >> numAristas;

    linea g(numVertices);

    for(std::string& l: g)
    {
        std::cin >> l;
    }

    Mapa m(g);

    std::cout << m.getNumManchas() << " " << m.getMaxTam() << "\n";

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
