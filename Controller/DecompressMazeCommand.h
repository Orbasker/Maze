#pragma once
#include <iostream>
#include "../Model.h"
#include "command.cpp"
#include "../View.h"
#include "../Model/mazeCompression.cpp"
class DecompressMazeCommand: public Command
{
    public:
    DecompressMazeCommand(MazeModel *model, MazeView *view): model_(model),view_(view)   {}
    void execute() override;
    void solveMaze();

    private:
    MazeModel* model_;
    MazeView *view_;
};
