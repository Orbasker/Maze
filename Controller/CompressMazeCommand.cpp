#include "CompressMazeCommand.h"

void CompressMazeCommand::execute()
{
    std::string file_name;
    std::cout << "Enter the name of the file you want to compare to the maze: " << std::endl;
    std::cin >> file_name;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character


    //Get the maze to compress
    Maze2d maze = model_->getMaze(file_name);
    MazeCompression maze_compression;
    maze_compression.compressAndWriteToFile(maze, file_name + ".txt");
    long long size_of_file = maze_compression.getFileDetails("Mazes/"+file_name + ".txt");
    std::cout << "The size of the compressed file is: " << size_of_file << " bytes" << std::endl;
    std::cout << "The maze was compressed and saved to the file: " << file_name + ".txt" << std::endl;
}