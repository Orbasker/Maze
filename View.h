#pragma once

#include <iostream>
#include "Model/Maze2dSearchable.h"  

class MazeView {
public:
    MazeView();

    void displayMaze(const Maze2d& maze) const;
    void displaySolution(Solution<std::pair<int, int> >& maze);
    void displayMessage(const std::string& message) const;
};
