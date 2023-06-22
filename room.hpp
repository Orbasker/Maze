#ifndef ROOM_HPP
#define ROOM_HPP
#include <array>
#include <iostream>
#include "mapSite.hpp"

enum Direction {
    North,
    South,
    East,
    West
};

class Room {
private:
    // MapSite* sides[4];
    std::array<MapSite*, 4> sides;

    const int roomNumber;
public:
    Room(int roomNo);
    MapSite* getSide(Direction direction);
    void setSide(Direction direction, MapSite* site);
    int getRoomNumber() const;
    friend std::ostream& operator<<(std::ostream& os, const Room& room);
    
};

#endif
