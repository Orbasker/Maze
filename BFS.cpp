
#include "BFS.h"
#include <iostream>
#include <queue>
#include <chrono>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <iterator>
#include <stack>
#include <set>
#include <map>
#include <list>
#include "CommonSearcher.cpp"
#include "mazeAdapter.h"
#include "Maze2dSearchable.h"
template <class T>
class BFS : public CommonSearcher<T>
{
public:
    BFS() : evaluatedNodes_(0) {}
    virtual Solution<T> search(Maze2dSearchable &maze) override
    {
        std::queue<State<T> *> openList;
        openList.push(maze.getStartState()); // Using maze instead of Maze2d
        maze.getStartState()->setVisited();  // Assuming you have a setVisited method in State class
        Solution<T> solution;
        while (!openList.empty())
        {
            State<T> *currentState = openList.front();
            openList.pop();
            this->evaluatedNodes_++;
            cout << "BFS: Current state came from: " << currentState->getCameFrom() << endl;
            cout << "BFS evaluated nodes: " << this->evaluatedNodes_ << endl;
            if (*currentState == *(maze.getGoalState()))
            {
                std::cout << "BFS: Goal has been found!" << std::endl;
                return this->backtrace(currentState);
            }

            std::vector<State<T> *> successors = maze.getAllPossibleStates(*currentState); // Assuming this method exists
            for (State<T> *successor : successors)
            {
                if (!successor->isVisited()) // Assuming you have an isVisited method in State class
                {
                    openList.push(successor);
                    successor->setVisited(); // Mark successor as visited
                    successor->setCameFrom(currentState);
                }
            }
        }

        // No solution found
        cout << "BFS: No solution found!" << endl;
        return Solution<T>();
    }
    virtual int getNumberOfNodesEvaluated() override
    {
        return this->evaluatedNodes_;
    }
    virtual void checkEfficiency(const Searchable<T> &s) override
    {
        // ... Your efficiency checking implementation here ...
        // Record start time
        std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();

        // Run the BFS search
        // Solution<T> solution = search(s);

        // Record end time
        std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();

        // Calculate the time taken
        std::chrono::duration<double> timeTaken = std::chrono::duration_cast<std::chrono::duration<double>>(endTime - startTime);

        std::cout << "BFS Efficiency Check:" << std::endl;
        std::cout << "Number of explored nodes: " << getNumberOfNodesEvaluated() << std::endl;
        std::cout << "Time taken: " << timeTaken.count() << " seconds" << std::endl;

        // Additional efficiency analysis or comparisons can be added here
    }

private:
    int evaluatedNodes_;
};
