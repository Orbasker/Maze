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
    std::cout << message << std::endl;
}
