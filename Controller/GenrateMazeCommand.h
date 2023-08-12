#pragma once
#include "command.cpp"
#include "../Model/SimpleMaze2dGenerator.h"
#include <unordered_map>
#include <string>
#include "Model.h"
#include "View.h"
class GenerateMazeCommand : public Command {
public:
    GenerateMazeCommand(MazeModel* model, MazeView* view);

    void execute() override;

private:
    MazeModel* model_;
    MazeView* view_;
    std::string name_;
    int size_;
    // Other parameters needed for maze generation
};
