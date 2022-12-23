#include "graph.h"

Graph::Graph()
{
}

Graph::Graph(int nodes)
{
    _nodeCount = nodes;
    _adjacency = std::vector<std::vector<int>>(_nodeCount);

    // Graph with 0 distance between the nodes
    for (int i = 0; i < _nodeCount; i++)
    {
        _adjacency[i] = std::vector<int>(_nodeCount, 0);
    }
}

Graph::Graph(int nodes, std::vector<std::vector<int>> adj)
{
    _nodeCount = nodes;
    _adjacency = adj;
}

std::vector<int> Graph::prim()
{
    // Priority queue to maintain highest cost path on top
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    // Key with the node identifier and max distance
    std::vector<int> key(_nodeCount, __INT32_MAX__);

    // Minimum spanning tree with -1 as connection to each node representing no connection
    std::vector<int> mst(_nodeCount, -1);

    // Vector of visited nodes
    std::vector<bool> visited(_nodeCount, false);

    // First visited node
    int src = 0;

    // First visited node connected to itself so distance 0
    pq.push(std::pair<int, int>(0, src));

    // Self connected node
    key[src] = 0;

    while (!pq.empty())
    {
        // Node to check
        int u = pq.top().second;

        pq.pop();

        // If node already visited we continue the algorithm
        if (visited[u] == true)
        {
            continue;
        }

        // Node already visited
        visited[u] = true;

        for (int i = 0; i < _nodeCount; ++i)
        {
            if (u == i)
            {
                continue;
            }
            // get weight between current node and the adjacent ones
            int weight = _adjacency[u][i];

            if (visited[i] == false && key[i] > weight)
            {
                // if node is not visited and the weight storaged is greater, update values
                key[i] = weight;
                pq.push(std::pair<int, int>(key[i], i));
                mst[i] = u;
            }
        }
    }

    return mst;
}
