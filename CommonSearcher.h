#pragma once
#include "Searchable.h"
#include "Solution.h"
#include "maze2d.h" // Include the necessary header for Maze2d

// Define CommonSearcher class
template <class T>
class CommonSearcher {
    // Define the CommonSearcher class members
public:
    // Define the CommonSearcher class methods
    virtual Solution search(Maze2d& maze) = 0; // Pure virtual function
    virtual int getNumberOfNodesEvaluated() = 0; // Pure virtual function
    virtual void checkEfficiency(const Searchable<T>& s) = 0;

    // ...
};
