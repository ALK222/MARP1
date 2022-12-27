#ifndef __WILLIAMS_HEAP__
#define __WILLIAMS_HEAP__

#include <vector>
#include <map>
#include <iostream>

/// @brief Williams heap implementation with support for the decreaseKey operation
class Williams_heap
{
private:
    /// @brief Queue implementation of a min tree
    std::vector<int> _heap;
    /// @brief Position where the next element will be inserted
    long unsigned int _next;

public:
    /// @brief Constructor for the heap with length
    /// @param l Number of nodes for the tree
    Williams_heap(int l);

    /// @brief Default destructor
    ~Williams_heap();

    /// @brief Checks if the current tree is a heap
    /// @return True if min heap, false otherwise
    bool isHeap();

    /// @brief Inserts an element in the heap maintaining the heap constraint
    /// @param e Element to insert
    void insert(int e);

    /// @brief Floats an element until its greater than its parents or is root
    void wh_float();

    /// @brief Deletes the min element of the heap and sinks the rest
    void deleteMin();

    /// @brief Sinks the element in the heap until is lower than its sons or is a leaf
    /// @param s Key of the element to sink
    /// @param l Lenght of the sink
    void sink(int s, int l);

    /// @brief Checks the root of the heap
    /// @return The minimum element of the heap
    int min();

    /// @brief Sorts an array using Williams heap
    /// @param a Array to sort
    void heapsort(std::vector<int> &a);

    /// @brief Decreases the value of a given key
    /// @param key Key of the element to decrease
    /// @param sub Cuantity to decrease
    void decreaseKey(int key, int sub);

    /// @brief Debug utility to print the vector without popping elements
    void printVector();
};

#endif // __WILLIAMS_HEAP__
