#include "SimpleMaze2dGenerator.h"
#include <cstdlib>  // Include for rand()
#include <ctime>    // Include for srand()

Maze2d SimpleMaze2dGenerator::generate() {
    // Algorithm for generating a simple maze with random walls and a random path
    int n = 5;
    int m = 5;
    Maze2d maze(n, m);
    

    // Seed the random number generator between 0 and 1
    

    srand(static_cast<unsigned int>(time(nullptr)));

    // Set all cells as walls
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Randomly set some cells as empty spaces
            if (rand() % 4 != 0) {
                maze.setCell(i, j, 0); // 0 represents empty space
            } else {
                maze.setCell(i, j, 1); // 1 represents wall
            }
        }
    }
    
    // Create a path from (0,0) to (n-1,m-1)
    // sign 0 for empty cell(path), 1 for wall, 2 for start point, 3 for end point 
    maze.setCell(0, 0, 2);
    maze.setCell(n - 1, m - 1, 3);

    return maze;
}
