#pragma once
#include "maze2d.h"
#include <iostream>
#include <fstream>
Maze2d::Maze2d(int n, int m) : maze_(n, std::vector<int>(m, 0)) {}

State<std::pair<int, int>>* Maze2d::getStartState() {
    return new State<std::pair<int, int>>(std::make_pair(0, 0));
}

State<std::pair<int, int>>* Maze2d::getGoalState() {
    int n = getRows();
    int m = getCols();
    return new State<std::pair<int, int>>(std::make_pair(n - 1, m - 1));
}

std::vector<State<std::pair<int, int>>*> Maze2d::getAllPossibleStates(State<std::pair<int, int>>& s) {
    std::vector<State<std::pair<int, int>>*> possibleStates;
    int i = s.getState().first;
    int j = s.getState().second;
    int n = getRows();
    int m = getCols();

    // Populate possibleStates based on maze conditions
    // ...

    return possibleStates;
}

int Maze2d::getCell(int i, int j) const {
    return maze_[i][j];
}

int Maze2d::getRows() const {
    return maze_.size();
}

int Maze2d::getCols() const {
    return maze_.empty() ? 0 : maze_[0].size();
}

void Maze2d::setCell(int i, int j, int value) {
    maze_[i][j] = value;
}

void Maze2d::print() const {
    // Implement the method to print the maze
    for (const auto& row : maze_) {
        for (int cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << '\n';
    }
}


bool Maze2d::saveToFile(const std::string& filename) {
    std::ofstream file(filename, std::ios::binary | std::ios::out);
    if (!file.is_open()) {
        return false; // File could not be opened
    }

    // Serialize and write maze data to the file
    int rows = getRows();
    int cols = getCols();
    file.write(reinterpret_cast<char*>(&rows), sizeof(int));
    file.write(reinterpret_cast<char*>(&cols), sizeof(int));
    for (const auto& row : maze_) {
        file.write(reinterpret_cast<const char*>(row.data()), row.size() * sizeof(int));
    }

    file.close();
    return true; // Successfully saved
}

Maze2d Maze2d::loadFromFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary | std::ios::in);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for reading");
    }

    int rows, cols;
    file.read(reinterpret_cast<char*>(&rows), sizeof(int));
    file.read(reinterpret_cast<char*>(&cols), sizeof(int));
    Maze2d maze(rows, cols);
    for (auto& row : maze.maze_) {
        file.read(reinterpret_cast<char*>(row.data()), row.size() * sizeof(int));
    }

    file.close();
    return maze;
}
bool Maze2d::operator==(const Maze2d& other) const {
    // Compare maze_ data and any other relevant attributes for equality
    return maze_ == other.maze_; // Assuming maze_ is your maze data member
}