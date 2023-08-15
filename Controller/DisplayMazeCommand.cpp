// Or Basker   316388743
// Nave Maymon 318887965

#include "DisplayMazeCommand.h"


void DisplayMazeCommand::execute()
{
    //get teh maze name from the user
    std::string mazeName;
    std::cout << "Please enter the name of the maze you want to display: " << std::endl;
    std::cin >> mazeName;

    //get the maze from the model
    try {
    Maze2d maze = model_->getMaze(mazeName);
    view_->displayMaze(maze);
    view_->displayMessage("Maze displayed successfully");

    view_->displaySolution(*model_->getSolution(mazeName));
    }
    catch (std::exception& e) {

        view_->displayMessage(e.what());
    }
    
}