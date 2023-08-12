#pragma once
#include "command.cpp"
#include "../Model/BFS.cpp"
#include <iostream>
#include <vector>
#include <unordered_map>
#include "../Model/SimpleMaze2dGenerator.h"
#include "Model.h"
#include "View.h"

class SolveMazeCommand : public Command
{
public:
    SolveMazeCommand(MazeModel *model, MazeView *view) : model_(model), view_(view){};

    void execute() override;

private:
    MazeModel *model_;
    MazeView *view_;
};
