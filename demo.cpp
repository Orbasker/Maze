#include "demo.h"
#include "Maze2dSearchable.h"
void Demo::run()
{
  // Create a maze using MyMazeGenerator
  SimpleMaze2dGenerator generator;
  Maze2d maze = generator.generate();

  // Print the maze
  maze.print();

  // Solve using BFS
  BFS<std::pair<int, int>> bfsSolver;
  Maze2dSearchable mazeSearchable(maze);
  mazeSearchable.BFS();
  mazeSearchable.getSolution()->printSolution();
  
  std::cout << "BFS situations developed: " << mazeSearchable.getSolution()->getNumOfEvaluatedNodes() << std::endl;
}