// Or Basker   316388743
// Nave Maymon 318887965

#include "Model.h"

MazeModel::MazeModel()
{
}

void MazeModel::generateMaze(const std::string &name, int rows, int cols)
{
    SimpleMaze2dGenerator generator;
    Maze2d generatedMaze = generator.generate(rows, cols);
    addMaze(name, generatedMaze);
}

const Maze2d &MazeModel::getMaze(const std::string &name) const
{
    return mazes_.at(name);
}

void MazeModel::solveMaze(const std::string &name, const std::string &algorithm)
{
    if (mazes_.find(name) == mazes_.end())
    {
        throw std::invalid_argument("Maze not found");
    }
    if (algorithm == "BFS" || algorithm == "bfs")
    {
        BFS<std::pair<int, int>> bfs;
        cout << "Solving the following maze using BFS" << endl;
        mazes_.at(name).print();
        Maze2dSearchable searchable(mazes_.at(name));
        Solution<std::pair<int, int>> result = bfs.search(searchable);
        // result.printSolution();
        Solution<std::pair<int, int>> *newSolution = new Solution<std::pair<int, int>>(result);
        solutions_[name] = newSolution;
        cout << "Solution added to map" << endl;
    }
    else
    {
        throw std::invalid_argument("Invalid algorithm");
    }
}

Solution<std::pair<int, int>> *MazeModel::getSolution(const std::string &name)
{
    if (solutions_.find(name) == solutions_.end())
    {
        throw std::invalid_argument("Solution not found");
    }
    cout << "Solution found" << endl;
    return solutions_.at(name);
}

std::unordered_map<std::string, Maze2d> &MazeModel::getMazes()
{
    return mazes_;
}
const std::unordered_map<std::string, Solution<std::pair<int, int>> *> &MazeModel::getSolutions() const
{
    return solutions_;
}

void MazeModel::addMaze(const std::string &name, const Maze2d &maze)
{
    try
    {
        mazes_[name] = maze;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
