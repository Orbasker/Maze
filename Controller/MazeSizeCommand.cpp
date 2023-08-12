

#include "MazeSizeCommand.h"



void MazeSizeCommand::execute()
{
    MazeCompression mazeCompression ;
    //ask the user for input file 
    std::cout << "Please enter the name of the maze you want to get the size of: " << std::endl;
    std::string mazeName;
    std::cin >> mazeName;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character
    //get the size of the maze
    long long size = mazeCompression.getFileDetails(mazeName+".txt");
    //print the size of the maze
    if (size == -1)
    {
        std::cout << "The maze does not exist" << std::endl;
        return;
    }
    std::cout << "The name of the maze is: " << mazeName << std::endl;
    std::cout << "The size of the maze is: " << size << std::endl;

}