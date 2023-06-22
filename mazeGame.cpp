#include "mazeGame.hpp"
#include "mazeFactory.cpp"
#include <iostream>
MazeGame::MazeGame(int size) {
    MazeFactory factory;
    Maze* maze = factory.makeMaze();
    for (int i = 0; i < size; i++) {
        Room* room = factory.makeRoom(i);
        maze->addRoom(room);

        // Connect the rooms with doors
        Room* roomNorth = maze->getRoom(i - 1);
        Room* roomSouth = maze->getRoom(i + 1);
        MapSite* door = factory.makeDoor(room, roomNorth);
        room->setSide(North, door);
        if (roomNorth != nullptr)
            roomNorth->setSide(South, door);
        door = factory.makeDoor(room, roomSouth);
        room->setSide(South, door);
        if (roomSouth != nullptr)
            roomSouth->setSide(North, door);
        maze->addRoom(room);
    }
    this->maze = *maze;
}

Maze* MazeGame::getMaze() {
    return &maze;
}


std::ostream& operator<<(std::ostream& os, const MazeGame& mazeGame) {
    os << mazeGame.maze << std::endl;
    return os;
}