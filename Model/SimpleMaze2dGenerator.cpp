#include "SimpleMaze2dGenerator.h"
#include <cstdlib> // Include for rand()
#include <ctime>   // Include for srand()

SimpleMaze2dGenerator::SimpleMaze2dGenerator()
{
    this->_maze = Maze2d(5, 5);
}

Maze2d SimpleMaze2dGenerator::generate(int rows = 5, int cols = 5)
{
    // Algorithm for generating a simple maze with random walls and a random path
    int n = rows;
    int m = cols;
    Maze2d maze(n, m);

    srand(static_cast<unsigned int>(time(nullptr)));

    // Set all cells as walls
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // Randomly set some cells as empty spaces
            if (rand() % 4 != 0)
            {
                maze.setCell(i, j, 0); // 0 represents empty space
            }
            else
            {
                maze.setCell(i, j, 1); // 1 represents wall
            }
        }
    }

    maze.setCell(0, 0, 2);
    maze.setCell(n - 1, m - 1, 3);
    this->_maze = maze;
    return maze;
}

ostream &operator<<(ostream &os, const SimpleMaze2dGenerator &maze)
{
    os << "SimpleMaze2dGenerator" << endl;
    maze._maze.print();
    return os;
}

Maze2d SimpleMaze2dGenerator::getMaze() const
{
    return this->_maze;
}

void SimpleMaze2dGenerator::setMaze(const Maze2d &maze)
{
    this->_maze = maze;
}

SimpleMaze2dGenerator &SimpleMaze2dGenerator::operator=(const SimpleMaze2dGenerator &maze)
{
    this->_maze = maze._maze;
    return *this;
}
