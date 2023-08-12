
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
#ifndef BFS_CPP
#define BFS_CPP
template <class T>
class BFS : public CommonSearcher<T>
{
public:
    BFS() : evaluatedNodes_(0) {}
    virtual Solution<T> search(Maze2dSearchable &maze) override
    {
        Solution<T> *solution;
        maze.BFS();
        cout << "BFS complete!" << endl;
        solution = maze.getSolution();

        Solution<T> result(*solution);

        return result;
    }
    virtual int getNumberOfNodesEvaluated() override
    {
        return this->evaluatedNodes_;
    }
    virtual void checkEfficiency(Maze2dSearchable &mazing) override
    {
        // ... Your efficiency checking implementation here ...
        // Record start time
        std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();

        // Run the BFS search
        mazing.BFS();

        Solution<T> *solution = mazing.getSolution();

        std::cout << "BFS Efficiency Check:" << std::endl;
        std::cout << "Number of explored nodes: " << solution->getNumOfEvaluatedNodes() << std::endl;
        // Record end time
        std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();

        // Calculate the time taken
        std::chrono::duration<double> timeTaken = std::chrono::duration_cast<std::chrono::duration<double>>(endTime - startTime);

        std::cout << "Time taken: " << timeTaken.count() << " seconds" << std::endl;

        // Additional efficiency analysis or comparisons can be added here
    }

private:
    int evaluatedNodes_;
    int numOfVertics_;
};

#endif