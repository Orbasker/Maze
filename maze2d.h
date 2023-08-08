#pragma once

#include <vector>
#include "Searchable.h"
#include "State.h"

class Maze2d : public Searchable<std::pair<int, int>> {
public:
    Maze2d(int n=10, int m=10);

    State<std::pair<int, int>>* getStartState() override;
    State<std::pair<int, int>>* getGoalState() override;
    std::vector<State<std::pair<int, int>>*> getAllPossibleStates(State<std::pair<int, int>>& s) override;

    int getCell(int i, int j) const;
    int getRows() const;
    int getCols() const;
    void setCell(int i, int j, int value);
    void print() const;
    // Save the maze to a file
    bool saveToFile(const std::string& filename);

    // Load the maze from a file
    static Maze2d loadFromFile(const std::string& filename);
    bool operator==(const Maze2d& other) const;

private:
    std::vector<std::vector<int>> maze_;
};
