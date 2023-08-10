#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include "SimpleMaze2dGenerator.h"
#include <fstream>
#include "CLI.h"
#include <sstream>
#include "demo.h"
#include "mazeCompression.cpp"
#include <vector>
#include "Maze2dSearchable.h"
#include "SolveMazeCommand.h"

// Test 1: Maze Generation Test
void testMazeGeneration() {
    std::cout << "Test 1: Maze Generation Test" << std::endl;
    SimpleMaze2dGenerator generator;
    Maze2d maze = generator.generate();
    maze.print();
    std::cout << std::endl;
}


// Test 2: Pathfinding Test
void testPathfinding() {
    std::cout << "Test 2: Pathfinding Test" << std::endl;

    // Generate a maze using SimpleMaze2dGenerator
    SimpleMaze2dGenerator generator;
    Maze2d maze = generator.generate();

    // // Print the maze
    std::cout << "Generated Maze:" << std::endl;
    maze.print();

    Maze2dSearchable searchableMaze(maze);
    searchableMaze.BFS();
    searchableMaze.getSolution()->printSolution();
    std::cout << std::endl;
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
            Maze2d generate() override {
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
    // Add the performance testing code here
    // Measure the time taken to generate mazes of various sizes and compare the performance of different algorithms
    // Define the sizes of the mazes to test
    std::vector<int> mazeSizes = {10, 50, 100, 500, 1000};

    // Measure the time taken for each maze size using SimpleMaze2dGenerator
    SimpleMaze2dGenerator generator;
    for (int size : mazeSizes) {
        std::clock_t start_time = std::clock();

        // Generate the maze of the specified size
        generator.generate();

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
    Maze2d maze1 = generator.generate();
    Maze2d maze2 = generator.generate();

    std::cout << "Maze 1:" << std::endl;
    maze1.print();
    std::cout << "Maze 2:" << std::endl;
    maze2.print();

    // Check if maze1 and maze2 are consistent and reproducible
    // Compare the mazes generated with the same input parameters
    // They should be different as they are generated independently
}

// Test 7: Integration Test
void testIntegration() {
    std::cout << "Test 7: Integration Test" << std::endl;
    SimpleMaze2dGenerator generator;
    Maze2d maze = generator.generate();

    // Store the generated maze in Maze2d class and test its methods
    // For example, test if Maze2d can correctly represent and store the maze
}

// Test 8: Serialization Test
void testSerialization() {
    std::cout << "Test 8: Serialization Test" << std::endl;
   // Generate a maze using the generator
    SimpleMaze2dGenerator generator;
    Maze2d maze1 = generator.generate();

    // Save maze1 to a file
    maze1.saveToFile("maze.txt");

    // Load the maze from the file into maze2
    Maze2d maze2;
    maze2.loadFromFile("maze.txt");

    // Check if maze1 and maze2 are identical
    if (maze1 == maze2) {
        std::cout << "Serialization Test: Passed" << std::endl;
    } else {
        std::cout << "Serialization Test: Failed" << std::endl;
    }
    // Load the maze from the file into maze2
    // Check if maze1 and maze2 are identical
}

// Test 9: Memory Management Test
void testMemoryManagement() {
    std::cout << "Test 9: Memory Management Test" << std::endl;
    // Add the memory management testing code here
    // Check for memory leaks or memory-related issues during maze generation and usage

}

// Test 10: Error Handling Test
void testErrorHandling() {
    std::cout << "Test 10: Error Handling Test" << std::endl;
    // Add the error handling testing code here
    // Test how the algorithm and the Maze2d class handle unexpected errors or exceptions
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
    testMazeGeneration();
    testPathfinding();
    testBoundary();
    testInputValidation();
    // testPerformance();
    testConsistency();
    testIntegration();
    testSerialization();
    testMemoryManagement();
    testErrorHandling();
    Demo demo;
    demo.run();
    // Create a maze using Maze2d class (you might have your own way to create the maze)
    Maze2d originalMaze(5, 5);
    // ... Set the maze data ...
    originalMaze.setCell(0, 0, 1); // Setting a cell in the maze
    originalMaze.setCell(0, 4, 1); // Setting a cell in the maze
    originalMaze.setCell(0, 4, 1); // Setting a cell in the maze
    originalMaze.setCell(0, 3, 1); // Setting a cell in the maze
    originalMaze.setCell(0, 4, 1); // Setting a cell in the maze
    originalMaze.setCell(1, 0, 1); // Setting a cell in the maze
    originalMaze.setCell(1, 1, 0); // Setting a cell in the maze
    originalMaze.setCell(1, 2, 0); // Setting a cell in the maze
    //print the maze
    originalMaze.print();
    // Save the original maze
    originalMaze.saveToFile("original_maze.txt");

    // Compress and save the maze
    MazeCompression::compressAndWriteToFile(originalMaze, "compressed_maze.txt");

    // Load and decompress the maze
    Maze2d decompressedMaze = MazeCompression::decompressAndReadFromFile("compressed_maze.txt");

    // Compare the decompressed maze with the original
    if (decompressedMaze == originalMaze) {
        std::cout << "Decompressed maze matches the original maze." << std::endl;
        std::cout << "Decompressed maze:" << std::endl;
        decompressedMaze.print();
    } else {
        std::cout << "Decompressed maze does not match the original maze." << std::endl;
    }


    Maze2d hugeMaze(10,10);

    HelloCommand helloCommand;
    ByeCommand byeCommand;
    SolveMazeCommand solveMazeCommand(hugeMaze);
    // Create CLI instance with input from standard input and output to standard output
    CLI cli(std::cin, std::cout);

    // Add commands to the CLI
    cli.addCommand("hello", &helloCommand);
    cli.addCommand("bye", &byeCommand);
    cli.addCommand("solve", &solveMazeCommand);

    // Start the CLI
    std::cout << "Enter a command (hello, bye,solve, or exit to teminate the program):" << std::endl;
    cli.start();

    return 0;
}

