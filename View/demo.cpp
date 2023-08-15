// Or Basker   316388743
// Nave Maymon 318887965

#include "demo.h"
#include "Model/Maze2dSearchable.h"
void Demo::run()
{
  SimpleMaze2dGenerator generator;
  Maze2d maze = generator.generate(10, 10);

  maze.print();

  BFS<std::pair<int, int>> bfsSolver;
  Maze2dSearchable mazeSearchable(maze);
  mazeSearchable.BFS();
  mazeSearchable.getSolution()->printSolution();

  std::cout << "BFS situations developed: " << mazeSearchable.getSolution()->getNumOfEvaluatedNodes() << std::endl;
}