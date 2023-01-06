#include <vector>
#include <queue>

/// @brief Representation of a weighted non directional graph
/// using a adjacency list and implementing Prim's algorithm
/// @author Alejandro Barrachina Argudo
class Graph
{
public:
    /// @brief Void constructor
    Graph();

    /// @brief Graph constructor with no edges between the nodes
    /// @param nodes Number of nodes of the graph
    Graph(int nodes);

    /// @brief Constructor with a matrix of connections already made
    /// @param nodes number of nodes
    /// @param adj Matrix of edges
    Graph(int nodes, std::vector<std::vector<std::pair<int, int>>> adj);

    /// @brief Finds the minimum spanning three of the graph
    /// @return vector with each position representing a
    /// conection between the node of that position and the
    /// node refered by the value of the position
    std::vector<int> prim();

private:
    /// @brief number of nodes of the graph
    int _nodeCount;
    /// @brief Matrix of connections of the graph
    std::vector<std::vector<std::pair<int, int>>> _adjacency;
};
