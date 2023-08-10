#include "SolveMazeCommand.h"

SolveMazeCommand::SolveMazeCommand(Maze2d& maze) : maze_(maze) {
   

}

void SolveMazeCommand::execute() {
     Maze2dSearchable* searchableMaze = new Maze2dSearchable(maze_);
    searchableMaze->BFS();
    searchableMaze->getSolution()->printSolution();
    // send to view model to print it nice 
    //view_model_->printSolution(searchableMaze->getSolution());
    
}