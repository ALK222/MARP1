#include <vector>
#include <fstream>
#include <string>
#include <iostream>

/// @brief Dummy structure for testing purposes
struct dummygraph
{
    /// @brief number of nodes
    int num;
    /// @brief adjacency list
    std::vector<std::vector<std::pair<int, int>>> adj;
};

#ifdef __PRUEBA__
/// @brief graph generator depending of the compiling flag
/// @param archivo Archivo con los datos del grafo
/// @return a dummygraph struct with all graph
dummygraph dgGenerator(std::string archivo);
#else
/// @brief graph generator depending of the compiling flag
/// @return a dummygraph struct with all graph
dummygraph dgGenerator();
#endif

#ifdef __PRUEBA__

dummygraph dgGenerator(std::string archivo)
{
    dummygraph aux;

    std::ifstream in(archivo);
    if (!in)
    {
        throw std::ifstream::failure("error opening file");
    }
    auto cinbuf = std::cin.rdbuf(in.rdbuf());

    std::cin >> aux.num;

    std::vector<std::vector<std::pair<int, int>>> adjAux(aux.num);
    for (int i = 0; i < aux.num; ++i)
    {
        int numConnections = 0;
        std::cin >> numConnections;
        for (int j = 0; j < numConnections; ++j)
        {
            int auxNode;
            int auxWeight;
            std::cin >> auxNode >> auxWeight;
            adjAux[i].push_back(std::make_pair(auxNode, auxWeight));
        }
    }

    aux.adj = adjAux;

    std::cin.rdbuf(cinbuf);
    // system("PAUSE");
    return aux;
}
#else // __PRUEBA__
dummygraph dgGenerator()
{
    dummygraph aux;
    aux.num = 7;
    aux.adj = {
        {std::make_pair(1, 28), std::make_pair(5, 10)},                         // 0
        {std::make_pair(0, 28), std::make_pair(2, 16), std::make_pair(6, 14)},  // 1
        {std::make_pair(1, 16), std::make_pair(3, 12)},                         // 2
        {std::make_pair(2, 12), std::make_pair(4, 22), std::make_pair(6, 18)},  // 3
        {std::make_pair(3, 22), std::make_pair(5, 25), std::make_pair(6, 24)},  // 4
        {std::make_pair(0, 10), std::make_pair(4, 25)},                         // 5
        {std::make_pair(2, 14), std::make_pair(3, 18), std::make_pair(4, 24)}}; // 6

    return aux;
}
#endif
