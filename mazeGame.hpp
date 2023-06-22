#ifndef MAZEGAME_HPP
#define MAZEGAME_HPP
#include <iostream>
#include "mazeFactory.cpp"
#include "maze.hpp"

class MazeGame {
private:
    Maze maze;

public:
    MazeGame(int size); // Constructor
    Maze* getMaze();
    friend std::ostream& operator<<(std::ostream& os, const MazeGame& mazeGame);
};

#endif
