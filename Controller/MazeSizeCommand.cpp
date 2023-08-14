

#include "MazeSizeCommand.h"



void MazeSizeCommand::execute()
{
    MazeCompression mazeCompression ;
    std::cout <<MAGENTA<< "Please enter the name of the maze you want to get the size of: " <<RESET<< std::endl;
    std::string mazeName;
    std::cin >> mazeName;
<<<<<<< HEAD
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character
    //get the size of the maze
    long long size = mazeCompression.getFileDetails("Mazes/"+mazeName+".txt");
    //print the size of the maze
=======
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    long long size = mazeCompression.getFileDetails(mazeName+".txt");
>>>>>>> 1a1b51d (fgfg)
    if (size == -1)
    {
        std::cout <<RED<< "The maze does not exist" << RESET<<std::endl;
        return;
    }
    std::cout <<GREEN<< "The name of the maze is: " << mazeName << std::endl;
    std::cout << "The size of the maze is: " << size <<RESET<< std::endl;

}