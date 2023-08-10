#include "Solution.cpp"
#include "Maze2dSearchable.h"
#include "maze2d.h" // Include the necessary header for Maze2d

// Define CommonSearcher class
template <class T>
class CommonSearcher {
    // Define the CommonSearcher class members
public:
    // Define the CommonSearcher class methods
    virtual Solution<T> search(Maze2dSearchable& maze) = 0; // Pure virtual function
    virtual int getNumberOfNodesEvaluated() = 0; // Pure virtual function
    virtual void checkEfficiency(const Searchable<T>& s) = 0;
    Solution<T> backtrace(State<T>* goalState) {
        // ... Your backtrace implementation here ...
        Solution<T> solution;
        State<T>* currentState = goalState;
        while (currentState != nullptr) {
            solution.addState(currentState);
            currentState = currentState->getCameFrom();
        }
        return solution;
    }

    // ...
};
