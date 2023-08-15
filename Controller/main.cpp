// Or Basker   316388743
// Nave Maymon 318887965

#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include "Model/SimpleMaze2dGenerator.h"
#include <fstream>
#include "../View/CLI.h"
#include <sstream>
#include "../View/demo.h"
#include "Model/mazeCompression.cpp"
#include "GenrateMazeCommand.h"
#include <vector>
// #include "Model/Maze2dSearchable.h"
#include "SolveMazeCommand.h"
#include "Model/BFS.cpp"



#include "View.h"
#include "Model.h"
#include "Controller.h"
// #include "TestAspect.ah"
// Test 1: Maze Generation Test
void testMazeGeneration() {
    std::cout << "Test 1: Maze Generation Test" << std::endl;
    SimpleMaze2dGenerator generator;
    Maze2d maze = generator.generate(5,5);
    maze.print();
    std::cout << std::endl;
}


// Test 2: Pathfinding Test
void testPathfinding() {
    std::cout << "Test 2: Pathfinding Test" << std::endl;

    // Generate a maze using SimpleMaze2dGenerator
    SimpleMaze2dGenerator generator;
    Maze2d maze = generator.generate(8,8);

    // // Print the maze
    std::cout << "Generated Maze:" << std::endl;
    maze.print();

    Maze2dSearchable searchableMaze(maze);
    cout << "BFS: Old way" << endl;
    searchableMaze.BFS();
    searchableMaze.getSolution()->printSolution();
    std::cout << std::endl;

    cout << "BFS: New way" << endl;
    BFS<std::pair<int, int> > bfs;
    Solution<std::pair<int,int > > result = bfs.search(searchableMaze);
    std::cout << "Efficency test: " <<endl;
    bfs.checkEfficiency(searchableMaze);
    std::cout << "end of search patterns"<<std::endl;
    
}

// Test 3: Boundary Testing
void testBoundary() {
    std::cout << "Test 3: Boundary Testing" << std::endl;

    // Test 1: Small Maze Size
    std::cout << "Test 3.1: Small Maze Size" << std::endl;
    try {
        // Attempt to create a maze with a small size
        int smallSize = 1;
        Maze2d smallMaze(smallSize, smallSize);
        smallMaze.print(); // Print the maze
    } catch (const std::exception& e) {
        std::cout << "Exception occurred: " << e.what() << std::endl;
    }

    // Test 2: Large Maze Size
    std::cout << "Test 3.2: Large Maze Size" << std::endl;
    try {
        // Attempt to create a maze with a large size
        int largeSize = 10000;
        Maze2d largeMaze(largeSize, largeSize);
        // Print only the first and last rows and columns to avoid overwhelming output
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                std::cout << largeMaze.getCell(i, j) << ' ';
            }
            std::cout << "... ";
            for (int j = largeSize - 2; j < largeSize; j++) {
                std::cout << largeMaze.getCell(i, j) << ' ';
            }
            std::cout << std::endl;
        }
        std::cout << "..." << std::endl;
        for (int i = largeSize - 2; i < largeSize; i++) {
            for (int j = 0; j < 2; j++) {
                std::cout << largeMaze.getCell(i, j) << ' ';
            }
            std::cout << "... ";
            for (int j = largeSize - 2; j < largeSize; j++) {
                std::cout << largeMaze.getCell(i, j) << ' ';
            }
            std::cout << std::endl;
        }
    } catch (const std::exception& e) {
        std::cout << "Exception occurred: " << e.what() << std::endl;
    }

    // Test 3: Zero or Negative Dimensions
    std::cout << "Test 3.3: Zero or Negative Dimensions" << std::endl;
    try {
        // Attempt to create a maze with zero or negative dimensions
        Maze2d zeroSizeMaze(0, 5); // This should throw an exception
    } catch (const std::exception& e) {
        std::cout << "Exception occurred: " << e.what() << std::endl;
    }

    // Test 4: Other Boundary Scenarios
    std::cout << "Test 3.4: Other Boundary Scenarios" << std::endl;
    try {
        // Add any other boundary scenarios you want to test
        // For example, test extremely large maze sizes, edge cases, etc.
    } catch (const std::exception& e) {
        std::cout << "Exception occurred: " << e.what() << std::endl;
    }
}


// Test 4: Input Validation Test
void testInputValidation() {
    std::cout << "Test 4: Input Validation Test" << std::endl;

    // Test 1: Invalid Maze Dimensions
    std::cout << "              Test 4.1: Invalid Maze Dimensions" << std::endl;
    try {
        // Attempt to create a maze with negative dimensions
        Maze2d invalidMaze(-5, 5); // This should throw an exception
    } catch (const std::exception& e) {
        std::cout << "Exception occurred: " << e.what() << std::endl;
    }

    // Test 2: Incorrect Inputs to Maze Generation Algorithm
    std::cout << "              Test 4.2: Incorrect Inputs to Maze Generation Algorithm" << std::endl;
    try {
        // Create a custom maze generator that takes incorrect inputs
        class IncorrectMazeGenerator : public Maze2dGenerator {
        public:
            Maze2d generate(int rows=5,int cols=5) override {
                // Incorrect input: Trying to access maze_ without initializing it
                Maze2d maze(5, 5);
                maze.setCell(0, 0, 1); // Setting a cell in the maze
                return maze;
            }
        };

        IncorrectMazeGenerator generator;
        generator.generate(); // This should throw an exception
    } catch (const std::exception& e) {
        std::cout << "          Exception occurred: " << e.what() << std::endl;
    }
}





// Test 5: Performance Test
void testPerformance() {
    std::cout << "Test 5: Performance Test" << std::endl;
    std::vector<int> mazeSizes = {10, 50, 100, 500, 1000};

    // Measure the time taken for each maze size using SimpleMaze2dGenerator
    SimpleMaze2dGenerator generator;
    for (int size : mazeSizes) {
        std::clock_t start_time = std::clock();

        // Generate the maze of the specified size
        generator.generate(5,5);

        std::clock_t end_time = std::clock();
        double time_taken = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

        std::cout << "Maze size " << size << "x" << size << ": ";
        std::cout << "Time taken: " << time_taken << " seconds" << std::endl;
    }
}
// Test 6: Consistency Test
void testConsistency() {
    std::cout << "Test 6: Consistency Test" << std::endl;
    SimpleMaze2dGenerator generator;
    Maze2d maze1 = generator.generate(5,5);
    Maze2d maze2 = generator.generate(5,5);

    std::cout << "Maze 1:" << std::endl;
    maze1.print();
    std::cout << "Maze 2:" << std::endl;
    maze2.print();

}




class HelloCommand : public Command {
public:
    void execute() override {
        std::cout << "Hello, world!" << std::endl;
    }
};

class ByeCommand : public Command {
public:
    void execute() override {
        std::cout << "Goodbye!" << std::endl;
    }
};




int main() {
    testPathfinding();
    testMazeGeneration();
    testPathfinding();
    testBoundary();
    testInputValidation();
    testPerformance();
    testConsistency();
   
    Demo demo;
    demo.run();

    // std::unordered_map<std::string, Maze2d> mazes;
    
    

    MazeController controller;

    controller.start();
    return 0;
}

