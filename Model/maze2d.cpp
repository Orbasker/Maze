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
    return new State<std::pair<int, int> >(std::make_pair(n - 1, m - 1));
}

std::vector<State<std::pair<int, int> >* > Maze2d::getAllPossibleStates(State<std::pair<int, int>>& s) {
    std::vector<State<std::pair<int, int> > * > possibleStates;
    int i = s.getState().first;
    int j = s.getState().second;
    int n = getRows();
    int m = getCols();

    //check for neighbors
    if (i > 0 && maze_[i - 1][j] == 0) {
        possibleStates.push_back(new State<std::pair<int, int> >(std::make_pair(i - 1, j)));
    }
    if (i < n - 1 && maze_[i + 1][j] == 0) {
        possibleStates.push_back(new State<std::pair<int, int> >(std::make_pair(i + 1, j)));
    }
    if (j > 0 && maze_[i][j - 1] == 0) {
        possibleStates.push_back(new State<std::pair<int, int> >(std::make_pair(i, j - 1)));
    }
    if (j < m - 1 && maze_[i][j + 1] == 0) {
        possibleStates.push_back(new State<std::pair<int, int> >(std::make_pair(i, j + 1)));
    }
    
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

std::vector<int> Maze2d::getData() const {
    std::vector<int> data;
    // Append maze dimensions, entrance/exit, and maze contents to data
    data.push_back(getRows());
    data.push_back(getCols());

    // Append maze cell values
    for (const auto& row : maze_) {
        for (int cell : row) {
            data.push_back(cell);
        }
    }

    return data;
}

Maze2d Maze2d::createFromData(const std::vector<int>& data) {
    int rows = data[0];
    int cols = data[1];
    Maze2d maze(rows, cols);
    
    int dataIndex = 2; // Start from the first maze cell in the data vector
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            maze.setCell(i, j, data[dataIndex++]);
        }
    }

    return maze; // Return the constructed maze
}


void Maze2d::setData(const std::vector<int>& data) {
    // Use the data to set the maze_ data member
    int rows = data[0];
    int cols = data[1];
    maze_ = std::vector<std::vector<int>>(rows, std::vector<int>(cols));
    int dataIndex = 2; 
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                maze_[i][j] = data[dataIndex++];
            }
        }
}

long long Maze2d::getSize() const{
    return sizeof(maze_)*maze_.size()*maze_[0].size();
}