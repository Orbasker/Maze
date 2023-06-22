#include <iostream>
#include "mazeGame.hpp"
using namespace std;
int main() {
    MazeGame mazeGame(10);
    // mazeGame.createMaze(10);
    Maze* maze = mazeGame.getMaze();
    int a,b;
        a=6;
    std::cout << maze;
    std::cout <<"the number is"<<a<<endl;
    return 0;
}
