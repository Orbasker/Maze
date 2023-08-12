#include "View.h"

MazeView::MazeView() {
    // Constructor, if needed
}

void MazeView::displayMaze(const Maze2d& maze) const {
    // Display the maze to the user
    // You need to implement how you want to visualize the maze

    maze.print();
}
void MazeView::displaySolution(Solution<std::pair<int, int> >& maze)  {
    // Display the solution of the maze to the user
    // You need to implement how you want to visualize the solution
    maze.printSolution();

}
void MazeView::displayMessage(const std::string& message) const {
    // Display a message to the user
    std::cout << message << std::endl;
}
