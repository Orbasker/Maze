#include "door.hpp"
#include <iostream>
Door::Door(Room* room1, Room* room2) {
    this->room1 = room1;
    this->room2 = room2;
    isOpen = false;
}

void Door::enter() {
    // Logic for the player to enter the door
    if (isOpen) {
        // Logic for the player to enter the door
        std::cout << "You entered the door." << std::endl;
    }
    else {
        // Logic for the player to not enter the door
        std::cout << "You hit a door." << std::endl;
    }
}

Room* Door::otherSideFrom(Room* room) {
    // Logic to get the other side room from the given room
    if (room == room1) {
        return room2;
    } else if (room == room2) {
        return room1;
    }
    return nullptr;
}

void Door::open() {
    // Logic to open the door
    isOpen = true;
}
void Door::close() {
    // Logic to close the door
    isOpen = false;
}