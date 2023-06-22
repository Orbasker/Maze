#ifndef DOOR_HPP
#define DOOR_HPP

#include "mapSite.hpp"
#include "room.hpp"

class Door : public MapSite {
private:
    Room* room1;
    Room* room2;
    bool isOpen;

public:
    Door(Room* room1, Room* room2);
    void enter() override;
    Room* otherSideFrom(Room* room);
    void open();
    void close();
};

#endif
