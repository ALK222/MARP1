#include "graph/graph.h"
#include <iostream>
#include "graph/dummygraphs.h"

int main(int argc, char *argv[])
{
    dummygraphs d;
#ifndef __PRUEBA__
    d = dgGenerator();
#else
    if (argc == 1)
    {
        throw std::invalid_argument("Expected 1 argument");
        return -1;
    }
    try
    {
        d = dgGenerator(argv[1]);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error generating graph: " << e.what() << '\n';
        return -1;
    }
#endif

    Graph g(d.num, d.adj);

    auto mst = g.prim();

#ifndef __PRUEBA__
    for (std::size_t i = 0; i < mst.size(); ++i)
    {
        std::cout << i + 1 << "-" << mst[i] + 1 << " ";
    }
#endif // __PRUEBA__
    return 0;
}
