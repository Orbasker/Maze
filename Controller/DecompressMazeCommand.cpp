
#include "DecompressMazeCommand.h"
void DecompressMazeCommand::execute() {
    //ask the user for the path
    string path;
    cout << "Please enter the path of the file you want to decompress" << endl;
    cin >> path;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character

    Maze2d maze = MazeCompression::decompressAndReadFromFile(path+".txt");

    //print the maze
    try{
    if(maze.getCell(0,0) != 2)
    {
        throw "An error has accured while decompressing the maze, please try again";
    }
    view_->displayMaze(maze);
    }
    catch(const char* msg)
    {
        cout << RED << "An error has accured while decompressing the maze, please try again" << RESET << endl;
    }
    // cout << maze << endl;
}

void DecompressMazeCommand::solveMaze() {
    string path;
    cout << "Please enter the path of the file you want to solve" << endl;
    cin >> path;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character

    Maze2d maze = MazeCompression::decompressAndReadFromFile(path+".txt");
    Maze2dSearchable searchableMaze(maze);
    BFS< std::pair<int, int> >  bfs;
    Solution<std::pair<int, int> > solution = bfs.search(searchableMaze);
    //print the maze
    view_->displayMaze(maze);
    view_->displaySolution(solution);
}