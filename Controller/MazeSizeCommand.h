

#pragma once
#include <iostream>
#include "../Model.h"
#include "command.cpp"
#include "../View.h"
#include "../Model/mazeCompression.cpp"
class MazeSizeCommand : public Command
{
    public:
    MazeSizeCommand(MazeView* view, MazeModel* model) : model_(model), view_(view) {};

    void execute() override;

    private:
    MazeModel* model_;
    MazeView* view_;
};