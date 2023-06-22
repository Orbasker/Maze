#ifndef MAZEFACTORY_H
#define MAZEFACTORY_H
#include "room.hpp"
#include "wall.hpp"
#include "door.hpp"
#include "maze.hpp"
#include "mapSite.hpp"




class MazeFactory {
public:
    MazeFactory() {}
    virtual Maze* makeMaze() {return new Maze();}
    virtual Room* makeRoom(int roomNo) {return new Room(roomNo);}
    virtual MapSite* makeWall() {return new Wall();}
    virtual MapSite* makeDoor(Room* r1, Room* r2) {return new Door(r1, r2);}
};

#endif
