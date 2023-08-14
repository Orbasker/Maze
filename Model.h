#pragma once
#include <iostream>
#include <vector>
#include "Model/BFS.cpp" 
#include "Model/SimpleMaze2dGenerator.h"
#include <map>
#include <unordered_map>

class MazeModel
{
public:
    MazeModel();

    void generateMaze(const std::string &name, int rows, int cols);
    void solveMaze(const std::string &name, const std::string &algorithm);
    const Maze2d &getMaze(const std::string &name) const;
    void addMaze(const std::string &name, const Maze2d &maze);
    Solution<pair<int, int>> *getSolution(const std::string &name);
    std::unordered_map<std::string, Maze2d> &getMazes();
    const std::unordered_map<std::string, Solution<pair<int, int>> *> &getSolutions() const;

private:
    std::unordered_map<std::string, Maze2d> mazes_;
    std::unordered_map<std::string, Solution<pair<int, int>> *> solutions_;
};
