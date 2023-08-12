#include "GenrateMazeCommand.h"
#include <iostream> // Include necessary headers for std::cout

GenerateMazeCommand::GenerateMazeCommand(MazeModel *model, MazeView *view)
    : model_(model), view_(view) /* other params initialization */ {}

void GenerateMazeCommand::execute()
{
    // Get from user the paramaters for the maze'
    std::cout << "Enter the name of the maze: ";
    std::cin >> name_;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character

    std::cout << "Enter the size of the maze: ";
    try
    {
        std::cin >> size_;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character

    }
    catch (std::exception &e)
    {
        std::cout << "Invalid input" << std::endl;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character
    model_->generateMaze(name_, size_, size_);

    std::cout << "Maze '" << name_ << "' generated and saved." << std::endl;
    view_->displayMaze(model_->getMaze(name_));
}
