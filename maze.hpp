#ifndef MAZE_HPP
#define MAZE_HPP
#include <iostream>
#include <vector>
#include "room.hpp"

class Maze {
private:
    std::vector<Room*> rooms;

public:
    void addRoom(Room* room);
    Room* getRoom(int roomNo);
    const std::vector<Room*>& getRooms() const;
    friend std::ostream& operator<<(std::ostream& os, const Maze& maze);
};

#endif
