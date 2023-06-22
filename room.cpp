#include "room.hpp"

Room::Room(int roomNo) : roomNumber(roomNo) {
    // constructor implementation
    // initialize the room with the room number
    
    for (int i = 0; i < 4; i++) {
        sides[i] = nullptr;
    }
}

MapSite* Room::getSide(Direction direction) {
    if(direction < 0 || direction > 3) {
        return nullptr;
    }
    if (direction == North) {
        return sides[0];
    } else if (direction == South) {
        return sides[1];
    } else if (direction == East) {
        return sides[2];
    } else if (direction == West) {
        return sides[3];
    }
    else {
        return nullptr;
    }
}

void Room::setSide(Direction direction, MapSite* site) {
    // Logic to set the side of the room based on direction
    if (direction < 0 || direction > 3) {
        return;
    }
    if (direction == North) {
        sides[0] = site;
    } else if (direction == South) {
        sides[1] = site;
    } else if (direction == East) {
        sides[2] = site;
    } else if (direction == West) {
        sides[3] = site;
    }
}
int Room::getRoomNumber() const {
    return roomNumber;
}

std::ostream& operator<<(std::ostream& os, const Room& room) {
    os << "Room " << room.roomNumber << std::endl;
    return os;
}
