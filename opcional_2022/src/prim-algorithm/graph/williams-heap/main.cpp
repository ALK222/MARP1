#include "williams-heap/williams-heap.h"
#include <iostream>
#include "williams-heap/dummyheaps.h"

int main(int argc, char *argv[])
{
    tDummyheaps d;
#ifndef __PRUEBA__
    d = dhGenerator();
#else
    if (argc == 1)
    {
        throw std::invalid_argument("Expected 1 argument");
        return -1;
    }
    try
    {
        d = dhGenerator(argv[1]);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error generating heap: " << e.what() << '\n';
        return -1;
    }

#endif

    Williams_heap wh(d.l);

    for (int i = 0; i < d.l; ++i)
    {
        wh.insert(d.a[i].first, d.a[i].second);
    }

#ifdef __DISPLAY__
    wh.printVector();
#endif // __DISPLAY__

    wh.decreaseKey(d.keyToDecrease, d.cuantityToDecrease);

#ifdef __DISPLAY__
    wh.printVector();
#endif // __DISPLAY__
    return 0;
}
