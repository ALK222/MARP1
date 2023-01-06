#include "graph.h"

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

        for (std::pair<int, int> i : _adjacency[u])
        {
            if (u == i.first)
            {
                continue;
            }
            // get weight between current node and the adjacent ones
            int weight = i.second;

            if (visited[i.first] == false && key[i.first] > weight)
            {
                // if node is not visited and the weight storaged is greater, update values
                key[i.first] = weight;
                pq.push(std::pair<int, int>(key[i.first], i.first));
                mst[i.first] = u;
            }
        }
    }

    return mst;
}
