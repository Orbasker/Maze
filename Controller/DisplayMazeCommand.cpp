#include "DisplayMazeCommand.h"


void DisplayMazeCommand::execute()
{
    //get teh maze name from the user
    std::string mazeName;
    std::cout << "Please enter the name of the maze you want to display: " << std::endl;
    std::cin >> mazeName;

    //get the maze from the model
    Maze2d maze = model_->getMaze(mazeName);
    view_->displayMaze(maze);
    view_->displayMessage("Maze displayed successfully");

    view_->displaySolution(*model_->getSolution(mazeName));

    
}