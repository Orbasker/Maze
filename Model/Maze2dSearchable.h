#pragma once
#include <iostream>
#include "Searchable.h"
#include "State.cpp"
#include "maze2d.h"
#include "Solution.cpp"

#include <list>

<<<<<<< HEAD
class Maze2dSearchable : public Searchable<std::pair<int, int> > {
=======
class Maze2dSearchable : public Searchable<std::pair<int, int>>
{
>>>>>>> 1a1b51d (fgfg)
public:
    Maze2dSearchable(const Maze2d &maze);

<<<<<<< HEAD
    State<std::pair<int, int> >* getStartState() override;
    State<std::pair<int, int> >* getGoalState() override;
    std::vector<State<std::pair<int, int> >*> getAllPossibleStates(State<std::pair<int, int> >& s) override;
=======
    State<std::pair<int, int>> *getStartState() override;
    State<std::pair<int, int>> *getGoalState() override;
    std::vector<State<std::pair<int, int>> *> getAllPossibleStates(State<std::pair<int, int>> &s) override;
>>>>>>> 1a1b51d (fgfg)
    void setPossibleMoves();
    void BFS();
    void addEdge(std::pair<int, int> src, std::pair<int, int> dest);
    Solution<std::pair<int, int>> *getSolution();
    void setVisited();
<<<<<<< HEAD
    void set_solution(Solution<std::pair<int, int> >* solution);
private:
    const Maze2d& maze_;
    //init a list with all the possible moves
    //possible move is where the value is 0
    Solution<std::pair<int, int> >* solution_;
    std::list<std::pair<int, int> > possibleMoves_;
    bool* visited_;
=======
    void set_solution(Solution<std::pair<int, int>> *solution);

private:
    const Maze2d &maze_;
    Solution<std::pair<int, int>> *solution_;
    std::list<std::pair<int, int>> possibleMoves_;
    bool *visited_;
>>>>>>> 1a1b51d (fgfg)
    int numOfVertics_;
};
