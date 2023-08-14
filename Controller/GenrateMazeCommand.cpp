#include "GenrateMazeCommand.h"
#include <iostream>

GenerateMazeCommand::GenerateMazeCommand(MazeModel *model, MazeView *view)
    : model_(model), view_(view) {}

void GenerateMazeCommand::execute()
{

    std::cout <<MAGENTA<< "Enter the name of the maze: "<<RESET;
    std::cin >> name_;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout <<MAGENTA<< "Enter the size of the maze: "<<RESET;
    try
    {
        std::cin >> size_;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    catch (std::exception &e)
    {
        std::cout <<RED<< "Invalid input" <<RESET<< std::endl;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    model_->generateMaze(name_, size_, size_);

    std::cout <<GREEN<< "Maze '" << name_ << "' generated and saved." <<RESET<< std::endl;
    view_->displayMaze(model_->getMaze(name_));
}
