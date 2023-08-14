
#include "DecompressMazeCommand.h"
void DecompressMazeCommand::execute()
{
    string path;
    cout <<MAGENTA<< "Please enter the path of the file you want to decompress" <<RESET<< endl;
    cin >> path;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

    Maze2d maze = MazeCompression::decompressAndReadFromFile(path + ".txt");
    view_->displayMaze(maze);
}