#include "maze.hpp"
Maze::Maze(int width, int height) {
    mazeWidth = width;
    mazeHeight = height;
}

void Maze::addRoom(Room* room) {
    rooms.push_back(room);
}

Room* Maze::getRoom(int roomNo) {
    // Logic to retrieve a room based on room number
    if (roomNo >= 0 && roomNo < rooms.size()) {
        return rooms[roomNo];
    }
    return nullptr; // Replace nullptr with the actual logic to return the room
}

// MazeGame methods implementation
const std::vector<Room*>& Maze::getRooms() const {
    return rooms;
}
std::ostream& operator<<(std::ostream& os, const Maze& maze) {
    std::vector<Room*> maze_rooms = maze.getRooms();
    for (int i = 0; i < maze_rooms.size(); i++) {
        os << maze_rooms[i] << std::endl;
    }
    return os;
}

Room* Maze::getRoom(int roomY, int roomX) const {
    // Logic to retrieve the room based on roomY and roomX
    // Make sure to handle out-of-bound coordinates appropriately
    // For example, check if roomY and roomX are within the maze boundaries
    // and return nullptr if they are not valid.

    if (roomY >= 0 && roomY < mazeHeight && roomX >= 0 && roomX < mazeWidth) {
        // Return the room at the specified coordinates
        return rooms[roomY * mazeWidth + roomX];
    }

    // Invalid coordinates, return nullptr
    return nullptr;
}


int Maze::getMazeWidth() const {
    return mazeWidth;
}
int Maze::getMazeHeight() const {
    return mazeHeight;
}