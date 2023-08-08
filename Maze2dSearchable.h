#pragma once

#include "Searchable.h"
#include "State.h"
#include "maze2d.h"

class Maze2dSearchable : public Searchable<std::pair<int, int>> {
public:
    Maze2dSearchable(const Maze2d& maze);

    State<std::pair<int, int>>* getStartState() override;
    State<std::pair<int, int>>* getGoalState() override;
    std::vector<State<std::pair<int, int>>*> getAllPossibleStates(State<std::pair<int, int>>& s) override;

private:
    const Maze2d& maze_;
};
