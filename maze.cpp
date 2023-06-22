#include "maze.hpp"

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

