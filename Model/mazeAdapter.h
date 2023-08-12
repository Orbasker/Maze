#pragma once

#include "Searchable.h"
#include "maze2d.h"

class MazeAdapter : public Searchable<std::pair<int, int> > {
public:
    MazeAdapter(Maze2d& maze) ;

    // Implement the methods of the Searchable interface by delegating to the Maze2d instance
    virtual State<std::pair<int, int> >* getStartState() {
        return startState_;
    }
    virtual State<std::pair<int, int> >* getGoalState() {
        return goalState_;
    }

private:
    Maze2d& maze_;
    State<std::pair<int, int> >* startState_;
    State<std::pair<int, int> >* goalState_;

};
