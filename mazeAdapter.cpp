#include "mazeAdapter.h"

MazeAdapter::MazeAdapter(Maze2d& maze) : maze_(maze) {
    startState_ = maze_.getStartState();
    goalState_ = maze_.getGoalState();
}