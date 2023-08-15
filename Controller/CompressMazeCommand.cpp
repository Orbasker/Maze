// Or Basker   316388743
// Nave Maymon 318887965

#include "CompressMazeCommand.h"

void CompressMazeCommand::execute()
{
    std::string file_name;
    std::cout <<BLUE<< "Enter the name of the file you want to compare to the maze: " <<RESET<< std::endl;
    std::cin >> file_name;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 


    //Get the maze to compress
    try {
    Maze2d maze = model_->getMaze(file_name);
    MazeCompression maze_compression;
    maze_compression.compressAndWriteToFile(maze, file_name + ".txt");
    long long size_of_file = maze_compression.getFileDetails("Mazes/"+file_name + ".txt");
    std::cout <<YELLOW<< "The size of the compressed file is: " << size_of_file << " bytes" << std::endl;
    std::cout <<GREEN<< "The maze was compressed and saved to the file: " << file_name + ".txt" <<RESET<< std::endl;
    }
    catch (const std::exception& e) {
        std::cout <<RED<< e.what() <<RESET<< std::endl;
    }
}