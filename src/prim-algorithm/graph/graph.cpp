#include "graph.h"
#include "./williams-heap/williams-heap/williams-heap.h"
#include <iostream>
Graph::Graph()
{
}

Graph::Graph(int nodes)
{
    _nodeCount = nodes;
    _adjacency = std::vector<std::vector<std::pair<int, int>>>(_nodeCount);
}

Graph::Graph(int nodes, std::vector<std::vector<std::pair<int, int>>> adj)
{
    _nodeCount = nodes;
    _adjacency = adj;
}

std::vector<int> Graph::prim()
{
    // Priority queue to maintain highest cost path on top
    Williams_heap pq(_nodeCount);

    // Key with the node identifier, pq position and max distance
    std::vector<int> key(_nodeCount, __INT32_MAX__);

    for (int i = 0; i < _nodeCount; ++i)
    {
        pq.insert(i, __INT32_MAX__);
    }

    // Minimum spanning tree with -1 as connection to each node representing no connection
    std::vector<int> mst(_nodeCount, -1);

    // Vector of visited nodes and position on pq
    std::vector<bool> visited(_nodeCount, false);

    // First visited node
    int src = 0;

    // First visited node connected to itself so distance 0
    pq.insert(0, __INT32_MAX__);

    // Self connected node
    // key[src] = std::make_pair(pq.next() - 1, 0);

    // pq.printVector();

    while (!pq.empty())
    {
        // Node to check
        int u = pq.min().first;

        // std::cout << u << "\n";

        pq.deleteMin();

        // If node already visited we continue the algorithm
        if (visited[u] == true)
        {
            continue;
        }

        // Node already visited
        visited[u] = true;

        for (std::pair<int, int> i : _adjacency[u])
        {
            if (u == i.first)
            {
                continue;
            }
            // get weight between current node and the adjacent ones
            int weight = i.second;

            // std::cout << i.first << "\n";

            if (visited[i.first] == false && key[i.first] > weight)
            {
                // if node is not visited and the weight storaged is greater, update values
                key[i.first] = weight;
                // std::cout << i.first << "-" << u << "\n";
                pq.decreaseKey(i.first, weight);
                mst[i.first] = u;
            }
        }
    }

    return mst;
}
