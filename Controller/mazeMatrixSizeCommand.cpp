// Or Basker   316388743
// Nave Maymon 318887965

#include "mazeMatrixSizeCommand.h"

void mazeMatrixSizeCommand::execute() {
    //get the size in the memory of the Maze2d Object
    //get the name of the maze from the user
    string name;
    cout << "Please enter the name of the maze: " << endl;
    cin >> name;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //get the maze from the memory
    MazeCompression *compress;
    Maze2d maze = compress->decompressAndReadFromFile("Mazes/" + name + ".txt");
    // Maze2d maze = model_->getMaze(name);
    if (maze.getSize() == 0  || maze.getCell(0,0) != 2 ){
        cout<<BOLD <<RED << "The maze does not exist" <<RESET<< endl;
        cout<<BOLD <<YELLOW<< "Maybe you tried to search in the mazes file? so try the command:"<<BOLD<<CYAN<<" fileSize " <<RESET<< endl;
        return;
    }
    cout << "The size of the maze is: " << maze.getSize() << endl;
    //print the size of the maze
    cout << "The size of the maze is: " << maze.getSize() << endl;
    
}