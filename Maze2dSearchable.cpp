#pragma once

#include "maze2dSearchable.h"

Maze2dSearchable::Maze2dSearchable(const Maze2d& maze) : maze_(maze) {}

State<std::pair<int, int>>* Maze2dSearchable::getStartState() {
    return new State<std::pair<int, int>>(std::make_pair(0, 0));
}

State<std::pair<int, int>>* Maze2dSearchable::getGoalState() {
    int n = maze_.getRows();
    int m = maze_.getCols();
    return new State<std::pair<int, int>>(std::make_pair(n - 1, m - 1));
}

std::vector<State<std::pair<int, int>>*> Maze2dSearchable::getAllPossibleStates(State<std::pair<int, int>>& s) {
    std::vector<State<std::pair<int, int>>*> possibleStates;
    int i = s.getState().first;
    int j = s.getState().second;
    int n = maze_.getRows();
    int m = maze_.getCols();

    // Populate possibleStates based on maze conditions
    // ...

    return possibleStates;
}
