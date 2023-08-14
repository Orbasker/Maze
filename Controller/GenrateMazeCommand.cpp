#include "GenrateMazeCommand.h"
#include <iostream> // Include necessary headers for std::cout

GenerateMazeCommand::GenerateMazeCommand(MazeModel *model, MazeView *view)
    : model_(model), view_(view) /* other params initialization */ {}

void GenerateMazeCommand::execute()
{
    // Get from user the paramaters for the maze'
    std::cout << "Enter the name of the maze: ";
    std::cin >> name_;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character

    std::cout << "Enter the size of the maze: ";
    try
    {
        std::cin >> size_;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character
        while (!(std::cin >> size_)) {
        // Clear the input stream and ignore any remaining characters
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout <<BOLD<<RED<< "Invalid input. Please enter a valid number: "<<RESET<<std::endl;
        }
        
            model_->generateMaze(name_, size_, size_);
            std::cout <<BOLD<<GREEN<< "Maze '" << name_ << "' generated and saved." <<RESET<< std::endl;
        
            view_->displayMaze(model_->getMaze(name_));
        
       
    }
    catch (std::exception &e)
    {
        std::cout <<BOLD<<RED<< "Invalid input" <<RESET<< std::endl;
    }
    catch (const char *msg)
    {
        std::cout <<RED<< msg <<RESET<< std::endl;
    }
    
    
}
