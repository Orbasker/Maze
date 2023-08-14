#include "Controller.h"

#include <iostream>
class HelloCommand : public Command
{
public:
    void execute() override
    {
        std::cout << "Hello, world!" << std::endl;
    }
};

class ByeCommand : public Command
{
public:
    void execute() override
    {
        std::cout << "Goodbye!" << std::endl;
    }
};
MazeController::MazeController() : cli_(new CLI(std::cin, std::cout)), model_(new MazeModel()), view_(new MazeView())
{
    // HelloCommand *helloCommand = new HelloCommand();
    // ByeCommand *byeCommand = new ByeCommand();
    SolveMazeCommand *solveMazeCommand = new SolveMazeCommand(model_, view_);
    GenerateMazeCommand *genrateMazeCommand = new GenerateMazeCommand(model_, view_);
    CompressMazeCommand *compressMazeCommand = new CompressMazeCommand(model_, view_);
    DecompressMazeCommand *decompressMazeCommand = new DecompressMazeCommand(model_, view_);
    MazeSizeCommand *mazeSizeCommand = new MazeSizeCommand(view_,model_);
    mazeMatrixSizeCommand *MazeMatrixSizeCommand = new mazeMatrixSizeCommand(view_,model_);
    DisplayMazeCommand *displayMazeCommand = new DisplayMazeCommand(view_,model_);
    ShowDirCommand *showDirCommand = new ShowDirCommand(view_,model_);
    cli_->addCommand("generateMaze", genrateMazeCommand);
    cli_->addCommand("solveMaze", solveMazeCommand);
    cli_->addCommand("saveMaze", compressMazeCommand);
    cli_->addCommand("loadMaze", decompressMazeCommand);
    cli_->addCommand("mazeSize", MazeMatrixSizeCommand);
    cli_->addCommand("fileSize", mazeSizeCommand);
    cli_->addCommand("display", displayMazeCommand);
    cli_->addCommand("dir", showDirCommand);
}



void MazeController::start()
{
    std::cout <<BOLD<<UNDERLINE<<RED<< "Welcome to the Maze Game!" <<RESET<< endl;
    // std::cout << "Here are the commands you can use:" << endl;
    cli_->printMenu();
    cli_->start();
}
