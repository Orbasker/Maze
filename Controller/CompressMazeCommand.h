#pragma once
#include <iostream>
#include "../Model.h"
#include "command.cpp"
#include "../View.h"
#include "../Model/mazeCompression.cpp"
class CompressMazeCommand : public Command
{
public:
    CompressMazeCommand(MazeModel *model, MazeView *view) : model_(model), view_(view) {}
    void execute() override;

private:
    MazeModel *model_;
    MazeView *view_;
};