#pragma once

#include <iostream>
#include "CommonSearcher.h"
#include "Searchable.h" // Include the necessary header for Searchable

template <class T>
class BFS : public CommonSearcher<T> {
public:
    virtual Solution search(Maze2d& maze) override {
        // Write BFS algorithm
        // Return solution
        std::cout << "BFS" << std::endl;
        return Solution();
    }

    virtual int getNumberOfNodesEvaluated() override {
        // Provide an implementation for the number of nodes evaluated
        return 0;
    }

    virtual void checkEfficiency(const Searchable<T>& s) override {
        // Provide an implementation for efficiency checking
    }
};
