// Your individual command implementations (e.g., SolveMazeCommand, LoadMazeCommand, etc.)
#pragma once
#include "command.cpp"
// #include "maze2d.h"
#include "Maze2dSearchable.h"
#include <iostream>
class SolveMazeCommand : public Command {
public:
    SolveMazeCommand(Maze2d& maze);

    void execute() override ;
      
private:
    Maze2d& maze_;
};

