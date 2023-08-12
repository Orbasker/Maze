
#include "DecompressMazeCommand.h"
void DecompressMazeCommand::execute() {
    //ask the user for the path
    string path;
    cout << "Please enter the path of the file you want to decompress" << endl;
    cin >> path;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character

    Maze2d maze = MazeCompression::decompressAndReadFromFile(path+".txt");
    //print the maze
    view_->displayMaze(maze);
    // cout << maze << endl;
}