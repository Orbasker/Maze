#include "View.h"

MazeView::MazeView() {
}

void MazeView::displayMaze(const Maze2d& maze) const {

    maze.print();
}
void MazeView::displaySolution(Solution<std::pair<int, int> >& maze)  {
    maze.printSolution();

}
void MazeView::displayMessage(const std::string& message) const {
<<<<<<< HEAD
    // Display a message to the user
    std::cout <<RED<< message << RESET<<std::endl;
=======
    std::cout << message << std::endl;
>>>>>>> 1a1b51d (fgfg)
}
