#pragma once
#include <iostream>
#include <vector>
#include "Model/BFS.cpp" // Include your Maze data structure header
#include "Model/SimpleMaze2dGenerator.h"
#include <map>
#include <unordered_map>
#define RED "\033[31m"
#define RESET "\033[0m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define MAGENTA "\033[35m"
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"
#define BLINK "\033[5m"
#define REVERCE "\033[7m"
#define HIDE "\033[8m"
#define CLEAR "\033[2J"
#define CLRLINE "\r\033[K"
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
