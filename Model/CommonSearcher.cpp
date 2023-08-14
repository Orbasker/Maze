#include "Solution.cpp"
#include "Maze2dSearchable.h"
#include "maze2d.h"
#ifndef COMMONSEARCHER_H_
#define COMMONSEARCHER_H_
template <class T>
class CommonSearcher
{
public:
    virtual Solution<T> search(Maze2dSearchable &maze) = 0;
    virtual int getNumberOfNodesEvaluated() = 0;
    virtual void checkEfficiency(Maze2dSearchable &mazing) = 0;
    Solution<T> backtrace(State<T> *goalState)
    {
        Solution<T> solution;
        State<T> *currentState = goalState;
        while (currentState != nullptr)
        {
            solution.addState(currentState);
            currentState = currentState->getCameFrom();
        }
        return solution;
    }
};

#endif /* COMMONSEARCHER_H_ */