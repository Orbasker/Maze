#ifndef MAZE_HPP
#define MAZE_HPP
#include <iostream>
#include <vector>
#include "room.hpp"

class Maze {
private:
    std::vector<Room*> rooms;
    int mazeWidth;
    int mazeHeight;

public:
    Maze(int width=10, int height=10);
    void addRoom(Room* room);
    Room* getRoom(int roomNo);
    Room* getRoom(int roomY, int roomX) const;
    int getMazeWidth() const;
    int getMazeHeight() const;

    const std::vector<Room*>& getRooms() const;
    friend std::ostream& operator<<(std::ostream& os, const Maze& maze);
};

#endif
