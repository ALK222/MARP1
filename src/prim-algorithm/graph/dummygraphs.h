#include <vector>
#include <fstream>
#include <string>

/// @brief Dummy structure for testing purposes
struct dummygraphs
{
    /// @brief number of nodes
    int num;
    /// @brief adjacency list
    std::vector<std::vector<int>> adj;
};

#ifdef __PRUEBA__
/// @brief graph generator depending of the compiling flag
/// @param archivo Archivo con los datos del grafo
/// @return a dummygraph struct with all graph
dummygraphs dgGenerator(std::string archivo);
#else
/// @brief graph generator depending of the compiling flag
/// @return a dummygraph struct with all graph
dummygraphs dgGenerator();
#endif

#ifdef __PRUEBA__

dummygraphs dgGenerator(std::string archivo)
{
    dummygraphs aux;

    std::ifstream in(archivo);
    if (!in)
    {
        throw std::ifstream::failure("error opening file");
    }
    auto cinbuf = std::cin.rdbuf(in.rdbuf());

    std::cin >> aux.num;

    std::vector<std::vector<int>> adjAux(aux.num, std::vector<int>(aux.num, 0));
    for (int i = 0; i < aux.num; ++i)
    {
        for (int j = 0; j < aux.num; ++j)
        {
            int aux;
            std::cin >> aux;
            adjAux[i].push_back(aux);
        }
    }

    aux.adj = adjAux;

    std::cin.rdbuf(cinbuf);
    // system("PAUSE");
    return aux;
}
#else // __PRUEBA__
dummygraphs dgGenerator()
{
    dummygraphs aux;
    aux.num = 7;
    aux.adj = {
        {0, 28, __INT32_MAX__, __INT32_MAX__, __INT32_MAX__, 10, __INT32_MAX__},
        {28, 0, 16, __INT32_MAX__, __INT32_MAX__, __INT32_MAX__, 14},
        {__INT32_MAX__, 16, 0, 12, __INT32_MAX__, __INT32_MAX__, __INT32_MAX__},
        {__INT32_MAX__, __INT32_MAX__, 12, 0, 22, __INT32_MAX__, 28},
        {__INT32_MAX__, __INT32_MAX__, __INT32_MAX__, 22, 0, 25, 24},
        {10, __INT32_MAX__, __INT32_MAX__, __INT32_MAX__, 25, 0, __INT32_MAX__},
        {__INT32_MAX__, 14, __INT32_MAX__, 18, 24, __INT32_MAX__, 0}};

    return aux;
}
#endif
