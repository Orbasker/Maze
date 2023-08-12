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
    HelloCommand *helloCommand = new HelloCommand();
    ByeCommand *byeCommand = new ByeCommand();
    SolveMazeCommand *solveMazeCommand = new SolveMazeCommand(model_, view_);
    GenerateMazeCommand *genrateMazeCommand = new GenerateMazeCommand(model_, view_);
    CompressMazeCommand *compressMazeCommand = new CompressMazeCommand(model_, view_);
    DecompressMazeCommand *decompressMazeCommand = new DecompressMazeCommand(model_, view_);
    MazeSizeCommand *mazeSizeCommand = new MazeSizeCommand(view_,model_);
    cli_->addCommand("hello", helloCommand);
    cli_->addCommand("bye", byeCommand);
    cli_->addCommand("genrate", genrateMazeCommand);
    cli_->addCommand("solve", solveMazeCommand);
    cli_->addCommand("compress", compressMazeCommand);
    cli_->addCommand("decompress", decompressMazeCommand);
    cli_->addCommand("mazeSize", mazeSizeCommand);
}

void MazeController::start()
{
    std::cout << "Welcome to the Maze Game!" << endl;
    cli_->start();
}
