#ifndef __DUMMYHEAPS__
#define __DUMMYHEAPS__

#include <vector>
#include <fstream>
#include <string>

/// @brief dummy structure to store all the test case data
typedef struct
{
    /// @brief Number of nodes of the heap
    int l;

    /// @brief Heap represented by a vector
    std::vector<std::pair<int, int>> a;

    /// @brief Key for decreaseKey
    int keyToDecrease;

    /// @brief Sub for decreaseKey
    int cuantityToDecrease;
} tDummyheaps;

#ifdef __PRUEBA__
/// @brief heap generator depending of the compiling flag
/// @param archivo File with all the data for the heap
/// @return a tDummyheaps struct with all heap
tDummyheaps dgGenerator(std::string archivo);
#else  // __PRUEBA__
/// @brief graph generator depending of the compiling flag
/// @return a dummygraph struct with all graph
tDummyheaps dhGenerator();
#endif // __PRUEBA__

#ifdef __PRUEBA__

tDummyheaps dhGenerator(std::string archivo)
{
    tDummyheaps aux;

    std::ifstream in(archivo);
    if (!in)
    {
        throw std::ifstream::failure("error opening file");
    }
    auto cinbuf = std::cin.rdbuf(in.rdbuf());

    std::cin >> aux.l;

    std::vector<std::pair<int, int>> a(aux.l, 0);
    for (int i = 0; i < aux.l; ++i)
    {
        int auxi;
        int auxj;
        std::cin >> auxi;
        std::cin >> auxj;
        a[i] = std::make_pair(auxi, auxj);
    }

    aux.a = a;
    std::cin >> aux.keyToDecrease;
    std::cin >> aux.cuantityToDecrease;

    std::cin.rdbuf(cinbuf);
    // system("PAUSE");
    return aux;
}
#else  // __PRUEBA__
tDummyheaps dhGenerator()
{
    tDummyheaps aux;
    aux.l = 7;
    aux.a = {std::make_pair(1, 3), std::make_pair(4, 5), std::make_pair(12, 7), std::make_pair(6, 9), std::make_pair(7, 133), std::make_pair(34, 14), std::make_pair(8, 16)};
    aux.keyToDecrease = 12;
    aux.cuantityToDecrease = 10;

    return aux;
}
#endif // __PRUEBA__

#endif // __DUMMYHEAPS__
